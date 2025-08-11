#include <iostream>
#include <vector>
#include <string>


    class Game {
private:
    std::vector<std::string> Players;
    std::string bingoword;
public:
    Game(const std::vector<std::string>& players1, const std::string b) : Players(players1), bingoword(b) {}


    void displayfailure(int count) {
        switch (count) {
            case 1:
                std::cout << " \\" << std::endl;
                break;
            case 2:
                std::cout << "/";
                std::cout << " \\" << std::endl;
                break;
            case 3:
                std::cout << " |\n"
                             " |\n"
                             " |\n"
                             " |\n";

                std::cout << "/";
                std::cout << " \\" << std::endl;
                break;
            case 4:

                std::cout << "  _ _ _ _ _" << std::endl;
                std::cout << " |\n"
                             " |\n"
                             " |\n"
                             " |\n";

                std::cout << "/";
                std::cout << " \\" << std::endl;
                break;
        }
    }




    void gameplay() {
            std::string word(bingoword.size(),'_');
            std::cout << word;
            int count = 0;
        do {
            char letter;
            size_t j;

            for (size_t i = 0; i < Players.size(); i++) {
                bool isThere = false;
                std::cout << "\nWähle einen Buchstabe aus, " << Players[i] << ": ";
                std::cin >> letter;

                for ( j = 0; j < bingoword.size(); j++) {
                    if (letter == bingoword[j]) {
                        word[j] = letter;
                        isThere = true;
                    }
                }

                if (!isThere) {
                    count++;
                    displayfailure(count);
                }

                std::cout << "Wort Status: " << std::endl;

                std::cout << word;
                if (bingoword == word) {
                    break;
                }
            }
        } while (bingoword != word);

        std::cout << "\n\ngewonnen!" << std::endl;

    }



};


int main() {
    int count;
    std::string  name;
    std::vector<std::string> Players;
    std::string bingoword;
    std::cout << "Wie viele Spieler?: ";
    std::cin >> count;
    std::cout << "\n";

    for (int i = 0; i < count; i++) {
        std::cout << "Wie heißt dein Spieler: ";
        std::cin >> name;
        Players.emplace_back(name);
    }

    std::cout << "Welches Wort für Hangman: ";
    std::cin >> bingoword;

    Game game(Players,bingoword);

    game.gameplay();


    return 0;
}