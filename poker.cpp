#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <map>
#include <cmath>
using namespace std;

class Card {
public:
    int cardRank;
    char suit;
    string name;
    int suitVal;

    friend bool operator<(const Card &card1, const Card &card2) {

        int val1 = card1.cardRank;
        int val2 = card2.cardRank;

        return val1 < val2;
    }

    friend bool operator==(const Card &card1, const Card &card2) {

        int val1 = card1.cardRank;
        int val2 = card2.cardRank;

        return val1 == val2;
    }

    friend bool operator!=(const Card &card1, const Card &card2) {

        int val1 = card1.cardRank;
        int val2 = card2.cardRank;

        return val1 != val2;
    }

    friend ostream &operator<<(ostream &output, Card &card) {
        output << card.name;
        return output;
    }
};

class Hand {
public:
    vector<Card> cards;
    int handRank;
    Card removedCard;

    friend bool operator<(const Hand &hand1, const Hand &hand2) {

        int val1 = hand1.handRank;
        int val2 = hand2.handRank;

        return val1 < val2;
    }

};

void playCards();
bool isRoyalStraight(bool straight, vector<Card> &cards);
bool isStraight(vector<Card> &cards);
bool isAceLowStraight(vector<Card> &cards);
bool isFlush(vector<Card> &cards);
void findDupValues(int &dupCounter1, int &dupCounter2, vector<Card> &hand);
void createHandList(vector<Card> &cards, vector<Hand> &hands);
void breakTies(vector<vector<Hand> > &handSublists, vector<Hand> &newList);
void printHandOrder(vector<Hand> &hands);
void rankHands(vector<Card> &cards);
void showHand(vector<Card> &cards);
void showHandCombos(vector<Card> &cards);
void setHandFromFile(vector<Card> &cards, int numArgs, string filename);
bool duplicateFound(vector<Card> &cards);
char getCardSuit(string cardName);
int getCardVal(string cardName);
void createDeck(vector<Card> &deck);
void printDeck(vector<Card> &deck);
void setHand(vector<Card> &hand, vector<Card> &deck);
int getAceInd(vector<Card> &hand);
void assignSuitVals(vector<Card> &hand);

const int HIGH_CARD = 100000;
const int PAIR = 200000;
const int TWO_PAIR = 300000;
const int THREE_KIND = 400000;
const int STRAIGHT = 500000;
const int FLUSH = 600000;
const int FULL_HOUSE = 700000;
const int FOUR_KIND = 800000;
const int STRAIGHT_FLUSH = 900000;
const int ROYAL_FLUSH = 1000000;

const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;
const int ACE_LOW = 1;

const int DECK_SIZE = 52;
const int HAND_SIZE = 6;

const int WIDTH = 3;

int main(int argc, const char* argv[]) {

  vector<Card> deck;
  vector<Card> hand;
  
  if (argc > 1) {
    string filename = argv[1];
    setHandFromFile(hand, argc, filename);

    if (duplicateFound(hand)) {
      cerr << "Duplicate found in hand ";

      for (int i = 0; i < hand.size(); i++)
        cout << hand[i].name << " ";

      cout << endl;
      exit(1);
    }
  }

  else {
    createDeck(deck);
    printDeck(deck);
    setHand(hand, deck);
  }

  showHand(hand);
  showHandCombos(hand);
  rankHands(hand);
}

bool isRoyalStraight(bool straight, vector<Card> &cards) {

  if (!straight)
    return false;

  vector<Card> tempList = cards;
  sort(tempList.begin(), tempList.end());
  
  return (tempList[0].cardRank == 10);
}

bool isStraight(vector<Card> &cards) {

  vector<Card> tempList = cards;
  sort(tempList.begin(), tempList.end());
  
  if (isAceLowStraight(tempList)) {
    cards[getAceInd(cards)].cardRank = ACE_LOW;
    return true;
  }

  for (int i = 0; i < tempList.size()-1; i++) {
    if (tempList[i+1].cardRank - tempList[i].cardRank != 1)
      return false;
  }
  
  return true;
}

