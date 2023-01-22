#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//Function that converts all uppercase caracters to lower case.
char lowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

std::string maxOccuringWord(std::string text) {
    //Creates a vector containing all the words and a temporary variable to contain the chars that make up a word.
    std::vector<std::string> words;
    std::string word = "";
    //Makes sure that the entire string is lowercase characters and split the text into words.
    for (int i = 0; i < text.length(); ++i) {
        text[i] = lowercase(text[i]);
        if (word == "" && text.at(i) == ' ' || text.at(i) == ',' || text.at(i) == '.') {
            ;
        }
        else if (text.at(i) == ' ' || text.at(i) == ',' || text.at(i) == '.') {
            words.push_back(word);
            word = "";
        }
        else {
            word += text.at(i);
        }
    }
    words.push_back(word);

    //Sorting the vector
    std::sort(words.begin(), words.end());
    for (int i = 0; i < words.size(); ++i) {
        std::cout << words[i] << std::endl;
    }
    //Finding the word that repeats the most in the vector words
    int index = 0;
    int temp = 0;
    int maxOcc = 0;
    int occurences = 0;
    for (int i = 0; i < words.size(); ++i) {
        //Checks how many occurenses of a word there is
        if (words[temp] == words[i]) {
            occurences++;
            //checks if current word is max occuring by the last element in the vector
            if (i + 1 == words.size()) {
                if (occurences > maxOcc) {
                    maxOcc = occurences;
                    index = temp;
                }
                occurences = 0;
                temp = i;
            }
            
        }//Checks if the word we are looking at is different from the one we are counting, and checks if the one we are couning is the most occuring.
        else if (words[temp] != words[i] || i+1 == words.size()) {
            if (occurences > maxOcc) {
                maxOcc = occurences;
                index = temp;
            }
            occurences = 1;
            temp = i;
        }
    }
    //Prints result and returns most occuring word
    std::cout << "The word that occured the most in this sentence is: " << words[index] << ", it occured " << maxOcc << " times." << std::endl;
    return words[index];
}

int main()
{
    std::string s = "The cattle were running back and forth, but there was no wolf to be seen, heard, or smelled, so the shepherd decided to take a little nap in a bed of grass and early summer flowers. Soon he was awakened by a sound he had never heard before.";
    std::string s1 = "kan jeg lide lide dig dig dig";
    std::string s2 = "kan jeg lide lide dig dig dig lide lide";
    std::string maxocc = maxOccuringWord(s);
    //std::cout << "The word that occured the most in this sentence is: " << maxocc << std::endl;
    return 0;
}

