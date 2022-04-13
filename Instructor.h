#pragma once
#include <string>
#include <map>
#include <vector> 
#include <iostream>

using namespace std;

class Instructor
{
public:
	Instructor();

	Instructor(int insId, shared_ptr<string> lecture);

	int getInsId() const;

	string getLecture() const;

private:
	int id;
	shared_ptr<string> lecture;
};

