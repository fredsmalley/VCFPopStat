/*!   @class Population
 *  @file   Population.h
 *  @brief  VCFPopStat
 *
 *  @author Fred Smalley
 *  @date   4/16/15
 *
 *    Copyright (c) 2015 Song Lab. All rights reserved.
 */

#ifndef __VCFPopStat__Population__
#define __VCFPopStat__Population__

#include <string>

using std::string;

class Population {
private:
   string population;
   string super_population;
   string population_description;
   
public:
   Population (const string&, const string&, const string&);
   Population ();
   
   void setPopulation (const string&);
   void setSuper (const string&);
   void setDescription (const string&);
   
   string getPopulation () const;
   string getSuper () const;
   string getDescription () const;
   string toString () const;
};

#endif /* defined(__VCFPopStat__Population__) */
