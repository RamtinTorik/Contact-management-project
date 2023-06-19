// 40111360027 , ramtin torik , project
// 40111360027 ، رامتین طریک ، project

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char initial_input;
int i = 0, j = 0, k = 0;

class contact
{
	public:
	char firstname[15];
	char lastname[15];
	char number[15];
	char address[25];
	char email[30];
};
contact obj_arr_contact[100];

void printmenu()
{
	cout << "\n:::::::::::::::::::::::::::::::::::::::::"
		<< "\n::           Contact Manager           ::"
		<< "\n:::::::::::::::::::::::::::::::::::::::::\n";

	cout << "\n:::::::::::::: Program Menu :::::::::::::\n";

	cout << "1. Save New Contact\n"
		<< "2. Display All Saved Contacts\n"
		<< "3. Search Specific Contact\n"
		<< "4. Modify Existing Contact\n"
		<< "5. Delete Specific Contact\n"
		<< "6. Delete All Existing Contacts\n"
		<< "0. Exit\n";

	cout << "\nPlease Enter Your Choice: ";
}

void read_contacts_book()
{
	ifstream read_contacts_book("contactsbook.txt", ios::app);
	if (!read_contacts_book)
		cout << "can not open file...";
	char ch;
	i = 0;
	while (!read_contacts_book.eof())
		{
			read_contacts_book >> obj_arr_contact[i].firstname;
			read_contacts_book.get(ch);
			read_contacts_book.get(ch);
			read_contacts_book >> obj_arr_contact[i].lastname;
			read_contacts_book.get(ch);
			read_contacts_book.get(ch);
			read_contacts_book >> obj_arr_contact[i].number;
			read_contacts_book.get(ch);
			read_contacts_book.get(ch);
			read_contacts_book >> obj_arr_contact[i].address;
			read_contacts_book.get(ch);
			read_contacts_book.get(ch);
			read_contacts_book >> obj_arr_contact[i].email;
			read_contacts_book.get(ch);
			read_contacts_book.get(ch);
			if (!read_contacts_book.eof())
				i++;
		}
	read_contacts_book.close();
}

void returnmenu()
{
	char ch1;
	if(k>0)
	{
		cin.get(ch1);
		if(ch1=='\n')
			system("cls");
	}
}

void printallcontacts(int index)
{
	for(int a=0; a<index; a++)
	{
		cout << a+1 << ". ";
		cout << "firstname: " << obj_arr_contact[a].firstname << " | ";
		cout << "lastname: " << obj_arr_contact[a].lastname << " | ";
		cout << "number: " << obj_arr_contact[a].number << " | ";
		cout << "address: " << obj_arr_contact[a].address << " | ";
		cout << "email: " << obj_arr_contact[a].email << " |";
		cout << "\n";
	}
}

void deleteinsidefile()
{
	ofstream delete_all_contacts("contactsbook.txt");
	delete_all_contacts.close();
	cout<<"\nThe inside of the file was deleted!\n";
}

void printonecontact(int index)
{
	cout << "firstname: " << obj_arr_contact[index].firstname << " | ";
	cout << "lastname: " << obj_arr_contact[index].lastname << " | ";
	cout << "number: " << obj_arr_contact[index].number << " | ";
	cout << "address: " << obj_arr_contact[index].address << " | ";
	cout << "email: " << obj_arr_contact[index].email << " |";
}

void saveallcontacts(int i)
{
	ofstream contacts_book("contactsbook.txt", ios::app);
	if (!contacts_book)
		cout << "can not open file...";
	for(int d=0; d<i; d++)
	{
		contacts_book << obj_arr_contact[d].firstname;
		contacts_book << " ,";
		contacts_book << obj_arr_contact[d].lastname;
		contacts_book << " ,";
		contacts_book << obj_arr_contact[d].number;
		contacts_book << " ,";
		contacts_book << obj_arr_contact[d].address;
		contacts_book << " ,";
		contacts_book << obj_arr_contact[d].email;
		contacts_book << " ,";
		if (d!=i-1)
			contacts_book << "\n";
	}
	contacts_book.close();
	cout << "All contacts are saves";
}

void deleteonecontact(int index)
{
	strcpy(obj_arr_contact[index].firstname, "");
	strcpy(obj_arr_contact[index].lastname, "");
	strcpy(obj_arr_contact[index].number, "");
	strcpy(obj_arr_contact[index].address, "");
	strcpy(obj_arr_contact[index].email, "");
}

void swapcontacts(int index, int i)
{
	for(; index<i-1; index++)
	{
		strcpy(obj_arr_contact[index].firstname, obj_arr_contact[index+1].firstname);
		strcpy(obj_arr_contact[index].lastname, obj_arr_contact[index+1].lastname);
		strcpy(obj_arr_contact[index].number, obj_arr_contact[index+1].number);
		strcpy(obj_arr_contact[index].address, obj_arr_contact[index+1].address);
		strcpy(obj_arr_contact[index].email, obj_arr_contact[index+1].email);
	}
	deleteonecontact(i-1);
	deleteinsidefile();
	i--;
	saveallcontacts(i);
}

bool confirmation()
{
	cout << "\nAre you sure?(y/n) ";
	char ch;
	cin.get(ch);
	getchar();
	if(ch == 'y' || ch == 'Y')
		return true;
	else
		return false;
}