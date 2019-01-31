#ifndef LAB3UTILITY_H
#define LAB3UTILITY_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <math.h>

using namespace std;

void Tokenize(string line, vector<string> & tokens, string delimiters = "\t ");

vector<string> inputParser(string inputFileName);

pair<string, int> mapper(string token);

pair<string, int> reducer(vector<pair<string, int> > keyValuePair);

#endif