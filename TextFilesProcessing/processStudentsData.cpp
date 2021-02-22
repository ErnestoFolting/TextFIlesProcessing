#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "student.h"

using namespace std;

string getNameOfDirectory()
{
	cout<<"Please, enter the name of directory: ";
	string directory;
	cin>>directory;
	return directory;
}

vector<student> processDirectoryWithStudentsData(string directory)
{
	vector <string> files, allStudents;
	for (const auto & entry : filesystem::directory_iterator(directory))
        files.push_back(entry.path().string());
	for(int i=0;i<files.size();i++)
	{
		student studentData;
		ifstream fIn(files[i]);
		fIn>>studentData.lastName;
		fIn.ignore();
		unsigned int sumOfGrades=0;
		for(int j=0;j<5;j++)
		{
			int grade;
			fIn>>grade;
			sumOfGrades+=grade;
			fIn.ignore();
		}
		studentData.averageScore=sumOfGrades/5.0;
		
		
	}
}

