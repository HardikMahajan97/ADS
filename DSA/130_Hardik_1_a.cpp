//Student data sorting Using Insertion Sort.
#include<iostream>
using namespace std;

class student
{
	int prn;
	string name;
	int age;
	float cgpa;
	public:
	void getData()
	{
		cout<<" Enter the Name, PRN, CGPA and age of the student:\n";
		cin>>name>>prn>>cgpa>>age;
	}
	
	void showData(int idx)
	{
		cout<<" Details of the student "<<idx<<" are:\n";
		cout<<" Name : "<<name<<endl<<" PRN : "<<prn<<endl<<" AGE : "<<age<<endl<<" CGPA : "<<cgpa<<endl;
	}
	friend void sortData(student *s, int size);
};

//Insertion Sort
void sortData(student *s, int size)
{
	for(int i = 1; i < size; i++){
		student key = s[i];
		int j = i-1;
		while(j>=0 && s[j].prn > key.prn){
			s[j+1] = s[j];
			j--;
		}
		s[j+1] = key;
	}
}


int main()
{
	cout<<" Enter the size of the students data : \n";
	int size;
	cin>>size;
	
	student s[size]; 
	for(int i = 0; i < size; i++){
		s[i].getData();
	}
	
	sortData(s, size);
	for(int i = 0; i < size; i++){
		s[i].showData(i+1);
	}
	return 0;
}