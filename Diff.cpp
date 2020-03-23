
#include "Diff.h"

// #include <iostream>
// #include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////
// DifferentiateTree: takes the input Tree and applies operators to operands 
/////////////////////////////////////////////////////////////////////////

string DifferentiateTree(Expression *& Tree)
{
	
		if(Tree == NULL){
	return NULL;

	}

	Expression * p_Exp = Tree;

	if(p_Exp->c_Operator)
	{

	string u = Tree->left->GetInput();
	 string du = DifferentiateTree(Tree->left);
	string v = Tree->right->GetInput();
	string dv = DifferentiateTree(Tree->right);
	

	
		if(du == "0")	
			switch(p_Exp->c_Operator)
			{
			case '-':	
				p_Exp->str_Output = "(-"+dv+')';
				break;
			case '+':	
				p_Exp->str_Output = dv;
				break;
			case '*':	
				p_Exp->str_Output = u+'*'+dv;
				break;
			case '/':
				p_Exp->str_Output = "(-"+u+'*'+dv+")/("+v+")^2";
				break;
			case '^':	
				p_Exp->str_Output = dv+"*"+u+"^"+v+(u == "e" ? "" : "*ln("+u+")");
				break;
			}
		else	if(dv == "0")	
			switch(p_Exp->c_Operator)
			{
			case '-':	
			case '+':	
				p_Exp->str_Output = du;
				break;
			case '*':	
				p_Exp->str_Output = du+'*'+v;
				break;
			case '/':	
				p_Exp->str_Output = '('+du+")/"+v;
				break;
			case '^':	
			p_Exp->str_Output=v+'*'+u+'^'+Simplify::TFloat(atof(v.c_str())-1)+'*'+du;
				break;
			}
		else
			switch(p_Exp->c_Operator)
			{
			case '-':	
			case '+':	
				p_Exp->str_Output = '('+du+p_Exp->c_Operator+dv+')';
				break;
			case '*':	
				p_Exp->str_Output = '('+u+'*'+dv+'+'+du+'*'+v+')';
				break;
			case '/':	
				p_Exp->str_Output = '('+du+'*'+v+'-'+u+'*'+dv+")/("+v+")^2";
				break;
			case '^':	
				p_Exp->str_Output = '('+v+'*'+u+"^("+v+"-1)*"+du+'+'+u+'^'+v+"*ln("+u+")*"+dv+')';
				break;
			}
	}

	
		else
		p_Exp->GetDifferentiation();
		
	return p_Exp->str_Output.c_str();
}


void treeprint(Expression *tree) {
  if (tree!=NULL) { 
    treeprint(tree->left); 
    treeprint(tree->right); 

}};


string Differentiate(string usrInput) 
{
	const char* strInput = usrInput.c_str();
	string s_strInput = usrInput;
	
	Simplify::RmChar(s_strInput," "); // remove spaces
	Simplify::ToLowerCase(s_strInput); // lower case


	Expression *root=NULL;

	if(Parser::ParseExpression(strInput, root) < 0)
		return "Invalid input";

	string strOutput = DifferentiateTree(root);

	  Simplify::SimplifyString(strOutput); 
	 Expression::DelTree(root);
	return strOutput;


}

void Expression::GetDifferentiation()	
{


	if(i_n_Function != -1)
	{
	
		string str=Parser::GetArgument(str_Input);
		switch(i_n_Function)
		{
	
		case 0:		str_Output = d_sin(str);		break;		
		case 1:		str_Output = d_cos(str);		break;
		case 2:		str_Output = d_tan(str);		break;
		case 3:		str_Output = d_ctg(str);		break;	

		case 4:		str_Output = d_sinh(str);		break;	
		case 5:		str_Output = d_cosh(str);		break;	

		case 6:	    str_Output = d_sqrt(str);		break;	

		case 7:		str_Output = d_log10(str);		break;
		case 8:		str_Output = d_log(str);		break;
		case 9:		str_Output = d_ln(str);		    break;
		case 10:	str_Output = d_sign(str);		break;
		case 11:	str_Output = d_abs(str);		break;
		
		case 12:	str_Output = df(str);			break;
		}
		str_Output = (i_Sign == -1?"-":"")+str_Output;
	}
	else
	{
		// dx/dx = 1
		if(str_Input == "x" || str_Input == "+x")
			str_Output = '1';
		else	if(str_Input == "-x")
			str_Output = "-1";
		else	if(Simplify::IsNumeric(str_Input.c_str()))
			// dc/dx = 0
			str_Output = '0';
		else
			// du/dx du=f()
			str_Output = 'd'+str_Input+"/dx";
	}
}


