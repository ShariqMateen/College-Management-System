#include <iostream>//for inpu and output
#include <conio.h>//for using _getch()
#include <fstream>//for file io stream which contain ifstream,ofstream
using namespace std;
int i = 0, main_option, option;
//some common string variable
string  regno, u,  filename;
//some general purpose char variable
char choice, ps[11];
//student uses variable
int  flag;
//function

struct student {
    string fname, lname, stpass, stsubj, stdtb, last_school, streg1,stemail;
    int st_class{}, stmarks{};
}st;
struct teacher {
    string fname, lname, subj, exp, qual, email, dob, teacher_reg,Class,pass;
}tch;
struct timetable {
    string subj,subj1,subj2,subj3,subj4,subj5,subj6,d1, d2, d3, d4, d5,t1, t2, t3, t4, t5, t6 ,t7;
    int c1{}, c2{};
}st_tt;
class LOGIN 
{
    void passwd(char* ar, int Max)
    {
        char ch;
        int x = 0;
        while (1)
        {
            ch =_getch();
            if (ch == 13)                  //13 ascii code of enter or vertical tab
            {
                ar[x] = '\0';
                break;
            }
            if (ch == 8 && x != 0)           //8 ascii code of back space
            {
                cout << "\b \b";
                if (x <= Max && x > 0)
                    x--;
            }
            else if (x < Max && ch != 8)
            {
                cout << "*";
                ar[x] = ch;
                x++;
            }
        }
    }
public:
    void putpass()
    {
        cout << "\n\n\n\n\n\n\n\t\tEnter User Name: ";
        cin >> u;
        cout << "\n\t\tEnter Password: ";
        passwd(ps, 11);
    }
    
