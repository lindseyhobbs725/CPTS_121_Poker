#include "Poker.h"

int welcome_menu(void)
// menu to allow user to view game rules, play game or exit game
{
	int option = 0;
	do
	{
		printf("Hello, wanna play some poker? We are playing 5-card-draw!\n");
		printf("1. View rules\n2. Play game\n3. Exit\n");
		printf("What'll it be?: ");
		scanf("%d", &option);
		if (option > 3)
		{
			printf("\nInvalid option. Try again.\n\n");
		}
	} while (option > 3);
		
	if (option == 1)
	{
		printf("My mom says gambling is bad, so we aren't going to in this game. But winner gets bragging rights as the best 5-card-draw player eva!!! Alright, here are the rules:\n");
		printf("I'm the dealer, so I will deal 5 cards to each of us. Take a moment to evaluate what you have. You want to get one of the following:\n\n");
		//printf("Royal flush (Ace, King, Queen, Jack, & 10 all of the same suit)\nStraight flush (A straight in the same suit)\n");
		//printf("Full house (3 of the same face value and the other 2 same of a different face value)\n");
		printf("Flush (all cards of the same suit)\nStraight(all cards in direct order)\nFour of a kind (4 of the same face value)\nThree of a kind (3 of the same face value)\nTwo pairs\nOne pair\n\n");
		printf("Based on what is dealt, you can replace whatever you want by drawing from the deck. We will replace and draw one more time if need be.\nOnce the drawing of cards is done, whoever has the best hand WINS!!!\n");
		printf("\nOk, let me know when you ready for me to deal the cards? ");
		system("pause");
	}
	else if (option == 2)
	{
		printf("My mom says gambling is bad, so we aren't going to in this game. But winner gets bragging rights as the best 5-card-draw player eva!!\n");
		printf("Remember this is what we are looking for: \n");
		printf("Flush (all cards of the same suit)\nStraight(all cards in direct order)\nFour of a kind (4 of the same face value)\nThree of a kind (3 of the same face value)\nTwo pairs\nOne pair\nHighest card\n\n");
		printf("\nOk, let me know when you ready for me to deal the cards? ");
		system("pause");
	
	}
	else if (option == 3)
	{
		printf("Oh ok, it was nice seeing you. Let me know if you want to play later.");
		system("pause");
		system("cls");
	}
	return option;
}


/* shuffle cards in deck */
void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[],Hand *h1,int index,int amount_deal,int card_start_index)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = index;   /* card counter */

	int i = card_start_index;
	index += amount_deal;
	/* deal each of the 52 cards */
	for (; card <= 52; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					if (card <= index)
					{
						h1->h[i].face_index = column;
						h1->h[i].suit_index = row;
						i++;	
					}
					
				}
			}
		}
	}
}
void print_hand(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* h,int amount_of_cards)
//prints current hand
{
	printf("\nHere's your hand: \n");
	for (int i = 0; i < amount_of_cards; i++)
	{
		printf("%5s of %-8s\n", wFace[h->h[i].face_index], wSuit[h->h[i].suit_index]);
		
	}
	putchar('\n');
}

int new_cards(void)
//asks how many cards want to keep and put away
{
	int keep = 0, c = 0, p = 0;
	do
	{
		printf("Do you want to switch any cards? (1 Yes, 2 No): ");
		scanf("%d", &keep);
		if (keep > 2)
		{
			printf("Um, did you want to switch any cards?\n\n");
		}
	} while (keep > 2);
	if (keep == 2)
	{
		p = 0;
	}
	else
	{
		do
		{
			printf("How many cards do you want to switch out? (1-5): ");
			scanf("%d", &c);
			if (c > 5)
			{
				printf("You can only switch out 5 or less. It's not called whatever-card-draw, is it?\n\n");
			}
		} while (c > 5);

		p = c;
	}
	return p;
}

void switch_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* h1, int index, int amount_deal)
//switches out cards for player
{
	int c1 = 0, c2 = 0, c3 = 0, c4 =0;
	if (amount_deal == 5)
	{
		deal(wDeck, wFace, wSuit, h1, index, HAND_SIZE, 0);
	}
	else if (amount_deal < 5)
	{
		printf("Hand me the first card (0-4 top to bottom) you don't want: ");
		scanf("%d", &c1);
		deal(wDeck, wFace, wSuit, h1, index+amount_deal, 0, c1);
		
		if (amount_deal == 2)
		{
				printf("Hand me the next card (0-4 top to bottom) you don't want: ");
				scanf("%d", &c2);
				deal(wDeck, wFace, wSuit, h1, index + amount_deal - 1, 0, c2);
				
		}
		else if (amount_deal == 3)
		{
			printf("Hand me the next card (0-4 top to bottom) you don't want: ");
			scanf("%d", &c2);
			deal(wDeck, wFace, wSuit, h1, index + amount_deal - 1, 0, c2);
			printf("Hand me the next card (0-4 top to bottom) you don't want: ");
			scanf("%d", &c3);
			deal(wDeck, wFace, wSuit, h1, index + amount_deal - 2, 0, c3);

		}
		else if (amount_deal == 4)
		{
			printf("Hand me the next card (0-4 top to bottom) you don't want: ");
			scanf("%d", &c2);
			deal(wDeck, wFace, wSuit, h1, index + amount_deal - 1, 0, c2);
			printf("Hand me the next card (0-4 top to bottom) you don't want: ");
			scanf("%d", &c3);
			deal(wDeck, wFace, wSuit, h1, index + amount_deal - 2, 0, c3);
			printf("Hand me the next card (0-4 top to bottom) you don't want: ");
			scanf("%d", &c4);
			deal(wDeck, wFace, wSuit, h1, index + amount_deal - 3, 0, c4);
		}
	}
}

