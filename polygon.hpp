#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Polygon {
	public :
		Polygon();
		Polygon(vector<double> x, vector<double> y);
		~Polygon() {};

		int 	number(); 	
		double 	sum_x(); 
		double 	sum_y(); 

		int 	find_centroid(double *x_vertex, double *y_vertex); // returns -1 on error

	private :
		vector <vector <double> > *vertices;
		double 	sum(int index);
};
