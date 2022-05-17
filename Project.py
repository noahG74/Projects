import random

game = True
rounds = True
suits = ('Spades','Hearts','Clubs','Diamonds')

nums = ('Two','Three','Four', 'Five','Six','Seven','Eight','Nine','Ten','Jack','Queen','King','Ace')

values = {'Two':2,'Three':3,'Four':4, 'Five':5,'Six':6,'Seven':7,'Eight':8,'Nine':9,'Ten':10,'Jack':10,'Queen':10,'King':10,'Ace':11}

colors = {'Spades':'Black','Hearts':'Red','Clubs':'Black', 'Diamonds':'Red'}

#Making the cards
class Card:
  def __init__(self,suit,num):
    self.suit = suit
    self.num = num
    
  def __str__(self):
    return 'Card Color: ' + colors[self.suit] + '\n' + 'Card Number: ' + self.num + '\n' + 'Card Suit: ' + self.suit + '\n'

#Adding cards into the the deck
class Deck: 
  def __init__(self):
    self.deck = []
    for j in suits:
      for i in nums:
        self.deck.append(Card(j,i))
    
  def __str__(self):
    deckCont = ''
    for i in self.deck:
      deckCont += i.suit + ' ' + i.num + ' ' + colors[i.suit] + '\n'
    return deckCont
    
  def shuffle(self):
    random.shuffle(self.deck)

  def deal(self):
    randomCard = random.choice(self.deck)
    return randomCard

#For players hand
class Hand:
  def __init__(self):
    self.cards = [] 
    self.value = 0   
    self.ace = 0   
    
  def addCard(self,card):
    self.cards.append(card)
    self.value += values[card.num]
    if card.num == 'Ace':
      self.ace += 1
    
  def aceValue(self):
    while self.value > 21 and self.ace:
      self.value -= 10
      self.ace -= 1

class Money:
  def __init__(self):
    self.total = 2500
    self.bet = 0
    
  def blackjackWin(self):
    self.total += self.bet*2
    
  def win(self):
    self.total += self.bet*2
    
  def lose(self):
    self.total -= self.bet

def bet(money,count):
  print ("Player",count+1,": current Balance: ", money.total)
  while True:
    try:
      money.bet = int(input("Please place your bet: "))
    except ValueError:
      print("Invalid entry, please try again")
    else:
      if money.bet > money.total:
        print("Cannot bet more than money owned, please try again")
      elif money.bet < 25:
        print("Bet must be a minimum of $25")
      elif money.bet == money.total:
        print("Cannot go all in at any point, please try again")
      else:
        break
        
def hit(deck,hand):
  hand.addCard(deck.deal())
  hand.aceValue()

def hiddenValue(num, hand):
  return hand.value - values[num] 

  
while game:

  print("Blackjack Project: \n\n")
  
  players = []
  playersMoney = []
  deck = Deck()
  dealer = Hand()
  count2 = []
  
  while True:
    try:
      x = int(input("Please enter the number of players: "))
    except ValueError:
      print("Invalid entry, please try again: ")
    else:
      if x < 1:
        print("There must at least one player at the table")
      elif x > 7:
        print("There can be no more than 7 players")
      else:
        break
  for i in range(x):
    players.append(Hand())
    playersMoney.append(Money())
    count2.append(0)
  
  for i in range(x):
    bet(playersMoney[i], i)

  for i in range(x):
    deck.shuffle
    players[i].addCard(deck.deal())
    deck.shuffle
    players[i].addCard(deck.deal())
    
  dealer.addCard(deck.deal())
  dealer.addCard(deck.deal())

  print("\nDealer Cards:\n")
  print ("*HIDDEN CARD*\n")
  print(dealer.cards[1])
  print ("Total: ", hiddenValue(dealer.cards[0].num, dealer))
  for i in range(x):
    print("\nPlayer",i+1,"cards:")
    print(*players[i].cards)
    print("Total:",players[i].value)
    
  count = 1
  losers = [999]
  while (rounds == True):
    print("\nROUND",count)
    for i in range(x):
      for j in losers:
        if j != i:
          while True:
            if count2[i] <= 3:
              try: 
                print("Player",i+1,"would you like to hit or stand (h or s): ")
                choice = input('')
                break
              except ValueError:
                print("Invalid entry, please try again: ")
            else:
              print("Player",i+1,"must hit since you already stood 3 times: ")
              choice = 'h'
              break

          if choice[0].lower() == 'h':
            hit(deck,players[i])
            print("\nPlayer",i+1,"cards:")
            print(*players[i].cards)
            print("Total:",players[i].value)
          elif choice[0].lower() == 's':
            count2[i] += 1

          if players[i].value > 21:
            print("BUST!!")
            playersMoney[i].lose()
            if losers[0] == 999:
              losers.remove(999)
            losers.append(i)
          elif players[i].value == 21:
            print("BLACKJACK!!")
            playersMoney[i].blackjackWin() 
            losers.append(i)
        else:
          print("Player",i+1,"can no longer make a decision")
          continue
        
    print("\nDealer Cards:\n")
    print ("*HIDDEN CARD*\n")
    print(dealer.cards[1])
    print ("Total: ", hiddenValue(dealer.cards[0].num, dealer))
    if dealer.value > 17:
      continue
    else:
      dealer.addCard(deck.deal())

    if count == 4 or len(losers) == x:
      rounds = False

  print("Dealer's cards: ")
  for i in range(x):
    print(dealer.cards[i])
  print("Total:",dealer.value)

  if dealer.value == 21:
    print("Dealer has won the game")
    for i in range(x):
      playersMoney[i].lose()
  elif dealer.value > 21 :
    print("Dealer has lost the game")
    for i in range(x):
      playersMoney[i].win()
      
  for i in range(x):
    if players[i].value > dealer.value:
      print("Player",i+1,"score:",players[i].value)
      print("Dealers score:",dealer.value)
      print("Player",i+1,"has beat the dealer")
      playersMoney[i].win()
      
    elif dealer.value > players[i].value:
      print("Player",i+1,"score:",players[i].value)
      print("Dealers score:",dealer.value)
      print("Player",i+1,"has lost to the dealer")
      playersMoney[i].lose()

  while True:
    try:
      choice = input("Would you like to play again: ")
    except ValueError:
      print("Invalid entry, please try again: ")
    else:
      if choice[0].lower() != 'y' and choice[0].lower() != 'n':
        print("Must enter yes or no")
      else:
        break
        
  if choice[0].lower() != 'y':
    print ("Bye Bye!!")
    game = False
  else:
    game = True

  
