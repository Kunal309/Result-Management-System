#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

class student{
    int rollno;
    char name[50];
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    double per;
    char grade;
    void calculate();
    public:
    void showdata();
    void getdata();
    void show_tabular();
    int retrollno();
};
void student::calculate(){
    per = (p_marks+c_marks+m_marks+e_marks+cs_marks)/5.0;
    if(per >= 80)
    grade = 'A';
    else if(per < 80 && per >=60)
    grade = 'B';
    else if(per<60 && per>=50)
    grade = 'C';
    else if(per<50 && per>=33)
    grade = 'D';
    else
    grade = 'F';
}
void student :: getdata(){
     cout << "\nPlease enter the rollno of the student : ";
     cin >> rollno;
     cout << "\nPlease enter the name of the student : ";
     cin.ignore();
     cin.getline(name,50);
     cout << "\nPlease enter the marks in physics : ";
     cin >> p_marks;
     cout << "\nPlease enter the marks in chemistry : ";
     cin >> c_marks;
     cout << "\nPlease enter the marks in mathematics : ";
     cin >> m_marks;
     cout << "\nPlease enter the marks in english : ";
     cin >> e_marks;
     cout << "\nPlease enter the marks in computer science : ";
     cin >> cs_marks;
     calculate();
}
void student::showdata(){
     cout << "\nRollno of the student is : " << rollno;
     cout << "\nName of the student is :   " << name;
     cout << "\nMarks in Physics is :      " << p_marks;
     cout << "\nMarks in Chemistry is :    " << c_marks;
     cout << "\nMarks in Mathematics is :  " << m_marks;
     cout << "\nMarks in English is :      " << e_marks;
     cout << "\nMarks in Computer Science is : " << cs_marks;
     cout << "\nPercentage of the student is : " << per;
     cout << "\nGrade of the student is :  " << grade;
     
}
void student:: show_tabular(){
    cout <<"  " << rollno << setw(21) << name << setw(10) << p_marks << setw(5) << c_marks << setw(5) << m_marks << setw(5) << e_marks << setw(5) << cs_marks << setw(10) << per << setw(7) << grade << endl;
}
int student::retrollno() {
    return rollno;
}
void display_sp(int);
void write_student();
void display_all();
void modify_student(int);
void delete_student(int);
void class_result();
void result();
void intro();
void entry_menu();

