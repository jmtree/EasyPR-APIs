#ifndef PLATE_RECOGNITION_APP_H
#define PLATE_RECOGNITION_APP_H

#include "OpenCVCommon.h"
#include "../include/easypr/api.hpp"
// #include "../include/easypr/plate_judge.h"
// #include "../include/easypr/plate_locate.h"
// #include "../include/easypr/plate_recognize.h"

class PlateRecognitionApp{

public:
	static vector<string> plateRecoResults(string picPath);
	static vector<string> plateRecoResults(Mat img);
	static vector<Mat> getAllPlateImg(string picPath);
};

#endif
