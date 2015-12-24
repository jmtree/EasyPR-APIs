
#include "PlateRecognitionApp.h"

vector<string> PlateRecognitionApp::plateRecoResults(string picPath){
	// vector<string> ans;
	vector<string> res;
	map<string, int> strMap;
	res = easypr::api::plate_recognize(picPath.c_str(), 
		"resources/model/svm.xml",
		"resources/model/ann.xml",
		true);
	for(auto s: res){
		// ans.push_back(s);
		cout<<"Plate: "<<s<<endl;
		strMap[s]++;
	}
	for(auto s: res){
		cout<<s<<": "<<strMap[s]<<endl;
	}
	return res;
}

vector<string> PlateRecognitionApp::plateRecoResults(Mat img){
  assert(!img.empty());
  easypr::CPlateRecognize pr;
  pr.LoadSVM("resources/model/svm.xml");
  pr.LoadANN("resources/model/ann.xml");
  pr.setLifemode(true);
  pr.setDebug(false);
  std::vector<std::string> results;
  pr.plateRecognize(img, results);
  return std::move(results);
}

vector<Mat> PlateRecognitionApp::getAllPlateImg(string picPath){
	vector<Mat> res = easypr::api::plate_locate(picPath.c_str());
	string windowNameSuffix = "a";
	for(auto m: res){
		namedWindow("plate-"+windowNameSuffix, WINDOW_AUTOSIZE);
        imshow("plate-"+windowNameSuffix, m);
        windowNameSuffix[0]++;
        // break;
	}
	waitKey();
	return res;
}

