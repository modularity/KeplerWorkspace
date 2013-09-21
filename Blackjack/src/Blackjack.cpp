//============================================================================
// Name        : Blackjack.cpp
// Author      : Lauren Kroll
// Version     :
// Description : Hello World in C++
//============================================================================

#include <iostream>
#include <stdlib.h>
using namespace std;

void playGame();
int dealCard();

int main() {

	playGame();

	return 0;
}

void playGame() {

	char anthCard = 'a';
	char replay = 'n';
	bool endGame = false;
	int plyrCard = 0, newPlyrCard = 0, plyrTotal = 0;
	int dlrCard = 0, newDlrCard = 0, dlrTotal = 0;

do {
	//prep new game variables
	plyrTotal = 0, dlrTotal = 0;
	endGame = false;
	anthCard = 'a';

	//prep initial cards for game
	dlrCard = dealCard();
	plyrCard = dealCard();
	newPlyrCard = dealCard();

	cout << "The dealer starts with a " << dlrCard << endl;
	dlrTotal = dlrCard;
	cout << "Your first cards: " << plyrCard << ", " << newPlyrCard << endl;
	plyrTotal = plyrCard + newPlyrCard;
	cout << "Total: " << plyrTotal << endl;;

	do {
		cout << "Hit? (y/n): ";
		cin >> anthCard;
		if (anthCard != 'y') break;

		newPlyrCard = dealCard();
		cout << "Card: " << newPlyrCard << endl;
		plyrTotal += newPlyrCard;
		cout << "Total: " << plyrTotal << endl;

		if (plyrTotal > 21) {
			cout << "BUST!" << endl;
			endGame = true;
			break;
		}
	} while (anthCard);

	cout << "Dealer has a " << dlrCard << endl;

	//continue if Dealer is shortchanged
	while (endGame == false && dlrTotal < 17) {

		//dramatic pause
		char cntnu = 'a';
		while (cntnu != 'c') {
			cout << "Press 'c' to continue: ";
			cin >> cntnu;
		}

		//new Dealer card and total
		newDlrCard = dealCard();
		cout << "Dealer gets a " << newDlrCard << endl;
		dlrTotal += newDlrCard;
		cout << "Total: " << dlrTotal << endl;

		//check Dealer's hand
		if (dlrTotal > 21) {
			cout << "DEALER BUST! U WIN :)" << endl;
			endGame = true;
			break;
		} else if (dlrTotal == 21) {
			cout << "DEALER WINS :0" << endl;
			endGame = true;
			break;
		}
	}

	if (endGame == false) {
		dlrTotal >= plyrTotal ? cout << "DEALER WINS :0\n" : cout << "YOU WIN! :)\n";
	}
	cout << "Play again? (y/n): ";
	cin >> replay;
	cout << endl;

	} while (replay == 'y');

}

int dealCard() {
	//range of card types
	int deckrange = 13;
	int currCard;
	//determine a random index, greater than 0
	int curIndex = (int)(rand() % deckrange + 1);

	//if index is less than 10, return index
	//otherwise return 10 -> J, Q, K or 10
	currCard = (curIndex < 10) ? curIndex : 10;

	return currCard;
}
