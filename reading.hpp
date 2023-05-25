#include <iostream>
#include <string>
#include <vector>
using namespace std;


/* Header file for the Reading class.
 *
 * Reads in vertices from a text file. Makes some minor calculations for 
 * the basic centroid-of-set-of-points derivation.
 */


class Reading {
	public :
		Reading();
		Reading(string filename);
		~Reading() {};

		vector<double> x_vector();
		vector<double> y_vector();

	private :
		vector <vector <double> > *vertices;
		vector<double> internal_x;
		vector<double> internal_y;
};
