#include"BMI.h"
float Record::get(float height,float weight){
	return weight/height/height;
}
int Record::set(float BMI){
	if(BMI<15) return 1;
	if(BMI>=15&&BMI<16) return 2;
	if(BMI>=16&&BMI<18.5) return 3;
	if(BMI>=18.5&&BMI<25) return 4;
	if(BMI>=25&&BMI<30) return 5;
	if(BMI>=30&&BMI<35) return 6;
	if(BMI>=35&&BMI<40) return 7;
	if(BMI>=40) return 8;
}
