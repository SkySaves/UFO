#include <iostream>
#include "ufo_functions.hpp"
std::string codeword = "cockandballs";
std::string answer = "__________";
int misses = 0;
char letter;


int main() {
    greet();
    std::vector<char> incorrect;
    bool guess = false;

    while (answer != codeword and misses < 7) {
        display_misses(misses);
        display_status(incorrect, answer);
        std::cout << "Please enter your guess: ";
        std::cin >> letter;
        for (int k = 0; k < codeword.length();
            k++) {

            if (letter == codeword[k]) {
                answer[k] = letter;
                guess = true;
            }
        }
        if (guess) {
            std::cout << "\nCorrect! You're closer to cracking the codeword.\n";
        }
        else {
            std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(letter);
            misses++;
        }
        guess = false;
    }
    end_game(answer, codeword);
}

