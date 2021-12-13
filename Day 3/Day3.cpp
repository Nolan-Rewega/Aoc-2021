#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;


int partOne(){
    // -- file IO
    ifstream file;
    string line;
    file.open("demo.txt");

    // -- get size of file and length per line
    int lineLength = 0;
    int fileLength = 0;
    while(getline(file, line)){
        lineLength = line.length();
        fileLength++;
    }
    file.clear();
    file.seekg(0);

    int bitArray[fileLength][lineLength];
 
    // -- parse the data in a array
    for(int l = 0; l < fileLength; l++){
        // -- parse line into a bit array
        int bits[lineLength];
        getline(file, line);
        for(int c = 0; c < lineLength; c++){\
            bitArray[l][c] = (int)line[c] - 48;
        }
    }

    int mostCommonBit[lineLength];
    // -- BF loop through every row coll
    for(int i = 0; i < lineLength; i++){
        int zeros = 0;
        int ones = 0;
        for(int j = 0; j < fileLength; j++){
            if(bitArray[j][i] == 0){zeros++;}
            else{ones++;}
        }
        mostCommonBit[lineLength -1 - i] = ones > zeros;
    }

    
    // -- get the gamma and epsilon data
    int gamma = 0;
    int epsilon = 0;
    for(int c = 0; c < lineLength; c++){
        if(mostCommonBit[c] == 1){gamma += pow(2, c);}
        else{epsilon += pow(2, c);}
    }
    
    return gamma * epsilon;
}

int main(){
    int result = partOne();
    cout << "PART ONE ANSWER: " << result << "\n" ;
    return 0;
}