    void getpasswd()
    {
        passwd(ps, 11);
    }
    int cmp(string l1,string l2) //comparing userid and password with our stored data in txt file
    {
        if (l1 == u && l2 == ps)
            return 1;
        else
            return 0;
    }
};
class Student {
    public:
    void stdetail(string b) {
       string file="Student.txt";
        ifstream f1;
        f1.open(file.c_str());
        while (f1 >> st.streg1 >> st.fname >> st.lname >> st.stdtb >>st.stemail>> st.stmarks >> st.st_class >> st.stsubj >> st.last_school ) {
            if (b == st.streg1) {
                flag = 1;
                break;
            }
        }
        f1.close();
        if (flag == 1) {
            system("cls");
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << "\t\t\t\t\t\t!             PERSONAL DETAIL                 !" << endl;
            cout << "\t\t\t\t\t\t===============================================" << endl<<endl;
            cout << "\t\t\t\t\t**************************************************************" << endl << endl;
            cout << "\t***************************************************" << endl;
            cout << "\t       CMS ID:      |     " << st.streg1  << endl;
            cout << "\t       Name:        |     " << st.fname << " " << st.lname  << endl;
            cout << "\t       Email:       |     " << st.stemail << endl;
            cout << "\t       DOB:         |     " << st.stdtb  << endl;
            cout << "\t       Class:       |     " << st.st_class  << endl;
            cout << "\t       Course:      |     " << st.stsubj << endl;
            cout << "\t  Last Institution  |     " << st.last_school << endl;
            cout << "\t****************************************************" << endl;
        }
        else {
            cout << "Record not found!\a" << endl;
        }
    }
    void forgetpassword() {
       
        string u,file = "Student_login.txt", p, pw, id;
        ifstream f1;
        f1.open(file.c_str());
        fstream f2;
        f2.open("temp2.txt", ios::trunc);
        f2.close();
        f2.open("temp2.txt", ios::out);
        while (f1 >> p >> id >> pw)
        {
            f2 << p << " " << id << " " << pw << endl;
        }
        f1.close();
        f2.close();
       
        cout << "Enter email: ";
        cin >> u;
        cout << "Enter new password: ";
        LOGIN l;
        l.getpasswd();
        
        string file2 = "temp2.txt";
        f1.open(file2.c_str());
        
        f2.open("Student_login.txt", ios::trunc);
        f2.close();
        f2.open("Student_login.txt", ios::out);
        while (f1 >> p >> id >> pw)
        {
            if (id == u)
            {
                f2 << p << " " << id << " " << ps << endl;
            }
            else
            {
                f2 << p << " " << id << " " << pw << endl;
            }
        }
        f1.close();
        f2.close();
        cout << "\nYour password is successfully updated.\n" << endl;
        remove("temp2.txt");
    }
    void displaytimetable(string c) {
        ifstream f,f1;
        string f2 = "student.txt";
        filename = "student_tt.txt";
        f1.open(f2.c_str());
        f.open(filename.c_str());
        while (f1 >> st.streg1 >> st.fname >> st.lname >> st.stdtb >> st.stemail >> st.stmarks >> st.st_class >> st.stsubj >> st.last_school) {
            if (c == st.streg1) {
                while (f >> st_tt.subj >> st_tt.subj1 >> st_tt.subj2 >> st_tt.subj3 >> st_tt.subj4 >> st_tt.subj5 >> st_tt.subj6 >> st_tt.d1 >> st_tt.d2 >> st_tt.d3 >> st_tt.d4 >> st_tt.d5 >> st_tt.t1 >> st_tt.t2 >> st_tt.t3 >> st_tt.t4 >> st_tt.t5 >> st_tt.t6 >> st_tt.t7) {
                    if (st.stsubj == st_tt.subj) {
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 1) {
            system("cls");
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << "\t\t\t\t\t\t!             CLASSES SCHEDULE                !" << endl;
            cout << "\t\t\t\t\t\t===============================================" << endl << endl;
            cout << "\t\t\t\t\t**************************************************************" << endl << endl;
            cout << "\t*****************************************************************************************************" << endl;
            cout << "\t  Day " << "  " << st_tt.t1 << "   " << st_tt.t2 << "   " << st_tt.t3 << "  " << st_tt.t4 << "  " << st_tt.t5 << "  " << st_tt.t6 << "  " << st_tt.t7 << endl;
            cout << "\t  " << st_tt.d1 << "    " << st_tt.subj1 << "   \t\t" << st_tt.subj2 << "   \t\t" << st_tt.subj3 << "\t " << st_tt.subj4 << "   \t" << st_tt.subj5 << "     \t" <<  st_tt.subj6 << "  \t" << st_tt.subj3 << endl;
            cout << "\t  " << st_tt.d2 << "    " << st_tt.subj1 << "   \t\t" << st_tt.subj2 << "   \t\t" << st_tt.subj3 << "\t " << st_tt.subj4 << "   \t" << st_tt.subj5 << "     \t" <<  st_tt.subj6 << "  \t" << st_tt.subj3 << endl;
            cout << "\t  " << st_tt.d3 << "    " << st_tt.subj1 << "   \t\t" << st_tt.subj2 << "   \t\t" << st_tt.subj3 << "\t " << st_tt.subj4 << "   \t" << st_tt.subj5 << "     \t" <<  st_tt.subj6 << "  \t" << st_tt.subj3 << endl;
            cout << "\t  " << st_tt.d4 << "   " << st_tt.subj1 << "   \t\t" << st_tt.subj2 << "   \t\t" << st_tt.subj3 << "\t " << st_tt.subj4 << "   \t" << st_tt.subj5 << "     \t" << st_tt.subj6 << "  \t" << st_tt.subj3 << endl;
            cout << "\t  " << st_tt.d5 << "    " << st_tt.subj1 << "   \t\t" << st_tt.subj2 << "   \t\t" << st_tt.subj3 << "\t " << st_tt.subj4 << "   \t" << st_tt.subj5 << endl;
            cout << "\t******************************************************************************************************" << endl;
        }
        else {
            cout << "Record not found" << endl;
        }
    }
};
class Teacher {
    public:
        void tdetail(string x) {
            string file="teacher.txt";
            ifstream f;
            f.open(file.c_str());
            while (f >> tch.teacher_reg >> tch.fname >> tch.lname >> tch.dob >>tch.email>> tch.exp >> tch.qual >> tch.Class >> tch.subj) {
                if (x == tch.teacher_reg)
                    flag = 1;
                break;
            }
            if (flag == 1) {
                system("cls");
                cout << "\t\t\t\t\t\t===============================================" << endl;
                cout << "\t\t\t\t\t\t!             PERSONAL DETAIL                 !" << endl;
                cout << "\t\t\t\t\t\t===============================================" << endl << endl;
                cout << "\t\t\t\t\t**************************************************************" << endl << endl;
                cout << "\t***************************************************************" << endl;
                cout << "\t       CMS ID:             |     " << tch.teacher_reg << "            " << endl;
                cout << "\t       Name:               |     " << tch.fname << " " << tch.lname  << endl;
                cout << "\t       Email:              |     " << tch.email  << endl;
                cout << "\t       DOB:                |     " << tch.dob  << endl;
                cout << "\t      Class teaches:       |     " << tch.Class << endl;
                cout << "\t      Subject teach:       |     " << tch.subj << endl;
                cout << "\t      Qualification:       |     " << tch.qual<< endl;
                cout << "\t***************************************************************" << endl;
            }
        }
        void forgetpassword() {

            string u, file = "Teacher_login.txt", p, pw, id;;
            ifstream f1;
            f1.open(file.c_str());
            fstream f2;
            f2.open("temp1.txt", ios::trunc);
            f2.close();
            f2.open("temp1.txt", ios::out);
            while (f1 >> p >> id >> pw)
            {
                f2 << p << " " << id << " " << pw << endl;
            }
            f1.close();
            f2.close();

            cout << "Enter email: ";
            cin >> u;
            cout << "Enter new password: ";
            LOGIN l;
            l.getpasswd();
            
            string file2 = "temp1.txt";
            f1.open(file2.c_str());
            f2.open("Teacher_login.txt", ios::trunc);
            f2.close();
            f2.open("Teacher_login.txt", ios::out);
            while (f1 >> p >> id >> pw)
            {
                if (id == u)
                {
                    f2 << p << " " << id << " " << ps << endl;
                }
                else
                {
                    f2 << p << " " << id << " " << pw << endl;
                }
            }
            f1.close();
            f2.close();
            cout << "\nYour password is successfully updated.\n" << endl;
            remove("temp1.txt");
        }
        void displaytimetable(string n) {
            ifstream f, f1;
            filename = "teacher_tt.txt";
            string f2 = "Teacher.txt";
            f1.open(f2.c_str() );
            f.open(filename.c_str());
            while (f1 >> tch.teacher_reg >> tch.fname >> tch.lname >> tch.dob >> tch.email >> tch.exp >> tch.qual >> tch.Class >> tch.subj) {
                if (n == tch.teacher_reg) {
                    while (f >> st_tt.subj >> st_tt.d1 >> st_tt.d2 >> st_tt.d3 >> st_tt.t1 >> st_tt.t2 >> st_tt.c1 >> st_tt.c2) {
                        if (tch.subj == st_tt.subj) {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if (flag == 1) {
                system("cls");
                cout << "\t\t\t\t\t\t===============================================" << endl;
                cout << "\t\t\t\t\t\t!             CLASSES SCHEDULE                !" << endl;
                cout << "\t\t\t\t\t\t===============================================" << endl << endl;
                cout << "\t\t\t\t\t**************************************************************" << endl << endl;
                cout << "\t***********************************************" << endl;
                cout << "\t  Day " << "  " << st_tt.t1 << "   " << st_tt.t2 << endl;
                cout << "\t  " << st_tt.d1 << "    " << st_tt.c1 << "   \t\t" << st_tt.c2 << "   \t\t" << endl;
                cout << "\t  " << st_tt.d2 << "    " << st_tt.c2 << "   \t\t" << st_tt.c1 << "   \t\t" << endl;
                cout << "\t  " << st_tt.d3 << "    " << st_tt.c1 << "   \t\t" << st_tt.c2 << endl;
                cout << "\t***********************************************" << endl;
            }
            else {
                cout << "Record not found" << endl;
            }
        }

};
class Admin {
public:
    void student_main() {
        LOGIN l;
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << endl;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       1. Register an Student.         !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       2. View Students.               !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       3. Update Students.             !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       4. Give Time Tabele.            !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       5. Exit.                        !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl << endl;
        cout << "Enter your choice: ";
        cout << endl;

        cin >> option;
        switch (option)
        {
        case 1:
        D: {

            filename = "student.txt";
            string file = "Student_login.txt";
            cout << "\n Enter registration no: " << endl;
            cin >> st.streg1;
            cout << "\nEnter student first name: \n";
            cin >> st.fname;
            cout << "\nEnter student last name: \n";
            cin >> st.lname;
            cout << "\nEnter student date of birth(DD/MM/YYYY):\n";
            cin >> st.stdtb;
            cout << "\n Enter  email of student: " << endl;
            cin >> st.stemail;
            cout << "\nEnter student marks in Matriculation:\n ";
            cin >> st.stmarks;
            cout << "\nEnter class of student (11 or 12):\n";
            cin >> st.st_class;
            cout << "\nEnter student course (PM,PE,ICS,ICOM):  \n";
            cin >> st.stsubj;
            cout << "\nEnter last school of student, use _ for space: \n";
            cin>>st.last_school;
            cout << "\nEnter password: \n";
            l.getpasswd();
            ofstream f(filename.c_str(), ios::app);
            ofstream f1(file.c_str(), ios::app);
            f << st.streg1 << "  " << st.fname << " " << st.lname << "  " << st.stdtb << "  " << st.stemail << " " << st.stmarks << "  " << st.st_class << "  " << st.stsubj << "  " << st.last_school << endl;
            f1 << st.streg1 << " " << st.stemail << " " << ps << endl;
            cout << endl << endl;
            cout << "Do you want to add more student(Y or N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                ++i;
                system("cls");
                goto D;

            }
            else if (choice == 'N' || choice == 'n') {
                f.close();
                f1.close();
                system("pause");
                system("cls");
            }

        }
        break;
        case 2:
            view_student();
            system("pause");
            system("cls");
            student_main();
            break;
        case 3:
            update_student();
            system("pause");
            system("cls");
            student_main();
            break;
        case 4:
            system("pause");
            system("cls");
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << endl;
            cout << "\t\t\t\t\t**************************************************************" << endl << endl;
            givesttimetable();
            system("pause");
            system("cls");
            student_main();
            break;
        case 5:
            system("pause");
            system("cls");
            break;
        default:
            cout << "InValid";
            system("pause");
            system("cls");
            student_main();
            break;
        }

    }
    void teacher_main() {
        LOGIN l;
        filename = "Teacher.txt";
        string file1 = "Teacher_login.txt";
        ofstream f2(filename.c_str(), ios::app);
        ofstream f3(file1.c_str(), ios::app);
    H:
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << endl;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       1. Register an Teacher.         !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       2. View Teacher.                !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       3. Update Teacher.              !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       4. Give Time Table.             !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
        cout << "\t\t\t\t\t\t!       5. Exit.                        !" << endl;
        cout << "\t\t\t\t\t\t-----------------------------------------" << endl << endl;
        cout << "Enter your choice: " << endl;
        cin >> option;
        switch (option) {
        case 1:
        F: {

            cout << "\n Enter registration no: " << endl;
            cin >> tch.teacher_reg;
            cout << "\nEnter teacher first name: \n";
            cin >> tch.fname;
            cout << "\nEnter teacher last name: \n";
            cin >> tch.lname;
            cout << "\nEnter teacher date of birth(DD/MM/YYYY):\n";
            cin >> tch.dob;
            cout << "\n Enter qualification: " << endl;
            cin >> tch.qual;
            cout << "\n Enter Expirience: " << endl;
            cin >> tch.exp;
            cout << "\nEnter class which does teacher teach (11 or 12):\n";
            cin >> tch.Class;
            cout << "\n Enter which subject does teacher teach  " << endl;
            cin >> tch.subj;
            cout << "\nEnter Email of teacher: \n";
            cin >> tch.email;
            cout << "\nEnter password: \n";
            l.getpasswd();
            f2 << tch.teacher_reg << "  " << tch.fname << " " << tch.lname << "  " << tch.dob << "  " << tch.email << " " << tch.exp << " " << tch.qual << "  " << tch.Class << "  " << tch.subj << endl;
            f3 << tch.teacher_reg << " " << tch.email << " " << ps << endl;
            cout << endl << endl;
            cout << "Do you want to add more teacher(Y or N): ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                ++i;
                system("cls");
                goto F;

            }
            else if (choice == 'N' || choice == 'n') {
                f2.close();
                f3.close();
                system("pause");
                system("cls");
            }
            break;
        case 2:
            view_teacher();
            system("pause");
            system("cls");
            goto H;
            break;
        case 3:
            update_teacher();
            system("pause");
            system("cls");
            goto H;
            break;
        case 4:
            system("pause");
            system("cls");
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << endl;
            cout << "\t\t\t\t\t**************************************************************" << endl << endl;
            givetttimetable();
            system("pause");
            system("cls");
            teacher_main();
            break;
        case 5:
            break;
        default:
            cout << "Invalid\a";
            system("pause");
            system("cls");
            goto H;
        }
        }

    }
    void view_teacher() {
        cout << "Enter Y or y for view teacher list:" << endl;
        cin >> choice;
        system("cls");
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << endl;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        ifstream f1;
        f1.open("Teacher.txt");
        while (f1 >> tch.teacher_reg >> tch.fname >> tch.lname >> tch.dob >> tch.email >> tch.exp >> tch.qual >> tch.Class >> tch.subj) {
            if (choice == 'Y' || choice == 'y') {
                cout << "\t***************************************************************" << endl;
                cout << "\t       CMS ID:             |     " << tch.teacher_reg << "            " << endl;
                cout << "\t       Name:               |     " << tch.fname << " " << tch.lname << endl;
                cout << "\t       Email:              |     " << tch.email << endl;
                cout << "\t       DOB:                |     " << tch.dob << endl;
                cout << "\t      Class teaches:       |     " << tch.Class << endl;
                cout << "\t      Subject teach:       |     " << tch.subj << endl;
                cout << "\t      Qualification:       |     " << tch.qual << endl;
                cout << "\t***************************************************************" << endl;
            }
        }
        f1.close();
        system("pause");


    }
    void view_student() {
        cout << "Enter Y or y for view student list:" << endl;
        cin >> choice;
        system("cls");
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << endl;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        ifstream f1;
        f1.open("student.txt");
        while (f1 >> st.streg1 >> st.fname >> st.lname >> st.stdtb >> st.stemail >> st.stmarks >> st.st_class >> st.stsubj >> st.last_school) {
            if (choice == 'Y' || choice == 'y') {
                cout << "\t***************************************************" << endl;
                cout << "\t       CMS ID:      |     " << st.streg1 << endl;
                cout << "\t       Name:        |     " << st.fname << " " << st.lname << endl;
                cout << "\t       Email:       |     " << st.stemail << endl;
                cout << "\t       DOB:         |     " << st.stdtb << endl;
                cout << "\t       Class:       |     " << st.st_class << endl;
                cout << "\t       Course:      |     " << st.stsubj << endl;
                cout << "\t  Last Institution  |     " << st.last_school << endl;
                cout << "\t****************************************************" << endl;
            }
        }
        f1.close();
        system("pause");
      
        
    }
    void update_student() {
        ifstream f;
        filename = "student.txt";
        f.open(filename.c_str());
        fstream f1;
        f1.open("temp3.txt", ios::trunc);
        f1.close();
        f1.open("temp3.txt", ios::out);
        while (f >> st.streg1 >> st.fname >> st.lname >> st.stdtb >> st.stemail >> st.stmarks >> st.st_class >> st.stsubj >> st.last_school) {
            f1 << st.streg1 <<" " << st.fname <<" " << st.lname<<" " << st.stdtb<<" " << st.stemail <<" " << st.stmarks <<" " << st.st_class <<" " << st.stsubj <<" " << st.last_school << endl;
        }
        f.close();
        f1.close();
        
        cout << "Enter registration no: " << endl;
        cin >> regno;
        filename = "temp3.txt";
        f.open(filename.c_str());
        f1.open("student.txt",ios::trunc);
        f1.close();
        f1.open("student.txt", ios::out);
        while (f >> st.streg1 >> st.fname >> st.lname >> st.stdtb >> st.stemail >> st.stmarks >> st.st_class >> st.stsubj >> st.last_school) {
            if (regno == st.streg1) 
                continue;
                f1 << st.streg1 <<" " << st.fname<<" " << st.lname<<" " << st.stdtb <<" " << st.stemail <<" " << st.stmarks <<" " << st.st_class <<" " << st.stsubj <<" " << st.last_school << endl;
        }
        f.close();
        f1.close();
        remove("temp3.txt");
        filename = "Student_login.txt";
        f.open(filename.c_str());
        f1.open("temp2.txt", ios::trunc);
        f1.close();
        f1.open("temp2.txt", ios::out);
        while (f >> st.streg1 >> st.stemail >> st.stpass) {
            f1 << st.streg1 << " " << st.stemail << " " << st.stpass << endl;
        }
        f.close();
        f1.close();
        filename = "temp2.txt";
        f.open(filename.c_str());
        f1.open("Student_login.txt", ios::trunc);
        f1.close();
        f1.open("Student_login.txt", ios::out);
        while (f >> st.streg1 >> st.stemail >> st.stpass) {
            if (regno == st.streg1)
                continue;
            f1 << st.streg1 << " " << st.stemail << " " << st.stpass << endl;
        }
        f.close();
        f1.close();
        remove("temp2.txt");
    }
    void update_teacher() {
        ifstream f;
        filename = "Teacher.txt";
        f.open(filename.c_str());
        fstream f1;
        f1.open("temp3.txt", ios::trunc);
        f1.close();
        f1.open("temp3.txt", ios::out);
        while (f >> tch.teacher_reg >> tch.fname >> tch.lname >> tch.dob >> tch.email >> tch.exp >> tch.qual >> tch.Class >> tch.subj) {
            f1 << tch.teacher_reg << " " << tch.fname << " " << tch.lname << " " << tch.dob << " " << tch.email << " " << tch.exp << " " << tch.qual << " " << tch.Class << " " << tch.subj << endl;
        }
        f.close();
        f1.close();

        cout << "Enter registration no: " << endl;
        cin >> regno;
        filename = "temp3.txt";
        f.open(filename.c_str());
        f1.open("Teacher.txt", ios::trunc);
        f1.close();
        f1.open("Teacher.txt", ios::out);
        while (f >> tch.teacher_reg >> tch.fname >> tch.lname >> tch.dob >> tch.email >> tch.exp >> tch.qual >> tch.Class >> tch.subj) {
            if (regno == tch.teacher_reg)
                continue;
            f1 << tch.teacher_reg << " " << tch.fname << " " << tch.lname << " " << tch.dob << " " << tch.email << " " << tch.exp << " " << tch.qual << " " << tch.Class << " " << tch.subj << endl;
        }
        f.close();
        f1.close();
        remove("temp3.txt");

        filename = "Teacher_login.txt";
        f.open(filename.c_str());
        f1.open("temp2.txt", ios::trunc);
        f1.close();
        f1.open("temp2.txt", ios::out);
        while (f >> tch.teacher_reg>>tch.email>>tch.pass) {
            f1 << tch.teacher_reg << " " << tch.email << " " << tch.pass << endl;
        }
        f.close();
        f1.close();
        filename = "temp2.txt";
        f.open(filename.c_str());
        f1.open("Teacher_login.txt", ios::trunc);
        f1.close();
        f1.open("Teacher_login.txt", ios::out);
        while (f >> tch.teacher_reg >> tch.email >> tch.pass) {
            if (regno == tch.teacher_reg)
                continue;
            f1 << tch.teacher_reg << " " << tch.email << " " << tch.pass << endl;
        }
        f.close();
        f1.close();
        remove("temp2.txt");
    }
    void givesttimetable() {
        ofstream f;
        filename = "student_tt.txt";
        cout << "Enter Specific subject (PE,ICS,ICOM,PM): " << endl;
        cin >> st_tt.subj;
        cout << "Enter Specific subject of " << st_tt.subj << ": " << endl;
        cin >> st_tt.subj1;
        cout << "Enter Specific subject of " << st_tt.subj << ": " << endl;
        cin >> st_tt.subj2;
        cout << "Enter Specific subject of " << st_tt.subj << ": " << endl;
        cin >> st_tt.subj3;
        cout << "Enter Specific subject of " << st_tt.subj << ": " << endl;
        cin >> st_tt.subj4;
        cout << "Enter Specific subject of " << st_tt.subj << ": " << endl;
        cin >> st_tt.subj5;
        cout << "Enter Specific subject of " << st_tt.subj << ": " << endl;
        cin >> st_tt.subj6;
        cout << "Enter day1 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d1;
        cout << "Enter day2 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d2;
        cout << "Enter day3 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d3;
        cout << "Enter day4 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d4;
        cout << "Enter day5 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d5;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t1;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t2;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t3;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t4;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t5;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t6;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t7;
        f.open(filename.c_str(),ios::app);
        f << st_tt.subj << " " << st_tt.subj1 << " " << st_tt.subj2 << " " << st_tt.subj3 << " " << st_tt.subj4 << " " << st_tt.subj5 << " " << st_tt.subj6 << " " << st_tt.d1 << " " << st_tt.d2 << " " << st_tt.d3 << " " << st_tt.d4 << " " << st_tt.d5 << " " << st_tt.t1 << " " << st_tt.t2 << " " << st_tt.t3 << " " << st_tt.t4 << " " << st_tt.t5 << " " << st_tt.t6 <<" "<<st_tt.t7 << endl;
        cout << "If you want to add more time table then press Y or y, else N or n: " << endl;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            system("pause");
            system("cls");
            givesttimetable();
        }
        else {
            system("pause");
            system("cls");
            student_main();
        }
    }
    void givetttimetable() {
        ofstream f;
        filename = "teacher_tt.txt";
        cout << "Enter Specific subject : " << endl;
        cin >> st_tt.subj;
        
        cout << "Enter day1 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d1;
        cout << "Enter day2 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d2;
        cout << "Enter day3 as (MON,TUE,WED,THUR,FRI): " << endl;
        cin >> st_tt.d3;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t1;
        cout << "Enter time1 as (HH:MM-HH:MM): " << endl;
        cin >> st_tt.t2;
        cout << "Enter class (11 or 12) if not teach then (-): " << endl;
        cin >> st_tt.c1;
        cout << "Enter class (11 or 12) if not teach then (-): " << endl;
        cin >> st_tt.c2;
        f.open(filename.c_str(),ios::app);
        f << st_tt.subj << " " << st_tt.subj1 <<" " << st_tt.d1 << " " << st_tt.d2 << " " << st_tt.d3 << " " << st_tt.t1 << " " << st_tt.t2 << " "<<st_tt.c1<<" "<<st_tt.c2 << endl;
        cout << "If you want to add more time table then press Y or y, else N or n: " << endl;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            system("pause");
            system("cls");
            givesttimetable();
        }
        else {
            system("pause");
            system("cls");
            teacher_main();
        }
    }

};
void student_section() {
    cout << endl;
    system("cls");
    cout << "\t\t\t\t\t\t===============================================" << endl;
    cout << "\t\t\t\t\t\t!          WELCOME TO STUDENT DASHBOARD       !" << endl;
    cout << "\t\t\t\t\t\t===============================================" << endl <<endl;
    cout << "\t\t\t\t\t**************************************************************" << endl << endl;
}



int main() {
  
main: {

    cout << "\t\t\t\t\t\t===============================================" << endl;
    cout << "\t\t\t\t\t\t!          COLLEGE MANAGEMENT SYSTEM          !" << endl;
    cout << "\t\t\t\t\t\t===============================================" << endl;
    cout << endl;
    cout << "\t\t\t\t\t**************************************************************" << endl << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t !       1. Log in as Student.           !" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t !       2. Log in as Teacher.           !" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t !       3. Log in as Admin.             !" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << "\t\t\t\t\t\t !       4. Exit.                        !" << endl;
    cout << "\t\t\t\t\t\t -----------------------------------------" << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> option;
    switch (option) {
    case 1:
    B: {
        system("cls");
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          STUDENT LOG IN SYSTEM              !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl << endl;;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        cout << endl;
            LOGIN l;
            string l1, l2, ll;
                filename = "Student_login.txt";
            l.putpass();
            
            ifstream f2;
            f2.open(filename.c_str());
            while (f2 >> l1 >> ll >>l2) {
               flag = l.cmp(l1, l2);
                if (flag == 1)
                    break;

            }
            f2.close();
            if (flag == 1) {
            E: {
                student_section();
                cout << endl;
                cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
                cout << "\t\t\t\t\t\t!       1. Personal Profile             !" << endl;
                cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
                cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
                cout << "\t\t\t\t\t\t!       2. Time table.                  !" << endl;
                cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
                cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
                cout << "\t\t\t\t\t\t!       3.Exit                          !" << endl;
                cout << "\t\t\t\t\t\t-----------------------------------------" << endl << endl;
                cout << "Enter your choice: " << endl;
                cin >> main_option;
                switch (main_option) {
                case 1:
                    Student S;
                    S.stdetail(u);
                    system("pause");
                    system("cls");
                    goto E;
                    break;
                case 2:
                    Student s;
                    s.displaytimetable(u);
                    system("pause");
                    system("cls");
                    goto E;
                    break;
                case 3:
                    system("cls");
                    goto main;
                    break;
                default:
                    cout << "Invalid\a" << endl;
                    system("pause");
                    system("cls");
                    goto E;
                    break;
                }
                }
            }
            else {
                char choice;
                cout << "\nInvalid!\a"<<endl;
                cout << "Do you want to continue?" << endl;
                cout << "If you forget the password press Y or y, for try again press N or n: " << endl;
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                    Student s;
                    s.forgetpassword();
                    system("pause");
                    system("cls");
                    goto B;
                }
                else {
                    system("cls");
                    goto B;
                }
            }

        }
    
          system("pause");
          system("cls");
          goto main;
          break;
    
    case 2:
    D: {
        system("cls");
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          TEACHER LOG IN SYSTEM              !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl << endl;;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        LOGIN l5;
        string l3, l4,ll, filename = "Teacher_login.txt";
        l5.putpass();
        ifstream f3;
        f3.open(filename.c_str());
        while (f3 >> l3 >> ll >> l4) {
            flag = l5.cmp(l3, l4);
            if (flag == 1)
                break;
        }
        f3.close();
        if (flag == 1) {
            J:
            Teacher t;
            system("cls");
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << "\t\t\t\t\t\t!          WELCOME TO TEACHER DASHBOARD       !" << endl;
            cout << "\t\t\t\t\t\t===============================================" << endl<<endl;
            cout << "\t\t\t\t\t**************************************************************" << endl << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t!       1. Personal Profile             !" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t!       2. Time Table.                  !" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t!       3. Exit.                        !" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl<<endl;
            cout << "Enter your choice: " << endl;
            cin >> option;
            switch (option) {
            case 1:
                t.tdetail(u);
                system("pause");
                system("cls");
                goto J;
                break;
            case 2:
                Teacher t;
                t.displaytimetable(u);
                system("pause");
                system("cls");
                goto J;
                break;
            case 3:
                system("cls");
                goto main;
                break;
            default:
                cout << "Invalid\a" << endl;
                system("pause");
                system("cls");
                goto J;
                break;
            }
            system("cls");
            goto D;
        }
        else {
            char choice;
            string e1, un;
            cout << "\nInvalid!\a" << endl;
            cout << "Do you want to continue?" << endl;
            cout << "If you forget the password press Y or y, for try again press N or n: " << endl;
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                Teacher t;
                t.forgetpassword();
                system("pause");
                system("cls");
                goto D;
            }
            else {
                system("cls");
                goto B;
            }
        }
        break;
    }
    case 3:
        system("cls");

    C: {
        Admin A;
        int flag;
        string admin = "Admin", pss = "admin";
        cout << "\t\t\t\t\t\t===============================================" << endl;
        cout << "\t\t\t\t\t\t!          ADMIN LOG IN  SYSTEM               !" << endl;
        cout << "\t\t\t\t\t\t===============================================" << endl<<endl;
        cout << "\t\t\t\t\t**************************************************************" << endl << endl;
        cout << endl;

        LOGIN l;
        l.putpass();

        flag = l.cmp(admin, pss);
        if (flag == 1) {
            cout << "Access Granted!" << endl;
            system("cls");
        G: {
            cout << "\t\t\t\t\t\t===============================================" << endl;
            cout << "\t\t\t\t\t\t!          WELCOME TO ADMIN DASHBOARD         !" << endl;
            cout << "\t\t\t\t\t\t===============================================" << endl<<endl;
            cout << "\t\t\t\t\t**************************************************************" << endl << endl;
            cout << endl << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t!       1. Student Section.             !" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t!       2. Teacher Section.             !" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl;
            cout << "\t\t\t\t\t\t!       3. Exit.                        !" << endl;
            cout << "\t\t\t\t\t\t-----------------------------------------" << endl << endl;
            cout << "Enter your choice: " << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                system("cls");
                cout << endl;
                A.student_main();
                system("cls");
                goto G;
                break;
            case 2:
                system("cls");
                A.teacher_main();
                system("cls");
                goto G;
                break;
            case 3:
                system("cls");
                goto main;
            default:
                cout << "Invalid!\a";
                system("cls");
                goto G;
                break;
            }
            }
        }
        else
        {
            flag == 0;
            cout << "Access Denied " << endl;
            system("cls");
            goto C;


        }
        system("pause");
        system("cls");
        goto main;
        }
        break;
    case 4:
        system("cls");
        return 0;
        break;
    default:
        cout << "Invalid\a" << endl;
        system("pause");
        system("cls");
        goto main;
        break;
   

    }
    }
    return 0;
}