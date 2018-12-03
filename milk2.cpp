/*
ID: jason.z2
PROG: milk2
LANG: C++
*/


#include <fstream>
#include <bitset>
#include <iostream>

int main(){
	
	std::ifstream input("milk2.in");
	int n;
	input >> n;
	int len = 0;
	int firststart = 1000000;
	std::bitset<1000000> times;
	for (int i = 0; i < n; i++){
		int start; int end;
		input >> start >> end;
		
		for (int j = start; j < end; j++)
			times[j] = true;
		
		if (end > len) len = end;
		if (start < firststart) firststart = start;
	}
	input.close();
	
	int longestMilk = 0;
	int longestNoMilk = 0;
	int length;
	bool curr;
	curr = times[firststart];
	for (int i = firststart; i < len; i++){
		if (times[i] == curr) {
			length++;
		}
		else{
			if (curr) {if (longestMilk < length) longestMilk = length;}
			else {if (longestNoMilk < length) longestNoMilk = length;}
			length = 1;
			curr = times[i];
		}
	}
	
	std::ofstream output("milk2.out");
	output << longestMilk << " " << longestNoMilk << "\n";
	output.close();
	return 0;
}
