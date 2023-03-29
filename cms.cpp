// Project- COLLEGE MANAGEMENT SYSTEM (CMS)
/* Cms is a command drive application that helps to maintain student and faculty records. It makes use of unique IDs and password to restrict the access and usage of different areas of the portal to its correct
 target audience. the faculty portal allows the faculties to update their profile, allocate the subjects to be taught.Likewise student portal helps to maintain student profile information ,including allocation and de
 allocation of subjects to the students. The admin protal is used for administrative purposes. It helps to make the user entry for the first time.*/

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <conio.h>
#include <bits/stdc++.h>
using namespace std;

char un[20];

// Designing Admin class
class Admin
{
	char name[20];
	int totsub;
	char subject[10][10];
	char mobile[15], mail[50], fname[20];
	char passwd[20], rpasswd[20];

public:
	char rollno[15];
	// this function is used to get the student data entry from the Admin portal. All the records, entries are made by this method.

	void getstdata()
	{
		cout << "\n Enter the Student Name :";
		gets(name);
		cout<<"\nEnter the Student ID/Roll No. : ";
		cin>>rollno;
		cout<<"|nEnter the Student Fatherr's Name :  ";
		gets(fname);
		cout<<"\nEnter the Mobile NUmber :  ";
		gets(mobile);
		cout<<"\nEnter the Email Id :  ";
		gets(mail);
		cout<<"\nEnter the Total Subjects :  ";
		cin>>totsub;
		for(int i = 0; i<totsub; i++){
			cout<<"\nEnter the Subject "<< i+1<<"Name : ";
			cin>>subject[i];
		}
		cout<<"\nCreate Your Login Password  :  ";
		cin>>passwd;
		cout<<"\nEnter the Unique Keyword to Recover Password : ";
		cin>>rpasswd;
		cout<<"\n\nPlease note your UserName is ID/ROll no.\n";
		
	}
	//this function aunthenticates the login of both the students & faculties. With their reference to their unique ID/PASSWORD login is provided.
	
	
	int login(){
		if((strcmp(::un,rollno))== 0){
			cout<<"\nEnter the Login Password:  ";
			int len = 0;
			len = strlen(passwd);
			char inputpasswd [20];
			int i;
			for( i= 0 ; i<len; i++){
				inputpasswd[i] = getch();
				cout<<"#";
			}
			inputpasswd[i] = NULL;
			//cout<<"\nThe Entered Password is "<<inputpasswd;
			if((strcmp(::un,rollno)==0)&& (strcmp(passwd,inputpasswd)==0)){
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}
	//this function help both the students & faculties to recover the password with the help of unique keyword provided by the Admin	
	
	
		
		int recover(){
			//cout<<"\nThe Input Username is" <<::un;
			char key[20];
			if(strcmp(::un,rollno)==0){
				cout<<"\nEnter the Unique Keyword (provided by Admin) :";
				cin>>key;
				if((strcmp(key,rpasswd)==0)){
					cout<<"\nYou are a Valid user.";
					cout<<"\nYour Password is "<<passwd;
					cout<<"\nPlease Exit To Login Again";
					return 1;
				}
				else{
					return 0;
				}
			}else{
				return 0;
			}
		}
		//this function displays the faculty profile to the faculty at their respective portals
		
		
		int faprofile(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nFaculty Name           :"<<name;
				cout<<"\nFaculty Father's Name  :"<<fname;
				cout<<"\nFaculty Mobile NO.     :"<<mobile;
				cout<<"\nFaculty E-Mail ID      :"<<mail;
				return 1;
			}else{
				return 0;
			}
		}
		
		//this function displays the different subjects of the facculty at their respective portals
		int knowfasub(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nFaculty Total Subjects:-"<<totsub;
				for(int i = 0; i<totsub; i++){
					cout<<"\n\tSubject "<<i+1<<":"<<subject[i];	
					}				
					return 1;	
				}else{
					return 0;
				}
		}
		
		// this function helps a faculty to add a subject in their module.
		
		
		void addfasub(){
			if((strcmp(::un,rollno))==0){
				cout<<"\nEnter the New Subject :";
				cin>>subject[totsub];
				totsub++;
				cout<<"\n\nNew Subject Added Successfully....";
			}
		}
		
