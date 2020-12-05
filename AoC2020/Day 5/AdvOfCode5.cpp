#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <fstream>
#include <iostream>

std::vector<std::string> read_input_file() {//Reading the data
  std::ifstream file("data5.txt");
  std::vector<std::string> data;
  std::string line;

  while(std::getline(file, line)) data.push_back(line);//Line by line just like Maradona

  return data;
}

// What is the highest seat ID on a boarding pass?
int parse_id(std::string ticket) {
  std::replace(ticket.begin(), ticket.end(), 'F', '0');
  std::replace(ticket.begin(), ticket.end(), 'L', '0');
  std::replace(ticket.begin(), ticket.end(), 'B', '1');
  std::replace(ticket.begin(), ticket.end(), 'R', '1');

  return stoi(ticket, nullptr, 2);
}

int part1(const std::set<int> &ids) { //Part 1
    return *ids.rbegin();
    }

//Where is your seat? The seats with IDs +1 and -1 from yours will be in your list.
int part2(const std::set<int> &ids) { //Part 2
  for(auto it = ++ids.begin(); it != ids.end(); it++){
    auto prev = it; --prev;
    if(*prev + 2 == *it) return *it - 1;
  }
  return 0;
}

int main() { //Main for that crisp result showing skillz
  std::set<int> ids;
  for(auto &ticket: read_input_file()) ids.insert(parse_id(ticket)); //yo no se si estoy escribiendo bien esta movida pero yolo
  std::cout << part1(ids) << " " << part2(ids) << std::endl;
}