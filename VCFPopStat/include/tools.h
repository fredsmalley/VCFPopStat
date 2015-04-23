/*!	@file	tools.h
 *	@brief	Ease-of-use functions
 *	@author	Fred A Smalley
 *	@date	4-8-2015
 *
 *	These functions take care of simple tasks that are called
 *	many times in the main program.
 *
 */
#ifndef __VCFPopStat__tools__
#define __VCFPopStat__tools__

#include <string>
#include <sys/stat.h>
#include <cctype>

using std::string;
using std::exception;

/*!     @fn             string nextValue (string& line, const string& delimiter)
 *      @brief          Extracts a string from another string using a delimiter
 *      @param[in,out]  line The string to parse
 *      @param[in]      delimiter A delimiting string
 *      @return		Returns a substring of line
 *      @post		line no longer contains the returned value
 */

/*!	@fn	void removeWhiteSpace ()
 *
 *	@brief	Removes surrounding white space
 *
 *	@param[in,out]	s	The string to be cleaned
 *
 *	This function removes all white space, if any, from the beginning
 *	and ending of the parameter
 */

/*!	@fn		const bool exists (const string& fileName) const
 *	@brief		Checks for file existance
 *	@param[in]	fileName The name of the file
 */

string		nextValue (string& line, const string& delimiter = "\t");
void		removeWhiteSpace (string& s);
const bool	exists (const string& fileName);

#endif /* defined(__VCFPopStat__tools__) */
