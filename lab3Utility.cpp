#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include "lab3Utility.h"

using namespace std;

void Tokenize(string line, vector<string> &tokens, string delimiters){
	string token = "";
        string oneCharString = " ";
        for(int i=0; i<line.size(); i++)
                if(find(delimiters.begin(), delimiters.end(), line[i])!=delimiters.end()){
                        if (token != ""){
                                tokens.push_back(token);
			}
                        token = "";
                }
                else{
                        oneCharString[0] = line[i];
                        token += oneCharString;
                }
        if (token != ""){
                tokens.push_back(token);
	}
}

vector<string> inputParser(string inputFileName){
        ifstream inf(inputFileName);
        vector<string> returnVec;
        string line;
        while(getline(inf,line).good()){
                vector<string> tokens;
                Tokenize(line, tokens, " \t");

                for (int i=0; i<tokens.size(); i++){
                        returnVec.push_back(tokens[i]);
                }
        }
        return returnVec;
}

bool compare(pair<string, int> i, pair<string, int> j){
        return i.first < j.first;
}

pair<string, int> mapper(string token){
        pair<string, int> returnPair;
        returnPair.first = token;
        returnPair.second = 1;
        return returnPair;
}

pair<string, int> reducer(vector<pair<string, int> > keyValuePair){
        pair<string, int> returnPair;
        returnPair.first = keyValuePair[0].first;
        returnPair.second = keyValuePair.size();
        return returnPair;
}

// vector<pair<string, int> > mapper(vector<string> tokens){
//         vector<pair<string, int> > returnVec;
//         cout << "1\n";
//         for (int i=0; i<tokens.size(); i++){
//                 pair<string, int> toPush;
//                 toPush.first = tokens[i];
//                 toPush.second = 1;
//                 returnVec.push_back(toPush);
//         }
//         cout << "2\n";
//         sort(returnVec.begin(), returnVec.end(), compare);
//         return returnVec;
// }

