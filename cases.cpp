// 40111360027 , ramtin torik , project
// 40111360027 ، رامتین طریک ، project

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void savecontacts()
{
    cout << "\n::::::::::: Save New Contacts :::::::::::\n";
    ofstream contacts_book("contactsbook.txt", ios::app);
    if (!contacts_book)
        cout << "Can not open file...";
    cout << "Please enter firstname: ";
    cin.getline(obj_arr_contact[i].firstname, 15);
    if (i > 0)
        contacts_book << "\n";
    contacts_book << obj_arr_contact[i].firstname;
    contacts_book << " ,";
    cout << "Please enter lastname: ";
    cin.getline(obj_arr_contact[i].lastname, 15);
    contacts_book << obj_arr_contact[i].lastname;
    contacts_book << " ,";
    cout << "Please enter number: ";
    cin.getline(obj_arr_contact[i].number, 15);
    contacts_book << obj_arr_contact[i].number;
    contacts_book << " ,";
    cout << "please enter address: ";
    cin.getline(obj_arr_contact[i].address, 25);
    contacts_book << obj_arr_contact[i].address;
    contacts_book << " ,";
    cout << "please enter email: ";
    cin.getline(obj_arr_contact[i].email ,30);
    contacts_book << obj_arr_contact[i].email;
    contacts_book << " ,";

    contacts_book.close();
    i++;
    cout << "Contact saved ^_____^\n";
    cout << "Please press enter to return menu...";
}

void displaycontacts()
{
    cout << "\n:::::::::::::: All Contacts :::::::::::::\n";
    read_contacts_book();
    ifstream show("contactsbook.txt");
    if(show.peek()==ifstream::traits_type::eof())
    {
        cout << "There is no contact!\n\n";
    }
    else
    {
        printallcontacts(i);
    }
    show.close();
    cout << "\nPlease press enter to return menu...";
}

int searchcontact()
{
    bool print=false;
    int index=-1;
    ifstream show("contactsbook.txt");
    if(show.peek()!=ifstream::traits_type::eof())
    {
        char firstname_for_search[15];
        char lastname_for_search[15];
        char number_for_search[15];
        char input;
        cout << ":::::::::::::: Searching... :::::::::::::\n"
            << "Based on which item do you want to search?\n"
            << "1. Firstname\n"
            << "2. Lastname\n"
            << "3. Phone number\n";
        
        esc:
        cout << "Please enter your choice: ";
        cin.get(input);
        getchar();
        switch(input)
        {
            case '1':
            {
                cout << "Please enter firstname: ";
                cin.getline(firstname_for_search, 15);
                for(int e=0; e<i; e++)
                {
                    if(strcmp(obj_arr_contact[e].firstname, firstname_for_search) == 0)
                    {
                        index = e;
                        break;
                    }
                }
                if(index != -1)
                {
                    printonecontact(index);
                }
                else
                {
                    cout << "Contact not found :(";
                    print = true;
                }
                cout << "\n";
                
                break;
            }

            case '2':
            {
                cout << "Please enter lastname: ";
                cin.getline(lastname_for_search, 15);
                for(int e=0; e<i; e++)
                {
                    if(strcmp(obj_arr_contact[e].lastname, lastname_for_search) == 0)
                    {
                        index = e;
                        break;
                    }
                }
                if(index != -1)
                {
                    printonecontact(index);
                }
                else
                {
                    cout << "Contact not found :(";
                    print = true;
                }
                cout << "\n";

                break;
            }

            case '3':
            {    
                cout << "Please enter phone number: ";
                cin.getline(number_for_search, 15);
                for(int e=0; e<i; e++)
                {
                    if(strcmp(obj_arr_contact[e].number, number_for_search) == 0)
                    {
                        index = e;
                        break;
                    }
                }
                if(index != -1)
                {
                    printonecontact(index);
                }
                else
                {
                    cout << "Contact not found :(";
                    print = true;
                }
                cout << "\n";
                break;
            }

            default:
            {
                cout << "Please enter correct number:)\n";
                goto esc;
                break;
            }
        }
    }
    else
    {
        cout << ":::::::::::::: Searching... :::::::::::::\n";
        cout << "There is no contact!\n";
        print = true;
    }
    if(print)
        cout << "\nPlease press enter to return menu...";
    return index;
}

