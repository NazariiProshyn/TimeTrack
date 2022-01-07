# TimeTrack
The TimeTrackingReport folder implements a test task using the IDE visual studio.
The same code is implemented in the CrossPlatform folder, but with vs code and cmake.
Columns in the input file may be modified by cities, or may be missing altogether. The main thing is to have columns: "Name", "Date", "Logged Hours".
At the beginning of the program you need to enter the file name, you can enter immediately with the extension ".csv" or without it and the program will add it to the path itself.
The program implements the exception class in case of entering an incorrect file name or the absence of any of the above columns.
Implemented validation of data for the month, day, hours specified by the employee.
The program has a simple example of a logger that records the main events in the Log.txt file
