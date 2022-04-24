#ifndef INPUT_H_ 
#define INPUT_H_

class Variables{
	public:
	float N,T,Et,alpha,deltaT,lenght,width,NUS,force,ProbHole; //NUS- number of slices
	bool obiekt; // elektron lub czastka true = czastka false = dziura

	Variables(float a, float b, float c, float d, float e, float f, float g, float h, float i, bool j){
		N=a;
		T=b;
		Et=c;
		alpha=d;
		lenght=e;
		width=f;
		NUS=g;
		force=h;
		ProbHole=i;
		obiekt=j;
	}
};

#endif