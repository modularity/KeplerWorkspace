/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeam.cpp

Date: 9/19/13


Behaviors:
1) a method createProcessTeam(int n) that creates "n" operating system processes.

2) The class should keep track the process identification (PID) of launched processes and the execution time
	(the amount of time a process runs until terminated).

3) Each process should generate a random number between 7 and 35 which is the number of seconds it should sleep before exiting.

4) Each process should print a one line banner to the console of comma separated values containing:

PPID, PID, Date & Time of launch, its sleep time



*/
#include "ParallelTeam.h"

///ParallelTeam::ParallelTeam()

//creates 'n' operating system processes
//creates log for each PID created and its execution time
void ParallelTeam::createProcessTeam(int n) {
	//collection ready to store
	pidSet = new pid_t[ n ];
	sleepTime = new time_t[ n ];
	startTime = new time_t[ n ];
	execTime = new time_t[ n ];



	//create a new process
	//store PID, start time
	pid_t pid;
	for (int i=0; i < n; i++) {
		pid = fork();
		//check if child
		if (pid == 0) {
			//generate/store random # - sleeping
			time(timer);
			startTime[i] = *timer;
			sleepTime[i] = getRandomPause();

			//sleep for that time
			wait( *sleepTime[i] );
			displayProcessResults(i);
		}
	}

	//check for when sleep over -> update execTime and print banner for PID

}

//generates a random# 7-35, for seconds to sleep before exiting
time_t ParallelTeam::getRandomPause() {
	return (time_t) rand() % 35 + 7;
}

//Prints a one line csv banner to the console containing:
//PPID, PID, Date & Time of launch, its sleep time
void ParallelTeam::displayProcessResults(int i) {
	pid_t parent = getppid();
	cout << "PPID: "<< parent << ", " << endl;
	cout << "PID: "<< pidSet[i] << ", " << endl;
	cout << "Date/Time launched: "<< startTime[i] << ", " << endl;
	cout << "Sleep time: "<< sleepTime[i] << endl;
}


