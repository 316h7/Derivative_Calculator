#ifndef AUXILIARY_H /* any name uniquely mapped to file name */
#define AUXILIARY_H
 #include "Auxiliary.h"
#endif
using namespace std;
// class Expression
class Expression
{
public:
	Expression(string usrInput)
	{
		str_Input = usrInput;
		c_Operator = 0;
		i_n_Function = -1;
		i_Sign = 1;
	}
	

	char c_Operator;
	string str_Input;
	string str_Output;
	int i_n_Function;
	int i_Sign;

	 void GetDifferentiation();

	  void GetSign(string str){
		 i_Sign = (str.find("-") == 0?-1:1);
	};
	//  int GetExpFunction(){
	//  return i_n_Function;
	// }

	//  int GetSign(){
	// 	 return i_Sign;
	// }

	


	 // void  SetInput(string str){
		
		// 	str_Input = str;
		// }
	
	 // void  SetOutput(string str){
			
		// 	Expression::str_Output = str;
	
		// }
	 // string  GetOutput(){

		// 	return str_Output;
		// }

	    static void DelTree(Expression *tree) {
  if(tree!=NULL) {
    free(tree->left);
    free(tree->right);
    delete tree;
  }
}
	

	 string  GetInput(){
			if(Simplify::IsNumeric(str_Input.c_str()) == false && str_Input.find_first_of("+-/*^") != -1)
				return '('+str_Input+')';
		return str_Input;
	
	}

	struct Expression *left;  
    struct Expression *right;

	
};