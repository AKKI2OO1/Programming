#ifndef FUNTIONS_HPP
#define FUNTIONS_HPP
#include <iostream>
#include <cstring>
using namespace std;
class Node
{
public:
    char Number[15];
    char Gmail[50];
    char Name[50];
    Node *prev; 
    Node *next;
    Node(char n[], char r[], char g[])
    {
        n = Number;
        r = Gmail;


        next = NULL;
        prev = NULL;
    }
    friend class Funtions;
};
class Funtions
{
    Node *Head = NULL;
    Node *Temp = NULL;
    Node *Ptr  = NULL;

    Node *Ptr1 = NULL;
    Node *Ptr2 = NULL; 
    Node *Dup  = NULL;

public:

    void Insert();
    void Sort();
    void DeleteAContact(char n[15]);
    void DeleteSameNumber();
    void DeleteSameName();
    void DeleteSameGmail();
    void SearchByName(char p[20]);
    void SearchByNumber(char no[15]);
    void SearchByGmail(char g[20]);
    void Accept();
    void Display();
    void Update(char ch[10]);
};
void Funtions::Accept()
{
    char Number[15];
    char Gmail[40];
    char Name[30];
    char Reply;
    do
    {
        cout << "Enter The Name : ";
        cin >> Name;
        cout << "Enter The Number : ";
        cin >> Number;
        while (strlen(Number) != 10)
        {
            cout << "The Entered Number Is Invalid"
                 <<   "Please Enter A Valid Number :  ";
            cin >> Number;
        }
        cout << "Enter The Gmail ID : ";
        cin >> Gmail;
        Temp = new Node(Name, Number, Gmail);
        if (Head == NULL)
        {
            Head = Temp;
        }
        else
        {
            Ptr = Head;
            while (Ptr->next != NULL)
            {
                Ptr = Ptr->next;
            }
            Ptr->next = Temp;
            Temp->prev = Ptr;
        }
        cout << "----------DO YOU WANT TO CONTINUE ?----------"
             << "Please Answer In Y or N !";
        cin >> Reply;
    } while (Reply == 'Y');
}
void Funtions::Display()
{
    Ptr = Head;         
    while (Ptr != NULL) 
    {
        cout << "\n\nName  ::\t" << Ptr->Name;
        cout << "\nNumber::\t+91-" << Ptr->Number;
        cout << "\nG-MAIL::\t" << Ptr->Gmail;
        Ptr = Ptr->next;
    }
}

