/*
 * This is a simple application to demonstrate classes and objects in C++.
 * Note the header structure and files for all cpp and h files.
 * The only thing included in main.cpp is it's main.h file.
 * This file, main.cpp, includes only main.h.
 */

/* 
 * File:   main.cpp
 * Author: Alex Katrompas
 */

#include "main.h"

int main(int argc, char** argv) {
    //creates a rectangle object with no parameters
    Car myCar1(40, 1000, 50);
    Car myCar2;
    Car myCar3(10, 1000, 80);
    Car myCar4(-50, -1, 10000000);
    Car myCar5(40, 1000, -50);

	StudentRacecar myStudentRacecar1(55, 100, 50, UT);
	StudentRacecar myStudentRacecar2(100000, -1000, 1234567, UNIVERSITY_NOT_IN_SCOPE);
	StudentRacecar myStudentRacecar3(40, 1000, 50, A_AND_M);
	StudentRacecar myStudentRacecar4;
    //examples of passing objects by reference
    
    // for each car, will call turn the steering wheel, we'll (1) determine the associated tire angle
	// and (2) determine the new direction (for student records we'll also see if they set a new speed record)
       
    //first turn of steering wheel
    std::cout << "Think of this program simulating a car driving. As the person turns the wheel, the direction the car faces changes over time" << std::endl;
    std::cout << "First turn of Car 1 until the car is pointing the direction of the tire turn angle - " << std::endl;
	turnAndDisplayCar(&myCar1);

    //second turn of steering wheel
    std::cout << "Second turn of Car 1 until the car is pointing the direction of the tire turn angle - " << std::endl;
	turnAndDisplayCar(&myCar1);
	
    std::cout << "First turn of Car 2 until the car is pointing the direction of the tire turn angle - " << std::endl;
    std::cout << "The object myCar2 has not been initialized here" << std::endl;
	turnAndDisplayCar(&myCar2);
    
    std::cout << "First turn of Car 3 until the car is pointing the direction of the tire turn angle - " << std::endl;
	turnAndDisplayCar(&myCar3);
	
    std::cout << "First turn of Car 4 until the car is pointing the direction of the tire turn angle - " << std::endl;
    std::cout << "The object myCar4 has numbers well out of reality" << std::endl;
	turnAndDisplayCar(&myCar4);
	
	std::cout << "First turn of Car 5 until the car is pointing the direction of the tire turn angle - " << std::endl;
    std::cout << "This time Car 5 will turn left multiple times to test if the direction changes to west" << std::endl;
	turnAndDisplayCar(&myCar5);

    std::cout << "Second turn of Car 5 until the car is pointing the direction of the tire turn angle - " << std::endl;
	turnAndDisplayCar(&myCar5);
	
	//test case of student racecar weight not changing from normal car
	//test case of random university
	//test case of no university input
	//test case of a university
	std::cout << "We're now looking at the student racecar class objects" << std::endl;
	std::cout << "First turn of Student Racecar 1 until the car is pointing the direction of the tire turn angle - " << std::endl;
	std::cout << "This Student Racecar 1 object is a nominal scenario - " << std::endl;
	turnAndDisplayStudentRacecar(&myStudentRacecar1);
    
	std::cout << "First turn of Student Racecar 2 until the car is pointing the direction of the tire turn angle - " << std::endl;
	std::cout << "This Student Racecar 2 object has all of its parameters well out of reality - " << std::endl;
	turnAndDisplayStudentRacecar(&myStudentRacecar2);
    
	std::cout << "First turn of Student Racecar 3 until the car is pointing the direction of the tire turn angle - " << std::endl;
	std::cout << "This Student Racecar 3 object has the same parameters as the Car object (checking the override of tire turn angle) - " << std::endl;
	turnAndDisplayStudentRacecar(&myStudentRacecar3);
	
	std::cout << "First turn of Student Racecar 4 until the car is pointing the direction of the tire turn angle - " << std::endl;
	std::cout << "This Student Racecar 4 object has no inputs - " << std::endl;
	turnAndDisplayStudentRacecar(&myStudentRacecar4);	
    
    return 0;
}
