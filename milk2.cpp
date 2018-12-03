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
  std::bitset<1000000> times;
  for (int i = 0; i < n; i++){
    int start; int end;
    input >> start >> end;
    
    for (int j = start; j < end; j++)
      times[j] = true;
    
    if (end > len) len = end;
  }
  input.close();
  
  int longestMilk = 0;
  int longestNoMilk = 0;
  int len;
  bool curr;
  for (int i = 0; i < len; i += length){
    curr = times[i];
    length = 0;
    for (int j = i + 1; j < len; j++)
      if (times[j] == curr) length++;
    if (curr) if (longestMilk < length) longestMilk = length;
    else if (longestNoMilk < length) longestNoMilk = length;
  }
  
  std::ofstream output("milk2.out");
  output << longestMilk << " " << longestNoMilk << "\n";
  output.close();
  return 0;
}
