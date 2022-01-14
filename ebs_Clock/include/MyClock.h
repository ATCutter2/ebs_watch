/*
 * MyClock.h
 * Set Analog Clock via Stepper
 * Created: 23/12/2021 09:33:43
 *  Author: a
 */ 


#ifndef MYCLOCK_H_
#define MYCLOCK_H_
struct Step{
	bool a: 1;
	bool b: 1;
	bool c: 1;
	bool d: 1;
};

class MyStepper{
	//int SteppermotorPin
	private:
	int pin_a,pin_b,pin_c,pin_d;
	int stepPointer;
	Step unipolar[8] = { //may also be solved with bit shifting ones but this is more readable
		{1,0,0,0},  //1
		{1,1,0,0},  //2
		{0,1,0,0},  //3
		{0,1,1,0},  //4
		{0,0,1,0},  //5
		{0,0,1,1},  //6
		{0,0,0,1},  //7
		{1,0,0,1}   //8
	};
//	Step bipolar[8] = { //may also be solved with bit shifting ones but this is more readable
//		{1,0,0,0},  //1
//		{1,1,0,0},  //2
//		{0,1,0,0},  //3
//		{0,1,1,0},  //4
//	};
	Step *motorType;
	
	void nextStep(bool direction);
	public:
	MyStepper(int a, int b, int c, int d);
	void step(int Steps);
};
#define CLOCK_WISE         1
#define COUNTER_CLOCK_WISE 0
	void MyStepper::nextStep(bool direction){
		//Step in the correct direciton
		if (direction){ stepPointer++;}
		else{			stepPointer--;}
		//loop around
		if (stepPointer<0){ stepPointer = 7;}
		if (stepPointer>7){ stepPointer = 0;}
	}
	MyStepper::MyStepper(int a, int b, int c, int d){
		 pin_a = a;
		 pin_b = b;
		 pin_c = c;
		 pin_d = d;
	}
	void MyStepper::step(int steps){
		bool dir = CLOCK_WISE;
		if(steps<0){
			dir = COUNTER_CLOCK_WISE;
			steps *=-1; //make positive
		}
		for(int i = 0;i <steps; i++){
			nextStep(dir);
		}

	}

class MyClock{
	
	public:
	/************************************************************************/
	/* Allow Setting of Arms via Encoder    
	Needs Paralellprocessing                                                                 */
	/************************************************************************/
	void adjustTimeArms();
	/************************************************************************/
	/* Set Time To this Number                                                                     */
	/************************************************************************/
	void setTime();
	




#endif /* MYCLOCK_H_ */