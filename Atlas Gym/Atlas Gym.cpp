#include <iostream>		//input/output streams.
#include <Windows.h>	//Windows-specific header file this is use to chang console behaviors.
#include <string>		// use to ordered sequence of characters.
#include <fstream>		//header includes the iostream header, so you could leave out iostream and it would still compile.
#include <stdio.h>		//we use theis header file for use "printf".
#include <conio.h>		//used mostly by MS-DOS compilers to provide console input/output.
#include <stdlib.h>		// functions involving memory allocation.
#include <sstream>		// use to convert between strings and other numerical types.
#include <cstdlib>		//This header defines several general purpose functions, including dynamic memory management, random number generation, communication with the environment, integer arithmetics, searching, sorting and converting.
#include <iomanip>		//align ments

using namespace std;

struct member
{
	int member_id;
	int cn;
	int age;
	char fname[20];	//maximum caracters 20
	char sname[20];	//maximum caracters 20
	char add[500];  //maximum caracters 100
	

};

void head(); 
void main();
void menu();
void memberreg();
void mbvid();
void vall();
void up();
void mems(int x);
void forr();
void help();

void main() 
{
	string un = "";
	string pw = "";
	char ch;
	bool success = false;

	head();

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t      --------------------------------------" << endl;
	cout << "\t\t\t\t             Enter Your Login Details" << endl;
	cout << "\t\t\t\t      --------------------------------------" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t      --------------------------------------" << endl;
	cout << "\t\t           IF YOU NOT REMEMBER USER NAME AND PASSWORD PLEASE CHECK THE MANUAL" << endl;
	cout << "\t\t\t\t      --------------------------------------" << endl;
	do {
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); cout << "\t\t\t\t             Enter User Name :  "; getline(cin, un);
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY); cout << "\t\t\t\t             Enter Password  :  "; getline(cin,pw);



		if (un == "Admin" && pw == "Password") //check username and password true 
		{

			bool success = true;	//set bool as true
			system("CLS");			//clear the windows
			menu();			//go to function called menu()
			break;					//break the process 

		}

		else   // this part is use to do next steps if username or password wrong
		{
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << endl; //end line 
			cout << "\t\t\t            ------------------------------------------" << endl; //output
			cout << "\t\t\t         Incorrect Username or Password.Please try Again." << endl;; //output
			cout << "\t\t\t            ------------------------------------------" << endl; //output
		}
	} while (!success); // this while part is use for repeat process until password and username is correct
}

void menu(){
	while (1) {
	head();

	
		char choice;
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "\t\t                     ----------------------------------------" << endl;
		cout << "\t\t 		     | MEMBER REGISTRATION             =  1 |" << endl;
		cout << "\t\t 		     | VIEW MEMBER DETAILS BY ID       =  2 |" << endl;
		cout << "\t\t 		     | VIEW ALL MEMBER DETAILS         =  3 |" << endl;
		cout << "\t\t 		     | UPDATE MEMBER DETAILS           =  4 |" << endl;
		cout << "\t\t 		     |                                      |" << endl;
		cout << "\t\t 		     | HELP                            =  5 |" << endl;
		cout << "\t\t 		     | EXIT                            =  6 |" << endl;

		cout << "\t\t                     ----------------------------------------" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t                     ----------------------------------------" << endl;
		cout << "\t\t                     Enter Your Choice		:       "; cin >> choice;

		switch (choice) { //this statement is use to sellect next process of choice input
		case '1': // theis is case is for first input of choice "1"
			system("CLS");//clear the windows
			memberreg();//go to function called memberreg()
			

		case '2': // theis is case is for second input of choice "2"
			system("CLS"); //clear the windows
			mbvid(); //go to function called void mbvid()

		case '3': // theis is case is for third input of choice "3"
			system("CLS");//clear the windows
			vall();//go to function called vall()

		case '4': // theis is case is for third input of choice "3"
			system("CLS");//clear the windows
			up();//go to function called up()

		case '5': // theis is case is for third input of choice "3"
			system("CLS");//clear the windows
			help();//go to function called help()

		case '6': 
			exit(0);//exit application

		default: // default is the stataement that use for do default process 
			system("cls");//clear the windows
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << endl;
			cout << "\t\t                     ----------------------------------------" << endl;
			cout << "\t\t                            YOUR CHOICE WAS UNAVILABLE." << endl;;
			cout << "\t\t                     ----------------------------------------" << endl;
			menu();

			
		}
	}
}

