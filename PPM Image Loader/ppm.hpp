#pragma once
#include <string>
#include <cstdint>
#include "pixel.hpp"
#include <vector>
//header - ppm.hpp
//header files serve as interfaces
class PPM {
	public: 
		//constructor
		PPM(std::string filename);
		//destructor
		~PPM();

		void savePPM(std::string outFileName);
		void lighten();
		void darken();

	private:
		std::vector<uint8_t> mPixels;
		int mMaxRange;
		short mWidth;
		short mHeight;
		
};
