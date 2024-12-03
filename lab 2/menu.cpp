# include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "conio.h"
#define UP 65
#define DOWN 66
#define SET_WHITE printf("\033[0m")
#define SET_BLUE printf("\033[1;44m")
#define EXTENDED 27
#define BACK 127
#define ENTER 10
#define SIZE 100
#define Row 4
#define Col 10
#define HOME 72
#define END 70
#define RIGHT 67
#define LEFT 68
#define F1 80
using namespace std;

typedef struct Emp {
    char name[200];
    int id;
    int salary;
} EMP;

class stack
{
    EMP *items;
    int top;
    int size;

public:
    stack(int size)
    {
        this->size = size;
        items = new EMP[size];
        top = -1;
    }

    int get_size()
    {
        return size;
    }

    int get_top()
    {
        return top;
    }

    int push(EMP data)
    {
        if (top == size - 1)
        {
            return 0;
        }
        else
        {
            items[++top] = data;
            return 1;
        }
    }

    Emp pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty. Cannot pop any more employees.\n";
            throw runtime_error("Stack underflow");
        } else
        {
            return items[top--];
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << items[i].id <<endl;
            cout << items[i].name <<endl;
            cout << items[i].salary <<endl;
            cout<<"-----------------------------------------------------"<<endl;

        }
    }


    ~stack()
    {
        delete[] items;
        cout << "\nBye bye" << endl;
    }
};


void choices(int flag)
{
    clrscr();
    char str[Row][Col] = {"push", "pop", "display", "Exit"};
    for (int i = 0; i < Row; i++)
    {
        if (flag == i)
        {
            SET_BLUE;
            gotoxy1((i+1)*3,25);
            printf("%s\n", str[i]);
            SET_WHITE;
        } else
        {
            gotoxy1((i+1)*3,25);
            printf("%s\n", str[i]);
        }
    }
    gotoxy1(20,25);
    printf("\n\n\nFor documentation press F1");
}

Emp pop_emp(stack &s) {
    if (s.get_top() == -1)
    {
        clrscr();
        cout << "No more employees to remove.\n";
        fflush(stdout);
        sleep(2);
        choices(1);
        return {};
    } else
    {
        Emp data = s.pop();
        clrscr();
        cout << "Employee successfully removed:\n";
        cout<<"-----------------------------------------------------"<<endl;
        cout << "ID: " << data.id << "\n";
        cout << "Name: " << data.name << "\n";
        cout << "Salary: " << data.salary << "\n";
        cout<<"-----------------------------------------------------"<<endl;
        fflush(stdout);
        sleep(2);
        choices(1);
        return data;
    }
}

int isValidString(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' '))
        {
            return 0;
        }
    }
    return 1;
}

int GitInt() {
    int number;
    char buffer[100];

    while (1) {
        printf("Please enter a positive integer: ");

        if (fgets(buffer, sizeof(buffer), stdin))
        {

            if (sscanf(buffer, "%d", &number) == 1 && number > 0)
            {
                return number;
            }
        }
        printf("Invalid input! Try again.\n");
    }
}


void add_emp(stack &s) {
    Emp e;
    if (s.get_top() != s.get_size() - 1) {
        do {
            printf("Enter employee name: ");
            scanf(" %199[^\n]", e.name);
            while (getchar() != '\n');
        } while (!isValidString(e.name));

        printf("Enter employee ID: ");
        e.id = GitInt();

        printf("Enter employee salary: ");
        e.salary = GitInt();

        s.push(e);
        clrscr();
        cout << "Employee successfully added.";
        fflush(stdout);
        sleep(2);
        choices(0);
    } else {
        clrscr();
        cout << "You cannot add more employees.";
        fflush(stdout);
        sleep(2);
        choices(0);
    }
}


int main() {
    int empSize=0;
    cout<<"number of embloyee ";
    empSize=GitInt();
    stack s(empSize);
    char flag = 0;
    char home_flag=1;
    choices(flag);

    char choice;
    while (1) {
        while (kbhit())
        {
            getch();
        }
        choice = getch();
        if (choice == EXTENDED) {
            if (!kbhit()) {
                return 0;
            } else {

                choice = getch();
                choice = getch();
            }
        }
        clrscr();
        switch (choice) {
            case RIGHT:
            case UP:
                flag--;
                if (flag == -1) {
                    flag = 3;
                }
                choices(flag);
                break;

            case LEFT:
            case DOWN:
                flag++;
                if (flag == 4) {
                    flag = 0;
                }
                choices(flag);
                break;

            case ENTER:
                if (flag == 0) {
                    clrscr();
                    add_emp(s);
                } else if (flag == 1)
                {
                    clrscr();
                    pop_emp(s);
                } else if (flag == 2)
                {
                    clrscr();
                    s.display();
                    printf("\n\n\n enter Backspace to go to menu");
                    while(getch()!=BACK){}
                } else if (flag == 3)
                {
                    clrscr();
                    return 0;
                }
                break;

            case F1:
                clrscr();
                printf("Available buttons:\n");
                printf("Arrows: Navigate up or down\n");
                printf("ENTER: Select\n");
                printf("BACKSPACE: Go back\n");
                printf("HOME: Go to menu\n");
                printf("END: Exit\n");
                printf("puch: puch new employee\n");
                printf("Display: Show employees\n");
                printf("pop: pop employee data\n");
                printf("Exit: Quit program\n");
                break;

            case BACK:
                choices(flag);
                break;

            case HOME:
                flag = 0;
                choices(flag);
                break;

            case END:
                flag = 3;
                choices(flag);
                break;

            default:
                printf("Invalid input.");
                break;
        }
    }
}