int main(){
    char ch;
    intro();
    
    do{
    system("cls");
    cout << "\n\t MAIN MENU : \n";
    cout << "\n\t 1. RESULT MENU ";
    cout << "\n\t 2. ENTRY/EDIT MENU ";
    cout << "\n\t 3. EXIT";
    cout << "\n\n\t Please enter your choice from the menu : ";
    cin >> ch;
    switch(ch){
        case '1': result();
        break;
        case '2': entry_menu();
        break;
        case '3':system("cls");
                 cout << "\tYou exited the program.\n\tPress ENTER to use ReportCard Maker again.";getch();
        break;
        default : cout << "Wrong choice....!!!";getch();
        break;
    }
    }while(ch != 3);
    return 0;
}
void intro(){
    cout << "\n\n\n\t\t.....WELCOME TO STUDENT REPORT CARD MAKER.....";
    cout << "\n\n\t\t ...SCHOOL : DELHI TECHNOLOGICAL UNIVERSITY...";
    cout << "\n\n\t Made by : Kunal";
    cout << "\n\n\t\t     ......Press ENTER to continue......\n";
    cin.get();
}
void result(){
    char ch;
    int rno;
    cout << "\n\t RESULT MENU : ";
    cout << "\n\n\t 1. Class Result";
    cout << "\n\n\t 2. Student Report Card";
    cout << "\n\n\t 3. Return to Main Menu...";
    cout << "\n\t Please enter your choice ....";
    cin >> ch;
    switch(ch){
        case '1': class_result();
        break;
        case '2': cout << "Enter the rollno of the student : ";
                  cin >> rno;
                  display_sp(rno);
        break;
        case '3': 
        break;
        default : cout << "\a";
    }
}
void class_result(){
    student st;
    ifstream inFile;
    inFile.open("Reportcard.dat",ios::binary);
    if(!inFile){
        cout << "File Not Found.....!! Press any Key";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\t\t\t***ALL CLASS RESULT***\n";
    cout << "\n___________________________________________________________________________";
    cout << "\n___________________________________________________________________________";
    cout << "\n  ROLLNO.            NAME        P    C    M    E    CS      %age    GRADE  "  ;
    cout << "\n___________________________________________________________________________";
    cout << "\n___________________________________________________________________________";
    cout << "\n";
    while(inFile.read(reinterpret_cast<char *>(&st),sizeof(student)))
    {
      st.show_tabular();
    }
    cin.ignore();
    cin.get();
    inFile.close();
}
void display_sp(int n){
  student st;
  ifstream inFile;
  inFile.open("Reportcard.dat",ios::binary);
  if(!inFile){
      cout << "File not found...! Press any key";
      cin.ignore();
      cin.get();
      return;
  }
  bool flag = false;
  while(inFile.read(reinterpret_cast<char *>(&st),sizeof(student)))
  {
      if(st.retrollno()==n){
          st.showdata();
          flag = true;
      }
  }
  inFile.close();
  if(flag == false)
  cout << "\n Record not exists";
  cin.ignore();
  cin.get();
}

void entry_menu(){
    char ch;
    int num;
    system("cls");
    cout << "\n\n\n\tENTRY MENU :" ;
    cout << "\n\t1.CREATE STUDENT RECORD";
    cout << "\n\t2.DISPLAY ALL STUDENT RECORDS";
    cout << "\n\t3.SEARCH STUDENT RECORD ";
    cout << "\n\t4.MODIFY STUDENT RECORD ";
    cout << "\n\t5.DELETE STUDENT RECORD ";
    cout << "\n\t6.RETURN TO MAIN MENU";
    cout << "\n\tPlease enter your choice : ";
    cin >> ch;
    switch(ch){
       case '1':write_student();
                break;
       case '2':display_all();
                break;
       case '3':cout<<"\n\tPlease enter the roll number of the student : ";
                cin >> num;
                display_sp(num);
                break;
       case '4':cout<<"\n\tPlease enter the roll number of the student : ";
                cin >> num;
                modify_student(num);
                break;
       case '5':cout<<"\n\tPlease enter the roll number of the student : ";
                cin >> num;
                delete_student(num);
                break;
       case '6':
                break;
       default : cout << "\a"; entry_menu();
    }
}
    void write_student()
    {
        student st;
        ofstream outFile;
        outFile.open("Reportcard.dat",ios::binary|ios::app);
        st.getdata();
        outFile.write(reinterpret_cast<char *>(&st),sizeof(student));
        outFile.close();
        cout << "Student record has been created...";
        cin.ignore();
        cin.get();
    }
    void display_all(){
        student st;
        ifstream inFile;
        inFile.open("Reportcard.dat",ios::binary|ios::app);
        if(!inFile)
        {
          cout<<"File could not be open !! Press any Key...";
          cin.ignore();
          cin.get();
          return;
        }
        cout << "\nALL RECORD :-)";
        while(inFile.read(reinterpret_cast<char *>(&st),sizeof(st))){
            st.showdata();
            cout << "\n\n******************************************\n";
            cout << "==========================================\n";
        }
        inFile.close();
        cin.ignore();
        cin.get();
    }
    void modify_student(int num){
        bool found = false;
        student st;
        fstream File;
        File.open("Reportcard.dat",ios::binary|ios::in|ios::out);
         if(!File)
        {
          cout<<"File could not be open !! Press any Key...";
          cin.ignore();
          cin.get();
          return;
        }
        while(!File.eof() && found==false)
        {
            File.read(reinterpret_cast<char *>(&st),sizeof(student));
            if(st.retrollno()==num){
                st.showdata();
                cout << "\nPlease enter new details of student : ";
                st.getdata();
                int pos = (-1)*(int)(sizeof(st));
                File.seekp(pos,ios::cur);
                File.write((char*)&st,sizeof(student));
                
                cout << "\n\n\tRecord Updated";
                found = true;
            }
        }
        File.close();
        if(found==false)
        cout << "Record Not Found !!!";
        cin.ignore();
        cin.get();
    }
    void delete_student(int num){
        student st;
        ifstream inFile;
        inFile.open("Reportcard.dat",ios::binary);
        if(!inFile){
            cout<<"File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        ofstream outFile;
        outFile.open("Temp.dat",ios::out);
        inFile.seekg(0,ios::beg);

        while(inFile.read(reinterpret_cast<char *>(&st), sizeof(student)))
        {
            if(st.retrollno() != num)
            outFile.write(reinterpret_cast<char *>(&st), sizeof(student));
        }
        outFile.close();
        inFile.close();
        remove("Reportcard.dat");
        rename("Temp.dat","Reportcard.dat");
        cout<< "\tRecord Deleted";
        cin.ignore();
        cin.get();
    }

