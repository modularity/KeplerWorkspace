
#pragma once
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
//#include <vector>
using namespace std;

class ParallelTeam {
public:
	//ParallelTeam();
	//creates 'n' operating system processes
	//creates log for each PID created and its execution time
	void createProcessTeam(int n);

	//Prints a one line csv banner to the console containing:
	//PPID, PID, Date & Time of launch, its sleep time
	void displayProcessResults(int i);
private:
	//vector<pid_t> pidSet;
	//const int SIZE = 100;
	pid_t* pidSet;
	time_t* execTime;
	time_t* sleepTime;
	time_t* timer;

	time_t* startTime;


	//generates a random# 7-35, for seconds to sleep before exiting
	time_t getRandomPause();

};