void updatecontact(int index_for_delete)
{
    if (index_for_delete != -1)
    {
        char ch2;
        cout << "Do you want to update?(y/n) ";
        cin.get(ch2);
        getchar();
        if(ch2 == 'y' || ch2 == 'Y')
        {
            char firstname_for_update[15];
            char lastname_for_update[15];
            char number_for_update[15];
            char address_for_update[25];
            char email_for_update[30];
            cout << "New firstname: ";
            cin.getline(firstname_for_update, 15);
            cout << "New lastname: ";
            cin.getline(lastname_for_update, 15);
            cout << "New phone number: ";
            cin.getline(number_for_update, 15);
            cout << "new address: ";
            cin.getline(address_for_update, 25);
            cout << "new email: ";
            cin.getline(email_for_update, 30);
            strcpy(obj_arr_contact[index_for_delete].firstname, firstname_for_update);
            strcpy(obj_arr_contact[index_for_delete].lastname, lastname_for_update);
            strcpy(obj_arr_contact[index_for_delete].number, number_for_update);
            strcpy(obj_arr_contact[index_for_delete].address, address_for_update);
            strcpy(obj_arr_contact[index_for_delete].email, email_for_update);
            deleteinsidefile();
            cout << "All contacts are updated :-)\n";
            saveallcontacts(i);
            cout << "\nPlease press enter to return menu...";
        }
        else
        {
            cout << ";)";
            cout << "\nPlease press enter to return menu...";
        }
    }
}

void deletespecificcontact()
{
    ifstream show("contactsbook.txt");
    if(show.peek()!=ifstream::traits_type::eof())
    {
        cout << "\n:::::::: Delete Specific Contact ::::::::\n";
        printallcontacts(i);
        cout << "\nHow do you want to delete the contact?\n"
            << "1. Select the contact number\n"
            << "2. Contact search\n";
        char deleteinput;
        esc1:
        cout << "\nPlease enter your choice: ";
        cin.get(deleteinput);
        getchar();
        switch(deleteinput)
        {
            case '1':
            {
                esc2:
                cout << "Please enter the contact number: ";
                int contactindex;
                cin >> contactindex;
                getchar();
                if(contactindex > 0 && contactindex <= i)
                {
                    printonecontact(contactindex-1);
                    cout << "\nDo you want to delete?(y/n) ";
                    char ch3;
                    cin.get(ch3);
                    getchar();
                    if(ch3 == 'y' || ch3 == 'Y')
                    {
                        if(confirmation())
                        {
                            deleteonecontact(contactindex-1);
                            swapcontacts(contactindex-1, i);
                            cout << "\nPlease press enter to return menu...";
                        }
                    }
                    else
                    {
                        cout << ";)";
                        cout << "\nPlease press enter to return menu...";
                    }
                }
                else
                {
                    cout << "Please enter correct number:)\n";
                    goto esc2;
                }
                break;
            }
            case '2':
            {
                int contactindex = searchcontact();
                if(contactindex != -1)
                {
                    cout << "\nDo you want to delete?(y/n) ";
                    char ch3;
                    cin.get(ch3);
                    getchar();
                    if(ch3 == 'y' || ch3 == 'Y')
                    {
                        if(confirmation())
                        {
                            deleteonecontact(contactindex);
                            swapcontacts(contactindex, i);
                            cout << "\nPlease press enter to return menu...";
                        }
                        else
                        {
                            cout << ";)\n";
                            cout << "Please press enter to return menu...";
                        }
                    }
                    else
                    {
                        cout << ";)\n";
                        cout << "Please press enter to return menu...";
                    }
                }
                break;
            }
            default:
            {
                cout << "Please enter correct number:)\n";
                goto esc1;
                break;
            }
        }
    }
    else
    {
        cout << "\n:::::::: Delete Specific Contact ::::::::\n";
        cout << "There is no contact!\n";
        cout << "\nPlease press enter to return menu...";
    }
    show.close();
}

void deleteallcontacts()
{
    cout << "\n:::::::::: Delete All Contact :::::::::::\n";
    char confirmation;
    cout << "Do you really want to continu?(y/n): ";
    cin >> confirmation;
    if(tolower(confirmation) == 'y')
    {
        deleteinsidefile();
        for(int b=0; b<i; b++)
        {
            deleteonecontact(b);
        }
        cout<<"\nAll contacts have been deleted!\n";
        cout << "Please press enter to return menu...";
        getchar();
    }
    else
    {
        cout << ";)\n";
        cout << "Please press enter to return menu...";
        getchar();
    }
}