		//this function helps a faculty to delete a subject from their module.
		
		
		void delfasub(){
			knowfasub();
			int de= 0;
			if((strcmp(::un,rollno))==0){
				if(totsub==0 || totsub<0){
					totsub=0;
					cout<<"\nNone Subjects Exist...";
					getch();
					exit(0);
				}
				if(de == totsub){
					totsub--;
					strcpy(subject[totsub]," ");
				}else if(totsub == 1){
					totsub = 0;
					strcpy(subject[totsub]," ");
				}else{
					de--;
					strcpy(subject[totsub]," ");
					for(int p=de;p<totsub; p++){
						strcpy(subject[p],subject[p+1]);
					}
					totsub--;
				}
				cout<<"\n Records Updated Successfullly .......";
			}
		}
		
		//this function helps a faculty to modify his personal profile.
		
		void modfaprofile(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nThe Profile Details are :  ";
				cout<<"\n 1. Faculty E-Mail : "<<mail;
				cout<<"\n 2. Faculty Mobile : "<<mobile;
				int g =-1;
				cout<<"\n\nEnter the Detail No. to be Modified  :";
				cin>>g;
				if(g==1){
					char nmail[50];
					cout<<"\nEnter the New Mail Address : ";
					strcpy(mail,nmail);
					cout<<"\nRecords Updated Successfully.....";
				}
				else if(g==2){
					char nmobile[15];
					cout<<"\nEnter the New Mobile NO.  : ";
					gets(nmobile);
					strcpy(mobile,nmobile);
					cout<<"\nRecords Updated Successfully....";
				}else{
					cout<<"\nInvalid Input Provided...";
				}
			}
		}
		
		
		//this function displays the student profile at the student portal 
		
		
		int stprofile(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nStudent Name             : "<<name;
				cout<<"\nStudent Father's Name    : "<<fname;
				cout<<"\nStudent Mobile No.       : "<<mobile;
				cout<<"\nStudent E-Mail ID        : "<<mail;
				return 1;
			}
			else{
				return 0;
			}
		}
		
		// this function displays the differen tenrolled subjects of the respective students.... according to their profile.
		
		int knowstsub(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nStudent Total Subjects :- "<<totsub;
				for(int i = 0; i<totsub; i++){
					cout<<"\n\tSubject  "<<i+1<<" : "<<subject[i];
				}
				return 1;
			}
			else{
				return 0;
			}
		}
		
		// this function allows the student to add a subjects in total subjects of the student profile....
		
		void addstsub(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nEnter the New Subject  : ";
				cin>>subject[totsub];
				totsub++;
				cout<<"\n\nNew Subject Added Successfully... ";
			}
		}
		
		// this function allows the student to delete a subjects in total subjects of the student profile....
		
		
		void delstsub(){
			
			knowstsub();
			int de = 0;
			if((strcmp(::un,rollno)==0)){
				if(totsub == 0 || totsub<0 ){
					totsub=0;
					cout<<"\nNone Subjects Exist...";
					getch();
					exit(0);
				}
				cout<<"\nEnter the Subject NO. to be Deleted: ";
				cin>>de;
				if(de==totsub){
					totsub--;
					strcpy(subject[totsub]," ");
				}
				else if(totsub == 1){
					totsub=0;
					strcpy(subject[totsub]," ");
				}
				else{
					de--;
					strcpy(subject[totsub]," ");
					for(int p=de;p<totsub; p++){
						strcpy(subject[p],subject[p+1]);
					}
					totsub--;
				}
				cout<<"\nRecords Updated Successfully....";
			}
		}
		
		
		//this function allows the student to modify their personal profile details at the student portal
		
		void modstprofile(){
			if((strcmp(::un,rollno)==0)){
				cout<<"\nThe Profile Details are : ";
				cout<<"\n 1. Student E-Mail  : "<<mail;
				cout<<"\n 2. Student Mobile  : "<<mobile;
				int g=-1;
				cout<<"\n\nEnter the Detail No. to be Modified : ";
				cin>>g;
				if(g==1){
					char nmail[50];
					cout<<"\nEnter  the New Mail Address  :  ";
					strcpy(mail,nmail);
					cout<<"\nRecords Updated Successfully.... ";
				}else if(g==2){
					char nmobile[15];
					cout<<"\nEnter the New Mobile NO. :   ";
					gets(nmobile);
					strcpy(mobile,nmobile);
					cout<<"\nRecords Updated Successfully... ";
				}
				else{
					cout<<"\n Invalid Input Provided..";
				}
			}
		}
		
		
		//this function allow the ADMIN to make a new record entry for the different new faclties.. new faculty records are updated with the
		// help of this function.
		
		void getfadata(){
			cout<<"\nEnter the Faculty Name  :  ";
			gets(name);
			cout<<"\nEnter the Faculty ID/Roll no. : ";
			cin>>rollno;
			cout<<"\nEnter the Faculty Father's Name : ";
			gets(fname);
			cout<<"\nenter the Mobile No.  : ";
			gets(mobile);
			cout<<"\nEnter the E-Mail Id : ";
			gets(mail);
			cout<<"\nenter the Total Subjects  :";
			cin>>totsub;
			//cout<<"\nThe total subjects choosen are : "<<totsub;
			for(int i = 0; i<totsub; i++){
				cout<<"\nEnter the Subject"<< i+1<<"Name  : ";
				cin>>subject[i];
			}
			cout<<"\nCreate Your Login Password  : ";
			cin>>passwd;
			cout<<"\nEnter the Unique Keyword to Recover Password :  ";
			cin>>rpasswd;
			cout<<"\n\nPlease note your UserName is ID/Roll no. \n";
		}
		
		//this function displays all the relevant information to the admin related to the students at the ADMIN portals.
		
		void stdisplay(){
			cout<<"\nStudent Name         : "<<name;
			cout<<"\nStudent ID/Roll NO.  : "<<rollno;
			cout<<"\nStudent Father's Name: "<<fname;
			cout<<"\nStudent Mobile No.   : "<<mobile;
			cout<<"\nStudent E-Mail       : "<<mail;
			cout<<"\nStudent Subjects     : "<<totsub;
			for(int i = 0; i<totsub; i++){
				cout<<"\n   Subject "<<i+1<<" : "<<subject [i];
			}
			if(totsub==0){
				cout<<"(None Subjects Specified ... )";
			}
		}
		
		//this function displays all the relevant information to the admin related to the faculty at the ADMIN portals
		
		
		void fadisplay(){
			cout<<"\nFaculty Name           : "<<name;
			cout<<"\nFaculty ID/Roll No.    : "<<rollno;
			cout<<"\nFaculty Father's Name  : "<<fname;
			cout<<"\nFaculty Mobile No.     : "<<mobile;
			cout<<"\nFaculty E-Mail Id.     : "<<mail;
			cout<<"\nFaculty Subjects       : "<<totsub;
			for(int i = 0; i<totsub;i++){
				cout<<"\n  Subject "<<i+1<<" : "<<subject[i];
			}
			if(totsub==0){
				cout<<"None Subjects Specified... ";
			}
		}
}a;


