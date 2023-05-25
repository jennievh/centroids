
#include "polygon.hpp"

#define X_VERTEX 0
#define Y_VERTEX 1

//===================================================================================
// polygon.cpp v1.5
//===================================================================================
/**
 * Class for calculating centroids of polygons from vertices. 
 * 
 * Class members allow for calculation of centroid of a set of points (average of
 * X values and Y values), and for the more complex polygon centroid formula.
 * 
 */ 

Polygon::Polygon() {
}

Polygon::Polygon(vector<double> x, vector<double> y)  {
	vertices = new vector< vector<double> >;

	if (x.size() != y.size()) {
		cout << "ERROR: vectors are of dissimilar size" << endl;
		return;
	}

	vertices->push_back(x);
	vertices->push_back(y);
}

int Polygon::number() {
	return (*vertices)[X_VERTEX].size();
}

double Polygon::sum(int index) {
	double total = 0.0;

	for (int i = 0; i < number(); ++i) {
		total += (*vertices)[index][i];
	}
	return total;
}

double Polygon::sum_x() {
	return sum(X_VERTEX);
}

double Polygon::sum_y() {
	return sum(Y_VERTEX);
}

/**
 * Formula for the centroid of a non-self-intersecting polygon: https://en.wikipedia.org/wiki/Centroid#Of_a_polygon
 * 
 * The loop uses x sub i, x sub i+1, y sub i, and y sub i+1.
 * 
 * In order to reduce lookups, x sub i+1 is stored into x sub i (same for y) at the end of the loop.
 * 
 * Also, the quantity "x_i * y_i_plus1 - x_i_plus1 * y_i" is used in the calculations for the x and y sums
 * as well the area (A). The final sums for X and Y are adjusted by 1/6A. So, for efficiency, the quantity is
 * calculated once, as 'blob,' and used for the 3 calculations.
 * 
 * After the end of the loop, the calculation requires one more addition using the last point and the first point.
 * 
 */
int Polygon::find_centroid(double *return_x, double *return_y) {

	int return_code = 0; 

	double x_value, y_value;
	double x_i, x_i_plus1, y_i, y_i_plus1;

	double area = 0.0;

	x_i 		= (*vertices)[X_VERTEX][0];
	y_i			= (*vertices)[Y_VERTEX][0];
	double blob; 

	for (int i = 0; i < number() - 1; ++i) {
		x_i_plus1 	= (*vertices)[X_VERTEX][i + 1];
		y_i_plus1	= (*vertices)[Y_VERTEX][i + 1];

		blob 	 = x_i * y_i_plus1 - x_i_plus1 * y_i;

		x_value += (x_i + x_i_plus1) * blob;
		y_value += (y_i + y_i_plus1) * blob;
		area 	+= blob;

		x_i 	 = x_i_plus1;
		y_i 	 = y_i_plus1;
	}

	x_i_plus1	= (*vertices)[X_VERTEX][0];
	y_i_plus1 	= (*vertices)[Y_VERTEX][0];

	blob 	=   x_i * y_i_plus1 - x_i_plus1 * y_i;
	x_value += (x_i + x_i_plus1) * blob;
	y_value += (y_i + y_i_plus1) * blob;

	area 	+=  blob;

	area 	*= 0.5;

	x_value = (1 / (6 * area)) * x_value;
	y_value = (1 / (6 * area)) * y_value;

	*return_x = x_value;
	*return_y = y_value;

	return return_code;
}


