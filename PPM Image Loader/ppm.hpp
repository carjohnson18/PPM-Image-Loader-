#pragma once
#include <string>
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
		//try maybe using
		// a pixel * mPixelArray;
		// a little less memory then array
		std::vector<pixel> mPixels;
		int mWidth; 
		int mHeight;
		int mMaxRange; 


};
