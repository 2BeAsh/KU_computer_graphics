/*
Goal: Generate the sentence "methinks it is like a weasel"
From: https://runestone.academy/ns/books/published/cpp4python/Functions/DefiningFunctions.html
*/
#include <iostream>
#include <random>
#include <string>
#include <list>
#include <array>


double score(int sentence_length, std::array<char, 23> real_sentence, std::array<char, 23> guessed_sentence){
    int i = 0;
    double score = 0;
    for (i=0; i<sentence_length; i++){
        char real_letter = real_sentence[i];
        char guessed_letter = guessed_sentence[i];
        if (real_letter == guessed_letter){
            score += 1;
        }
    }
    return score / sentence_length * 100;
}

std::array<char, 23> real_sentence(){
    // Create list where each element is a non-whitespace letter in the Shakespearean sentence
    std::array<char, 23> sentence_list;
    std::string sentence = "methinks it is like a weasel";
    const int sentence_length = 23;  // Counted manually
    int i = 0;
    for(i=0; i < sentence_length; i++){
        char sentence_letter = sentence[i];
        if (sentence_letter != ' '){
            sentence_list[i] = sentence_letter;
        }
    }
    return sentence_list;
    }

std::array<char, 23> generate_sentence(){
    const int sentence_length = 23;
    std::array<char, sentence_length> generated_sentence;
    // Alphabet
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    const int length_of_alphabet = 26;  // Should take length of the alphabet string

    // Get uniform random integer distribution
    std::random_device rd;  // random number from hardware to seed generator
    std::mt19937 gen(rd()); // Seed generator (Mersenne Twister)
    std::uniform_int_distribution<> distr(0, length_of_alphabet);

    // Create list of random sentence
    int j = 0;
    for (j = 0; j < sentence_length; j++){
        int random_number = distr(gen);
        char random_letter = alphabet[random_number];
        generated_sentence[j] = random_letter;
    }
    return generated_sentence;
}


int main(){
    // Real Sentence
    const int sentence_length = 23;
    std::array<char, sentence_length> sentence_list;
    sentence_list = real_sentence();

    int count = 0;
    int count_max = 10000;
    for (count=0; count<count_max; count++){
        // Random sentence
        std::array<char, sentence_length> guessed_sentence;
        guessed_sentence = generate_sentence();

        double score_val;
        score_val = score(sentence_length, sentence_list, guessed_sentence);
        if (count % 1000 == 0){
            std::cout << "Score = " + std::to_string(score_val) + " %" << std::endl;
        }
    }




    

    return 0;
}