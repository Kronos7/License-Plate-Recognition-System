/*
 * preprocess.h
 *
 *  Created on: Aug 23, 2013
 *      Author: burak
 */

#ifndef PREPROCESS_H_
#define PREPROCESS_H_

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;


class preprocess {
public:
	Mat resizing(Mat, double, double);
};

#endif /* PREPROCESS_H_ */
