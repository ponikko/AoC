#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//1st: count all the trees you encounter for the slope right 3 down 1
//2nd: multiply together the number of trees encountered on each of the listed slopes (3-1, 5-1, 7-1, 1-2)

int calcTrees(int x_o, int y_o, std::vector<std::string> map){//Gen eq
    int x = 0;
    int trees = 0;
    int width = map.at(0).length();
    for (int y = 0; y < map.size(); y+=y_o){
        if(map.at(y).at(x) == '#')
            trees++;
        x = (x+x_o)%width;
    }
    return trees;
}

int main(){
    std::ifstream inFile; // reading the map
    inFile.open("data3.txt");
    std::vector<std::string> map;
    if (inFile){
        std::string x;
        while(inFile >> x){
            map.push_back(x);
        }        
    }
    long long second = calcTrees(1,1,map);
    int first = calcTrees(3,1,map); //Applying them maths for 1st result, then appying it to all other slopes and multiplying it for magics numbers
    second *= first;
    second *= calcTrees(5,1,map);
    second *= calcTrees(7,1,map);
    second *= calcTrees(1,2,map); 
    std::cout << "For exercise 1: " << first << "\nAnd for exercise 2: " << second  << std::endl;
}