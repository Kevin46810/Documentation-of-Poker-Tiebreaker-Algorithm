Script started on 2025-10-31 00:46:35-04:00
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ make
make: Nothing to be done for 'all'.
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
JS AS 3C 7D 5H 9D 

***Hand Combinations***
 AS  3C  7D  5H  9D | JS
 JS  3C  7D  5H  9D | AS
 JS  AS  7D  5H  9D | 3C
 JS  AS  3C  5H  9D | 7D
 JS  AS  3C  7D  9D | 5H
 JS  AS  3C  7D  5H | 9D

***High Hand Order***
 AS  JS  9D  7D  5H |  3C -- High Card
 AS  JS  9D  7D  3C |  5H -- High Card
 AS  JS  9D  5H  3C |  7D -- High Card
 AS  JS  7D  5H  3C |  9D -- High Card
 AS  9D  7D  5H  3C |  JS -- High Card
 JS  9D  7D  5H  3C |  AS -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
AS AD 3C 7D 5H 9D 

***Hand Combinations***
 AD  3C  7D  5H  9D | AS
 AS  3C  7D  5H  9D | AD
 AS  AD  7D  5H  9D | 3C
 AS  AD  3C  5H  9D | 7D
 AS  AD  3C  7D  9D | 5H
 AS  AD  3C  7D  5H | 9D

***High Hand Order***
 AD  AS  9D  7D  5H |  3C -- Pair
 AD  AS  9D  7D  3C |  5H -- Pair
 AD  AS  9D  5H  3C |  7D -- Pair
 AD  AS  7D  5H  3C |  9D -- Pair
 AS  9D  7D  5H  3C |  AD -- High Card
 AD  9D  7D  5H  3C |  AS -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
2S 2D 3C 7D 5H 9D 

***Hand Combinations***
 2D  3C  7D  5H  9D | 2S
 2S  3C  7D  5H  9D | 2D
 2S  2D  7D  5H  9D | 3C
 2S  2D  3C  5H  9D | 7D
 2S  2D  3C  7D  9D | 5H
 2S  2D  3C  7D  5H | 9D

***High Hand Order***
 9D  7D  5H  2D  2S |  3C -- Pair
 9D  7D  3C  2D  2S |  5H -- Pair
 9D  5H  3C  2D  2S |  7D -- Pair
 7D  5H  3C  2D  2S |  9D -- Pair
 9D  7D  5H  3C  2S |  2D -- High Card
 9D  7D  5H  3C  2D |  2S -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
JS JD 3C 7D 4H 8S 

***Hand Combinations***
 JD  3C  7D  4H  8S | JS
 JS  3C  7D  4H  8S | JD
 JS  JD  7D  4H  8S | 3C
 JS  JD  3C  4H  8S | 7D
 JS  JD  3C  7D  8S | 4H
 JS  JD  3C  7D  4H | 8S

***High Hand Order***
 JD  JS  8S  7D  4H |  3C -- Pair
 JD  JS  8S  7D  3C |  4H -- Pair
 JD  JS  8S  4H  3C |  7D -- Pair
 JD  JS  7D  4H  3C |  8S -- Pair
 JS  8S  7D  4H  3C |  JD -- High Card
 JD  8S  7D  4H  3C |  JS -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
QS QD 3S 3H 5H 6S 

***Hand Combinations***
 QD  3S  3H  5H  6S | QS
 QS  3S  3H  5H  6S | QD
 QS  QD  3H  5H  6S | 3S
 QS  QD  3S  5H  6S | 3H
 QS  QD  3S  3H  6S | 5H
 QS  QD  3S  3H  5H | 6S

***High Hand Order***
 QD  QS  6S  3H  3S |  5H -- Two Pair
 QD  QS  5H  3H  3S |  6S -- Two Pair
 QD  QS  6S  5H  3S |  3H -- Pair
 QD  QS  6S  5H  3H |  3S -- Pair
 QS  6S  5H  3H  3S |  QD -- Pair
 QD  6S  5H  3H  3S |  QS -- Pair
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
4H 4S 5D 5C AS AD 

***Hand Combinations***
 4S  5D  5C  AS  AD | 4H
 4H  5D  5C  AS  AD | 4S
 4H  4S  5C  AS  AD | 5D
 4H  4S  5D  AS  AD | 5C
 4H  4S  5D  5C  AD | AS
 4H  4S  5D  5C  AS | AD

***High Hand Order***
 AD  AS  5C  5D  4S |  4H -- Two Pair
 AD  AS  5C  5D  4H |  4S -- Two Pair
 AD  AS  5C  4S  4H |  5D -- Two Pair
 AD  AS  5D  4S  4H |  5C -- Two Pair
 AS  5C  5D  4S  4H |  AD -- Two Pair
 AD  5C  5D  4S  4H |  AS -- Two Pair
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ 
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
KS KH KC 7D 7S 7H 

***Hand Combinations***
 KH  KC  7D  7S  7H | KS
 KS  KC  7D  7S  7H | KH
 KS  KH  7D  7S  7H | KC
 KS  KH  KC  7S  7H | 7D
 KS  KH  KC  7D  7H | 7S
 KS  KH  KC  7D  7S | 7H

