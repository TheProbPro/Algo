#include "Algorithmer.h"
#include <iostream>

Algorithmer::Algorithmer()
{
}

std::vector<int> Algorithmer::sumPower2(std::vector<int> array)
{
    //Creates varibles to hold eventual solutions
    double closest = INT_MAX;
    std::vector<int> result;
    //Checks all possible combinations
    for (int i = 0; i < array.size(); ++i) {
        for (int j = i + 1; j < array.size(); ++j) {
            for (int k = j + 1; k < array.size(); ++k) {
                int temp = abs(int(pow(2, round(log2(array[i] + array[j] + array[k])))) - (array[i] + array[j] + array[k]));
                //If solution is closer to zero the varibles gets updated
                if (temp < closest) {
                    closest = temp;
                    result = { array[i], array[j], array[k], int(pow(2, int(round(log2(array[i] + array[j] + array[k]))))) };
                }
            }
        }
    }
    //Returns the closest solution
    return result;
}

std::vector<int> Algorithmer::xPowY(int Z)
{
    //Checks the boundary values of Z given in the assignment and returns error message and dummy value
    if (Z > 100000 || Z < 4) {
        std::cout << "Illegal value entered. Z must be between 4 and 100.000. Z entered: " << Z << std::endl;
        return { 0 , 0 }; //{X, Y}
    }
    //Finds the biggest X value for the number entered and returns X,Y value
    for (int x = 11; x > 1; x--) {
        for (int y = 10; y > 1; y--) {
            if (pow(x, y) == Z) {
                return { x , y };
            }
        }
    }
    //Returns dummy value if there isnt a solution
    std::cout << "No solution was found." << std::endl;
    return { 0 , 0 }; //{X, Y}
}

int Algorithmer::majorityVote(std::vector<int> array)
{
    //Initializes conatiners for solution
    int maxVotes = 0;
    int index = 0;
    //Counts the amount of votes for each candidate
    for (int i = 0; i < array.size(); ++i) {
        int votes = 0;
        for (int j = 0; j < array.size(); ++j) {
            if (array[i] == array[j]) {
                votes++;
            }
        }//Checks if the candidate got more votes than the previous most voted candidate
        if (votes > maxVotes) {
            maxVotes = votes;
            index = i;
        }
    }//If the candidate gets more than half the votes the candidate gets returned
    if (maxVotes > (array.size() / 2)) {
        return array[index];
    }//If no candidate got more than half the votes -1 is returned
    else {
        return -1;
    }
}

std::string Algorithmer::maxOccuringWord(std::string text)
{
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
        else if (words[temp] != words[i] || i + 1 == words.size()) {
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

int Algorithmer::findPattern(std::string text, std::string word)
{
    std::string temp = "";
    std::vector<std::string> words;
    for (int i = 0; i < text.length(); ++i) {
        if (text.at(i) == ' ') {
            words.push_back(temp);
            temp = "";
        }
        else {
            temp += text.at(i);
        }
    }
    words.push_back(temp);
    for (int i = 0; i < words.size(); ++i) {
        temp = words.at(i);
        if (temp.length() == word.length()) {
            if (temp.at(0) == word.at(0)) {
                if (word == temp) {
                    return 1;
                }
            }
            for (int j = 0; j < word.length(); ++j) {
                for (int k = 0; k < word.length(); ++k) {
                    if (temp.at(k) != word.at(j)) {
                        break;
                    }
                    else {
                        return 2;
                    }
                }
            }
        }
        for (int j = 0; j < word.length(); ++j) {
            for (int k = 0; k < words.at(i).length(); ++k) {
                if (words.at(i).at(k) != word.at(j)) {
                    break;
                }
                else {
                    return 3;
                }
            }
        }
    }

    return 0;
}

int Algorithmer::longestChain(int val)
{
    int num = 0;
    int l = 0;
    for (int i = 1; i < val; ++i) {
        if (findLengthOfChain(i) > l) {
            l = findLengthOfChain(i);
            num = i;
        }
    }
    return num;
}

int Algorithmer::pythagoranTriplets(int eq)
{
    // triplet: a^2 + b^2 = c^2
    int a, b, c = 0;

    // loop from 2 to max_limit
    int m = 2;

    // Limiting c would limit
    // all a, b and c
    while (c < eq) {

        // now loop on j from 1 to i-1
        for (int n = 1; n < m; ++n) {

            // Evaluate and print triplets using
            // the relation between a, b and c
            a = m * m - n * n;
            b = 2 * m * n;
            c = m * m + n * n;
            // stop when we find the right numbers and print and return
            if (a + b + c == eq) {
                printf("%d %d %d %d\n", a, b, c, (a + b + c));
                return a * b * c;
            }
        }
        m++;
    }
    return a * b * c;
}

int Algorithmer::pythagoranTriplets()
{
    for (int a = 0; a < 1000; a++) {
        for (int b = 0; b < 1000; b++) {
            for (int c = 0; c < 1000; c++) {

                // Look only at Pythagorian tribles
                if (a < b && b < c) {
                    if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                        if (a + b + c == 1000) {
                            std::cout << a << " " << b << " " << c << std::endl;
                            return a*b*c;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// Alternativ løsning:
int Algorithmer::numberOfPossiblePasswords() {
    int poss = 0;
    for (int a = 0; a < 9; ++a) {
        for (int b = 1; b < 9; ++b) {
            for (int c = 2; c < 9; ++c) {
                for (int d = 3; d < 9; ++d) {
                    for (int e = 4; e < 9; ++e) {
                        for (int f = 5; f < 9; ++f) {
                            if ((a < b) && (b < c) && (c < d) && (d < e) && (e < f)) {
                                poss++;
                            }
                        }
                    }
                }
            }
        }
    }
    return poss;
}

bool Algorithmer::anagram(std::string word1, std::string word2)
{
    if (word1.length() == word2.length()) {
        bool letterFound = false;
        for (int i = 0; i < word1.length(); ++i) {
            for (int j = 0; j < word1.length(); ++j) {
                if (word1.at(i) == word2.at(j)) {
                    letterFound = true;
                }
            }
            if (letterFound == false) {
                return false;
            }
            letterFound = false;
        }
    }
    else {
        std::cout << "Word length doesnt match!" << std::endl;
        return false;
    }
    return true;
}
