#ifndef PLATE_RECOGNITION_APP_H
#define PLATE_RECOGNITION_APP_H

#include "OpenCVCommon.h"
#include "../include/easypr/api.hpp"

class PlateRecognitionApp{

public:
	static vector<string> plateRecoResults(string picPath);
	static vector<string> plateRecoResults(Mat img);
	static vector<Mat> getAllPlateImg(string picPath);
	static easypr::CPlate getTheBestMatchedPlate(string picPath);

};

#endif
