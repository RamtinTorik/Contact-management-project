// 40111360027 , ramtin torik , project
// 40111360027 ، رامتین طریک ، project

#include <iostream>
#include <fstream>
#include <cstring>
#include "other.cpp"
#include "cases.cpp"
using namespace std;

int main()
{
    read_contacts_book();
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
                // cout << "case 1\n";
                savecontacts();
                k++;
                break;
            }

            case '2':
            {
                // cout << "case 2\n";
                displaycontacts();
                k++;
                break;
            }

            case '3':
            {
                // cout << "case 3\n";
                searchcontact();
                cout << "\nPlease press enter to return menu...";
                k++;
                break;
            }
            case '4':
            {
                cout << ":::::::::::: Update Contact :::::::::::::\n";
                updatecontact(searchcontact());
                k++;
                break;
            }

            case '5':
            {
                // cout << "case 5\n";
                deletespecificcontact();
                k++;
                break;
            }
            case '6':
            {
                // cout << "case 6\n";
                deleteallcontacts();
                k++;
                break;
            }

            case '0':
            {
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
