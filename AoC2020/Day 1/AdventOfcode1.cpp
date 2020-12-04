#include <fstream>
#include <vector>
    
using namespace std;

int main() {
    std::ifstream file("Adv1data.txt"); //Input file stream
    std::vector<int> v;
    int a;
    while(file >> a)
    {
        v.push_back(a);

    }
    file.close();

    for(int a : v)
        for( int b : v)
                for( int c : v)
                    if ( a+b+c == 2020 )
                        cout << a*b*c << endl;

}