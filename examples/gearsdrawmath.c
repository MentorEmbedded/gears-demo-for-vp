#include "gearsdrawmath.h"

GLfloat gearsDrawMathIdentity(GLfloat angle) {
	return angle;
}

GLfloat gearsDrawMathNine(GLfloat angle) {
	GLfloat newAngle;
	newAngle = -2.0*angle-10.0;
	return (newAngle);
}

GLfloat gearsDrawMathTwentyFive(GLfloat angle){
	GLfloat newAngle;
	newAngle = -2.0*angle-25.0;
	return (newAngle);
}
