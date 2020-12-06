#include <iostream>
#include <fstream>

using namespace std;
//Part 1: For each group, count the number of questions to which anyone answered "yes". What is the sum of those counts?

int main() {
    
    std::ifstream input("data6.txt");

    int questionnaire[26] = (); //Zero-initialize
    int part1(0);
    int part2(0);
    int n(0); //Number of passengers in a group

    std::string line;
    while (input) {
        std::getline(input, line);
        n++;

        if (line.empty()) {//Empty line denotes a new group
            n--;
            for (int i=0; i<26; i++) {
                if (questionnaire[i] == n) {
                    part2++;
                }
                questionnaire[i] = 0; //Reset
            }
            n = 0;
        }

        for (int c : line) { //Converts every char to an int
            if (!questionnaire[c-97]) { //'a' = 97, subtract 97 to map a-z --> 0-26
                part1++;
            }
            questionnaire[c-97]++;
        }
	}
    std::cout << "Answer 1: " << part1 << "\n";
    std::cout << "Answer 2: " << part2 << "\n";

    return 0;
}