bool isAceLowStraight(vector<Card> &cards) {

  vector<Card> tempList = cards;
  sort(tempList.begin(), tempList.end());

  return ((tempList[0].cardRank == 2) && (tempList[1].cardRank == 3) && (tempList[2].cardRank == 4) && (tempList[3].cardRank == 5) && (tempList[4].cardRank == ACE));
}

int getAceInd(vector<Card> &cards) {

  for (int i = 0; i < cards.size(); i++)
    if (cards[i].cardRank == ACE)
      return i;

  cerr << "Incorrectly entered getAceInd." << endl;
  exit(1);
  return -1;
}

bool isFlush(vector<Card> &cards) {

  char lastSuit = cards[cards.size()-1].suit;
  int numSuits = 1;

  for (int i = 0; i < cards.size()-1; i++)
    if (cards[i].suit == lastSuit)
      numSuits++;

  return (numSuits >= HAND_SIZE-1);
}

void findDupValues(int &dupCounter1, int &dupCounter2, vector<Card> &hand) {

  vector<int> vals;

  for (int i = 0; i < hand.size(); i++)
    vals.push_back(hand[i].cardRank);

  sort(vals.begin(), vals.end());

  vector<vector<int> > valsLists;
  vector<int> sublist;
  int currNum = vals[0];

  for (int i = 0; i < vals.size(); i++) {
    if (currNum != vals[i]) {
      valsLists.push_back(sublist);
      currNum = vals[i];
      sublist = {};
    }

    sublist.push_back(vals[i]);

    if (i == vals.size()-1)
      valsLists.push_back(sublist);
  }

  int bannedInd = -1;

  for (int i = 0; i < valsLists.size(); i++) {
    if (valsLists[i].size() > dupCounter1) {
      dupCounter1 = valsLists[i].size() - 1;
      bannedInd = i;
    }
  }

  for (int i = 0; i < valsLists.size(); i++)
    if (valsLists[i].size() > dupCounter2 && i != bannedInd)
      dupCounter2 = valsLists[i].size() - 1;
}

void createHandList(vector<Card> &cards, vector<Hand> &hands) {

  for (int i = 0; i < cards.size(); i++) {
    vector<Card> tempHand;
    Card removedCard;
    for (int j = 0; j < cards.size(); j++) {
      if (j != i)
        tempHand.push_back(cards[j]);

      else
        removedCard = cards[j];
    }

    sort(tempHand.begin(), tempHand.end());
    reverse(tempHand.begin(), tempHand.end());

    int dupCounter1 = 0;
    int dupCounter2 = 0;
    findDupValues(dupCounter1, dupCounter2, tempHand);
    bool flush = isFlush(tempHand);
    bool straight = isStraight(tempHand);
    bool royalStraight = isRoyalStraight(straight, tempHand);

    Hand h;
    h.cards = tempHand;
    h.removedCard = removedCard;

    if (royalStraight && flush)
      h.handRank = ROYAL_FLUSH;

    else if (straight && flush)
      h.handRank = STRAIGHT_FLUSH;

    else if (dupCounter1 == 3 || dupCounter2 == 3)
      h.handRank = FOUR_KIND;

    else if ((dupCounter1 == 2 && dupCounter2 == 1) || (dupCounter1 == 1 && dupCounter2 == 2))
      h.handRank = FULL_HOUSE;

    else if (flush)
      h.handRank = FLUSH;

    else if (straight)
      h.handRank = STRAIGHT;

    else if (dupCounter1 == 2 || dupCounter2 == 2)
      h.handRank = THREE_KIND;

    else if (dupCounter1 == 1 && dupCounter2 == 1)
      h.handRank = TWO_PAIR;

    else if (dupCounter1 == 1 || dupCounter2 == 1)
      h.handRank = PAIR;

    else
      h.handRank = HIGH_CARD;

    hands.push_back(h);
  }

  sort(hands.begin(), hands.end());
}

