
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

#include "polygon.hpp"
#include "reading.hpp"

/**
 * 
 * runit.cpp -- code for testing out Polygon and Reading classes,
 * and calculating centroids two different ways.
 * 
 * Three input files--a trapezoid, square, and triangle--are used as
 * examples.
 * 
 */

int main() {


	cout << endl << "TRAPEZOID" << endl;
	Reading *getting_input = new Reading("trapezoid.txt");


	Polygon *this_poly = new Polygon(getting_input->x_vector(),getting_input->y_vector());

	int num 		= this_poly->number();
	double x_total  = this_poly->sum_x();
	double y_total  = this_poly->sum_y();

	cout << "Total number of points: " << num << ". Sum of x values: " << x_total << " y: " << y_total << endl;

	double centroid_x = x_total / (double) num;
	double centroid_y = y_total / (double) num;

	cout << "The centroid of the set of points is " << centroid_x << "," << centroid_y << endl;

	int result = this_poly->find_centroid(&centroid_x, &centroid_y);
	cout << "This polygon's centroid is " << centroid_x << "," << centroid_y << endl;

	delete getting_input;
	delete this_poly;


	cout << endl << "TRIANGLE" << endl;
	getting_input 	= new Reading("triangle.txt");
	this_poly 		= new Polygon(getting_input->x_vector(),getting_input->y_vector());

	num 		= this_poly->number();
	x_total		= this_poly->sum_x();
	y_total		= this_poly->sum_y();

	cout << "Total number of points: " << num << ". Sum of x values: " << x_total << " y: " << y_total << endl;

	centroid_x = x_total / (double) num;
	centroid_y = y_total / (double) num;

	cout << "The centroid of the set of points is " << centroid_x << "," << centroid_y << endl;
	result = this_poly->find_centroid(&centroid_x, &centroid_y);
	cout << "This polygon's centroid is " << centroid_x << "," << centroid_y << endl;
	delete getting_input;
	delete this_poly;

	cout << endl << "SQUARE" << endl;
	getting_input 	= new Reading("square.txt");
	this_poly 		= new Polygon(getting_input->x_vector(),getting_input->y_vector());

	num 		= this_poly->number();
	x_total		= this_poly->sum_x();
	y_total		= this_poly->sum_y();

	cout << "Total number of points: " << num << ". Sum of x values: " << x_total << " y: " << y_total << endl;

	centroid_x = x_total / (double) num;
	centroid_y = y_total / (double) num;
	cout << "The centroid of the set of points is " << centroid_x << "," << centroid_y << endl;
	result = this_poly->find_centroid(&centroid_x, &centroid_y);
	cout << "This polygon's centroid is " << centroid_x << "," << centroid_y << endl;
	delete getting_input;
	delete this_poly;

		cout << endl << "HOUSE" << endl;
	getting_input 	= new Reading("house.txt");
	this_poly 		= new Polygon(getting_input->x_vector(),getting_input->y_vector());

	num 		= this_poly->number();
	x_total		= this_poly->sum_x();
	y_total		= this_poly->sum_y();

	cout << "Total number of points: " << num << ". Sum of x values: " << x_total << " y: " << y_total << endl;

	centroid_x = x_total / (double) num;
	centroid_y = y_total / (double) num;
	cout << "The centroid of the set of points is " << centroid_x << "," << centroid_y << endl;
	result = this_poly->find_centroid(&centroid_x, &centroid_y);
	cout << "This polygon's centroid is " << centroid_x << "," << centroid_y << endl;
	delete getting_input;
	delete this_poly;


}
