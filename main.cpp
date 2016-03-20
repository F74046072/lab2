#include<iostream>
#include<fstream>
#include<iomanip>
#include"BMI.h"
using namespace std;

int main(){
	ifstream Read("file.in",ios::in); //從file.in讀入
	if(!Read){
		cerr<<"fail to read"<<endl;
	}
	ofstream Write("file.out",ios::out); //輸出至file.out
	if(!Write){
		cerr<<"fail to write"<<endl;
	}

	Record Rec;
	float height,weight,BMI;
	cout<<"檔案處理中..."<<endl;
	while(Read>>height>>weight){ //每行讀入到height、weight
		if(height==0&&weight==0) break; //終止條件
		else{
			BMI=Rec.get(height/100,weight); //身高轉為公尺，利用get傳回BMI
			switch(Rec.set(BMI)){ //利用setprecision控制BMI精確值
				case 1: Write<<setprecision(4)<<BMI<<"\t"<<"Very severely underweight"<<endl; break;
				case 2: Write<<setprecision(4)<<BMI<<"\t"<<"Severly underweight"<<endl; break;
				case 3: Write<<setprecision(4)<<BMI<<"\t"<<"Underweight"<<endl; break;
				case 4: Write<<setprecision(4)<<BMI<<"\t"<<"Normal"<<endl; break;
				case 5: Write<<setprecision(4)<<BMI<<"\t"<<"Overweight"<<endl; break;
				case 6: Write<<setprecision(4)<<BMI<<"\t"<<"Obese Class I (Moderately obese)"<<endl; break;
				case 7: Write<<setprecision(4)<<BMI<<"\t"<<"Obese Class II (Severely obese)"<<endl; break;
				case 8: Write<<setprecision(4)<<BMI<<"\t"<<"Obese Class III (Very severely obese)"<<endl; break;
			}
		}
	}
	cout<<"檔案處理完成！"<<endl;
	return 0;
}

