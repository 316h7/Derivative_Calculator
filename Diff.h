
 // #include "Parser.h"

#ifndef EXPRESSION_H /* any name uniquely mapped to file name */
#define EXPRESSION_H
#include "Expression.h"
#endif
#ifndef AUXILIARY_H /* any name uniquely mapped to file name */
#define AUXILIARY_H
 #include "Auxiliary.h"
#endif

#ifndef PARSER_H /* any name uniquely mapped to file name */
#define PARSER_H
 #include "Parser.h"
#endif


//   differentiation functions
#define df(u)			Differentiate(u)
#define d_sin(u)		df(u)+"*cos("+u+")"						// du*cos(u)
#define d_cos(u)		df(u)+"*-sin("+u+")"						// du*(-sin(u))
#define d_tan(u)		df(u)+"/cos("+u+")^2"						// du*sec(u)^2
#define d_ctg(u)		df(u)+"/-sin("+u+")^2"					// du*(-cosec(u)^2)
#define d_sinh(u)		df(u)+"*cosh("+u+")"						// du*cosh(u)
#define d_cosh(u)		df(u)+"*sinh("+u+")"						// du*(sinh(u))
#define d_sqrt(u)		df(u)+"/(2*sqrt("+u+"))"					// du/(2*sqrt(u))
#define d_log10(u)	    df(u)+"/(("+u+")*log(10))"					// du/(u*log(10))
#define d_log(u)		df(u)+"/("+u+")"							// du/u
#define d_ln(u)		    d_log(u)
#define d_sign(u)		"0"
#define d_abs(u)		df(u)+"*("+u+")/abs("+u+")"				// du*u/abs(u)

string Differentiate(string usrInput); 

