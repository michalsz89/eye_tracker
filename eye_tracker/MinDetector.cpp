#include "MinDetector.h"

MinDetector::MinDetector()
{
	this->kernel = getStructuringElement(CV_SHAPE_ELLIPSE, Size(3, 3));
	//hDetector.showSettingsWin();
}

MinDetector::~MinDetector()
{
	//
}

Point MinDetector::detect(Mat src, Point &relativeCenter, Point rel, int &dx, int &dy)
{
	double factor = 1.47;
	int minSize = 150;

	Point minLoc, refminLoc;

	if (src.empty())
		return Point(-1, -1);

	
	normalize(src, src, 0, 255, NORM_MINMAX, CV_8UC1);
	//dilate(src, src, this->kernel);
	Mat forRelative = src.clone();
	resize(forRelative, forRelative, Size(minSize, minSize / factor));

	minMaxLoc(src, NULL, NULL, &minLoc, NULL);
	minMaxLoc(forRelative, NULL, NULL, &refminLoc, NULL);

	//circle(src, minLoc, 10, Scalar(255, 255, 255), 2);
	//circle(forRelative, refminLoc, 10, Scalar(255, 255, 255), 2);

	imshow("EYE1", src);
	imshow("EYE2", forRelative);

	relativeCenter = refminLoc;
	dx = abs(rel.x - refminLoc.x);
	dy = abs(rel.y - refminLoc.y);

	return minLoc;
}