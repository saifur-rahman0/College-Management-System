#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <string.h>

void main_menu();
void gotocr(int, int);
void admin_login_f();
void admin_home_f();
void aStudent();
void aTeacher();
void aClubs();
void show_mem_f();
void show_club_list();
void add_std_panel();
void mod_mem_f();
void add_club();
void std_login_f();
void std_home_f();
void sub_list_f();
void add_member_f(char []);
void search_mem_f();
void del_mem_f();
void quite_f();

typedef struct catagory
{
    char id[15];
    char name[20];
    char dept[10];
    long int number;
}cat;
cat mem;
int i, point;
char sign= 176;
int main()
{
    main_menu();
}
void main_menu()
{
    char sign=176;
    gotocr(35,11);
	printf("\t\t%c  <1> : Admin Panel",sign);
	gotocr(35,13);
	printf("\t\t%c  <2> : Student Panel",sign);
	gotocr(35,15);
	printf("\t\t%c  <0> : Quit",sign);
	gotocr(35, 19);
	printf("Enter your choice: ");
	switch(getch() )
	{
    case '1':
        admin_login_f();
        break;
    case '2':
        std_login_f();
        break;
    case '0':
        quite_f();
    default:
        gotocr(35, 23);
        printf("\aWrong Entry! Please re-entered correct option");
        if(getch())
            main_menu();
	}
}
void admin_login_f()
{
    system("cls");
    int i;
    char save_pass[10]= {"saifur"}, pass[10], ch;
    gotocr(35, 11);
    printf("Admin Login Panel");
    gotocr(35,15);
    printf("Enter Password: ");
    while(ch != 13)
    {
        ch= getch();
        if(ch !=13 && ch != 8)
        {
            putch('*');
            pass[i]= ch;
            i++;
        }
    }
    pass[i]= '\0';
    if(strcmp(pass, save_pass)== 0)
    {
        printf("\n\n\t\t\tPassword Matched");
        printf("\n\n\t\t\tPress any key to continue.....");
        getch();
        admin_home_f();
    }
    else
    {
        printf("\n\n\t\t\t\aWarning!!\tIncorrect Password");
        getch();
        admin_login_f();
    }
}
void admin_home_f()
{
    system("cls");
    gotocr(40, 9);
    printf("Admin Section");
    gotocr(35, 11);
    printf("\t%c <1> : Student", sign);
    gotocr(35, 13);
    printf("\t%c <2> : Teachers", sign);
    gotocr(35, 15);
    printf("\t%c <3> : Courses", sign);
    gotocr(35, 17);
    printf("\t%c <4> : Clubs", sign);
    gotocr(35, 19);
    printf("\t%c <0> : Quite", sign);
    gotocr(35, 21);
    printf("\tEnter a Choice");
    switch(getch() )
    {
    case '1':
        aStudent();
        break;
    case '2':
        aTeacher();
        break;
    case '3':
        point=0;
        sub_list_f();
        break;
    case '4':
        aClubs();
        break;
    case '0':
        quite_f();
        break;
    default:
        gotocr(35,23);
        printf("Invalid Choice...");
        admin_home_f();
        break;
    }
}
void aStudent()
{
    system("cls");
    point= 0;
    char file[]= "student_list.txt";
    gotocr(40, 9);
    printf("Admin Student Section");
    gotocr(35, 11);
    printf("\t%c <1> : View Student Information", sign);
    gotocr(35, 13);
    printf("\t%c <2> : Add Student", sign);
    gotocr(35, 15);
    printf("\t%c <3> : Add Student Panel", sign);
    gotocr(35, 17);
    printf("\t%c <4> : Modify Students", sign);
    gotocr(35, 19);
    printf("\t%c <5> : Remove Students", sign);
    gotocr(35, 21);
    printf("\t%c <6> : Search Students", sign);
    gotocr(35, 23);
    printf("\t%c <7> : Back to Admin Section", sign);
    gotocr(35, 25);
    printf("\t%c <0> : Quite", sign);
    switch (getch())
    {
    case '1':
        show_mem_f();
        break;
    case '2':
        add_member_f(file);
    case '3':
        add_std_panel();
        break;
    case '4':
        mod_mem_f();
        break;
    case '5':
        del_mem_f();
        break;
    case '6':
        search_mem_f();
        break;
    case '7':
        admin_home_f();
    case '0':
        quite_f();
    default:
        gotocr(35, 23);
        printf("\aWrong Entry! Please re-entered correct option");
        if(getch())
            aStudent();
    }

}
void aTeacher()
{
    system("cls");
    point= 1;
    char file[]= "teacher_list.txt";
    gotocr(40, 9);
    printf("Admin Teachers Section");
    gotocr(35, 11);
    printf("\t%c <1> : View Teachers List", sign);
    gotocr(35, 13);
    printf("\t%c <2> : Add Teachers", sign);
    gotocr(35, 15);
    printf("\t%c <3> : Search Teachers", sign);
    gotocr(35, 17);
    printf("\t%c <4> : Modify Teachers", sign);
    gotocr(35, 19);
    printf("\t%c <5> : Remove Teachers", sign);
    gotocr(35, 21);
    printf("\t%c <6> : Back to Admin Section", sign);
    gotocr(35, 23);
    printf("\t%c <0> : Quite", sign);
    switch(getch())
    {
    case '1':
        show_mem_f();
        break;
    case '2':
        add_member_f(file);
        break;
    case '3':
        search_mem_f();
        break;
    case '4':
        mod_mem_f();
        break;
    case '5':
        del_mem_f();
        break;
    case '6':
        admin_home_f();
        break;
    case '0':
        quite_f();
        break;
    default:
        gotocr(35, 23);
        printf("\aWrong Entry! Please re-entered correct option");
        if(getch())
        {
            aTeacher();
        }
    }
}
void aClubs()
{
    system("cls");
 	gotocr(35,2);
	printf("  Club Section  ");
	gotocr(35,11);
	printf("%c <1>: View Clubs List", sign);
	gotocr(35,13);
	printf("%c <2>: Add Clubs", sign);
	gotocr(35,15);
	printf("%c <3>: Back to AdminSection",sign);
	gotocr(35,17);
	printf("%c <0>: Quit",sign);
	gotocr(35,21);
	printf("\t\t Enter any Option:");
    switch(getch())
    {
    case '1':
        show_club_list();
        gotocr(35, 20);
        printf("Press any key to get back.");
        getch();
        aClubs();
        break;
    case '2':
        add_club();
        break;
    case '3':
        admin_home_f();
        break;
    case '0':
        quite_f();
    default:
        gotocr(35, 23);
        printf("\aWrong Entry! Please re-entered correct option");
        if(getch())
            aClubs();
    }
}
void std_login_f()
{
    system("cls");
    int point= 0, i;
    char u_name[10], pass[10], fstr[20], fpwr[10], pass_pwrd[10], ch;
    FILE *fptr;
    fptr= fopen("std_l_info.txt", "r");
    gotocr(35, 13);
    printf("Username: ");
    scanf("%s",u_name);
    gotocr(35,17);
    printf("Password: ");
    while(!feof(fptr))
    {
        fscanf(fptr,"%s", fstr); //fgets(fstr, 50, fptr)
        if(strcmp(u_name, fstr) == 0)
        {
            point= 1;
            gotocr(45, 17);
            for(i=0; i<20; i++)
            {
                ch= getch();
                pass[i]= ch;
                if(ch == 13)
                {
                    break;
                }
                if(ch!=13)
                {
                    printf("*");
                }
            }
            pass[i]= '\0';
            fscanf(fptr, "%s", fpwr);
            if(strcmp(pass, fpwr) == 0)
            {
                gotocr(35, 21);
                printf("You are successfully login to admin panel.");
                break;
            }
            else
            {
                gotocr(35, 21);
                printf("Invalid Password, Please try again....");
                std_login_f();
            }
        }
        else
        {
            fscanf(fptr, "%s", pass_pwrd);
        }
    }
    if(point == 0)
    {
        gotocr(35, 14);
        printf("Invalid Username, Please insert right username...");
        printf("\nPress any key to try again.");
        getch();
        std_login_f();
    }
    fclose(fptr);
    std_home_f();
}
void std_home_f()
{
    system("cls");
    gotocr(40,2);
    printf("Student Panele");
    gotocr(35, 11);
    printf("\t%c <1> : Subject List", sign);
    gotocr(35, 13);
    printf("\t%c <2> : Lecture Shedule", sign);
    gotocr(35, 15);
    printf("\t%c <3> : Club List", sign);
    gotocr(35, 17);
    printf("\t%c <0> : Quite", sign);
    gotocr(35, 23);
    printf("Enter your choice: ");
    switch(getch())
    {
    case '1':
        point=1;
        sub_list_f();
    case '2':
        system("cls");
        gotocr(35, 15);
        printf("Lecture Shedule will be published");
        getch();
        std_home_f();
        break;
    case '3':
        show_club_list();
        gotocr(35, 20);
        printf("Press any key to get back.");
        getch();
        std_home_f();
        break;
    case '0':
        quite_f();
    default:
        gotocr(35, 23);
        printf("\aWrong Entry! Please re-entered correct option");
        if(getch())
            std_home_f();
    }
}
void show_club_list()
{
    system("cls");
    FILE *fptr;
    char read[50];
    fptr= fopen("club_list.txt", "r");
    gotocr(40, 2);
    printf("Club List");
    gotocr(0, 5);
    i=1;
    while(!feof(fptr))
    {
        //fscanf(fptr, "%s", read);
        fgets(read, 50, fptr);
        printf("%d. %s",i++, read);
    }
}
void add_club()
{
    system("cls");
    FILE *fptr;
    char chr[50], yn;
    fptr= fopen("club_list.txt", "a+");
    fputs("\n", fptr);
    gotocr(40, 2);
    printf("Add Clubs Name");
    gotocr(35, 9);
    printf("Enter the clube name: ");
    gets(chr);
    fprintf(fptr, "%s", chr);
    gotocr(35, 15);
    printf("Club name is added in Database");
    fclose(fptr);
    jump:
    gotocr(35, 17);
    printf("Do you want add one more club name? (Y/N)");
    switch(getch())
    {
    case 'y':
        add_club();
    case 'Y':
        add_club();
    case 'n':
        admin_home_f();
    case 'N':
        admin_home_f();
    default:
        gotocr(35, 19);
        printf("please insert correct character and Use (y, Y, n, N) letters only");
        goto jump;
    }
}
void sub_list_f()
{
    system("cls");
    gotocr(40, 2);
    printf("Course List");
    gotocr(35, 7);
    printf("\t%c <1> : Semester I", sign);
    gotocr(35, 9);
    printf("\t%c <2> : Semester II", sign);
    gotocr(35, 11);
    printf("\t%c <3> : Semester III", sign);
    gotocr(35, 13);
    printf("\t%c <4> : Semester IV", sign);
    gotocr(35, 15);
    printf("\t%c <5> : Semester V", sign);
    gotocr(35, 17);
    printf("\t%c <6> : Semester VI", sign);
    gotocr(35, 19);
    printf("\t%c <7> : Semester VII", sign);
    gotocr(35, 21);
    printf("\t%c <8> : Semester VIII", sign);
    gotocr(35, 24);
    printf("\t%c <9> : Back to main menu", sign);
    gotocr(35, 27);
    printf("Enter your Choice: ");
    switch(getch())
    {
    case '1':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester I subject list");
        gotocr(5, 9);
        printf("%c >> Fundamental of Computers and Computing", sign);
        gotocr(5, 11);
        printf("%c >> Discrete Mathmatics", sign);
        gotocr(5, 13);
        printf("%c >> Chemistry", sign);
        gotocr(5, 15);
        printf("%c >> Differential and Integral Calculus", sign);
        gotocr(5, 17);
        printf("%c >> Government and Public Administation", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
        break;
    case '2':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester II subject list");
        gotocr(5, 9);
        printf("%c >> Fundamental of Programming", sign);
        gotocr(5, 11);
        printf("%c >> Digital Logic Design", sign);
        gotocr(5, 13);
        printf("%c >> Physics", sign);
        gotocr(5, 15);
        printf("%c >> Methods of Integration, Differential Equation and Series", sign);
        gotocr(5, 17);
        printf("%c >> Developing English Language Skills", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '3':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester III subject list");
        gotocr(5, 9);
        printf("%c >> Data Structures and Algorithm", sign);
        gotocr(5, 11);
        printf("%c >> Object Oriented Programming", sign);
        gotocr(5, 13);
        printf("%c >> Digital Electronics and Pulse Technique", sign);
        gotocr(5, 15);
        printf("%c >> Electronic Devices and Circuits", sign);
        gotocr(5, 17);
        printf("%c >> Linear Algebra", sign);
        gotocr(5, 19);
        printf("%c >> Bangladesh Studies", sign);
        gotocr(5, 23);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '4':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester IV subject list");
        gotocr(5, 9);
        printf("%c >> Database and Management Systems-I", sign);
        gotocr(5, 11);
        printf("%c >> Design and Analysis of Algorithm-I", sign);
        gotocr(5, 13);
        printf("%c >> Data and Telecommunication", sign);
        gotocr(5, 15);
        printf("%c >> Computer Architecture and Organization", sign);
        gotocr(5, 17);
        printf("%c >> introduction of Mechatronics", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '5':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester V subject list");
        gotocr(5, 9);
        printf("%c >> Computer Networking", sign);
        gotocr(5, 11);
        printf("%c >> Software Engineering", sign);
        gotocr(5, 13);
        printf("%c >> Microprocessor and Microcontroller", sign);
        gotocr(5, 15);
        printf("%c >> Database Management System-II", sign);
        gotocr(5, 17);
        printf("%c >> Multivariable Calculus and Geometry", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '6':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester VI subject list");
        gotocr(5, 9);
        printf("%c >> Operating Systems", sign);
        gotocr(5, 11);
        printf("%c >> numerical Methods", sign);
        gotocr(5, 13);
        printf("%c >> Design and Analysis of Algorithms - II", sign);
        gotocr(5, 15);
        printf("%c >> Formal Language, Automata and Computability", sign);
        gotocr(5, 17);
        printf("%c >> Introduction of Probability and Statistics", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '7':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester VII subject list");
        gotocr(5, 9);
        printf("%c >> Artificial Intelligence", sign);
        gotocr(5, 11);
        printf("%c >> Mathematical and Statistical Analysis for Engineers", sign);
        gotocr(5, 13);
        printf("%c >> Entrepreneurship fo IT Business", sign);
        gotocr(5, 15);
        printf("%c >> Option - I", sign);
        gotocr(5, 17);
        printf("%c >> Option - II", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '8':
        system("cls");
        gotocr(40, 2);
        printf("Subject List");
        gotocr(35, 5);
        printf("Semester VIII subject list");
        gotocr(5, 9);
        printf("%c >> Economics", sign);
        gotocr(5, 11);
        printf("%c >> Society and Technology", sign);
        gotocr(5, 13);
        printf("%c >> Engineering Ethics", sign);
        gotocr(5, 15);
        printf("%c >> Option - III", sign);
        gotocr(5, 17);
        printf("%c >> Option - IV", sign);
        gotocr(5, 21);
        printf("Press any key to back...");
        getch();
        sub_list_f();
    case '9':
        if(point == 0)
        {
            admin_home_f();
        }
        if(point == 1)
        {
            std_home_f();
        }
    default:
        gotocr(40, 27);
        printf("please insert correct option...");
        getch();
        sub_list_f();
    }
}
void add_member_f(char fname[])
{
    system("cls");
    FILE *fptr;
    fptr= fopen(fname, "a+");
    if(fptr == NULL)
    {
        printf("Unable to open '%s' file", fname);
        getch();
        quite_f();
    }
    gotocr(40, 2);
    if(point == 0)
    {
        printf("Add Student");
    }
    if(point == 1)
    {
        printf("Add Teacher");
    }
    gotocr(35, 9);
    printf("Enter Member ID: " );
    scanf("%s", &mem.id);
    gotocr(35, 11);
    printf("Enter Name: ");
    scanf(" %[^\n]s",mem.name);
    gotocr(35, 13);
    printf("Enter Department name: ");
    scanf(" %[^\n]s",mem.dept);
    gotocr(35, 15);
    printf("Enter Contact Number: ");
    scanf("%ld", &mem.number);
    fseek(fptr, 0, SEEK_END);
    fwrite(&mem, sizeof(mem), 1, fptr);
    fclose(fptr);
    gotocr(35, 18);
    printf("Successfully Member added to Database");
    gotocr(35, 20);
    printf("Do you want to add more? (Y/N): ");
    switch(getch())
    {
    case 'y':
        add_member_f(fname);
    case 'Y':
        add_member_f(fname);
    case 'n':
        if(point == 0)
        {
            aStudent();
        }
        if(point == 1)
        {
            aTeacher();
        }
    case 'N':
        if(point == 0)
        {
            aStudent();
        }
        if(point == 1)
        {
            aTeacher();
        }
    }
}
void show_mem_f()
{
    system("cls");
    int j;
    char chr;
    FILE *fptr;
    gotocr(40, 2);
    if(point == 0)
    {
        printf("Show Students List");
        fptr= fopen("student_list.txt", "r");
    }
    if(point == 1)
    {
        printf("Show Teachers List");
        fptr= fopen("teacher_list.txt", "r");
    }
    gotocr(2,2);
    printf("\n\n    ID                   NAME        COURSE       CONTACT     ");
    j=6;
    while(fread(&mem, sizeof(mem), 1, fptr) == 1)
    {
        gotocr(1,j);
        printf("%s", mem.id);
        gotocr(23,j);
        printf("%s", mem.name);
        gotocr(39,j);
        printf("%s", mem.dept);
        gotocr(50,j);
        printf("%ld",mem.number);
        printf("\n");
        j++;
    }
    fclose(fptr);
    printf("\n\n\n\tPress any key to go back");
    getch();
    if(point == 0)
    {
        aStudent();
    }
    if(point == 1)
    {
        aTeacher();
    }
}
void add_std_panel()
{
    system("cls");
    char str1[15], str2[15], temp[15];
    FILE *fptr;
    fptr= fopen("std_l_info.txt", "a+");
    gotocr(40, 2);
    printf("Add Student Panel");
    gotocr(35, 9);
    printf("Enter Student Username: ");
    scanf("%s", str1);
    while(fscanf(fptr, "%s", temp) == 1)
    {
        if(strcmp(temp, str1) == 0)
        {
            gotocr(35, 12);
            printf("\aThe Username already exists..");
            getch();
            add_std_panel();
        }
    }
    fprintf(fptr, "%s", str1);
    fputs("\n", fptr);
    gotocr(35, 11);
    printf("Enter Student Password: ");
    scanf("%s", str2);
    fprintf(fptr, "%s", str2);
    fputs("\n", fptr);
    fclose(fptr);
    jump:
    gotocr(35, 14);
    printf("Do you want to add one more? (y/n)");
    switch(getch())
    {
    case 'y':
        add_std_panel();
        break;
    case 'Y':
        add_std_panel();
        break;
    case 'n':
        aStudent();
        break;
    case 'N':
        aStudent();
        break;
    default:
        gotocr(35, 16);
        printf("Please Enter correct character..");
        getch();
        goto jump;
    }
}

void search_mem_f()
{
    system("cls");
    int flag= 0;
    char read[15];
    FILE *fptr;
    gotocr(40, 2);
    if(point == 0)
    {
        printf("Search Student");
        fptr= fopen("student_list.txt", "r");
        if(fptr == NULL)
        {
            printf("Unable to open 'student_list.txt' file.");
        }
    }
    if (point == 1)
    {
        printf("Search Teacher");
        fptr= fopen("teacher_list.txt", "r");
        if(fptr == NULL)
        {
            printf("Unable to open 'teacher_list.txt' file.");
        }
    }
    gotocr(35, 5);
    printf("%c <1> Search By ID", sign);
    gotocr(35, 7);
    printf("%c <2> Search By Name", sign);
    gotocr(35, 9);
    printf("%c <3> Back to Menu", sign);
    jump:
    gotocr(35, 12);
    printf("Enter Your Choice");
    switch(getch())
    {
    case '1':
        jump2:
        system("cls");
        gotocr(35, 7);
        printf("Enter the ID: ");
        scanf("%s", read);
        while(fread(&mem, sizeof(mem), 1, fptr) == 1)
        {
            if(strcmp(mem.id, (read)) == 0)
            {
                gotocr(35, 9);
                printf("The Record is Available");
                gotocr(35, 13);
                printf("ID: %s",mem.id);
                gotocr(35, 15);
                printf("Name:%s",mem.name);
                gotocr(35, 17);
                printf("Department Name: %s ",mem.dept);
                gotocr(35, 19);
                printf("Contact: %ld ",mem.number);
                flag= 1;
            }
        }
        if(flag == 0)
        {
            gotocr(35, 15);
            printf("\aNo Record Found");
            getch();
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
        }
        jump3:
        gotocr(35, 25);
        printf("Try another search?(Y/N)");
        switch(getch())
        {
        case 'y':
            goto jump2;
            break;
        case 'Y':
            goto jump2;
            break;
        case 'n':
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
            break;
        case 'N':
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
            break;
        default:
            gotocr(35, 27);
            printf("Please Enter correct character..");
            getch();
            goto jump3;
            break;
        }
        break;
    case '2':
        c2j2:
        system("cls");
        gotocr(35, 7);
        printf("Enter the Name: ");
        scanf("%s", read);
        while(fread(&mem, sizeof(mem), 1, fptr) == 1)
        {
            if(strcmp(mem.name, (read)) == 0)
            {
                gotocr(35, 9);
                printf("The Record is Available");
                gotocr(35, 13);
                printf("ID: %s",mem.id);
                gotocr(35, 15);
                printf("Name:%s",mem.name);
                gotocr(35, 17);
                printf("Department Name: %s ",mem.dept);
                gotocr(35, 19);
                printf("Contact: %ld ",mem.number);
                flag= 1;
            }
        }
        if(flag == 0)
        {
            gotocr(35, 15);
            printf("\aNo Record Found");
            getch();
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
        }
        c2j3:
        gotocr(35, 25);
        printf("Try another search?(Y/N)");
        switch(getch())
        {
        case 'y':
            goto c2j2;
            break;
        case 'Y':
            goto jump2;
            break;
        case 'n':
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
            break;
        case 'N':
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
            break;
        default:
            gotocr(35, 27);
            printf("Please Enter correct character..");
            getch();
            goto c2j3;
            break;
        }
        break;
    case '3':
        if(point == 0)
        {
            aStudent();
        }
        if (point == 1)
        {
            aTeacher();
        }
    default:
        gotocr(35, 16);
        printf("Please Enter correct character..");
        getch();
        goto jump;
    }
}
void mod_mem_f()
{
    system("cls");
    int flag= 0;
    char read[15];
    FILE *fptr;
    gotocr(40, 2);
    if(point == 0)
    {
        printf("Modify Student");
        fptr= fopen("student_list.txt", "r+");
        if(fptr == NULL)
        {
            printf("Unable to open 'student_list.txt' file.");
        }
    }
    if (point == 1)
    {
        printf("Modify Teacher");
        fptr= fopen("teacher_list.txt", "r+");
        if(fptr == NULL)
        {
            printf("Unable to open 'teacher_list.txt' file.");
        }
    }
    gotocr(35,6);
    printf("Enter Id to be edited:");
    scanf("%s",read);
    while(fread(&mem, sizeof(mem), 1, fptr) == 1)
    {
        if(strcmp(mem.id, (read)) == 0)
        {
            gotocr(35, 9);
            printf("The Record is Available");
            gotocr(35, 12);
            printf("The ID: %s", mem.id);
            gotocr(35, 14);
            printf("Enter New Name: ");
            scanf("%s", &mem.name);
            gotocr(35, 16);
            printf("Enter New Department: ");
            scanf("%s", &mem.dept);
            gotocr(35, 18);
            printf("Enter New Number: ");
            scanf("%d", &mem.number);
            fseek(fptr, (ftell(fptr)-sizeof(mem)), 0);
            fwrite(&mem, sizeof(mem), 1, fptr);
            fclose(fptr);
            gotocr(35,21);
            printf("The record is modified");
            flag= 1;
        }
        if(flag == 0)
        {
            gotocr(35, 9);
            printf("This ID not Found");
            getch();
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
        }
    }
    jump:
    gotocr(35, 23);
    printf("Modify another Record?(Y/N)");
    switch(getch())
    {
    case 'y':
        mod_mem_f();
        break;
    case 'Y':
        mod_mem_f();
        break;
    case 'n':
        if(point == 0)
        {
            aStudent();
        }
        if (point == 1)
        {
            aTeacher();
        }
        break;
    case 'N':
        if(point == 0)
        {
            aStudent();
        }
        if (point == 1)
        {
            aTeacher();
        }
        break;
    default:
        gotocr(35, 27);
        printf("Please Enter correct character..");
        getch();
        goto jump;
        break;
    }
}
void del_mem_f()
{
    jump2:
    system("cls");
    int flag= 0;
    char read[15];
    FILE *fptr , *fptr2;
    gotocr(40, 2);
    if(point == 0)
    {
        printf("Remove Student");
        fptr= fopen("student_list.txt", "r+");
        if(fptr == NULL)
        {
            printf("Unable to open 'student_list.txt' file.");
        }
    }
    if (point == 1)
    {
        printf("Remove Teacher");
        fptr= fopen("teacher_list.txt", "r+");
        if(fptr == NULL)
        {
            printf("Unable to open 'teacher_list.txt' file.");
        }
    }
    gotocr(35,6);
    printf("Enter Id to be remove: ");
    scanf("%s",read);
    while(fread(&mem, sizeof(mem), 1, fptr) == 1)
    {
        if(strcmp(mem.id, (read)) == 0)
        {
            gotocr(35, 9);
            printf("The Record is Available");
            gotocr(35, 12);
            printf("Name: %s", mem.name);
            flag= 1;
        }
    }
    if(flag == 0)
    {
        gotocr(35, 9);
        printf("\aThis ID not Found");
        getch();
        if(point == 0)
        {
            aStudent();
        }
        if (point == 1)
        {
            aTeacher();
        }
    }
    if(flag == 1)
    {
        jump:
        gotocr(35, 11);
        printf("Do you want to delete it?(Y/N):");
        switch(getch())
        {
        case 'y':
            fptr2= fopen("tmp.txt", "w+");
            rewind(fptr);
            while(fread(&mem, sizeof(mem), 1, fptr) == 1)
            {
                if(strcmp(mem.id, (read)) == 0)
                {
                    fseek(fptr2, 0, SEEK_CUR);
                    fwrite(&mem, sizeof(mem), 1, fptr2);
                }
            }
            fclose(fptr2);
            fclose(fptr);
            if(point == 0)
            {
                remove("student_list.txt");
                rename("tmp.txt", "student_list.txt");
                fptr= fopen("student_list.txt", "r+");
            }
            if (point == 1)
            {
                remove("teacher_list.txt");
                rename("tmp.txt", "teacher_list.txt");
                fptr= fopen("teacher_list.txt", "r+");
            }
            gotocr(35, 15);
            printf("The record is successfully deleted");
            fclose(fptr);
            jump3:
            gotocr(35, 17);
            printf("Delete another record?(Y/N)");
            switch(getch())
            {
            case 'y':
                goto jump2;
                break;
            case 'n':
                if(point == 0)
                {
                    aStudent();
                }
                if (point == 1)
                {
                    aTeacher();
                }
            default:
                gotocr(35, 13);
                printf("Please Enter correct character..");
                getch();
                goto jump3;
                break;
            }
            break;
        case 'n':
            if(point == 0)
            {
                aStudent();
            }
            if (point == 1)
            {
                aTeacher();
            }
            break;
        default:
            gotocr(35, 13);
            printf("Please Enter correct character..");
            getch();
            goto jump;
            break;
        }
    }
}
void gotocr(int col, int row)
{
    COORD coord={0,0};
    coord.X= col;
    coord.Y= row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void quite_f()
{
    system("cls");
    gotocr(16,3);
    printf("\tCollege Management System");
    gotocr(16,4);
    printf("\t\tProject in C");
    gotocr(16,10);
    printf("\tThis is made by SAIFUR RAHMAN.\n\n\n");
    exit(0);
}
