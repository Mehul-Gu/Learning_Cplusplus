/* 
 File: car.cpp
 Author: Mehul Gupta
 Coding 02
 Purpose: This is the cpp file for the superclass car. This class will contain the attributes speed, weight and 
 force on steering wheel. The methods will be determine tire turn angle and determine direction.
 All values are in metric
*/

#include "car.h"

//constructor with no parameters
//both constructors use Setter methods in order to internally find and save the attributes of the objects
Car::Car() {
    setSpeed(min_speed);
    setWeight(min_weight);
    setForceOnSteeringWheel(min_force);
}

//constructor with parameters
Car::Car(int s, int w, int f) {
    setSpeed(s);
    setWeight(w);
    setForceOnSteeringWheel(f);
}

//destructor (not used)
Car::~Car() {
}

//Getters for speed, weight and forceonsteeringwheel used in functions.cpp
int Car::getSpeed() {
    return speed;
}

int Car::getWeight() {
    return weight;
}

int Car::getForceOnSteeringWheel() {
    return force;
}

//This method will calculate the tire turn angle based on the set force, weight and speed
int Car::determineTireTurnAngle() {
	
	//Since actually calculating tire turn angle is complicated. I'm also 
    //just going to fudge the numbers but will make them correlate reasonably well to reality
	tire_Turn_Angle = ((force*adjustment_constant)/(speed*weight));
	
	//some conditions include that tire turn angle has to be between -30 and +30 degrees
	//as that's around what most cars allow. -30 implies turning left and +30 implies turning right
	if (tire_Turn_Angle > max_tire_turn_angle) {
		tire_Turn_Angle = max_tire_turn_angle;
	}
	if (tire_Turn_Angle < -max_tire_turn_angle) {
		tire_Turn_Angle = -max_tire_turn_angle;
	}
	return tire_Turn_Angle;
	
}

//This method will calculate the general direction of the car (north, east, west and south).
//This is being found using quadrants (ie. if the car is facing between -45 to 45 degrees than it is north)
const char* Car::determineGeneralDirection() {

	//This statement haves the direction term being added while calling an object multiple times
	//I did this in order to test different directions (as we cap the tire turn angle to 30 deg)
	//and the car has to be facing at least 45 degrees to change the direction
	general_Direction = general_Direction + tire_Turn_Angle;
	
	//The rest of the method is running an algorithm I thought of in order to find the quadrant the car is
	//facing. It's a little strange but I'm basically truncating the angle the car is facing and checking direction
	int find_Range = general_Direction / quandrant_ratio_45_deg;
	float find_Direction = (float(find_Range) / quadrant_ratio_divide_by_8);
	int integer_Part = find_Direction;
	float decimal_Part = find_Direction - integer_Part;
	
	//all the angles here are divided by 360 degrees. I read that using if statements with floats is considered
	//bad practice (since a float can be slightly off). Based on my algorithm I'm fairly certain its impossible
	//for a number to not equal to one of the below scenarios leaving me feeling comfortable using this
	const char* Direction;
	if (decimal_Part == angle_0_deg || decimal_Part == angle_315_deg || decimal_Part == -angle_315_deg) {
		Direction = "North";
	} else if (decimal_Part == angle_45_deg || decimal_Part == angle_90_deg) {
		Direction = "East";
	} else if (decimal_Part == angle_135_deg || decimal_Part == angle_180_deg || decimal_Part == -angle_135_deg || decimal_Part == -angle_180_deg) {
		Direction = "South";
	} else if (decimal_Part == angle_225_deg || decimal_Part == angle_270_deg) {
		Direction = "West";
	} else if (decimal_Part == -angle_45_deg || decimal_Part == -angle_90_deg) {
		Direction = "West";
	} else if (decimal_Part == -angle_225_deg || decimal_Part == -angle_270_deg) {
		Direction = "East";
	} else {
		Direction = "Error - Something went wrong when trying to find the direction";
	}

	return Direction;
}

void Car::setSpeed(int s) {
    //setters are where you keep your protections for attributes
    if (s > min_speed) {
        speed = s;
    } else {
        speed = min_speed;
    }
}

void Car::setWeight(int w) {
    //setters are where you keep your protections for attributes
    if (w > min_weight) {
        weight = w;
    } else {
        weight = min_weight;
    }
}

void Car::setForceOnSteeringWheel(int f) {
    //setters are where you keep your protections for attributes
    //this setter is unique in having both a max and min bound since a negative force
    //corresponds to a left turn in my algorithm in the method determineGeneralDirection
    if (f > min_force && f < max_force) {
        force = f;
    } else {
        force = min_force;
    }
}
