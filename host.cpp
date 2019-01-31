#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <thread>
#include <omp.h>
#include "lab3Utility.h"

using namespace std;

vector<string> segments;
vector<pair<string, int> > segmentsMapped;
map<string, vector<pair<string, int> > > groups;
vector<vector<pair<string, int> > > accessGroups;
vector<pair<string, int> > groupsReduced;

bool compare2(pair<string, int> i, pair<string, int> j){
	return i.second > j.second;
}

int main(){
	string fileName = "theHeadband.txt";
	

	segments = inputParser(fileName);
	for(int i=0; i<segments.size(); i++){
		cout << segments[i] << endl;
	}

	segmentsMapped.resize(segments.size());

#pragma omp parallel for
	for(int i=0; i<segments.size(); i++){
		segmentsMapped[i] = mapper(segments[i]);
	}

	cout << endl << "AFTER MAPPING:" << endl;
	for(int i=0; i<segmentsMapped.size(); i++){
		cout << segmentsMapped[i].first << " : " << segmentsMapped[i].second << endl;

		vector<pair<string, int> > interm;
		interm = groups[segmentsMapped[i].first];
		interm.push_back(segmentsMapped[i]);
		groups[segmentsMapped[i].first] = interm;
	}

	cout << "groups size: " << groups.size() << endl;

	cout << endl << "AFTER SORTING:" << endl;

	for (auto itr = groups.begin(); itr != groups.end(); itr++){
		vector<pair<string, int> > value = itr->second;
		accessGroups.push_back(value);
	}

	for(int i=0; i<accessGroups.size(); i++){
		vector<pair<string, int> > output = accessGroups[i];
		for(int j=0; j<output.size(); j++){
			cout << output[j].first << " : " << output[j].second << "\t";
		}
		cout << endl;
	}

	groupsReduced.resize(accessGroups.size());

#pragma omp parallel for
	for(int i=0; i<accessGroups.size(); i++){
		groupsReduced[i] = reducer(accessGroups[i]);
	}

	cout << endl << "AFTER REDUCING" << endl;
	for(int i=0; i<groupsReduced.size(); i++){
		cout << groupsReduced[i].first << " : " << groupsReduced[i].second << endl;
	}

	sort(groupsReduced.begin(), groupsReduced.end(), compare2);

	ofstream ofs("OUTPUT.txt");
	cout << endl << "AFTER REDUCING AND SORTING" << endl;
	for(int i=0; i<groupsReduced.size(); i++){
		cout << groupsReduced[i].first << " : " << groupsReduced[i].second << endl;
		ofs << groupsReduced[i].first << " : " << groupsReduced[i].second << endl;
	}
}
