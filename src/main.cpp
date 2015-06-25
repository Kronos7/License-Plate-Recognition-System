#include <cv.h>
#include <highgui.h>
#include <cvaux.h>

#include <iostream>
#include <vector>

#include "boost/findFilePath.h"
#include "preprocess/preprocess.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	cout << "OpenCV Training SVM Automatic Number Plate Recognition\n";
	cout << "\n";

	//42.3083

	Mat classes; //(numPlates+numNoPlates, 1, CV_32FC1);
	Mat trainingData; //(numPlates+numNoPlates, imageWidth*imageHeight, CV_32FC1 );

	Mat trainingImages;
	vector<int> trainingLabels;

	string pImgs[150], nImgs[150];

	int nOfFilesP, nOfFilesN;

	preprocess pp;
	findFilePath fp;
	nOfFilesP = fp.fileList(argv[1], pImgs);
	for (int i = 0; i < nOfFilesP; i++)
	{
		Mat img = imread(pImgs[i], 0);
		img = pp.resizing(img, 144, 33);
		img = img.reshape(1, 1);
		trainingImages.push_back(img);
		trainingLabels.push_back(1);
	}

	nOfFilesN = fp.fileList(argv[2], nImgs);
	for (int i = 0; i < nOfFilesN; i++)
	{
		Mat img = imread(nImgs[i], 0);
		img = pp.resizing(img, 144, 33);
		img = img.reshape(1, 1);
		trainingImages.push_back(img);
		trainingLabels.push_back(0);
	}

	Mat(trainingImages).copyTo(trainingData);
	//trainingData = trainingData.reshape(1,trainingData.rows);
	trainingData.convertTo(trainingData, CV_32FC1);
	Mat(trainingLabels).copyTo(classes);

	FileStorage fs("SVM.xml", FileStorage::WRITE);
	fs << "TrainingData" << trainingData;
	fs << "classes" << classes;
	fs.release();

	cout << "Number of Positive Images: " << nOfFilesP << endl << "Number of Negative Images: " << nOfFilesN << endl;
	return 0;
}
