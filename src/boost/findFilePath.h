/*
 * findFilePath.h
 *
 *  Created on: Sep 4, 2013
 *      Author: burak
 */

#ifndef FINDFILEPATH_H_
#define FINDFILEPATH_H_

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>

using namespace std;
using namespace boost::filesystem;

class findFilePath
{
public:
	int fileList(string, string*);
};

#endif /* FINDFILEPATH_H_ */
