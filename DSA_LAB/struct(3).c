#include <stdio.h>
#include<stdlib.h>
 
struct Student{
	char name[50];
	int rollno;
	char addr[150];
};
int main(){
	
    	struct Student s1 = {"Parth Sood",252,"Vadodara"};
    	printf("%s, %d, %s",s1.name, s1.rollno , s1.addr);
	return 0;
}
