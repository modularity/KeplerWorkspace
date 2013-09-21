/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: IllegalArgumentException.h

Date: 8/29/13

*/
#pragma once
#include <stdexcept>
#include <string>
using namespace std;

class IllegalArgumentException : public invalid_argument {

public:
	IllegalArgumentException(const string &msg);

};
