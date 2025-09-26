#include <iostream>
#include "ufo_functions.hpp"

int main() {
    std::string codeword = "codeacademy";
    std::string answer = "___________"; // 11 underscores for each letter
    int misses = 0;
    std::vector<char> incorrect;  // To track wrong guesses
    bool guess = false;           // To track if guess was correct
    char letter;  // to store player's guessed letter

    while (answer != codeword && misses < 7) {
        std::cout << "loop running\n";
        display_misses(misses);
        std::cout << "\nCodeword:\n";
        std::cout << "Please enter your guess: ";
        std::cin >> letter;

        for (int i = 0; i < answer.length(); i++) {
            std::cout << answer[i] << ' ';
            if (letter == codeword[i]) {   // Did the guess match this letter?
                answer[i] = letter;   // Reveal it in the answer str
                guess = true;   
            }
        }

        if (guess) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Incorrect! The tractor beam pulls the person in further.\n";
            incorrect.push_back(letter);
            misses++;  // Increment misses only on wrong guess
        }
    }

    // After loop ends, check result
    end_game(answer, codeword);
    // Removed invalid call: display_misses(int misses);

    return 0;
}
