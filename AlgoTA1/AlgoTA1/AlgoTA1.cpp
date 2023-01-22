#include <iostream>
#include <vector>
#include <string>
#include <cmath>


//Exercise 1
int exercise1(int N)
{
    //Checks if an even number has been entered
    if (N < 1) { //Makes sure that the recursive function doesnt continue forever
        return 0;
    }
    else if (N % 2 == 0) { //If N is even
        //Gives the next uneven number
        int NUneven = N - 1;
        //returns the sum of the uneven numbers squared
        return pow(NUneven, 2) + exercise1(NUneven - 1);
    }
    else if (N % 2 == 1) { //If N is uneven
        return pow(N, 2) + exercise1(N - 1);
    }
}

//Exercise 3
bool additive(std::string s)
{
    //Makes sure the recursive function doesnt continue forever
    if (s.length() == 2) {
        return false;
    }
    //Converts the first characters in the string to integer numbers
    int x = s[0]-48;
    int y = s[1]-48;
    int z = s[2]-48;
    //Checks if the two first numbers equals the thrid number
    if (x + y == z) {
        return true;
    }
    else { //If the two first numbers doesnt equal the third number then we run the function again without the first number in the string
        return additive(s.substr(1, s.length()));
    }
    return false;
}

//Exercise 4
std::vector<int> exercise4(std::vector<int> array)//Or use array[] if u want
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
};

//Exercise 6
int sumDivisibleBy3(int N)
{
    //Makes sure the recursive function doesnt continue forever
    if (N < 3) {
        return 0;
    }
    //Avoids unnessesary recursive calls
    while (N % 3 != 0) {
        N = N - 1;
    }
    //When N is divisible by 3 then I do the recursive call and add to N
    if (N % 3 == 0) {
        return N + sumDivisibleBy3(N - 1);
    }
}

//Exercise 7
std::vector<int> exercise7(int Z)
{
    //Checks the boundary values of Z given in the assignment and returns error message and dummy value
    if (Z > 100000 || Z < 4) {
        std::cout << "Illegal value entered. Z must be between 4 and 100.000. Z entered: " << Z << std::endl;
        return { 0 , 0 }; //{X, Y}
    }
    //Finds the biggest X value for the number entered and returns X,Y value
    for (int x = 10; x > 1; x--) {
        for (int y = 10; y > 1; y--) {
            if (pow(x, y) == Z) {
                return { x , y };
            }
        }
    }
    //Returns dummy value if there isnt a solution
    std::cout << "No solution was found." << std::endl;
    return { 0 , 0 }; //{X, Y}
};


//Exercise 10
long logTo(int N)
{
    //Makes sure the recursive function doesnt continue forever
    if (N <= 1) {
        return 0;
    }
    //Calculates the logartihm_2 to N
    return 1 + logTo(N / 2);
};

//Exercise 11
int exercise11(std::vector<int> array/*, int size*/) //Or you can use array[]
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
};


