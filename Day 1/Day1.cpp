#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



int partOne(){
    // -- file IO
    ifstream file;
    string line;
    file.open("inputs.txt");
    
    int numIncreased = -1, old = 0;

    while( getline(file, line) ){
        int converted = stoi(line);
        if(converted > old){ numIncreased++; }
        old = converted;
    }
    file.close();
    return numIncreased;
}

int partTwo(){
    // -- file IO
    ifstream file;
    string line;
    file.open("inputs.txt");

    int tracker = 0, old = 0, numIncreased = 0;

    // -- start from the first 3
    vector<int> counts = {376,252,127};
    getline(file, line);
    getline(file, line);
    getline(file, line);

    while( getline(file, line) ){
       // -- check the tracker to reset counts
        int mod = tracker % 3;
        if(counts[mod] > old){ numIncreased++; }
        old = counts[mod];
        counts[mod] = 0;

        int converted = stoi(line);
        counts[0] += converted;
        counts[1] += converted;
        counts[2] += converted;

        tracker++;
    }
    file.close();
    return numIncreased;
}

int main(){
    cout << partOne() << "\n";
    cout << partTwo() << "\n";
    return 0;
}