void breakTies(vector<Hand> &hands) {

  for (int i = 0; i < hands.size(); i++) {
    for (int j = 0; j < hands[i].cards.size(); j++) {
      int cardRank = hands[i].cards[j].cardRank * 100;
      hands[i].handRank += cardRank;
    }

    assignSuitVals(hands[i].cards);

    for (int j = 0; j < hands[i].cards.size(); j++) {
      int cardSuitVal = hands[i].cards[j].suitVal;
      hands[i].handRank += cardSuitVal;
    }
  }

  sort(hands.begin(), hands.end());
  reverse(hands.begin(), hands.end());
}

void assignSuitVals(vector<Card> &hand) {

  map<char, int> suitVals = {{'D', 1}, {'C', 2}, {'H', 3}, {'S', 4}};

  for (int i = 0; i < hand.size(); i++)
    hand[i].suitVal = suitVals[hand[i].suit];
}

void printHandOrder(vector<Hand> &hands) {

  cout << "***High Hand Order***" << endl;

  for (int i = 0; i < hands.size(); i++) {
    for (int j = 0; j < hands[i].cards.size(); j++)
      cout << setw(WIDTH) << right << hands[i].cards[j].name << " ";

    cout << "| " << setw(WIDTH) << right << hands[i].removedCard << " -- ";

    int rank = round(hands[i].handRank / 100000.0) * 100000;

    switch (rank) {
      case HIGH_CARD: cout << "High Card" << endl; break;
      case PAIR: cout << "Pair" << endl; break;
      case TWO_PAIR: cout << "Two Pair" << endl; break;
      case THREE_KIND: cout << "Three of a Kind" << endl; break;
      case STRAIGHT: cout << "Straight" << endl; break;
      case FLUSH: cout << "Flush" << endl; break;
      case FULL_HOUSE: cout << "Full House" << endl; break;
      case FOUR_KIND: cout << "Four of a Kind" << endl; break;
      case STRAIGHT_FLUSH: cout << "Straight flush" << endl; break;
      case ROYAL_FLUSH: cout << "Royal Flush" << endl; break;
      default:
        cerr << "Invalid hand ranking." << endl;
        exit(1);
    }
  }
}

void rankHands(vector<Card> &cards) {

  vector<Hand> hands;
  createHandList(cards, hands);

  breakTies(hands);

  printHandOrder(hands);
}

void showHand(vector<Card> &cards) {

  cout << "***This is the Hand***" << endl;

  for (int i = 0; i < cards.size(); i++) 
    cout << cards[i] << " ";

  cout << endl << endl;
}

void showHandCombos(vector<Card> &cards) {

  cout << "***Hand Combinations***" << endl;

  for (int i = 0; i < cards.size(); i++) {
    vector<Card> tempHand;
    Card removedCard;

    for (int j = 0; j < cards.size(); j++) {
      if (j != i)
        tempHand.push_back(cards[j]);

      else
        removedCard = cards[j];
    }

    for (int j = 0; j < tempHand.size(); j++)
      cout << setw(WIDTH) << right << tempHand[j].name << " ";

    cout << "|" << setw(WIDTH) << right << removedCard.name << endl;
  }

  cout << endl;
}

void setHandFromFile(vector<Card> &cards, int numArgs, string filename) {

  if (numArgs != 2) {
    cerr << "You cannot put more than 2 args." << endl;
    exit(1);
  }

  fstream handFile(filename.c_str(), ios::in);

  string item;

  while (getline(handFile, item, ',')) {
    
    item.erase(remove_if(item.begin(), item.end(), ::isspace), item.end());

    Card card;
    card.name = item;

    if (card.name.length() > 3) {
      cerr << "Invalid card name " << card.name << "." << endl;
      exit(1);
    }

    card.cardRank = getCardVal(card.name);
    card.suit = getCardSuit(card.name);

    if (card.cardRank < ACE_LOW || card.cardRank > ACE) {
      cerr << "Invalid card value " << card.cardRank << "." << endl;
      exit(1);
    }

    if (card.suit != 'D' && card.suit != 'C' && card.suit != 'H' && card.suit != 'S') {
      cerr << "Invalid card suit " << card.suit << "." << endl;
      exit(1);
    }

    cards.push_back(card);
  }
}

