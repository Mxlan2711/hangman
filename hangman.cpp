#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Game {
private:
    std::vector<std::string> Players;
    std::string bingoword;
    const std::vector<std::string> hangmanStages= {

            R"(



     ===)",



            R"(      |

      |

      |

      |

      |

     ===)",



            R"(  +   |

      |

      |

      |

      |

     ===)",



            R"(  +---+

      |

      |

      |

      |

     ===)",



            R"(  +---+

  |   |

      |

      |

      |

     ===)",



            R"(  +---+

  |   |

  O   |

      |

      |

     ===)",



            R"(  +---+

  |   |

  O   |

  |   |

      |

     ===)",



            R"(  +---+

  |   |

  O   |

 /|   |

      |

     ===)",



            R"(  +---+

  |   |

  O   |

 /|\  |

      |

     ===)",



            R"(  +---+

  |   |

  O   |

 /|\  |

 /    |

     ===)",



            R"(  +---+

  |   |

  0   |

 /|\  |

 / \  |

     ===)"

    };

public:
    Game(const std::vector<std::string>& players1, const std::string& b) : Players(players1), bingoword(b) {}


    void displayfailure(int fail_count) {
      if (fail_count < 1) return;
      for (int i = 0; i < hangmanStages.size(); i++) {
          if (i+1 == fail_count) {
              std::cout << hangmanStages[fail_count - 1];
              break;
          }
      }
    }

  void welcomeScreen(){
      std::cout << "\n _ _ _ _ _ _ " << std::endl;
      std::cout << "|           |" << std::endl;
      std::cout << "|  Hangman  |";
      std::cout << "\n|_ _ _ _ _ _|" << std::endl;
    std::cout << std::endl;

  }

  void isRight_screen(){
      std::cout << "\n _ _ _ _ _ _ " << std::endl;
      std::cout << "|           |" << std::endl;
      std::cout << "|  Richtig! |";
      std::cout << "\n|_ _ _ _ _ _|" << std::endl;
    std::cout << std::endl;

  }  



    void gameplay() {
        std::string word(bingoword.size(),'-');
      
        welcomeScreen();

        std::cout << word << std::endl;
        int total_failure = hangmanStages.size();
        int fail_count = 0;
        do {
            char letter;


            for (size_t i = 0; i < Players.size(); i++) {
                bool isThere = false;
                std::cout << "\nWähle einen Buchstabe aus, " << Players[i] << ": ";
                std::cin >> letter;

                for (size_t j = 0; j < bingoword.size(); j++) {
                    if (letter == bingoword[j]) {
                        word[j] = letter;
                        isThere = true;
                    }
                }

                if (!isThere) {
                    fail_count++;
                    displayfailure(fail_count);
                }
                else {
                    isRight_screen();                    
                  }

                std::cout << "\nWord Status: " << std::endl;
                std::cout << word;
                
                if (bingoword == word) break;

            }

        } while (bingoword != word && fail_count != total_failure);

        if (fail_count == total_failure) {
            std::cout << "\n\nVERLOREN" << std::endl;
        }
        else {
            std::cout << "\n\nGEWONNEN!" << std::endl;
        }
    }

};


int main(int argc, char*argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [file]" << std::endl;
        return 1;
    }

    int player_count;
    std::string  name;
    std::vector<std::string> Players;
    std::string bingoword;

    std::cout << "Wie viele Spieler?: ";
    std::cin >> player_count;
    std::cout << "\n";

    for (int i = 0; i < player_count; i++) {
        std::cout << "Wie heißt dein Spieler: ";
        std::cin >> name;
        Players.emplace_back(name);
    }


    std::ifstream file(argv[1]);
    file >> bingoword;

    Game game(Players,bingoword);

    game.gameplay();


    return 0;
}
