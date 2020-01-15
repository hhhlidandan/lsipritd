#include<iostream>

using namespace std;
class student{
private:
char *name;
int num,mathScore,englishScore;
static int count,englishTotalScore,mathTotalScore;
public:
student(char *a,int b,int c,int d):num(b),mathScore(c),englishScore(d){
name=a;
count++;
mathTotalScore+=c;
englishTotalScore+=d;


}
int getcount(){return count;}
int getmathTotalScore(){
return mathTotalScore;
}
int getenglishTotalScore(){
return englishTotalScore;
}
int getnum(){return num;}
int getmathScore(){return mathScore;}
int getenglishScore(){return englishScore;}
char *getname(){
return name;
}
void showbase(){
getname();
cout<<"\n姓名:"<<getnum()<<"\n数学成绩:"<<getmathScore()<<"英语成绩:"<<getenglishScore()<<endl;
}
void ShowStatic(){
cout<<"\n学号:"<<getcount()<<"\n数学总成绩:"<<getmathTotalScore()<<"\n英语总成绩:"<<getenglishTotalScore()<<endl;
}
};
int student::englishTotalScore=0;
int student::mathTotalScore=0;
int student::count=0;
int main()
{
student s[2]={student("asd",1,90,80),student("qwe",2,99,88)};
s[0].showbase();
s[1].showbase();
s[0].ShowStatic();
s[1].ShowStatic();
}
