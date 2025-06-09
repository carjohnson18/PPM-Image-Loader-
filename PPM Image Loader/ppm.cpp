//source - ppm.cpp
//serves as our implemention
#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include "ppm.hpp"
#include <algorithm>

PPM::PPM(std::string filename) {
	std::cout << "PPM::PPM()\n";

	//open file
	std::ifstream inputFile;
	inputFile.open(filename);

	bool foundp3{ false };
	bool foundDimensions{ false };
	bool foundRange{ false };
	bool readingPixels{ false };


	//if file opens 
	if (inputFile.is_open()) {
		std::cout << filename << " was opened\n";
		std::string line;

		//read each line
		while (std::getline(inputFile, line)) {
			std::stringstream stream(line);

			//read each space seperated character
			std::string chunck_of_data;
			while (stream >> chunck_of_data) {
				if (chunck_of_data[0] == '#') {
//					std::cout << line << std::endl;
					break; 
				}
				else if (false == foundp3) {
					if (chunck_of_data == "P3") {
//						std::cout << "found p3: " << std::endl;
					}
					foundp3 = true;
				}
				else if (false == foundDimensions) {
					mWidth = std::stoi(chunck_of_data);
					stream >> chunck_of_data;
					mHeight = std::stoi(chunck_of_data);
					foundDimensions = true; 
				}
				else if (false == foundRange) {
					mMaxRange = std::stoi(chunck_of_data); 
					foundRange = true; 
				}
				else {
					int data = std::stoi(chunck_of_data);
					mPixels.push_back(data);
				}
			}
		}
		inputFile.close();
	}
}

PPM::~PPM(){
	std::cout << "PPM::~PPM()\n";
}

void PPM::savePPM(std::string outFileName) {

	std::ofstream myFile;
	myFile.open(outFileName);
	myFile << "P3\n";
	myFile << "# saves by us\n";
	myFile << mWidth << " " << mHeight << "\n";
	myFile << mMaxRange<<"\n";
	for (int i = 0; i < mPixels.size(); i++) {
		myFile << mPixels[i] << '\n';
	}
	myFile.close();

}

void PPM::lighten() {
	for (int i = 0; i < mPixels.size(); i++) {
		int data = mPixels[i] * 4;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}

}
void PPM::darken() {
	for (int i = 0; i < mPixels.size(); i++) {
		int data = mPixels[i] / 4;
		mPixels[i] = std::clamp(data, 0, mMaxRange);
	}

}