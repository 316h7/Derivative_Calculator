
#include <cstring>
#include <string>
 #include <iostream>

#ifndef EXPRESSION_H 
#define EXPRESSION_H
#include "Expression.h"
#endif

// #ifndef AUXILIARY_H 
// #define AUXILIARY_H
//  #include "Auxiliary.h"
// #endif

// #ifndef PARSER_H  
// #define PARSER_H
//  #include "Parser.h"
// #endif

using namespace std;

extern char* pFunctions[];




class Parser
{
public:
static int ParseExpression(string usrInput, struct Expression *&tree);
static const char* GetLeft(const char* t_str,int index);
static const char* GetRight(const char* t_str,int index);
static int GetFunction(string str);
static int GetOperator(const char* str);
static string GetArgument(string str);
static bool IsSign(char c, const char*  Operators[], int index);



	
};