#include <iostream>

enum Suit {Spade, Ace, Club, Heart};

class Card {

    private:
        Suit suit_;
        int value_;
    public:
        virtual Suit suit() const {
            return suit_; 
        }

        virtual int value() const {
            return value_;
        }

        Card(Suit suit, int value) : suit_(suit), value_(value) {};
};

class BlackJackCard: public Card {

    public:
        virtual int value() {

            return Card::value();
        }

        BlackJackCard(Suit suit, int value) : Card (suit, value) {};

        //TODO blackjack game logic
};

int main() {

    Card ace_heart(Suit::Spade, 1);

    std::cout << ace_heart.suit() << " " << ace_heart.value() << '\n';
}





