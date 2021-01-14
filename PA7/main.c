#include "Poker.h"

int main(void)
{

	Hand player_hand, dealer_hand;

	int index = 1, cards = 0, player_score = 0, dealer_score = 0, start_game = 0;

	start_game = welcome_menu();
	if (start_game == 3)
	{
		system("cls");
	}
	else
	{
		/* initialize suit array */
		const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
		/* initialize face array */
		const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
			"Nine", "Ten", "Jack", "Queen", "King" };
		/* initalize deck array */
		int deck[4][13] = { 0 };

		srand((unsigned)time(NULL)); /* seed random-number generator */

		shuffle(deck);
		deal(deck, face, suit, &player_hand, index, HAND_SIZE, 0);
		index += 5;
		print_hand(deck, face, suit, &player_hand, HAND_SIZE);

		deal(deck, face, suit, &dealer_hand, index, HAND_SIZE, 0);
		index += 5;
		//print_hand(deck, face, suit, &dealer_hand,HAND_SIZE);

		cards = new_cards();
		if (cards > 0)
		{
			switch_cards(deck, face, suit, &player_hand, index, cards);
		}
		card_sort(&player_hand, HAND_SIZE);
		print_hand(deck, face, suit, &player_hand, HAND_SIZE);
		index += cards;

		cards = new_cards();
		if (cards > 0)
		{
			switch_cards(deck, face, suit, &player_hand, index, cards);
		}
		card_sort(&player_hand, HAND_SIZE);
		print_hand(deck, face, suit, &player_hand, HAND_SIZE);

		player_score = hand_check(player_hand);
		dealer_score = hand_check(dealer_hand);
		declare_winner(player_score, dealer_score,player_hand,dealer_hand);

		return 0;
	}
}