/*
 * findFilePath.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: burak
 */

#include "findFilePath.h"

int findFilePath::fileList(string folderPath, string* filePaths)
{
	path p(folderPath);

	try
	{
		if (exists(p))    // does p actually exist?
		{
			if (is_regular_file(p))        // is p a regular file?
				cout << p << " size is " << file_size(p) << '\n';

			else if (is_directory(p))      // is p a directory?
			{
				//cout << p << " is a directory containing:\n";

				typedef vector<path> vec;             // store paths,
				vec v;                              // so we can sort them later

				copy(directory_iterator(p), directory_iterator(),
						back_inserter(v));

				sort(v.begin(), v.end());     // sort, since directory iteration
											  // is not ordered on some file systems

				int i = 0;

				for (vec::const_iterator it(v.begin()), it_end(v.end());
						it != it_end; ++it)
				{
					//cout << "   " << *it << '\n';
					filePaths[i] = it->string();
					//fileNames[i] = path(it->string()).filename();
					i++;
				}

				return i;
			}
			else
				cout << p
						<< " exists, but is neither a regular file nor a directory\n";
		}
		else
			cout << p << " does not exist\n";
	}

	catch (const filesystem_error& ex)
	{
		cout << ex.what() << '\n';
	}
}
