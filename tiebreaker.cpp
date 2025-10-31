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
