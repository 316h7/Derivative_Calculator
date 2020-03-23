//header file containing declarations for a few auxiliary functions;

#include <cstring>
#include <string>
using namespace std;

class Simplify
{
public:
	static void SimplifySign(string& str); 
	static void SimplifyString(string& str); 
	static string RmChar(string &str, const char* c);
    static string TFloat(double f);
	static string ToLowerCase(string &str);
	static bool IsNumeric(const char* str);
	// Simplify();
	// ~Simplify();j
	
};