void Funtions::Insert()
{
    Accept();
}
void Funtions::Sort()
{
    int Temp;
    char n[10];
    for (Node * i = Head; i->next != NULL; i = i->next)
    {
        for (Node *j = i->next; j != NULL; j = j->next)
        {
            Temp = strcmp(i->Name, j->Name);
            if (Temp > 0)
            {
                strcpy(n, i->Name);
                strcpy(i->Name, j->Name);
                strcpy(j->Name, n);
            }
        }
    }
}
//____________________________________________________________________________
void Funtions::DeleteAContact(char s[20])
{
    int c = 0;
    Ptr = Head;
    while (Ptr != NULL)
    {
        if (strcmp(s, Ptr->Name) == 0)
        {
            c = 1;
            break;
        }
        else
        {
            c = 2;
        }
        Ptr = Ptr->next;
    }
    if (c == 1 && Ptr != Head && Ptr->next != NULL)
    {
        Ptr->prev->next = Ptr->next;
        Ptr->next->prev = Ptr->prev;
        delete (Ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (Ptr == Head)
    {
        Head = Head->next;
        Head->prev = NULL;
        delete (Ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (Ptr->next == NULL)
    {
        Ptr->prev->next = NULL;
        Ptr->prev = NULL;
        delete (Ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (c == 2)
    {
        cout << "YOUR ENTERED Name IS NOT IN THE LIST...";
    }
}
void Funtions::deletesameName()
{
    Ptr1 = Head;
    while (Ptr1 != NULL && Ptr1->next != NULL)
    {
        Ptr2 = Ptr1;
        while (Ptr2->next != NULL)
        {
            if (strcmp(Ptr1->Name, Ptr2->next->Name) == 0)
            {
                Dup = Ptr2->next;
                Ptr2->next = Ptr2->next->next;
                delete (dup);
            }
            else
            {
                Ptr2 = Ptr2->next;
            }
        }
        Ptr1 = Ptr1->next;
    }
}
void Funtions::deletesameGmail()
{
    Ptr1 = Head;
    while (Ptr1 != NULL && Ptr1->next != NULL)
    {
        Ptr2 = Ptr1;
        while (Ptr2->next != NULL)
        {
            if (strcmp(Ptr1->Gmail, Ptr2->next->Gmail) == 0)
            {
                Dup = Ptr2->next;
                Ptr2->next = Ptr2->next->next;
                delete (dup);
            }
            else
            {
                Ptr2 = Ptr2->next;
            }
        }
        Ptr1 = Ptr1->next;
    }
}
void Funtions::deletesameNumber()
{
    Ptr1 = Head;
    while (Ptr1 != NULL && Ptr1->next != NULL)
    {
        Ptr2 = Ptr1;
        while (Ptr2->next != NULL)
        {
            if (strcmp(Ptr1->Number, Ptr2->Number) == 0)
            {
                Dup = Ptr2->next;
                Ptr2->next = Ptr2->next->next;
                delete (dup);
            }
            else
            {
                Ptr2 = Ptr2->next;
            }
        }
        Ptr1 = Ptr1->next;
    }
}
void Funtions::searchbyName(char na[10])
{
    Ptr = Head;
    while (Ptr != NULL)
    {
        if (strcmp(na, Ptr->Name) == 0)
        {
            cout << "Name FOUND" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nName  ::\t" << Ptr->Name;
            cout << "\nNumber::\t+91-" << Ptr->Number;
            cout << "\nG-MAIL::\t" << Ptr->Gmail;
        }
        Ptr = Ptr->next;
    }
}
void Funtions::searchbyNumber(char num[20])
{
    Ptr = Head;
    while (Ptr != NULL)
    {
        if (strcmp(num, Ptr->Number) == 0)
        {
            cout << "Number FOUND\n"
                 << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nName  ::\t" << Ptr->Name;
            cout << "\nNumber::\t+91-" << Ptr->Number;
            cout << "\nG-MAIL::\t" << Ptr->Gmail;
        }
        Ptr = Ptr->next;
    }
}
void Funtions::searchbyGmail(char gm[20])
{
    Ptr = Head;
    while (Ptr != NULL)
    {
        if (strcmp(gm, Ptr->Gmail) == 0)
        {
            cout << "G-MAIL FOUND\n"
                 << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"
                 << endl;
            cout << "\n\nName  ::\t" << Ptr->Name;
            cout << "\nNumber::\t+91-" << Ptr->Number;
            cout << "\nG-MAIL::\t" << Ptr->Gmail;
        }
        Ptr = Ptr->next;
    }
}
void Funtions::update(char n[20])
{
    char ans;
    int c;
    Ptr = Head;
    while (Ptr != NULL)
    {
        if (strcmp(n, Ptr->Name) == 0)
        {

            do
            {
                cout << "\nWHAT DO YOU WANT TO UPDATE?\n1.Name\n2.PHONE Number\n3.G-MAIL\n";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "ENTER NEW-Name=";
                    cin >> Ptr->Name;
                    break;
                case 2:
                    cout << "ENTER NEW PHONE-Number?";
                    cin >> Ptr->Number;
                    while (strlen(Ptr->Number) != 10)
                    {
                        cout << "ENTER VALID Number  :";
                        cin >> Ptr->Number;
                    }
                    break;
                case 3:
                    cout << "ENTER NEW G-MAIL";
                    cin >> Ptr->Gmail;
                    break;
                }
                cout << "DO YOU WANT TO CONTINUE UPDATING?";
                cin >> ans;
            } while (ans == 'y');
        }
        Ptr = Ptr->next;
    }
}
int main()
{
    char n[20];
    char nam[20];
    char Name[10];
    char Number[10];
    char Gmail[20];
    Funtions d1;
    // apply d;
    char ans;
    int ch, a;
    cout << "**************                                PHONE BOOK                          ********************";
    cout << "\n\nWHAT IS YOUR Name?\n";
    cin.getline(Name, 20);
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << Name << "   !!!!!!!!!!!!!!!!!!!!!";
    cout << "\n\n\nLET'S CREATE OUR PHONEBOOK " << Name << "  \n\n";
    d1.accept();
    d1.sort();
    do
    {
        cout << "\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME Name IN PHONEBOOK\n6) DELETE SAME NumberS IN PHONEBOOK\n7) SEARCH\n";
        cin >> ch;
        switch (ch)
        {
        case 2:
            d1.insert();
            d1.sort();
            break;

        case 1:
            // d1.sort();
            d1.display();
            break;
        case 3:

            cout << "\n\nENTER THE Name OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
            cin >> n;
            d1.update(n);
            d1.sort();
            break;
        case 4:
            cout << "\nENTER THE Name YOU WANT TO DELETE FROM PHONEBOOK\n";
            cin >> Name;
            d1.deletecontact(Name);
            break;
        case 5:
            d1.deletesameName();
            d1.display();
            break;
        case 6:
            d1.deletesameNumber();
            d1.display();
            break;
        case 7:
            do
            {
                cout << "1.SEARCH BY Name\n2.SEARCH BY Number\n3.SEARCH BY Gmail";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "ENTER THE Name TO BE SEARCHED\n";
                    cin >> Name;
                    d1.searchbyName(Name);
                    break;
                case 2:
                    cout << "ENTER THE Name TO BE SEARCHED\n";
                    cin >> Number;
                    d1.searchbyNumber(Number);
                    break;
                case 3:
                    cout << "ENTER THE Name TO BE SEARCHED\n";
                    cin >> Gmail;
                    d1.searchbyGmail(Gmail);
                    break;
                default:
                    cout << "\nNO PROPER INPUT GIVEN.....\n";
                }
                cout << "DO YOU WANT TO CONTINUE SEARCHING?????????";
                cin >> ans;
            } while (ans == 'y');

            break;
        case 8:
            d1.deletesameGmail();
            d1.display();
            break;
        default:
            cout << "\nNO PROPER INPUT GIVEN..\n";
        }
        cout << "\n\nDO YOU WANT TO CONTINUE OPERATIONS?????????";
        cin >> ans;
    } while (ans == 'y');
}
/***************                                PHONE BOOK                          ********************

WHAT IS YOUR Name?
Priti jha


!!!!!!!!!!!!!!!!!!!!!!!   WELCOME Priti jha   !!!!!!!!!!!!!!!!!!!!!


LET'S CREATE OUR PHONEBOOK Priti jha

ENTER Name      :vijay
ENTER Number    :1234567890
ENTER G-MAIL    :priti@Gmail.com
DO YOU WANT TO CONTINUE?????????y
ENTER Name      :rahul
ENTER Number    :1234567890
ENTER G-MAIL    :rahh ul@Gmail.com
DO YOU WANT TO CONTINUE?????????n




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
1


Name  ::	rahul
Number::	+91-1234567890
G-MAIL::	priti@Gmail.com

Name  ::	vijay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
2
ENTER Name      :akshay
ENTER Number    :9819140108
ENTER G-MAIL    :akshay@Gmail.com
DO YOU WANT TO CONTINUE?????????y
ENTER Name      :Vijay
ENTER Number    :1234567890
ENTER G-MAIL    :vijay@Gmail.com
DO YOU WANT TO CONTINUE?????????n


DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
3 1


Name  ::	Vijay
Number::	+91-1234567890
G-MAIL::	priti@Gmail.com

Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	rahul
Number::	+91-9819140108
G-MAIL::	akshay@Gmail.com

Name  ::	vijay
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
3


ENTER THE Name OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...
Vijay

WHAT DO YOU WANT TO UPDATE?
1.Name
2.PHONE Number
3.G-MAIL
1
ENTER NEW-Name=Priti
DO YOU WANT TO CONTINUE UPDATING?n


DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
1


Name  ::	Priti
Number::	+91-1234567890
G-MAIL::	priti@Gmail.com

Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	rahul
Number::	+91-9819140108
G-MAIL::	akshay@Gmail.com

Name  ::	vijay
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
4

ENTER THE Name YOU WANT TO DELETE FROM PHONEBOOK
Priti
YOUR CONTACT IS SUCCESSFULLY DELETED



DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
1


Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	rahul
Number::	+91-9819140108
G-MAIL::	akshay@Gmail.com

Name  ::	vijay
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
2
ENTER Name      :akshay
ENTER Number    :1234567980
ENTER G-MAIL    :akshay@Gmail.com
DO YOU WANT TO CONTINUE?????????n


DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
1


Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	akshay
Number::	+91-9819140108
G-MAIL::	akshay@Gmail.com

Name  ::	rahul
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

Name  ::	vijay
Number::	+91-1234567980
G-MAIL::	akshay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
5


Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	rahul
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

Name  ::	vijay
Number::	+91-1234567980
G-MAIL::	akshay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
1


Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	rahul
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

Name  ::	vijay
Number::	+91-1234567980
G-MAIL::	akshay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
3


ENTER THE Name OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...
rahul

WHAT DO YOU WANT TO UPDATE?
1.Name
2.PHONE Number
3.G-MAIL
2
ENTER NEW PHONE-Number?1234567890
DO YOU WANT TO CONTINUE UPDATING?n


DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
1


Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

Name  ::	rahul
Number::	+91-1234567890
G-MAIL::	vijay@Gmail.com

Name  ::	vijay
Number::	+91-1234567980
G-MAIL::	akshay@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
6


Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.com

DO YOU WANT TO CONTINUE OPERATIONS?????????y




1) DISPLAY YOUR PHONE BOOK
2) INSERT NEW CONTACT
3) UPDATE DETAILS ON EXISTING CONTACT
4) DELETE CONTACT
5) DELETE SAME Name IN PHONEBOOK
6) DELETE SAME NumberS IN PHONEBOOK
7) SEARCH
7
1.SEARCH BY Name
2.SEARCH BY Number
3.SEARCH BY Gmail1
ENTER THE Name TO BE SEARCHED
akshay
Name FOUND
CONTACT DETAILS ARE BELOW:



Name  ::	akshay
Number::	+91-1234567890
G-MAIL::	rahul@Gmail.comDO YOU WANT TO CONTINUE SEARCHING?????????n


DO YOU WANT TO CONTINUE OPERATIONS?????????n


*/