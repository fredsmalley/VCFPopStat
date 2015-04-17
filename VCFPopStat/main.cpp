//
//  main.cpp
//  VCFPopStat
//
//  Created by Fred Smalley on 4/16/15.
//  Copyright (c) 2015 Song Lab. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <map>

#include "tools.h"

using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::map;

int main(int argc, const char * argv[]) {
   string fileName = "test.out";
   
   uint_fast16_t col = 0;
   map<string, uint_fast16_t> column_names;
   map<string, string> races;
   
   string line;
   fstream file;
   file.open(fileName, fstream::in);
   if (file.is_open()) {
      while (getline(file, line)) {
         if (line[0] == '#' && line[1] == '#') {
            continue;
         }
         
         while (line.length() != 0) {
            column_names[nextValue(line)] = col++;
         }
         
         cout << "Number of columns in " << fileName << " = " << col << endl;
         cout << "Number of samples in " << fileName << " = " << col - 9 << endl;   // subtract 9 default columns
         
         /*for (map<string, uint_fast16_t>::const_iterator itr = column_names.begin(); itr != column_names.end(); itr++) {
            cout << itr->second << ": " << itr->first << endl;
         }*/
         
         //cout << column_names["CHROM"] << endl;
         //cout << column_names["POS"] << endl;
         //cout << column_names["ID"] << endl;
         //cout << column_names["REF"] << endl;
         
         /*for (int i = 0; i < 9; i++)
            nextValue(line);
         
         while (line.length() != 0) {
            cout << nextValue(line) << endl;
         }*/
         
         break;
      }
      file.close();
   } else
      cout << "Unable to open " << fileName << endl;
   
   fileName = "populations.tsv";
   file.open(fileName, fstream::in);
   if (file.is_open()) {
      cout << fileName << " is open" << endl;
      
      ;
      
      file.close();
   } else
      cout << "Unable to open " << fileName << endl;
   
   fileName = "participant_population.tsv";
   file.open(fileName, fstream::in);
   if (file.is_open()) {
      cout << fileName << " is open" << endl;
      
      ;
      
      file.close();
   } else
      cout << "Unable to open " << fileName << endl;
}
