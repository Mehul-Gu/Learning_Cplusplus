/* 
 File: car.cpp
 Author: Mehul Gupta
 Coding 02
*/

#include "student_racecar.h"

StudentRacecar::StudentRacecar() {
    setSpeed(min_speed);
    setWeight(min_weight);
    setForceOnSteeringWheel(min_force);
    setUniversity(UNDEFINED);
}

StudentRacecar::StudentRacecar(int s, int w, int f, int u) {
    setSpeed(s);
    setWeight(w);
    setForceOnSteeringWheel(f);
    setUniversity(u);
}

StudentRacecar::~StudentRacecar() {
}

int StudentRacecar::getUniversity() {
    return university;
}

int StudentRacecar::getWeight() {
    return weight;
}

// this is an example of overriding a method. The difference is that in this method the adjustment
// constant is a much lower number for racecars to account for the lower weight
int StudentRacecar::determineTireTurnAngle() {
	
    //power steering is not enabled for the student car subclass. The tire turn angle is therefore way less
    //unless the weight is reduced massively to keep up with common student car weights
	tire_Turn_Angle = ((force*racecar_adjustment_constant)/(speed*weight));
	
	if (tire_Turn_Angle>30) {
		tire_Turn_Angle = 30;
	}
	if (tire_Turn_Angle<-30) {
		tire_Turn_Angle = -30;
	}
	return tire_Turn_Angle;
}

// +1 indicates beating the record, 0 indicates not beating the record, -1 indicates could not find
int StudentRacecar::getStudentSpeedRecord() {
	int beating_record = 0;
	if (university = ACC) {
        if (speed < ACC_speed_record) {
        	beating_record = NOT_BEAT_RECORD;
		} else {
			beating_record = BEAT_RECORD;
		}
    } else if (university == UT) {
    	if (speed < UT_speed_record) {
        	beating_record = NOT_BEAT_RECORD;
		} else {
			beating_record = BEAT_RECORD;
		}
    } else if (university == A_AND_M) {
    	if (speed < A_AND_M_speed_record) {
        	beating_record = NOT_BEAT_RECORD;
		} else {
			beating_record == BEAT_RECORD;
		}
    } else {
        beating_record = COULD_NOT_FIND;
    }
    return beating_record;
}

void StudentRacecar::setUniversity(int u) {
    //setters are where you keep your protections for attributes
    if ((u == ACC) || (u == UT) || (u == A_AND_M)) {
    	university = u;
    }
    else {
    	university = UNDEFINED;
	}	
}

// another example of overriding a method
void StudentRacecar::setWeight(int w) {
    //setters are where you keep your protections for attributes
    //the idea here is that a student racecar weight will not go beyond 100-300kgs. Therefore this effects
    //what the tire turn angle can go to overriding that method as compared to the superclass car
    if (w > min_student_racecar_weight && w < max_student_racecar_weight) {
        weight = w;
    } else {
        weight = min_student_racecar_weight;
    }
}
