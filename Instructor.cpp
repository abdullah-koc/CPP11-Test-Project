#include "Instructor.h"

Instructor::Instructor()
{
}

Instructor::Instructor(int insId, shared_ptr<string> lecture)
{
	id = insId;
	this->lecture = lecture;
}

int Instructor::GetInsId() const
{
	return id;
}

string Instructor::GetLecture() const
{
	return *lecture;
}


