#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "ETF.h"


using namespace std;

#define M_PI 3.14159265358979323846
#define SIGMA_RATIO 1.6 
#define BINARIZATION_THRESHOLDING 200
#define BIAS 200
#define STEPSIZE 1.0

class CLD
{
public:
	CLD();
	CLD(cv::Size);
	void init(cv::Size);
	void readSrc(string);
	void genCLD();

	// Perform eq.(6) on each pixel
	void gradientDoG(cv::Mat& src, cv::Mat& dst, const double rho, const double sigma_c);

	// Perform eq.(9) on each pixel
	void flowDoG(cv::Mat& src, cv::Mat& dst, const double sigma_m);
 	
	// eq.(10)
	void binaryThresholding(cv::Mat& src, cv::Mat& dst, const double tau);

	// re-initialize the filter input by superimposing the black edge pixels of the previous binary output upon the original image I
	void combineImage();

	cv::Mat originalImg;
	cv::Mat DoG;
	cv::Mat FDoG;
	cv::Mat result;
	ETF etf;

	double sigma_c;
	double sigma_m;
	double rho;
	double tau;

};