//source - main.cpp
#include <iostream>
#include "ppm.hpp"

void test1() {
	PPM myPPM("./PPM.ppm");
	myPPM.lighten();
	myPPM.savePPM("./lighten.ppm ");
}

void test2() {
	PPM myPPM("./PPM.ppm");
	myPPM.darken();
	myPPM.savePPM("./darken.ppm ");
}

int main() {


	test1();
	test2();

	std::cout << "size of ppm:" << sizeof(PPM) << std::endl;

	return 0;
}