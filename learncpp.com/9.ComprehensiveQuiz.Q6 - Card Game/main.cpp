#include <iostream>
#include <array>
#include <algorithm>
#include <random>

namespace rng
{
	auto rd{ std::random_device() };
	auto rng{ std::default_random_engine{ rd() } };
}

enum class CardSuit
{
	suit_clubs,
	suit_diamonds,
	suit_hearts,
	suit_spades,
};

enum class CardRank
{
	rank_2,
	rank_3,
	rank_4,
	rank_5,
	rank_6,
	rank_7,
	rank_8,
	rank_9,
	rank_10,
	rank_jack,
	rank_queen,
	rank_king,
	rank_ace,
};

struct Card
{
	CardSuit suit;
	CardRank rank;
};

using deck_type = std::array<Card, 52>;

void printCard(Card card)
{
	switch (card.rank)
	{
		case CardRank::rank_2:
		{
			std::cout << "2";
			break;
		}
		case CardRank::rank_3:
		{
			std::cout << "3";
			break;
		}
		case CardRank::rank_4:
		{
			std::cout << "4";
			break;
		}
		case CardRank::rank_5:
		{
			std::cout << "5";
			break;
		}
		case CardRank::rank_6:
		{
			std::cout << "6";
			break;
		}
		case CardRank::rank_7:
		{
			std::cout << "7";
			break;
		}
		case CardRank::rank_8:
		{
			std::cout << "8";
			break;
		}
		case CardRank::rank_9:
		{
			std::cout << "9";
			break;
		}
		case CardRank::rank_10:
		{
			std::cout << "T";
			break;
		}
		case CardRank::rank_jack:
		{
			std::cout << "J";
			break;
		}
		case CardRank::rank_queen:
		{
			std::cout << "Q";
			break;
		}
		case CardRank::rank_king:
		{
			std::cout << "K";
			break;
		}
		case CardRank::rank_ace:
		{
			std::cout << "A";
			break;
		}
		default:
		{
			std::cout << "?";
			break;
		}
	}

	switch (card.suit)
	{
		case CardSuit::suit_clubs:
		{
			std::cout << "C";
			break;
		}
		case CardSuit::suit_diamonds:
		{
			std::cout << "D";
			break;
		}
		case CardSuit::suit_hearts:
		{
			std::cout << "H";
			break;
		}
		case CardSuit::suit_spades:
		{
			std::cout << "S";
			break;
		}
		default:
		{
			std::cout << "?";
			break;
		}
	}
}

deck_type createDeck()
{
	std::array<Card, 52> deck{};
	int card{ 0 };

	// Iterate four times, for the four CardSuit's
	for (int s{ 0 }; s < 4; ++s)
	{
		// Iterate thirteen times, for the thirteen CardRank's
		for (int r{ 0 }; r < 13; ++r)
		{
			deck[card] = Card{ static_cast<CardSuit>(s), static_cast<CardRank>(r) };
			++card;
		}
	}

	return deck;
}

void printDeck(const deck_type &deck)
{
	for (Card card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}

	std::cout << '\n';
}

void shuffleDeck(deck_type &deck)
{
	std::shuffle(deck.begin(), deck.end(), rng::rng);
}

int getCardValue(Card card)
{
	switch (card.rank)
	{
		case CardRank::rank_10:
		case CardRank::rank_jack:
		case CardRank::rank_queen:
		case CardRank::rank_king:
		{
			return 10;
			break;
		}
		case CardRank::rank_ace:
		{
			return 11;
			break;
		}
		default:
		{
			return (static_cast<int>(card.rank) + 2); // E.g. 0 becomes 2, 1 becomes 3, etc
			break;
		}
	}
}

int main()
{
	deck_type deck{ createDeck() };
	printDeck(deck);
	shuffleDeck(deck);
	printDeck(deck);

	return 0;
}