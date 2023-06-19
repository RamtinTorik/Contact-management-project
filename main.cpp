// 40111360027 , ramtin torik , project
// 40111360027 ، رامتین طریک ، project

#include <iostream>
#include <fstream>
#include <cstring>
#include "other.cpp"
#include "cases.cpp"
using namespace std;

// void read_contacts_book()
// {

// }

int main()
{
    read_contacts_book();
    
    // for(int h=0;h<3;h++)
    // {
    //     cout << obj_arr_contact[h].firstname << obj_arr_contact[h].lastname << obj_arr_contact[h].number;
    // }
    system("cls");
    while (true)
    {
        returnmenu();
        printmenu();
        cin >> initial_input;
        getchar();
        system("cls");
        switch (initial_input)
        {
            case '1':
            {
                // system("cls");
                // cout << "case 1\n";
                savecontacts();
                k++;
                break;
            }

            case '2':
            {
                // system("cls");
                // cout << "case 2\n";
                displaycontacts();
                k++;
                break;
            }

            case '3':
            {
                // system("cls");
                // cout << "case 3\n";
                searchcontact();
                cout << "\nPlease press enter to return menu...";
                k++;
                break;
            }
            case '4':
            {
                // system("cls");
                cout << ":::::::::::: Update Contact :::::::::::::\n";
                updatecontact(searchcontact());
                k++;
                break;
            }

            case '5':
            {
                // system("cls");
                // cout << "case 5\n";
                deletespecificcontact();
                k++;
                break;
            }
            case '6':
            {
                // system("cls");
                cout << "case 6\n";
                deleteallcontacts();
                k++;
                break;
            }

            case '0':
            {
                // system("cls");
                // cout << "case 0\n";
                cout << "\nI hope to see you in the future!... ^_^\n";
                k++;
                exit(0);
                break;
            }
            
            default:
            {
                // cout << "default";
                cout << "Please enter correct number :)\n";
                cout << "Please press enter to return menu...";
                k++;
                break;
            }

        }
    }

    return 0;
}
