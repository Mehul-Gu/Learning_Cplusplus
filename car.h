/* 
 File: car.h
 Author: Mehul Gupta
 Coding 02
 Purpose: This is the header file for the superclass car. This class contains the attributes speed, weight and 
 force on steering wheel. The methods will be determine tire turn angle and determine direction.
 All values are in metric
*/

#ifndef CLASSES_CAR_H
#define CLASSES_CAR_H

// some parameters for the program and the calculations - defining here for this particular assignment
#define min_speed 1
#define min_weight 1000
#define min_force -1000
#define max_force 1000

#include <iostream>

class Car {

    public:
    /*
     * constructors
     * one with no params, one with params (overloading)
     */
    Car();
    Car(int, int, int);

    //destructor (not used)
    ~Car();

    // Getters
    int getSpeed();
    int getWeight();
    int getForceOnSteeringWheel();
    
    /*
     * Calculated Methods (Getters)
     */
    int determineTireTurnAngle();
    const char* determineGeneralDirection();

    /*
     * Setters
     */
    void setSpeed(int);
    void setWeight(int);
    void setForceOnSteeringWheel(int);

protected:
	
    //private variables that define a car
    // tire_turn_angle represents the current 
    int speed, weight, force, tire_Turn_Angle;
    
    //this variable is being initialized here to be used in the determinedirection method
    int general_Direction = 0;   // zero indicates going straight North
    
    //various angles represented as fractions out of 360 degrees. These are being used in the 
	//determinedirection method in an algorithm to calculate which quadrant the car object is facing
	const float angle_45_deg = 0.125;
	const float angle_0_deg = 0;
	const float angle_90_deg = 0.25;
	const float angle_135_deg = 0.375;
	const float angle_180_deg = 0.5;
	const float angle_225_deg = 0.625;
	const float angle_270_deg = 0.75;
	const float angle_315_deg = 0.875;
	
	//student racecars and cars in general dont have their tires go much above 30ish degrees.
	const int max_tire_turn_angle = 30;
	
	//the below variable is an adjustment constant for the formula used for the car class
	//this is based on the steering ratio and power steering and is a constant needed to have 
	//the very rough not accurate calculations make sense.
	const int adjustment_constant = 20000;
	
	//both these literals are used in the algorithm in determingGeneralDirection
	const int quandrant_ratio_45_deg = 45;
	const float quadrant_ratio_divide_by_8 = 8.0;
};

#endif //CLASSES_CAR_H