void memberreg() {
	
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0; //set memeber id as 0
	member obj; //load memeber struct
	fstream myfile, id; 
	ofstream oid;
	string ne; //string vriable
	id.open("id.txt"); //open txt file called id
	do {
	head();
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "     |         In Address you have to use underscore _ as space (near 88 charactors, no spaces)   |" << endl;
	myfile.open("member.dat", ios::binary | ios::out | ios::app);

	id >> i;
	obj.member_id = ++i;
	oid.open("id.txt");
	oid << i;
	cout << "" << "" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "                          Enter Member ID			: " << obj.member_id << endl;	//cin >> obj.member_id;
	cout << "                          Enter Member First Name		: ";	cin >> obj.fname;
	cout << "                          Enter Member Surname	                : ";		cin >> obj.sname;
	cout << "                          Enter Member Address		        : "; cin>>obj.add;
	cout << "                          Enter Member Contact Number	        : "; cin >> obj.cn;

	while (cin.fail())
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t                          Error: Invalid Number         " << endl;
		cin.clear();//clear the error on cin
		cin.ignore(256, '\n');//skips to the next newline
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "                          Enter Member Contact Number	        : ";
		cin >> obj.cn;
	}

	cout << "                          Enter Member Age		        : ";			cin >> obj.age;

	while (cin.fail())
	{
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t                          Error: Age         " << endl;
		cin.clear();//clear the error on cin
		cin.ignore(256, '\n');//skips to the next newline
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "                          Enter Member Age		        : ";
		cin >> obj.age;
	}

	cout << "" << "" << endl;

	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	cout << "                          Member ID			        : " << obj.member_id << endl;
	cout << "                          Member Name		                : " << obj.fname << " " << obj.sname << endl;
	cout << "                          Member Address		        : " << obj.add << endl;
	cout << "                          Member Contact Number			: " << obj.cn << endl;
	cout << "                          Member Age			        : " << obj.age << endl;;
	cout << "" << "" << endl;

	myfile.write((char*)&obj, sizeof(obj));
	myfile.close();
	oid.close();

	cout << "		Do you want to add another member?(Y/N) : "; cin >> ne;


	system("cls");
	} while (ne == "y" || ne == "Y");
	system("cls");
		menu();
		
		
}	

void mbvid() {
	
	
	HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		MoveWindow(console, r.left, r.top, 1940, 700, TRUE); //MoveWindow(window_handle, x, y, width, height, redraw_window);

		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "" << "" << endl;
		cout << "\t\t\t\t\t\t############ ############ ###          ############ ############	" << endl
			<< "\t\t\t\t\t\t############ ############ ###          ############ ############	" << endl
			<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ### ###			" << endl
			<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ### ###			" << endl
			<< "\t\t\t\t\t\t############     ####     ###          ############ ############   " << endl
			<< "\t\t\t\t\t\t############     ####     ###          ############ ############   " << endl
			<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ###          ###   " << endl
			<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ###          ###   " << endl
			<< "\t\t\t\t\t\t###      ###     ####     ############ ###      ### ############   " << endl
			<< "\t\t\t\t\t\t###      ###     ####     ############ ###      ### ############   " << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "\t\t\t\t\t\t\t      Welcome to ATLAS GYM MANAGEMENT system" << endl;
		cout << "" << "" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "########################################################################################################################################################################" << endl
			<< "########################################################################################################################################################################" << endl;

		cout << "" << "" << endl;
		SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "\t\t\t\tIf memeber ID you entered is wrong, it shows all memeber details in Data Base";
		cout << "" << "" << endl;
		cout << "" << "" << endl;
		int search;
		SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout << "               Enter Member ID : "; cin >> search;
		cout << "         ------------------------------------------------------------" << endl;

		mems(search);
		cout << endl << endl;
		

	
}

