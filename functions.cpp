/*
 * 
 * 
 * 
 * 
 */

/* 
 * File:   functions.cpp
 * Author: Mehul Gupta
 */

#include "functions.h"

void turnAndDisplayCar(Car *myCar){

    std::cout << "Speed: " << myCar->getSpeed() << "m/s" << std::endl;
    std::cout << "Weight: " << myCar->getWeight() << "kg" << std::endl;
    std::cout << "Force: " << myCar->getForceOnSteeringWheel() << "N" << std::endl;
    std::cout << "Tire Turn Angle: " << myCar->determineTireTurnAngle() << "degrees" << std::endl;
    std::cout << "General Direction: " << myCar->determineGeneralDirection() << std::endl;
    std::cout << std::endl;

}

void turnAndDisplayStudentRacecar(StudentRacecar *myStudentRacecar){
	int student_record;
	
    std::cout << "Speed: " << myStudentRacecar->getSpeed() << "m/s" << std::endl;
    std::cout << "Weight: " << myStudentRacecar->getWeight() << "kg" << std::endl;
    std::cout << "Force: " << myStudentRacecar->getForceOnSteeringWheel() << "N" << std::endl;
    std::cout << "University: " << myStudentRacecar->getUniversity() << std::endl;
    std::cout << "Tire Turn Angle: " << myStudentRacecar->determineTireTurnAngle() << "degrees" << std::endl;
    std::cout << "General Direction: " << myStudentRacecar->determineGeneralDirection() << std::endl;
    std::cout << "Are you the fastest racer in your university?: ";
    student_record = myStudentRacecar->getStudentSpeedRecord();
	if (student_record == BEAT_RECORD) {
        std::cout << "Congrats, you beat your Universities Speed Record!";
	} else if (student_record == NOT_BEAT_RECORD) {
        std::cout << "Unfortunately you failed to beat your University's Speed Record this time'";
	} else {
	    std::cout << "Unable to determine";
	}
    std::cout << std::endl;
}

