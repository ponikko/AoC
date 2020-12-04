#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//Part1: Detect which passports have all required fields.
//Part2: Count the number of valid passports - those that have all required fields

class passport{// Fields -- yes im coding like im 5 but it worked suck it
	string byr;
	string iyr;
	string eyr;
	string hgt;
	string hcl;
	string ecl;
	string pid;
	string cid;

	public:
	void reset(){// Resets the current passports fields
		byr.clear();
		iyr.clear();
		eyr.clear();
		hgt.clear();
		hcl.clear();
		ecl.clear();
		pid.clear();
		cid.clear();
	}

	void setField(string field, string val){// Sets specified field
		if (field == "byr")
			byr = val;
		if (field == "iyr")
			iyr = val;
		if (field == "eyr")
			eyr = val;
		if (field == "hgt")
			hgt = val;
		if (field == "hcl")
			hcl = val;
		if (field == "ecl")
			ecl = val;
		if (field == "pid")
			pid = val;
		if (field == "cid")
			cid = val;
	}

	bool isValid(){// Check if the passport is valid for part 1 (has all fields with cid optional)
		return !(byr.empty() || iyr.empty() || eyr.empty() || hgt.empty() || hcl.empty() || ecl.empty() || pid.empty());
	}
	
	bool isValidPart2(){//Check if the passport is valid for part 1 (has all fields within requirments with cid optional)
		if (!isValid())
			return false;

		//Checking Part2 requirments
		if (byr.empty() || stoi(byr) < 1920 || stoi(byr) > 2002)
			return false;
		if (iyr.empty() || stoi(iyr) < 2010 || stoi(iyr) > 2020)
			return false;
		if (eyr.empty() || stoi(eyr) < 2020 || stoi(eyr) > 2030)
			return false;
		string measurment = hgt.substr(hgt.size()-2);
		int heightVal = stoi(hgt);
		if (measurment == "cm" && (heightVal < 150 || heightVal > 193))
			return false;
		if (measurment == "in" && (heightVal < 59 || heightVal > 76))
			return false;
		if (measurment != "cm" && measurment != "in")
			return false;

		/* check hcl */
		if (hcl[0] != '#' || hcl.size() != 7)
			return false;
		for (int i = 1; i < hcl.size(); i++){
			if (!((hcl[i] >= 48 && hcl[i] <= 57) || (hcl[i] >= 97 && hcl[i] <= 102)))
				return false;
		}

		/* check ecl */
		if (ecl != "amb" && ecl != "blu" && ecl != "brn" && ecl != "gry" && ecl != "grn" && ecl != "hzl" && ecl != "oth")
			return false;

		/* check pid */
		int digits = 0;
		for (int i = 0; i < pid.size(); i++){
			if (pid[i] < 48 ^ pid[i] > 57)
				return false;
			digits++;
		}
		if (digits != 9)
			return false;

		return true;
	}
};

// Reads input file and return a vector of passport structs
vector<passport> readInput(string file){
	vector<passport> passports;
	ifstream inFile;
	inFile.open(file);
	passport currPassport;
	string line;
	while (getline(inFile, line)){
		int index = 0;

		if (line == ""){
			passports.push_back(currPassport);
			currPassport.reset();
		}

		while (index < line.size()){// Loop through the current line
			string fieldName = line.substr(index, 3);
			index += 4;
			string fieldVal = "";
			while (line[index] != ' ' && index < line.size()){
				fieldVal += line[index];
				index++;
			}
			index++;
			currPassport.setField(fieldName, fieldVal);
		}
	}

	passports.push_back(currPassport);

	inFile.close();
	return passports;
}

int countValidPassports(vector<passport> passports){// Track number of valid passports
	int validPassports = 0;

	for (int i = 0; i < passports.size(); i++)
		if (passports[i].isValid())
			validPassports++;
		
	return validPassports;
}

int countValidPassportsPart2(vector<passport> passports){
	int validPassports = 0;
	for (int i = 0; i < passports.size(); i++)
		if (passports[i].isValidPart2())
			validPassports++;
		
	return validPassports;
}

int main(){//Setting d¡the actual data we are using and showing da results
	vector<passport> passports = readInput("data4.txt");

	cout << "Part 1: " << countValidPassports(passports) << endl;
	cout << "Part 2: " << countValidPassportsPart2(passports) << endl;
	return 0;
}