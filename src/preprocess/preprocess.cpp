/*
 * preprocess.cpp
 *
 *  Created on: Aug 23, 2013
 *      Author: burak
 */

#include "preprocess.h"

Mat preprocess::resizing(Mat src, double width, double heigth)
{
		Mat out;
		resize(src, out, Size(width, heigth), 0, 0, INTER_NEAREST);
		return out;
		out.release();
}
