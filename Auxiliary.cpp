#include "Auxiliary.h"
using namespace std;


#define DIGITS			"0123456789."
#define IsDigit(c)		(c && strchr(DIGITS, c) != NULL)


bool Simplify::IsNumeric(const char* str)
{
	char* p = (char*)str;
	if(*p == '-' || *p == '+')
		p++;
	if(*p == 'e' && *(p+1) == 0)
		return true;
	if(*p == 'p' && *(p+1) == 'i' && *(p+2) == 0)
		return true;
	while (*p)
	{
		if(IsDigit(*p) == false)
			return false;
		p++;
	}
	return true;
}




void Simplify::SimplifySign(string& str) 	// replace "+-", "--" 
{
	int index = 0;

	
	while((index = str.find("--", index)) != string::npos){
		if(index == 0 )
		    str.erase (index,2); 
		else{
		    str.erase(index,2);   str.insert(index,"+");
		}
	}
	index = 0;
	// replace "+-" 
	while((index = str.find("+-", index)) != string::npos)
		str.erase(index,1);
	index = 0;
	while((index = str.find("-+", index)) != string::npos)
		str.erase(index+1,1);
}


void Simplify::SimplifyString(string& str) //reremove *1/1*/^1 , (( .... ))
{

	SimplifySign(str);

	int index = 0;
	int o_index = 0;
	int c_index = 0;

    while((index = str.find("1*", index)) != string::npos){
		if(index == 0 )
		    str.erase (index,2); 
		else
		    str.erase(index,2);  
}

   index = 0;

		     while((index = str.find("*1", index)) != string::npos)
		    str.erase(index,2); 

   index = 0;

		     while((index = str.find("^1", index)) != string::npos)
		    str.erase(index,2); 

  index = 0;
  	while(( o_index = str.find("((", o_index)) != string::npos){
        if((( c_index = str.find("))", o_index))!= string::npos) && ((str.find(")", o_index))!= string::npos || str.find("))", o_index))!= string::npos){
      str.erase(o_index,1);
      str.erase(c_index,1); 
		 
	}}
		SimplifySign(str);

}



string Simplify::RmChar(string &str, const char* c){
	int n;
 while((n=str.find_first_of(c))!=-1)
 str.erase(n,1);  
return str;
}

string Simplify::TFloat(double f)
{	string str;
	char buf[40];
	snprintf(buf, sizeof(buf), "%f",f);
	str=buf;
	if(str.find_first_of(".") != -1)
		while(*(str.cend()-1)=='0') str.pop_back();
	while(*(str.cend()-1)=='.') str.pop_back();
	return str;
}


string Simplify::ToLowerCase(string &str){
string str_s;
for (auto it=str.cbegin(); it!=str.cend(); ++it){
	str_s.append(1,(char)tolower((int)*it)); 
	}
	str=str_s;
	return str;}