***High Hand Order***
 KC  KH  KS  7H  7S |  7D -- Full House
 KC  KH  KS  7S  7D |  7H -- Full House
 KC  KH  KS  7H  7D |  7S -- Full House
 KH  KS  7H  7S  7D |  KC -- Full House
 KC  KS  7H  7S  7D |  KH -- Full House
 KC  KH  7H  7S  7D |  KS -- Full House
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
10H 10S 10D 8D 8C 2S 

***Hand Combinations***
10S 10D  8D  8C  2S |10H
10H 10D  8D  8C  2S |10S
10H 10S  8D  8C  2S |10D
10H 10S 10D  8C  2S | 8D
10H 10S 10D  8D  2S | 8C
10H 10S 10D  8D  8C | 2S

***High Hand Order***
10D 10S 10H  8C  8D |  2S -- Full House
10D 10S 10H  8C  2S |  8D -- Three of a Kind
10D 10S 10H  8D  2S |  8C -- Three of a Kind
10S 10H  8C  8D  2S | 10D -- Two Pair
10D 10S  8C  8D  2S | 10H -- Two Pair
10D 10H  8C  8D  2S | 10S -- Two Pair
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
7S 7H 7C 8S 3H 4S 

***Hand Combinations***
 7H  7C  8S  3H  4S | 7S
 7S  7C  8S  3H  4S | 7H
 7S  7H  8S  3H  4S | 7C
 7S  7H  7C  3H  4S | 8S
 7S  7H  7C  8S  4S | 3H
 7S  7H  7C  8S  3H | 4S

***High Hand Order***
 8S  7C  7H  7S  4S |  3H -- Three of a Kind
 8S  7C  7H  7S  3H |  4S -- Three of a Kind
 7C  7H  7S  4S  3H |  8S -- Three of a Kind
 8S  7H  7S  4S  3H |  7C -- Pair
 8S  7C  7S  4S  3H |  7H -- Pair
 8S  7C  7H  4S  3H |  7S -- Pair
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
10H 10C 10S 10D 5C 5S 

***Hand Combinations***
10C 10S 10D  5C  5S |10H
10H 10S 10D  5C  5S |10C
10H 10C 10D  5C  5S |10S
10H 10C 10S  5C  5S |10D
10H 10C 10S 10D  5S | 5C
10H 10C 10S 10D  5C | 5S

***High Hand Order***
10D 10S 10C 10H  5S |  5C -- Four of a Kind
10D 10S 10C 10H  5C |  5S -- Four of a Kind
10S 10C 10H  5S  5C | 10D -- Full House
10D 10S 10H  5S  5C | 10C -- Full House
10D 10S 10C  5S  5C | 10H -- Full House
10D 10C 10H  5S  5C | 10S -- Full House
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
AS AD AH AC 10S 9S 

***Hand Combinations***
 AD  AH  AC 10S  9S | AS
 AS  AH  AC 10S  9S | AD
 AS  AD  AC 10S  9S | AH
 AS  AD  AH 10S  9S | AC
 AS  AD  AH  AC  9S |10S
 AS  AD  AH  AC 10S | 9S

***High Hand Order***
 AC  AH  AD  AS 10S |  9S -- Four of a Kind
 AC  AH  AD  AS  9S | 10S -- Four of a Kind
 AC  AH  AS 10S  9S |  AD -- Three of a Kind
 AH  AD  AS 10S  9S |  AC -- Three of a Kind
 AC  AD  AS 10S  9S |  AH -- Three of a Kind
 AC  AH  AD 10S  9S |  AS -- Three of a Kind
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
AS 2D 3H 4S 5S 6S 

***Hand Combinations***
 2D  3H  4S  5S  6S | AS
 AS  3H  4S  5S  6S | 2D
 AS  2D  4S  5S  6S | 3H
 AS  2D  3H  5S  6S | 4S
 AS  2D  3H  4S  6S | 5S
 AS  2D  3H  4S  5S | 6S

***High Hand Order***
 6S  5S  4S  3H  2D |  AS -- Straight
 AS  5S  4S  3H  2D |  6S -- Straight
 AS  6S  5S  4S  3H |  2D -- High Card
 AS  6S  5S  4S  2D |  3H -- High Card
 AS  6S  5S  3H  2D |  4S -- High Card
 AS  6S  4S  3H  2D |  5S -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
10D QH KH JH AH AS 

***Hand Combinations***
 QH  KH  JH  AH  AS |10D
10D  KH  JH  AH  AS | QH
10D  QH  JH  AH  AS | KH
10D  QH  KH  AH  AS | JH
10D  QH  KH  JH  AS | AH
10D  QH  KH  JH  AH | AS

