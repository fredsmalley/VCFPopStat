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
#include <vector>

#include "tools.h"
#include "Population.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::string;
using std::stoi;
using std::map;
using std::vector;

int main(int argc, const char * argv[]) {
   string line;
   uint_fast16_t defualt_columns = 9;
   
   map<string, Population> pop_map;
   map<string, uint_fast16_t> pop_count;
   string pop;
   string pop_des;
   string s_pop;
   string fileName = "files/populations.tsv";
   fstream file;
   file.open(fileName, fstream::in);
   if (file.is_open()) {
      cout << "Getting Populations...";
      
      getline (file, line);   // skip titles
      
      while (getline (file, line)) {
         pop_des = nextValue (line);
         if (pop_des.compare ("Total") == 0)
            break;
         pop = nextValue (line);
         s_pop = nextValue (line);
         
         pop_count[pop] = 0;
         pop_count[s_pop] = 0;
         pop_map[pop] = Population (pop, s_pop, pop_des);
      }
      
      cout << "Done" << endl;
      file.close();
   } else
      cout << "Unable to open " << fileName << endl;
   
   map<string, string> race_map;
   map<string, uint_fast16_t> pop_total;
   string id;
   fileName = "files/participant_population.tsv";
   file.open(fileName, fstream::in);
   if (file.is_open()) {
      cout << "Finding Participant Races...";
      
      getline (file, line);   // skip titles
      
      while (getline (file, line)) {
         id = nextValue (line);
         pop = nextValue (line);
         /*if (pop_map[pop].getSuper ().compare ("?") == 0) {
            continue;
         }*/
         race_map[id] = pop;
         pop_total[pop] = 0;
         pop_total[pop_map[pop].getSuper ()] = 0;
         
         //cout << nextValue (line) << endl;
      }
      
      cout << "Done" << endl;
      file.close();
   } else
      cout << "Unable to open " << fileName << endl;
   
   for (map<string, string>::const_iterator itr = race_map.begin(); itr != race_map.end(); itr++) {
      pop_total[itr->second] += 1;
      pop_total[pop_map[itr->second].getSuper ()] += 1;
   }
   
   /*for (map<string, uint_fast16_t>::const_iterator itr = pop_total.begin (); itr != pop_total.end (); itr++) {
      cout << itr->first << ": " << itr->second << endl;
   }*/
   
   cout << "Enter the name of the input file: ";
   //fileName = "files/test.out";
   getline (cin, fileName);
   
   uint_fast16_t col = 0;
   map<uint_fast16_t, string> column_index;
   
   bool first = true;
   string gt;
   string gt_0;
   file.open(fileName, fstream::in);
   fstream outFile;
   if (file.is_open()) {
      // skip meta-data
      while (getline(file, line)) {
         if (line[0] == '#' && line[1] == '#')
            continue;
         else
            break;
      }
         
      nextValue(line, "#");      // remove "#" from line
         
      cout << "Finding Participants and Column Placement...";
      while (line.length() != 0) {
         column_index[col++] = nextValue (line);
      }
      cout << "Done" << endl;
         
      //cout << "Number of columns in " << fileName << " = " << col << endl;
      //cout << "Number of samples in " << fileName << " = " << col - 9 << endl;   // subtract 9 default columns
      
      double percent;
      fileName = "files/Popstat.tsv";
      outFile.open (fileName, fstream::out);
      if (outFile.is_open ()) {
         outFile << "## Table entries are given as a fraction of those with the variation, either homozygous or heterozygous, to the total for the population" << endl;
         for (map<string, Population>::const_iterator itr = pop_map.begin(); itr != pop_map.end(); itr++) {
            if (itr->second.getSuper().compare("?") == 0)
               continue;
            outFile << "##" << itr->second.getPopulation () << "(" << pop_total[itr->first] << ")" << "->" << itr->second.getSuper () << "(" << pop_total[itr->second.getSuper()] << ")" << "\t" << itr->second.getDescription() << endl;
         }
         
         while (getline (file, line)) {
            col = 0;
         
            // skip default columns
            for (uint_fast16_t i = 0; i < defualt_columns; i++) {
               if (i == 2)
                  id = nextValue (line);
               else
                  nextValue (line);
               ++col;
            }
         
            while (line.length () != 0) {
               gt = nextValue (line);
               gt_0 = nextValue(gt, "|");
               if (stoi (gt_0) + stoi (gt) > 0) {
                  pop_count[pop_map[race_map[column_index[col]]].getSuper ()] += 1;
                  pop_count[pop_map[race_map[column_index[col]]].getPopulation ()] += 1;
               }
               ++col;
            }
         
            if (first) {
               first = false;
               outFile << column_index[2];
               for (map<string, uint_fast16_t>::const_iterator itr = pop_count.begin (); itr != pop_count.end (); itr++) {
                  outFile << "\t" << itr->first;
               }
               outFile << endl;
            }
      
            outFile << id;
            for (map<string, uint_fast16_t>::iterator itr = pop_count.begin (); itr != pop_count.end (); itr++) {
               percent = (double) itr->second / (double) pop_total[itr->first];
               outFile << "\t" << percent;
               itr->second = 0;
            }
            outFile << endl;
         }
         outFile.close ();
      }
      file.close ();
   } else
      cout << "Unable to open " << fileName << endl;
}
