#include "opencv2/opencv.hpp"
#include "EyeTracker.h"

#include "HoughDetector.h"
#include "ThresholdDetector.h"

using namespace cv;
using namespace std;


int main(int argc, char **argv)
{
	/*EyeTracker eyeTrackerApplication(argc, argv);
	eyeTrackerApplication.applicationModulesInit();
	eyeTrackerApplication.startApplicationLoop();
	eyeTrackerApplication.applicationModulesDeinit();*/
	
	
	//HoughDetector hDetector;
	ThresholdDetector tDetector;
	
	
	//20 LUX
	//Point reference(38, 18); //TOP
	//Point reference(44, 23); //BOTTOM
	//Point reference(36, 19);  //CENTER
	//Point reference(41, 16); //LEFT
	//Point reference(27, 18); //RIGTH

	//130 LUX
	//Point reference(42, 22); //TOP
	//Point reference(43, 24); //BOTTOM
	//Point reference(40, 18);  //CENTER
	//Point reference(35, 18); //LEFT
	//Point reference(45, 19); //RIGTH

	//320 LUX
	//Point reference(34, 16); //TOP
	//Point reference(38, 22); //BOTTOM
	//Point reference(39, 18);  //CENTER
	Point reference(33, 16); //LEFT
	//Point reference(38, 18); //RIGTH

	int valid = 0;
	int invalid = 0;

	for (int i = 0; i < 100; i++) {
		stringstream ss;
		stringstream fileSaveNameStream;
		ss << "C:\\Users\\mszcz_000\\Desktop\\eye_test_images\\20_lx_bottom\\test_" << i << ".jpg";
		fileSaveNameStream << "reusult_" << i << ".jpg";

		Mat img = imread(ss.str(), 1);

		cvtColor(img, img, CV_BGR2GRAY);
		Point d = tDetector.detect(img);
	
		//circle(img, d, 10, Scalar(255, 255, 255), 2);

		int dx = abs(d.x - reference.x);
		int dy = abs(d.y - reference.y);

		std::cout << "DX : " << dx << "DY: " << dy << std::endl;
		imwrite(fileSaveNameStream.str(), img);
		 
		if (dx <= 6 && dy <= 4)
			valid++;
		else
			invalid++;

		imshow("Debug1", img);
		waitKey(5);
	}

	std::cout << "===============================TEST RESULT=====================================" << std::endl;
	std::cout << "VALID : " << valid << std::endl;
	std::cout << "INVALID :" << invalid << std::endl;

	system("pause");
	
	return 0;
}