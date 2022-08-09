/*
 * 
 * 
 * 
 * 
 */

/* 
 * File:   student_racecar.h
 * Author: Mehul Gupta
 */

#ifndef CLASSES_STUDENT_RACECAR_H
#define CLASSES_STUDENT_RACECAR_H


#include "car.h"
#define min_student_racecar_weight 100
#define max_student_racecar_weight 300

#define BEAT_RECORD 1
#define NOT_BEAT_RECORD 0
#define COULD_NOT_FIND -1

#define ACC 1
#define UT 2
#define A_AND_M 3
#define UNIVERSITY_NOT_IN_SCOPE 999999999
#define UNDEFINED -1

class StudentRacecar : public Car {
public:
    StudentRacecar();
    StudentRacecar(int, int, int, int);
    ~StudentRacecar();

    /*
     * Getters
     */
    int getWeight();
    int getUniversity();
    int getStudentSpeedRecord();
    //Additional method which checks if the speed is above the record for that University. 
	//This is not something that can be tracked for a superclass such as car
    int determineTireTurnAngle();

    /*
     * Setters
     */
    void setUniversity(int);
	void setWeight(int);
private:
    //private variables that define a student racecar
    int university = UNDEFINED;
    
    // speed records per university
    int ACC_speed_record = 54;
    int UT_speed_record = 49;
    int A_AND_M_speed_record = 51;    std::string random_university = "RANDOM";
	  
    const int racecar_adjustment_constant = 2000; // racecars have a lower adjustment constant

};

#endif //CLASSES_STUDENT_RACECAR_H
