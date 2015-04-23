#include "tools.h"

string nextValue (string& line, const string& delimiter) {
	const size_t pos = line.find (delimiter);
	string result = line.substr (0, line.find (delimiter) );

	if (pos == string::npos)
		line = "";
	else
		line = line.substr (line.find (delimiter) + 1);

	removeWhiteSpace (result);
	removeWhiteSpace (line);

	return result;
}

void removeWhiteSpace (string& s) {
	while (isspace (s[0]))
		s = s.substr (1);

	while (isspace (s[s.size () - 1]))
		s = s.substr (0, s.size () - 1);
}

const bool exists (const string& fileName) {
	struct stat buffer;

	if (stat (fileName.c_str (), &buffer) == 0)
		return true;

	return false;
}

string stripPath (string& line) {
   string dir = "";
   
   while (line.find ("/") != string::npos) {
      dir += line.substr(0, line.find ("/") + 1);
      line = line.substr (line.find ("/") + 1);
   }
   
   return dir;
}