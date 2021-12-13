#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int partOne(){
    // -- file IO
    ifstream file;
    string line;
    string delimiter = " ";
    
    file.open("input.txt");
    int horizontal = 0, depth = 0;
    
    while(getline(file, line)){
        string command = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        int number = stoi(line);

        if(command == "forward"){ horizontal += number;}
        else if(command == "down"){ depth += number;}
        else{ depth -= number;}
    }
    return horizontal * depth;
}

int partTwo(){
    // -- file IO
    ifstream file;
    string line;
    string delimiter = " ";
    
    file.open("input.txt");
    int horizontal = 0, depth = 0, aim = 0;
    
    while(getline(file, line)){
        string command = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        int number = stoi(line);

        if(command == "forward"){ 
            horizontal += number;
            depth += number * aim;
        }
        else if(command == "down"){ aim += number; }
        else{ aim -= number;}
    }
    return horizontal * depth;
}

int main(){
    cout << "PART ONE ANSWER: "<< partOne() << "\n";
    cout << "PART TWO ANSWER: "<< partTwo() << "\n";
    return 0;
}
