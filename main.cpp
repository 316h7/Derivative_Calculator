#include "Diff.h"

#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{	
string in_str;	
while(1){
		cout << endl;
	cout << "f(x)=";
	cin >> in_str; //"f(x)=">> 
	// cout << endl;
	string out_str =  Differentiate(in_str);
		// treeprint(root);
	cout << "df/dx="<<out_str <<endl;
}

	return 0;
}