void vall() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1940, 700, TRUE); //MoveWindow(window_handle, x, y, width, height, redraw_window);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "" << "" << endl;
	cout << "\t\t\t\t\t\t############ ############ ###          ############ ############	" << endl
		<< "\t\t\t\t\t\t############ ############ ###          ############ ############	" << endl
		<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ### ###			" << endl
		<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ### ###			" << endl
		<< "\t\t\t\t\t\t############     ####     ###          ############ ############   " << endl
		<< "\t\t\t\t\t\t############     ####     ###          ############ ############   " << endl
		<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ###          ###   " << endl
		<< "\t\t\t\t\t\t###      ###     ####     ###          ###      ###          ###   " << endl
		<< "\t\t\t\t\t\t###      ###     ####     ############ ###      ### ############   " << endl
		<< "\t\t\t\t\t\t###      ###     ####     ############ ###      ### ############   " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t\t\t\t      Welcome to ATLAS GYM MANAGEMENT system" << endl;
	cout << "" << "" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "########################################################################################################################################################################" << endl
		<< "########################################################################################################################################################################" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "" << "" << endl;
	cout << left << setw(12) << "Member ID";
	cout << left << setw(22) << "Member First Name";
	cout << left << setw(22) << "Member Surname";
	cout << left << setw(15) << "Contact Number";
	cout << left << setw(6) << "Age";
	cout << left << setw(88) << "Member Address";
	cout << "" << "" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
	member obj;
	ifstream displayf;
	displayf.open("member.dat");
	if (displayf.is_open()) {
		while (displayf.read((char*)&obj, sizeof(obj))) {
			

			cout << left << setw(12) << obj.member_id;
			cout << left << setw(22) << obj.fname;
			cout << left << setw(22) << obj.sname;
			cout << left << setw(15) << obj.cn;
			cout << left << setw(6) << obj.age;
			cout << left << setw(88) << obj.add;
			cout << "" << "" << endl;
		
		}
		cout << "" << "" << endl;
		system("pause");
		system("cls");
		menu();
		}
}

void up() {
	string ne;
	do {
		
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		int search;
		member obj;
		fstream update_file;
		update_file.open("member.dat", ios::out | ios::in | ios::binary);
		if (update_file.is_open()) {
			head();
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout << endl;
			cout << "\t\tIf you can not find any information about memeber please check the memeber ID again";
			cout << endl << endl;
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout << "Enter Customer ID : ";
			cin >> search;
			cout << endl;
			while (update_file.read((char*)&obj, sizeof(obj))) {

				//update_file.read((char*)&obj, sizeof(obj));
				if (obj.member_id == search)
				{
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "\tYour ID is :" << obj.member_id << endl;
					cout << "\tYour First Name is : " << obj.fname << endl;
					cout << "\tYour Surname is    : " << obj.sname << endl;
					cout << "\tYour Address is    : " << obj.add << endl;
					cout << "\tYour ContactNo is  : " << obj.cn << endl;
					cout << "\tYour Age is        : " << obj.age << endl;

					cout << "\n\t\t\t\t\tEnter New Details to Update !!!" << endl;
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					cout << "\tYour Memeber ID is : " << obj.member_id << endl;
					cout << "\tEnter Memeber First Name : ";
					cin >> obj.fname;
					cout << "\tEnter Memeber Surname    : ";
					cin >> obj.sname;
					cout << "\tEnter Memeber Address    : ";
					cin >> obj.add;
					cout << "\tEnter Member Contact Number  : ";
					cin >> obj.cn;
					while (cin.fail())
					{
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << "\t\t                          Error: Invalid Number         " << endl;
						cin.clear();//clear the error on cin
						cin.ignore(256, '\n');//skips to the next newline
						SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\tEnter Member Contact Number	        : ";
						cin >> obj.cn;
					}

					cout << "\tEnter Member Age        : ";
					cin >> obj.age;
					while (cin.fail())
					{
						SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
						cout << "\t\t                          Error: Age         " << endl;
						cin.clear();//clear the error on cin
						cin.ignore(256, '\n');//skips to the next newline
						SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						cout << "\tEnter Member Age		        : "; cin >> obj.age;
					}

					int position = -1 * (int)sizeof(obj);
					update_file.seekp(position, ios::cur);
					update_file.write((char*)&obj, sizeof(obj));
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << "\nUpdate Success !!" << '\n';
					break;
				}
				

			}
		}
		SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << endl << endl;
		cout << "		Do you want to Update another member Details?(Y/N) : "; cin >> ne;
		update_file.close();
		system("cls");
		
	} while (ne == "y" || ne == "Y");
	menu();
}
	
void mems(int x) {
	member obj;
	ifstream searchf;
	searchf.open("member.dat");
	if (searchf.is_open()) {
		while (searchf.read((char*)&obj, sizeof(obj))) {
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			if (obj.member_id == x) {
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

				cout << "" << "" << endl;
				cout << left << setw(12) << "Member ID";
				cout << left << setw(22) << "Member First Name";
				cout << left << setw(22) << "Member Surname";
				cout << left << setw(20) << "Member Contact";
				cout << left << setw(5) << "Age";
				cout << left << setw(88) << "Member Address";
				cout << "" << "" << endl;

				cout << left << setw(12) << obj.member_id;
				cout << left << setw(22) << obj.fname;
				cout << left << setw(22) << obj.sname;
				cout << left << setw(20) << obj.cn;
				cout << left << setw(5) << obj.age;
				cout << left << setw(88) << obj.add;
				cout << "" << "" << endl;
				forr();
			}
			

			
		}

	}

}

