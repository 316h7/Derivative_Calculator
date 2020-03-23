

no_gui: 
	g++ main.cpp Parser.cpp Diff.cpp Auxiliary.cpp -o Derivative_calc
gui: 
	g++ `fltk-config --cxxflags --ldflags` dff_app.cxx Parser.cpp Diff.cpp Auxiliary.cpp -o Derivative_calc


uninstall:
	rm Derivative_calc

		
