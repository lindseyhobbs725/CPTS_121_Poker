#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HAND_INDEX 6
#define HAND_SIZE 5

typedef struct card
{
	int face_index;
	int suit_index;
}Card;

typedef struct hand
{
	Card h[HAND_INDEX];
}Hand;

int welcome_menu(void);
// menu to allow user to view game rules, play game or exit game
void shuffle(int wDeck[][13]);
//shuffles deck
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* h1, int index, int amount_deal, int card_start_index);
//deals amount of cards requested
void print_hand(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* h, int amount_of_cards);
//prints current hand
int new_cards(void);
//asks how many cards want to keep and put away
void switch_cards(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand* h1, int index, int amount_deal);
//switches out cards for player

int check_Flush(Hand h1);
//checks to see if all cards of the same suit
int check_Straight(Hand h1);
//checks to see if all cards in direct order
int check_Four_of_a_kind(Hand h1);
//checks to see if 4 of the same face value
int check_Three_of_a_kind(Hand h1);
//checks to see if 3 of the same face value
int check_pairs(Hand h1);
// checks for one and two pairs in the hand
int hand_check(Hand h);
// checks for all the possible types of hands (i.e Flush, Straight, 4 of a kind, 3 of a kind, two pairs, one pair)

void card_sort(Hand *h, int size);
//sorts the faces of cards into ascending order
// postcondition: list must be in ascending order

void declare_winner(int player_score, int dealer_score, Hand player, Hand dealer);
// checks to see who is the winner and displays

