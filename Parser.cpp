#ifndef PARSER_H /* any name uniquely mapped to file name */
#define PARSER_H
 #include "Parser.h"
#endif
// #include <iostream>
using namespace std;




const char* Functions[] = { 
	 
	"sin(", 
	"cos(", 
	"tan(", 
	"ctg(", 

	"sinh(", 
	"cosh(", 
	
	"sqrt(", 

	"log10(",
	"log(",
	"ln(",

	"sign(",
	"abs(",

	"(",
	NULL
};

// GeTLeft/Right part of expr
const char* Parser::GetLeft(const char* t_str,int index){
	 char *l_str = (char *) malloc(sizeof(char) * index);
	strncpy (l_str, t_str, index);
	 l_str[index]='\0';
	return l_str;

};

const char* Parser::GetRight(const char* t_str,int index){
	 char *l_str = (char *) malloc(sizeof(char) * strlen(t_str)-index);
	strncpy (l_str, t_str+index, strlen(t_str)-index);
	 l_str[strlen(t_str)-index]='\0';
	return l_str;

};

string Parser::GetArgument(string str){
  str.erase(0,str.find("(")+1);
  str.erase(str.rfind(")"),str.length()-str.rfind(")"));
	return str;}




/////////////////////////////////////////////////////////////////////////////////////////////
// GetFunction scans for finctions
//////////////////////////////////////////////////////////////////////////////////////////////

int Parser::GetFunction(string str)
{	
		for(int Index = 0; Functions[Index]; Index++){
		if( str.find(Functions[Index]) != std::string::npos)
		{
			if( str.find(Functions[Index]) == std::string::npos)
				return -2;
			return Index;
		}}
		return -1;
}



bool Parser::IsSign(char c, const char*  Operators[], int index)
{
	for(; Operators[index]; index++)
        if(strchr(Operators[index], c) != NULL)
			return false;
	return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////
// GetOperator scans for operators
//////////////////////////////////////////////////////////////////////////////////////////////
int Parser::GetOperator(const char* str){

	const char* Operators[] = { "+-", "*/", "^%", NULL };
	for(int Index = 0; Operators[Index]; Index++)
	{
		int nOpen = 0;
		// scan expression from end
		char* p = (char*)str+strlen(str)-1;
		while(p >= str)

		{	if(*p == ')')
				nOpen++;
			else	if(*p == '(')
				nOpen--;
			else	if(nOpen == 0 && strchr(Operators[Index], *p) != NULL)
				if((*p != '-' && *p != '+') || (p != str && IsSign(*(p-1), Operators, Index+1)))
					// return operator index
					return (int)(p-str);
			p--;
		}
									}

	return -1;
}


	

int Parser::ParseExpression(string usrInput, struct Expression *&tree)
{


 if (tree == NULL) { 
   tree = new Expression(usrInput);	
    tree->left =  NULL;
    tree->right = NULL;
  }

    const char* str = usrInput.c_str();
    while (1) { 

	    int op_index = GetOperator(str);

			if(op_index != -1){

		        tree->c_Operator = str[op_index];

				ParseExpression(GetLeft(str,op_index), tree->left);
				ParseExpression(GetRight(str,op_index+1), tree->right);
		
			
			}
		else {
	 			if((tree->i_n_Function = GetFunction(str)) != -1)	{
	 					tree->GetSign(str);
	 				}	
}
        return 0;
        } 
    } 