int check_Flush(Hand h1)
//checks to see if all cards of the same suit
{
	int score = 0;
	if (h1.h[0].suit_index == h1.h[1].suit_index && h1.h[0].suit_index == h1.h[2].suit_index && h1.h[0].suit_index == h1.h[3].suit_index && h1.h[0].suit_index == h1.h[4].suit_index)
	{
		score = 10;
	}
	
	return score;
}
int check_Straight(Hand h1)
//checks to see if all cards in direct order
{
	int score = 0;
	if (h1.h[0].face_index == (1 - h1.h[1].face_index))
	{
		if (h1.h[1].face_index == (1 - h1.h[2].face_index))
		{
			if (h1.h[2].face_index == (1 - h1.h[3].face_index))
			{
				if (h1.h[3].face_index == (1 - h1.h[4].face_index))
				{
					score = 9;
				}
			}
		}
	} 
	
	return score;
}
int check_Four_of_a_kind(Hand h1)
//checks to see if 4 of the same face value
{
	int score = 0;
	if (h1.h[0].face_index == h1.h[1].face_index && h1.h[0].face_index == h1.h[2].face_index && h1.h[0].face_index == h1.h[3].face_index)
	{
		score = 7;
	}
	else if(h1.h[1].face_index == h1.h[2].face_index && h1.h[1].face_index == h1.h[3].face_index && h1.h[1].face_index == h1.h[4].face_index)
	{
		score = 7;
	}
	
	return score;
}
int check_Three_of_a_kind(Hand h1)
//checks to see if 3 of the same face value
{
	int score = 0;
	if (h1.h[0].face_index == h1.h[1].face_index && h1.h[0].face_index == h1.h[2].face_index)
	{
		score = 4;
	}
	else if(h1.h[1].face_index == h1.h[2].face_index && h1.h[1].face_index == h1.h[3].face_index)
	{
		score = 4;
	}
	else if (h1.h[2].face_index == h1.h[3].face_index && h1.h[2].face_index == h1.h[4].face_index)
	{
		score = 4;
	}
	
	return score;
}
int check_pairs(Hand h1)
// checks for one and two pairs in the hand
{
	int score = 0;
	if (h1.h[0].face_index == h1.h[1].face_index)
	{
		if (h1.h[2].face_index == h1.h[3].face_index)
		{
			score = 2;
		}
		else if(h1.h[3].face_index == h1.h[4].face_index)
		{
			score = 2;
		}
	}
	else if (h1.h[1].face_index == h1.h[2].face_index)
	{
		if (h1.h[3].face_index == h1.h[4].face_index)
		{
			score = 2;
		}
	}
	
	
	if (h1.h[0].face_index == h1.h[1].face_index || h1.h[1].face_index == h1.h[2].face_index || h1.h[2].face_index == h1.h[3].face_index|| h1.h[3].face_index == h1.h[4].face_index)
	{
		score = 1;
	}
	
	return score;
}

int hand_check(Hand h)
// checks for all the possible types of hands (i.e Flush, Straight, 4 of a kind, 3 of a kind, two pairs, one pair)
{
	int flush_score = 0, straight_score = 0, four_of_kind_score = 0, three_of_kind_score = 0, pair_score = 0, final_score = 0;
	flush_score = check_Flush(h);
	straight_score = check_Straight(h);
	four_of_kind_score = check_Four_of_a_kind(h);
	three_of_kind_score = check_Three_of_a_kind(h);
	pair_score = check_pairs(h);
	final_score = flush_score + straight_score + four_of_kind_score + three_of_kind_score + pair_score;
}
void card_sort(Hand *h, int size)
//sorts the faces of cards into ascending order
// postcondition: list must be in ascending order
{
	{
		int index = 0, passes = 0;
		Hand temp;

		for (passes = 1; passes < size ; ++passes) 
		{
			for (index = 0; index < (size -passes); ++index) 
			{
				if (h->h[index].face_index > h->h[index + 1].face_index) 
				{
					
					temp.h[index] = h->h[index];
					h->h[index] = h->h[index + 1];
					h->h[index + 1] = temp.h[index];
				}
			}
		}
	}
		return &h;
}

void declare_winner(int player_score, int dealer_score,Hand player, Hand dealer)
// checks to see who is the winner and displays
{
	if (player_score > dealer_score)
	{
		printf("\n\nGood job! YOU WON!!!!!\n\n");
	}
	else if (player_score < dealer_score)
	{
		printf("\n\nThat's rough buddy... Dealer Wins!!!\n\n");
	}
	else if (player_score == dealer_score)
	{
		printf("\n\nWell that's really unusual...\nNow to see who has the highest card.");
		if (player.h[4].face_index > dealer.h[4].face_index)
		{
			printf("\nNice. YOU WON!!!\n\n");
		}
		else if (player.h[4].face_index < dealer.h[4].face_index)
		{
			printf("\nLooks like Dealer Wins!\n\n");
		}
		else if (player.h[4].face_index == dealer.h[4].face_index)
		{
			printf("\nWell that's even more usual, we have same high card! I guess it is truly a tie.\n\n");
		}
	}
	printf("Well that was fun. Let me know if you want to play again some time!\n");
	system("pause");
	system("cls");
}