***High Hand Order***
 AS  KH  QH  JH 10D |  AH -- Straight
 AH  KH  QH  JH 10D |  AS -- Straight
 AS  AH  KH  QH  JH | 10D -- Pair
 AS  AH  KH  QH 10D |  JH -- Pair
 AS  AH  KH  JH 10D |  QH -- Pair
 AS  AH  QH  JH 10D |  KH -- Pair
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile [Kpoker handFile 
***This is the Hand***
5S 6S 3S 2S AS 4S 

***Hand Combinations***
 6S  3S  2S  AS  4S | 5S
 5S  3S  2S  AS  4S | 6S
 5S  6S  2S  AS  4S | 3S
 5S  6S  3S  AS  4S | 2S
 5S  6S  3S  2S  4S | AS
 5S  6S  3S  2S  AS | 4S

***High Hand Order***
 6S  5S  4S  3S  2S |  AS -- Straight flush
 AS  5S  4S  3S  2S |  6S -- Straight flush
 AS  6S  5S  4S  3S |  2S -- Flush
 AS  6S  5S  4S  2S |  3S -- Flush
 AS  6S  5S  3S  2S |  4S -- Flush
 AS  6S  4S  3S  2S |  5S -- Flush
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
5S 6S 3H 2S AS 4S 

***Hand Combinations***
 6S  3H  2S  AS  4S | 5S
 5S  3H  2S  AS  4S | 6S
 5S  6S  2S  AS  4S | 3H
 5S  6S  3H  AS  4S | 2S
 5S  6S  3H  2S  4S | AS
 5S  6S  3H  2S  AS | 4S

***High Hand Order***
 AS  6S  5S  4S  2S |  3H -- Flush
 6S  5S  4S  3H  2S |  AS -- Straight
 AS  5S  4S  3H  2S |  6S -- Straight
 AS  6S  5S  4S  3H |  2S -- High Card
 AS  6S  5S  3H  2S |  4S -- High Card
 AS  6S  4S  3H  2S |  5S -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile [Kpoker handFile 
***This is the Hand***
10D QH KH JH AH 9S 

***Hand Combinations***
 QH  KH  JH  AH  9S |10D
10D  KH  JH  AH  9S | QH
10D  QH  JH  AH  9S | KH
10D  QH  KH  AH  9S | JH
10D  QH  KH  JH  9S | AH
10D  QH  KH  JH  AH | 9S

***High Hand Order***
 AH  KH  QH  JH 10D |  9S -- Straight
 KH  QH  JH 10D  9S |  AH -- Straight
 AH  KH  QH  JH  9S | 10D -- High Card
 AH  KH  QH 10D  9S |  JH -- High Card
 AH  KH  JH 10D  9S |  QH -- High Card
 AH  QH  JH 10D  9S |  KH -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
10D QH KH JH AH 8S 

***Hand Combinations***
 QH  KH  JH  AH  8S |10D
10D  KH  JH  AH  8S | QH
10D  QH  JH  AH  8S | KH
10D  QH  KH  AH  8S | JH
10D  QH  KH  JH  8S | AH
10D  QH  KH  JH  AH | 8S

***High Hand Order***
 AH  KH  QH  JH 10D |  8S -- Straight
 AH  KH  QH  JH  8S | 10D -- High Card
 AH  KH  QH 10D  8S |  JH -- High Card
 AH  KH  JH 10D  8S |  QH -- High Card
 AH  QH  JH 10D  8S |  KH -- High Card
 KH  QH  JH 10D  8S |  AH -- High Card
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
10S AS QS JS KS 10D 

***Hand Combinations***
 AS  QS  JS  KS 10D |10S
10S  QS  JS  KS 10D | AS
10S  AS  JS  KS 10D | QS
10S  AS  QS  KS 10D | JS
10S  AS  QS  JS 10D | KS
10S  AS  QS  JS  KS |10D

***High Hand Order***
 AS  KS  QS  JS 10S | 10D -- Royal Flush
 AS  KS  QS  JS 10D | 10S -- Straight
 AS  KS  QS 10D 10S |  JS -- Pair
 AS  KS  JS 10D 10S |  QS -- Pair
 AS  QS  JS 10D 10S |  KS -- Pair
 KS  QS  JS 10D 10S |  AS -- Pair
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ poker handFile 
***This is the Hand***
10S AS QS JS KS 9S 

***Hand Combinations***
 AS  QS  JS  KS  9S |10S
10S  QS  JS  KS  9S | AS
10S  AS  JS  KS  9S | QS
10S  AS  QS  KS  9S | JS
10S  AS  QS  JS  9S | KS
10S  AS  QS  JS  KS | 9S

***High Hand Order***
 AS  KS  QS  JS 10S |  9S -- Royal Flush
 KS  QS  JS 10S  9S |  AS -- Straight flush
 AS  KS  QS  JS  9S | 10S -- Flush
 AS  KS  QS 10S  9S |  JS -- Flush
 AS  KS  JS 10S  9S |  QS -- Flush
 AS  QS  JS 10S  9S |  KS -- Flush
]0;binder_kr@cobra:~/CSC330/poker/cpp[binder_kr@cobra cpp]$ exit
exit

Script done on 2025-10-31 00:50:10-04:00