Admin f;

//a &f are the objects of the class Admin.
int main(){
	int ch;
	system("CLS");
	cout<<"\n\n\n\t\t\tWelcome to SIT Database Portal";
	cout<<"\n\n\n\t\t\t\tEnter to Continue";
	getch();
	system("CLS");
	
	cout<<"\n\n\n\t\t\tPress 1 for Admin Portal";
	cout<<"\n\n\n\t\t\tPress 2 for Faculty Portal";
	cout<<"\n\n\n\t\t\tPress 3 for Student Portal";
	cout<<"\n\n\t\t\tEnter Your Choice : ";
	cin>>ch;
	system("CLS");
	if(ch==1){
		char adminuser[20],adminpass[20];
		int k;
		cout<<"\n\t\t\tWelcome to ADMIN Login Portal  ";
		cout<<"\n\nEnter the UserName: ";
		cin>>adminuser;
		cout<<"\nEnter the Password : ";
		for( k = 0; k<8;k++){
			adminpass[k]=getch();
			cout<<"*";
		}
		getch();
		adminpass[k] = NULL;
		if((strcmp(adminuser,"admin")==0)  && (strcmp(adminpass,"password")==0)){
			system("CLS");
		}else{
			cout<<"\n\n\n\t\t\t Invalid Access to Portal";
			cout<<"\n\n\n\t\t\t\t Thank You !!!";
			getch();
			exit(0);
		}
		char opera= 'y';
		do{
			int tmp;
			cout<<"\n\t\t\t\tWelcome To Admi Panel";
			cout<<"\n\nPress 1 to Add a Faculty Record ";
			cout<<"\n\nPress 2 to Add Multiple Records of Faculty ";
			cout<<"\n\nPress 3 to View All The Records of Faculty ";
			cout<<"\n\nPress 4 to Delete a Faculty Record ";
			cout<<"\n\nPress 5 to Add a Student Record";
			cout<<"\n\nPress 6 to Add Multiple Records of Student ";
			cout<<"\n\nPress 7 to View All the Records of Stduents ";
			cout<<"\n\nPress 8 to Delete a Student Record ";
			cout<<"\n\nPress 9 to Exit.";
			cout<<"\n\n\t Enter Your Choice : ";
			cin>>tmp;
			system("CLS");
			if(tmp==1)// for inserting d single faculty records
			{
				cout<<"\nEnter the Details :- ";
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
				a.getfadata();
				fs.write((char*)&a,sizeof(Admin));
				fs.close();
				cout<<"\nRecord Entered Successfully... ";
			}
			// for inserting d single faculty records
			if(tmp==2)//for inserting d multiple faculty records
			{
				int m=0;
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::out|ios::ate);
				do{
					cout<<"\nEnter the Details:-";
					a.getfadata();
					fs.write((char *)&a, sizeof(Admin));
					cout<<"Press 0 if you want to Enter More Records : ";
					cin>>m;
				}while(m==0);
				fs.close();
				cout<<"\nRecord Entered Successfully..";
			}//for inserting d multiple faculty records.
			if(tmp==3)//for view all faculty records
			{
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char*)&a,sizeof(Admin));
					a.fadisplay();
				}
				fs.close();
			}//for view all faculty records
			if(tmp==4){
				char tmpfaid[15];
				int de = 0, result =-1;
				cout<<"\nEnter the Faculty ID/Rollno. : ";
				cin>>tmpfaid;
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fstream fs1;
				fs1.open("fanewinfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&a,sizeof(Admin));
					result=strcmp(tmpfaid,a.rollno);
					if(result==0){
						de = 1;
					}else{
						fs1.write((char *)&a,sizeof(Admin));
					}
					if(de==1){
						cout<<"\nRecord Deleted Successfully...";
					}else{
						cout<<"\nRecord not found....";
					}
					fs.close();
					fs1.close();
					remove("fainfo.txt");
					rename("fanewinfo.txt","fainfo.txt");
				}//for deleting a faculty record.
			}
			if(tmp == 5)//for single student record input
			{
				cout<<"\nEnter the Details :- ";
				fstream fs;
				fs.open("stinfo.txt",ios::in| ios::out|ios::ate);
				a.getstdata();
				fs.write((char *)&a,sizeof(Admin));
				fs.close();
				cout<<"\nRecord Entered Successfully ...";
			}//for single student record input
			
			if(tmp == 6){
				int m = 0;
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::out|ios::ate);
				do{
					cout<<"\nEnter the Details :- ";
					a.getstdata();
					fs.write((char *)&a,sizeof(Admin));
					cout<<"Press 0 if you want to Enter More Records : ";
					cin>>m;
				}while(m==0);
				fs.close();
				cout<<"\nRecord Entered Successfully...";
			}//for mmultiple student record input
			if(tmp==7)//for view of all student record.
			{
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&a,sizeof(Admin));
					a.stdisplay();
				}
				fs.close();
			}//for view of all stduent record.
			
			if(tmp == 8)// for deleting a student record
			{
				char tmpstid[15];
				int de=0, result = -1;
				cout<<"\nEnter the Student ID/Rollno. :- ";
				cin>>tmpstid;
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fstream fs1;
				fs1.open("stnewinfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&a,sizeof(Admin));
					result=strcmp(tmpstid,a.rollno);
					if(result==0){
						de = 1;
					}
					else{
						fs1.write((char *)&a,sizeof(Admin));
					}
				}
				if(de==1){
					cout<<"\nRecord Deleted Successfully....";
				}else{
					cout<<"\nRecord not found...";
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("stnewinfo.txt","stinfo.txt");
			}//for deleting a student record
			if(tmp==9){
				cout<<"\n\n\n\n\t\t\t\tThank You !!!";
				getch();
				exit(0);
			}//for exit
			if(tmp<1 || tmp>9){
				system("CLS");
				cout<"\n\n\n\t\t\t\t\tInvalid Input.....";
			}//for invalid input among choice of operation
			getch();
			cout<<"\n\nPress y; For More Operations otherwise n : ";
			cin>>opera;
			if(opera != 'y'){
				getch();
				system("CLS");
				cout<<"\n\n\n\n\n\t\t\t\t\tThank You !!!";
				getch();
			}//closing of thank you
		}while(opera == 'Y' || opera=='y');
	}//closing of admin login
	
	
	
	if(ch==2)// begin of faculty view portal
	{
		system("CLS");
		char un[20];
		int val, s=0;
		cout<<"\n\t\t\tWelcome to Faculty Login Page";
		cout<<"\n\nEnter the UserName  : ";
		cin>>::un;
		fstream fs;
		fs.open("fainfo.txt",ios::in|ios::binary);
		fs.seekg(0);
		while(!fs.eof()){
			val=-1;
			fs.read((char*)&f,sizeof(Admin));
			val=f.login();
			if(val==1){
				s=1;
				break;
			}
		}
		fs.close();
		if(s==1){
			system("CLS");
		}//if first login is valid
		if(s!=1)// if first login is invalid then
		{
			system("CLS");
			int ho= 0;
			cout<<"\n\n\t\tYour Login Credentials are In-Correct";
			cout<<"\nThe UserName is Your ID/Rollno.";
			cout<<"\nThe Password is Case-Sensitive.";
			cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login";
			cout<<"\nEnter the Choice: ";
			cin>>ho;
			if(ho == 1)// recover password.
			{
				cout<<"Enter the UserName :- ";
				cin>>::un;
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				int re,su=-1;
				while(!fs.eof()){
					re = -1; fs.read((char *)&f,sizeof(Admin));
					re=f.recover();
					if(re==1){
						su = 1;
						break;
					}
				}
				fs.close();
				if(su==1){
					getch();
					system("CLS");
					cout<<"\n\n\n\n\t\t\tThank You !!!";
					getch();
					exit(0);
				}
				else{
					cout<<"\nYou are a Invalid User.";
					getch();
					exit(0);
				}
			}//recover password.
			if(ho == 2)//re-attemp of login
			{
				cout<<"\n\nEnter the UserName : ";
				cin>>::un;
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				int suc=-1,valu;  //valu for storing login() returnd value suc for success login
				while(!fs.eof()){
					valu=-1;
					fs.read((char *)&f,sizeof(Admin));
					valu=f.login();
					if(valu==1){
						suc=1;
						break;
					}
				}
				fs.close();
				if(suc==1){
					system("CLS");
				}else{
					getch();
					cout<<"\nYou are an Invalid User...";
					cout<<"\nThank You !!!";
					getch();
					exit(0);
				}
			}
			if(ho != 1 && ho != 2){
				cout<<"\n\nInvalid Input Provided.  ";
				cout<<"\n\n\t\t\tThank You !!!";
				getch();
				exit(0);
			}
		}//Closing of first invlaid login(forget password & recover password)
		//Begin of Faculty
		
		char con = 'y';
		do{
			system("CLS");
			cout<<"\n\n\t\t\tWelcome to Faculty Panel ";
			cout<<"\n\n\t\t\t\t\t Your User Id is:  "<<::un;
			cout<<"\n\nPress 1 to View Your Profile.";
			cout<<"\n\nPress 2 to Know Your Subjects.";
			cout<<"\n\nPress 3 to Add a Subject. ";
			cout<<"\n\nPrses 4 to Delete a Subject.";
			cout<<"\n\nPress 5 to Modify Your Profile.";
			int choice;
			cout<<"\n\nEnter Your Choice : ";
			cin>>choice;
			if(choice == 1){
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fs.seekg(0);
				int x;
				while(!fs.eof()){
					x = 0;
					fs.read((char*)&f,sizeof(Admin));
					x=f.faprofile();
					if(x==1){
						break;
					}
				}
				fs.close();
			}//closing of choice 1.
			if(choice == 2){
				fstream fs;
				fs.open("fainfo.txt",ios::in);
				fs.seekg(0);
				int y;
				while(!fs.eof()){
					y = 0;
					fs.read((char *)&f, sizeof(Admin));
					int y = f.knowfasub();
					if(y==1){
						break;
					}
				}
				fs.close();
			}//closing of choice 2.
			if(choice == 3){
				fstream fs;
				fstream fs1;
				fs.open("fainfo.txt", ios::in|ios::binary);
				fs1.open("tmpfainfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.addfasub();
					fs1.write((char *)&f, sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("tmpfainfo.txt","fainfo.txt");
			}//closing of choice  3
			if(choice == 4){
				fstream fs;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fstream fs1;
				fs1.open("delfainfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.delfasub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("delfainfo.txt","fainfo.txt");
			}//closing of choice 4.
			if(choice == 5){
				fstream fs;
				fstream fs1;
				fs.open("fainfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				fs1.open("modfainfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.modfaprofile();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("fainfo.txt");
				rename("modfainfo.txt","fainfo.txt");
			}
			if(choice<1 || choice>5){
				cout<<"\nInvalid Input Provided !!!";
				cout<<"\n\n\t\t\t\tEnter to Continue";
				getch();
				cout<<"\n\nPress y to Continue ; otherwise n : ";
				cin>>con;
				if(con!='y' || con!='Y'){
					system("CLS");
					cout<<"\n\n\n\n\n\t\t\tThank You !!!";
					getch();
					exit(0);
					}
				}
			}while(con=='y'|| con=='Y');
		}//close of faculty view
			//beign of student view
	
	if(ch == 3){
		system("CLS");
		//char un[20];
		int value, s1 = 0;
		cout<<"\n\t\t\tWelcome to Student Login Page";
		cout<<"\n\nEnter the UserName : ";
		cin>>::un;
		fstream fs;
		fs.open("stinfo.txt",ios::in|ios::binary);
		fs.seekg(0);
		while(!fs.eof()){
			value=01;
			fs.read((char *)&f, sizeof(Admin));
			value = f.login();
			if(value == 1){
				s1=1;
				break;
			}
		}
		fs.close();
		if(s1==1){
			system("CLS");
			//cout<<"\n\n\n\t\t\tWelcome to Student Page";
		}//if first login is valid
		if(s1 != 1 )//if firstt login is invlaid then
		{
			system("CLS");
			int sho = 0;
			cout<<"\n\n\t\tYour Login Credentials are In-Correct";
			cout<<"\nThe UserName is Your ID/Rollno. ";
			cout<<"\nThe Password is Case-Sensitive. ";
			cout<<"\nPress 1 to Re-Cover Password & 2 to Re-Attempt Login ";
			cout<<"\nEnter the Choice : ";
			cin>>sho;
			if(sho==1)// recover password
			{
				cout<<"Enter the UserName :- ";
				cin>>::un;
				fstream fs;
				fs.open("stinfo.txt",ios::in| ios::binary);
				fs.seekg(0);
				int re,su = -1;
				while(!fs.eof()){
					re = -1;
					fs.read((char *)&f,sizeof(Admin));
					re=f.recover();
					if(re==1){
						su = 1;
						break;
					}
				}
				fs.close();
				if(su == 1){
					getch();
					system("CLS");
					cout<<"\n\n\n\n\n\t\t\tThank You !!!";
					getch();
					exit(0);
				}else{
					cout<<"\nYou are a Invalid User.";
					cout<<"\nThank You !!!";
					getch();
					exit(0);
				}
			}//recover password
			if(sho == 2) // re-attempt of login.
			{
				cout<<"\n\nEnter the UserName : ";
				cin>>::un;
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				int suc=-1, valu; // valu for storing login() returned value suc for success login
				while(!fs.eof()){
					valu=-1;
					fs.read((char*)&f,sizeof(Admin));
					valu=f.login();
					if(valu==1){
						suc=1;
						break;
					}
				}
				fs.close();
				if(suc==1){
					system("CLS");
				}else{
					getch();
					cout<<"\nYou are an Invalid User... ";
					cout<<"\nthank You !!!";
					getch();
					exit(0);
				}
			}
			if(sho != 1 && sho != 2){
				cout<<"\n\nInvalid Input provided. ";
				cout<<"\n\n\t\t\tThank You !!!";
				getch();
				exit(0);
			}
		}//closing of first invlaid login(forget password & recover password)
		//getch();
		//Begin of Student Panel;
		
		
		char moreop='y';
		do{
			system("CLS");
			cout<<"\n\n\t\t\tWelcome to Student Panel..";
			cout<<"\n\n\t\t\t\t\t Your UserId is : "<<::un;
			cout<<"\n\nPress 1 to View Your Profile. ";
			cout<<"\n\nPress 2 to Know Your Subjects. ";
			cout<<"\n\nPress 3 to Add a Subject. ";
			cout<<"\n\nPress 4 to Delete a Subject.";
			cout<<"\n\nPress 5 to Modify Your Profile. ";
			int inchoice;
			cout<<"\n\nEnter Your Choice : ";
			cin>>inchoice;
			
			if(inchoice==1){
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				int x;
				while(!fs.eof()){
					x=0;
					fs.read((char *)&f,sizeof(Admin));
					x=f.stprofile();
					if(x==1){
						break;
					}
				}
				fs.close();
			}//closing of inchoice 1.
			if(inchoice == 2 ){
				fstream fs;
				fs.open("stinfo.txt",ios::in);
				fs.seekg(0);
				int y;
				while(!fs.eof()){
					y = 0;
					fs.read((char *)&f,sizeof(Admin));
					int y=f.knowstsub();
					if(y==1){
						break;
					}
				}
				fs.close();
			}//closing of choice 2.
			if(inchoice == 3){
				fstream fs;
				fstream fs1;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fs1.open("tmpstinfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.addstsub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("tmpstinfo.txt","stinfo.txt");
			}//closing of choice 3.
			if(inchoice == 4 ){
				fstream fs;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fstream fs1;
				fs1.open("delstinfo.txt",ios::out|ios::ate);
				fs.seekg(0);
				while(!fs.eof()){
					fs.read((char *)&f,sizeof(Admin));
					f.delstsub();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("delstinfo.txt","stinfo.txt");
			}//closing of choice 4.
			if(inchoice == 5){
				fstream fs;
				fstream fs1;
				fs.open("stinfo.txt",ios::in|ios::binary);
				fs.seekg(0);
				fs1.open("modstinfo.txt",ios::out|ios::ate);
				while(!fs.eof()){
					fs.read((char *)&f, sizeof(Admin));
					f.modstprofile();
					fs1.write((char *)&f,sizeof(Admin));
				}
				fs.close();
				fs1.close();
				remove("stinfo.txt");
				rename("modstinfo.txt","stinfo.txt");
			}
			if(inchoice<1 || inchoice>5){
				cout<<"\nInvalid Input Provided.. ";
				cout<<"\n\n\n\t\t\tEnter to Continue.. ";
				getch();
				cout<<"\n\nPress y, other wise n to Perofrm More Operations : ";
				cin>>moreop;
				if(moreop!='Y' && moreop != 'y'){
					system("CLS");
					cout<<"\n\n\n\t\t\tThank You !!";
					getch();
					exit(0);
				}
			}
			 }while(moreop=='Y' || moreop == 'y');
			getch();
		}
	//closing of student panel ch 3.
	
	if(ch<1 || ch>3){
		cout<<"\nInvalid Input Provided !!! ";
		getch();
		system("CLS");
		cout<<"\n\n\n\t\t\tThank You.";
	}

}


