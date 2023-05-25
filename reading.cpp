
#include "reading.hpp"
#include <fstream>
#include <iostream>

//===================================================================================
// reading.cpp v1.5
//===================================================================================
/**
 * Class for importing polygon vertices from a cleartext file. Used for input to the
 * Polygon class. Values are read in from strings and converted to double values.
 */ 

Reading::Reading() {
}

Reading::Reading(string fname)  {
	ifstream polygon(fname);

	if (!polygon.is_open()) {
		cout << "error opening file " << fname << endl;
		return;
	}

	string delimiter = ",";
	string x_str;
	string y_str;
	double x_value;
	double y_value;
	size_t comma_location;

	for (string line; getline(polygon, line); ) {
		comma_location = line.find(delimiter);
		if (comma_location == string::npos) {
			cout << "This line has no delimiter: " << line << ". skipping" << endl;
			continue;
		}

		try {
			x_str = line.substr(0, comma_location);
			y_str = line.substr(comma_location + 1);
		} catch (out_of_range) {
			cout << "Substr call failed on " << line << ". skipping" << endl;
			x_str = "";
			y_str = "";
			continue;
		}

		try {
			x_value = stod(x_str);
			y_value = stod(y_str);
		} catch (invalid_argument) {
			cout << "Failed on conversion of " << x_str << " or " << y_str << "to double. skipping" << endl;
			x_value = 0.0;
			y_value = 0.0;
			continue;
		}

		internal_x.push_back (x_value);
		internal_y.push_back (y_value);
	}
}

vector<double> Reading::x_vector() {
	return internal_x;
}

vector<double> Reading::y_vector() {
	return internal_y;
}


