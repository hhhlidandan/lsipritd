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
cout<<"\n����:"<<getnum()<<"\n��ѧ�ɼ�:"<<getmathScore()<<"Ӣ��ɼ�:"<<getenglishScore()<<endl;
}
void ShowStatic(){
cout<<"\nѧ��:"<<getcount()<<"\n��ѧ�ܳɼ�:"<<getmathTotalScore()<<"\nӢ���ܳɼ�:"<<getenglishTotalScore()<<endl;
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
