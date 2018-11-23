#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <fstream>
using namespace std;

const size_t maxNumber = 5900000; //estimated from the fact that the string is no longer than 400k characters -> 400k- th prime is approgimatelly 5.7M 
const bool initial_value = true;
std::vector<bool> prime(maxNumber, initial_value);

void generateSieve(int n) //generating sieve in order to be able to encode the number
{
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
}
void generateString(int n) //generates the code from a given number n
{
    ofstream outFile;
    outFile.open("cisla.out", std::ios_base::app); 
    outFile << "(";
    int number = n;
    int count;
    int x = 2;
    while (number > 1)
    {
        if (prime[x] == true)
        {
            count = 0;
            while (number % x == 0)
            {
                count++;
                number = number / x;
            }
            if (count == 0)
            {
                outFile << "."; //axiom
            }
            else if (count == 1)
            {
                outFile << "()"; //axiom
            }
            else if (count == 2)
            {
                outFile << "(())"; //helps to aptimise the process (the same goes for 3-8)
            }
            else if (count == 3)
            {
                outFile << "(.())";
            }
            else if (count == 4)
            {
                outFile << "((()))";
            }
            else if (count == 5)
            {
                outFile << "(..())";
            }
            else if (count == 6)
            {
                outFile << "(()())";
            }
            else if (count == 7)
            {
                outFile << "(...())";
            }
            else if (count == 8)
            {
                outFile << "((.()))";
            }
            else if (count > 8) //encoding recursion if count > 8
            {
                outFile.close();
                generateString(count);
                outFile.open("cisla.out", std::ios_base::app);
            }
        }
        x++;
    }
    outFile.close();
    outFile.open("cisla.out", std::ios_base::app);
    outFile << ")";
    outFile.close();
}
int main()
{
    generateSieve(maxNumber); //inicializing sieve for the entire file
    ifstream inFile;
    inFile.open("cisla.in");
    ofstream outFile;
    int value;
    int counter = 0;
    while (inFile >> value)
    {
        if (value >= 0)
        {
            if (counter > 0)
            {
                outFile.open("cisla.out", std::ios_base::app);
                outFile << endl;
                outFile.close();
            }

            counter++;

            if (value > 0)
            {
                generateString(value);
            }
            
            if (value < 1)
            {
                outFile.open("cisla.out", std::ios_base::app);
                outFile << ".";
                outFile.close();
            }
        }
    }

    outFile.close();
    inFile.close();
}