void head() 
{
	
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 940, 700, TRUE); //MoveWindow(window_handle, x, y, width, height, redraw_window);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY );
	cout	<< "" << "" << endl;
	cout	<<  "\t\t\t############ ############ ###          ############ ############	" << endl
			<<  "\t\t\t############ ############ ###          ############ ############	" << endl
			<<  "\t\t\t###      ###     ####     ###          ###      ### ###			" << endl
			<<  "\t\t\t###      ###     ####     ###          ###      ### ###			" << endl
			<<  "\t\t\t############     ####     ###          ############ ############   " << endl
			<<  "\t\t\t############     ####     ###          ############ ############   " << endl
			<<  "\t\t\t###      ###     ####     ###          ###      ###          ###   " << endl
			<<  "\t\t\t###      ###     ####     ###          ###      ###          ###   " << endl
			<<  "\t\t\t###      ###     ####     ############ ###      ### ############   " << endl
			<<  "\t\t\t###      ###     ####     ############ ###      ### ############   " << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t      Welcome to ATLAS GYM MANAGEMENT system" << endl;
	cout	<< "" << "" << endl; 
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout	<< "################################################################################################################" << endl
			<< "################################################################################################################" << endl;
	
	
}

void forr() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	string nc;
	cout << "		Do you want to check another member?(Y/N) : "; cin >> nc;
	if (nc == "y" || nc == "Y") {
		system("cls");
		mbvid();
	}
	else {
		system("cls");
		menu();
	}

}

void help() {
	
	head();
	cout << "" << "" << endl;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t\t\t\t Memeber Management System Help";
	cout << "" << "" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |                                           HELP FOR MAIN MENU                                      |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |                            PRESS NUMBER 1 FOR GO TO - MEMBER REGISTRATION                         |" << endl;
	cout << "       |                            PRESS NUMBER 2 FOR GO TO - VIEW MEMBER DETAILS BY ID                   |" << endl;
	cout << "       |                            PRESS NUMBER 3 FOR GO TO - VIEW ALL MEMBER DETAILS                     |" << endl;
	cout << "       |                            PRESS NUMBER 4 FOR GO TO - UPDATE MEMBER DETAILS                       |" << endl;
	cout << "       |                            PRESS NUMBER 5 FOR GO TO - HELP                                        |" << endl;
	cout << "       |                            PRESS NUMBER 6 FOR TO    - EXIT                                        |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |                                       HELP FOR MEMBER REGISTRATION                                |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |   User ID    - This will be automatically generated by the system for each member                 |" << endl;
	cout << "       |   First Name - Enter your First Name entering the Letter (Only 20 charactors, No spaces)          |" << endl;
	cout << "       |   Surname    - Enter your Sure Name entering the Letter (Only 20 charactors, No spaces)           |" << endl;
	cout << "       |   Address    - In Address you have to use underscore _ as space (near 88 charactors, no spaces)   |" << endl;
	cout << "       |                      Example for Address : Kalutara_KalutaraSout                                  |" << endl;
	cout << "       |   Mobile     - Enter your Mobile entering the number (Numbers only)                               |" << endl;
	cout << "       |   Age        - Enter your Age entering the number keys(Numbers only)                              |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |                                   HELP FOR MEMBER VIEW MEMBER DETAILS BY ID                       |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |         User ID    - Enter the Member Id of the member to show the details                        |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |         If memeber ID you entered is wrong, it shows all memeber details in Data Base             |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |                                   HELP FOR VIEW ALL MEMBER DETAILS                                |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |         This will display the all member details in the database                                  |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |                                       HELP FOR UPDATE MEMBER DETAILS                              |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       |   User ID    - Enter User ID you wish to Update                                                   |" << endl;
	cout << "       |   First Name - Enter your First Name entering the Letter (Only 20 charactors, No spaces)          |" << endl;
	cout << "       |   Surname    - Enter your Sure Name entering the Letter (Only 20 charactors, No spaces)           |" << endl;
	cout << "       |   Address    - In Address you have to use underscore _ as space (near 88 charactors, no spaces)   |" << endl;
	cout << "       |                      Example for Address : Kalutara_KalutaraSout                                  |" << endl;
	cout << "       |   Mobile     - Enter your Mobile entering the number (Numbers only)                               |" << endl;
	cout << "       |   Age        - Enter your Age entering the number keys(Numbers only)                              |" << endl;
	cout << "       |                                                                                                   |" << endl;
	cout << "       -----------------------------------------------------------------------------------------------------" << endl;
	cout << "" << "" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	system("pause");
	system("cls");
	menu();
}