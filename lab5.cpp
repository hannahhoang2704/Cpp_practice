//
// Created by Hanh Hoang on 30.1.2024.
//
//Function object
//Constructor must take two parameters (min and max) that determine the range of numbers
//that the generator produces.
//You may not write any for-loops in this exercise. Use only STL-algorithms!
//Write a program that generates numbers for three different games:
//1. Lotto: 7 numbers 1 – 40
//2. Viking lotto: 6 numbers 1 – 48
//3. Eurojackpot: 5 numbers 1 – 50
//Use either generate or generate_n algorithm to generate the three sets of numbers.
//Print each set of numbers using a suitable algorithm and output stream iterator.
//Then find numbers that appear in all three sets and print them. Use set_intersection
//algorithm to find the numbers that appear in all three sets:
//• Find matching numbers from two sets and print them using for_each algorithm
//• Find matching number from the third set and print them using for_each
//algorithm. Note that it is very unlikely to get matches in all three sets so you need
//to run multiple tests to see a match
//To print the numbers with index numbering you must use a function object to remember
//the index between calls.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RandGen {
public:
    RandGen(int min, int max);
    RandGen(): numbers() {srand(time(NULL));}
    int operator()();
private:
    vector<int> numbers;
    int range_min;
    int range_max;
};

class Print_matching_vector{
public:
    Print_matching_vector();
    void operator()(int nr);
private:
    int index=0;
};

int main(void) {
    vector<int> lotto(7);
    vector<int> viking_lotto(6);
    vector<int> eurojackpot(5);
    std::string answer = "yes";

    while(answer == "yes"){
        RandGen rand_lotto(1, 40);
        RandGen rand_viking_lotto(1, 48);
        RandGen rand_eurojackpot(1,50);

        generate(lotto.begin(), lotto.end(), rand_lotto);
        generate(viking_lotto.begin(), viking_lotto.end(), rand_viking_lotto);
        generate(eurojackpot.begin(), eurojackpot.end(), rand_eurojackpot);

        cout << "Lotto: ";
        copy( lotto.begin(), lotto.end(), ostream_iterator<int> (cout," "));
        cout << "\nViking lotto: ";
        copy( viking_lotto.begin(), viking_lotto.end(), ostream_iterator<int> (cout," "));

        sort(lotto.begin(), lotto.end());
        sort(viking_lotto.begin(), viking_lotto.end());

        vector<int>match_nr, final_match;
        set_intersection(lotto.begin(), lotto.end(), viking_lotto.begin(), viking_lotto.end(), back_inserter(match_nr));
        cout << "\nMatching numbers:\n";
        for_each(match_nr.begin(), match_nr.end(), Print_matching_vector());

        cout << "Eurojackpot: ";
        copy( eurojackpot.begin(), eurojackpot.end(), ostream_iterator<int> (cout," "));

        sort(eurojackpot.begin(), eurojackpot.end());
        set_intersection(match_nr.begin(), match_nr.end(), eurojackpot.begin(), eurojackpot.end(), back_inserter(final_match));
        cout << "\nMatching numbers in three sets:\n";
        for_each(final_match.begin(), final_match.end(), Print_matching_vector());

        cout << "\nDo you want to continue (yes/no): ";
        getline(cin, answer);
    }

    return 0;
}

RandGen::RandGen(int min, int max):range_min(min), range_max(max){}

int RandGen::operator()() {
    int number;
    int range = range_max - range_min + 1;
    do {
        number = rand() % range + range_min;
    } while(find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

Print_matching_vector::Print_matching_vector():index(0) {}

void Print_matching_vector::operator()(int nr) {
    cout << "#" << ++index << ": " << nr << endl;
}