int main()
{
    printf("------------------------- Exercise 1 -------------------------\n\n");
    printf("---- Test 1 ----\n\n");
    int some_input1 = 8;//Fill in your input

    printf("Input is: %2d\n\n", some_input1); //Print the input
    int some_result1 = exercise1(some_input1);
    printf("Result is:  %2d\n\n", some_result1); //Print the result

    printf("If you have more tests print the input and output of them as well\n\n");
    printf("---- Test 2 ----\n\n");
    int some_input12 = 7;
    printf("Input is: %2d\n\n", some_input12); //Print the input
    int some_result12 = exercise1(some_input12);
    printf("Result is:  %2d\n\n", some_result12); //Print the result

    printf("------------------------- Exercise 3 -------------------------\n\n");

    printf("---- Test 1 ----\n\n");
    std::string some_input2 = "82842605";
    printf("Input is: %s\n\n", some_input2.c_str()); //Print the input
    bool some_result2 = additive(some_input2);
    printf("Result is:  %2d\n\n", some_result2); //Print the result

    printf("---- Test 2 ----\n\n");
    std::string some_input22 = "8284205";
    printf("Input is: %s\n\n", some_input22.c_str()); //Print the input
    bool some_result22 = additive(some_input22);
    printf("Result is:  %2d\n\n", some_result22); //Print the result

    printf("------------------------- Exercise 4 -------------------------\n\n");
    
    printf("---- Test 1 ----\n\n");
    std::vector<int> some_input4 = { 23, 56, 22, 11, 65, 89, 3, 44, 87, 910, 45, 35, 98 };
    //Prints input
    std::cout << "Input is: ";
    for (int i = 0; i < some_input4.size(); ++i) {
        std::cout << some_input4[i];
    }
    std::cout << std::endl;
    std::vector<int> some_result4 = exercise4(some_input4);
    printf("Result is:  %2d + %2d + %2d is closest to %2d\n\n", some_result4[0], some_result4[1], some_result4[2], some_result4[3]); //Print the result
    
    printf("------------------------- Exercise 6 -------------------------\n\n");

    printf("---- Test 1 ----\n\n");
    int some_input6 = 12;
    printf("Input is: %2d\n\n", some_input6); //Print the input
    int some_result6 = sumDivisibleBy3(some_input6);
    printf("Result is:  %2d\n\n", some_result6); //Print the result


    printf("------------------------- Exercise 7 -------------------------\n\n");

    printf("---- Test 1 ----\n\n");
    int some_input7 = 3125;
    printf("Input is: %2d\n\n", some_input7); //Print the input
    std::vector<int> some_result7 = exercise7(some_input7);
    int some_result7X = some_result7[0];
    int some_result7Y = some_result7[1];
    printf("Result is:  X =%2d, Y =%2d\n\n", some_result7X, some_result7Y); //Print the result

    printf("---- Test 2 ----\n\n");
    int some_input71 = 6561;
    printf("Input is: %2d\n\n", some_input71); //Print the input
    std::vector<int> some_result71 = exercise7(some_input71);
    int some_result71X = some_result71[0];
    int some_result72Y = some_result71[1];
    printf("Result is:  X =%2d, Y =%2d\n\n", some_result71X, some_result72Y); //Print the result

    printf("---- Test 3 ----\n\n");
    int some_input72 = 9823;
    printf("Input is: %2d\n\n", some_input72); //Print the input
    std::vector<int> some_result72 = exercise7(some_input72);
    int some_result72X = some_result72[0];
    int some_result73Y = some_result72[1];
    printf("Result is:  X =%2d, Y =%2d\n\n", some_result72X, some_result73Y); //Print the result


    printf("------------------------- Exercise 10 -------------------------\n\n");
    
    printf("---- Test 1 ----\n\n");
    int some_input10 = 32;
    printf("Input is: %2d\n\n", some_input10); //Print the input
    long some_result10 = logTo(some_input10);
    printf("Result is:  %2d\n\n", some_result10); //Print the result

    printf("---- Test 2 ----\n\n");
    int some_input101 = 4096;
    printf("Input is: %2d\n\n", some_input101); //Print the input
    long some_result101 = logTo(some_input101);
    printf("Result is:  %2d\n\n", some_result101); //Print the result


    printf("------------------------- Exercise 11 -------------------------\n\n");
    
    printf("---- Test 1 ----\n\n");
    std::vector<int> some_input11 = { 7, 4, 3, 5, 3, 1, 6, 4, 5, 1, 7, 5 };
    //Print the input
    std::cout << "Input is:";
    for (int i = 0; i < some_input11.size(); ++i) {
        std::cout << some_input11[i] << ", ";
    }
    std::cout << std::endl;
    int some_result11 = exercise11(some_input11);
    printf("Result is:  %2d\n\n", some_result11); //Print the result
    
    printf("---- Test 2 ----\n\n");
    std::vector<int> some_input112 = { 5, 4, 4, 5, 4, 4, 6, 4, 4, 4, 7, 5 };
    //Print the input
    std::cout << "Input is:";
    for (int i = 0; i < some_input112.size(); ++i) {
        std::cout << some_input112[i] << ", ";
    }
    std::cout << std::endl;
    int some_result112 = exercise11(some_input112);
    printf("Result is:  %2d\n\n", some_result112); //Print the result

    return 0;
}

