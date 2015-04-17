/*!
 *  @file   Population.cpp
 *  @brief  VCFPopStat
 *
 *  @author Fred Smalley
 *  @date   4/16/15
 *
 *    Copyright (c) 2015 Song Lab. All rights reserved.
 */

#include "Population.h"

/*!   This is the basic contructor for the Population class
 *    @brief   Three parameter constructor
 *
 *    @param   pop   A string holding the population name
 *    @param   spop  A string holding the super population name
 *    @param   des   A string holding the population description
 *
 */
Population::Population (const string& pop, const string& spop, const string& des) {
   population = pop;
   super_population = spop;
   population_description = des;
}

/*!   This is the default constructor for the Population class
 *    @brief   Default
 *
 */
Population::Population () {
   population = "?";
   super_population = "?";
   population_description = "?";
}

/*!   This method sets the population in this Population object
 *    @brief   set population
 *
 *    @param   pop   A string holding the new population name
 *
 */
void Population::setPopulation(const string& pop) {   population = pop; }

/*!   This method sets the superpopulation in this Population object
 *    @brief   set super population
 *
 *    @param   spop A string holding the new super population name
 *
 */
void Population::setSuper(const string& spop) {   super_population = spop; }

/*!   This method sets the description for the Population object
 *    @brief   set description
 *
 *    @param   des   A string which holds the new population description
 *
 */
void Population::setDescription(const string& des) {    population_description = des; }

/*!   This method returns the population name
 *    @brief   get population
 *
 *    @return  A string holding the population name
 */
string Population::getPopulation() const {    return population; }

/*!   This method return the super population name
 *    @brief   get super population
 *
 *    @return  A string holding the super population name
 */
string Population::getSuper() const {    return super_population; }

/*!   This method returns the population discription
 *    @brief   get description
 *
 *    @return  A string holding the population description
 */
string Population::getDescription() const {    return population_description; }

/*!   This is a standard toString method for the Population class
 *    @brief   get info string
 *
 *    @return  A string holding a description of the Population object
 */
string Population::toString() const {
   return super_population + " <- " + population + "\n\t: " + population_description;
}