int getCardVal(string cardName) {

  if (cardName.length() <= 2) {
    char cardVal = cardName[0];

    switch (cardVal) {
      case '2': return 2;
      case '3': return 3;
      case '4': return 4;
      case '5': return 5;
      case '6': return 6;
      case '7': return 7;
      case '8': return 8;
      case '9': return 9;
      case 'J': return JACK;
      case 'Q': return QUEEN;
      case 'K': return KING;
      case 'A': return ACE;
      default:
        cerr << "Invalid card value " << cardVal << "." << endl;
        exit(1);
    }

  }

  else if (cardName.length() == 3)
    return 10;

  else {
    cerr << "Invalid card name " << cardName << "." << endl;
    exit(1);
  }
}

char getCardSuit(string cardName) {

  int lastInd = cardName.length() - 1;

  if (cardName[lastInd] == 'D' || cardName[lastInd] == 'C' || cardName[lastInd] == 'H' || cardName[lastInd] == 'S')
    return cardName[lastInd];

  else {
    cerr << "Invalid card suit " << cardName[lastInd] << "." << endl;
    exit(1);
  }

  return ' ';
}

bool duplicateFound(vector<Card> &cards) {

  for (int i = 0; i < cards.size(); i++) {
    string bannedName = cards[i].name;

    for (int j = 0; j < cards.size(); j++)
      if (cards[j].name == bannedName && j != i)
        return true;
  }

  return false;
}

void createDeck(vector<Card> &deck) {

  vector<char> suits;

  for (int i = 0; i < DECK_SIZE/4; i++) {
    suits.push_back('D');
    suits.push_back('C');
    suits.push_back('H');
    suits.push_back('S');
  }

  vector<int> vals;
  int currVal = 2;

  for (int i = 0; i < DECK_SIZE; i++) {
    vals.push_back(currVal);
    currVal++;

    if (currVal > ACE)
      currVal = 2;
  }

  for (int i = 0; i < DECK_SIZE; i++) {
    Card card;
    card.cardRank = vals[i];
    card.suit = suits[i];
    card.name = "";

    if (card.cardRank < JACK)
      card.name += to_string(card.cardRank);

    else {
      if (card.cardRank == JACK)
        card.name += 'J';

      else if (card.cardRank == QUEEN)
        card.name += 'Q';

      else if (card.cardRank == KING)
        card.name += 'K';

      else if (card.cardRank == ACE)
        card.name += 'A';

      else {
        cerr << "Invalid card value " << card.cardRank << "." << endl;
        exit(1); 
      }
    }

    card.name += card.suit;

    deck.push_back(card);
  }

  //Shuffling code gotten from google AI
  random_device rd;
  mt19937 g(rd());
  shuffle(deck.begin(), deck.end(), g);
}

void printDeck(vector<Card> &deck) {

  cout << "***Shuffled " << DECK_SIZE << " card deck***" << endl;

  for (int i = 0; i < deck.size(); i++) {
    if (i > 0 && i % 13 == 0) {
      string text = '\n' + deck[i].name;
      cout << setw(WIDTH) << left << text << " ";
    }

    else
      cout << setw(WIDTH) << left << deck[i].name << " ";
  }

  cout << endl << endl;
}

void setHand(vector<Card> &hand, vector<Card> &deck) {

  for (int i = 0; i < HAND_SIZE; i++)
    hand.push_back(deck[i]);
}
