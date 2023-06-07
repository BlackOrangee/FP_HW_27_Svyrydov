// FP_CW_02.06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

struct Resident
{
	string name = "0";
	string surname = "0";
	bool ocupated = false;
	string roomtype = "0";
	int room = 0;

	void add(string in_name, string in_surname, bool in_ocupated, string in_roomtype, int in_room)
	{
		name = in_name;
		surname = in_surname;
		ocupated = in_ocupated;
		roomtype = in_roomtype;
		room = in_room;
	}
	void print()
	{
		cout << "\n\n\t" << roomtype << room + 1;
		cout << "\n\t Name: " << name;
		cout << "\n\t Surname: " << surname;
	}
};

enum Enum_Menu
{
	Add = 1, Remoove, Search, Edit, Print
};

string NameCorrector(string inname);
bool HotelRoomCheker(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10);
bool OneRoomCheker(Resident* hotel1room, int& size5);
bool TwoRoomCheker(Resident** hotel2room, int& size, int& size10);
int Settlement(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10, int room);
void Error_No_Free_Rooms();
void AddResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10);
void PrintHotel(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10);
void RemooveResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10);
void SearchResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10, int& type, int& room);
void EditMenu();
void EditResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10, int& type, int& room);
void menu(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10);

int main()
{
	int size = 2;
	int size5 = 5;
	int size10 = 10;

	Resident* hotel1room = new Resident[size5];
	Resident** hotel2room = new Resident * [size];
	hotel2room[0] = new Resident[size10];
	hotel2room[1] = new Resident[size10];

	for(;;)
		menu(hotel1room, size5, hotel2room, size, size10);
}

string NameCorrector(string inname)//Increases the first letters 
{
	if (inname[0] >= 97 && inname[0] <= 122)
	{
		inname[0] = inname[0] - 32;
	}
	return inname;
}

bool HotelRoomCheker(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10) // checks for availability
{
	for (int i = 0; i < size5; i++)
	{
		if (!hotel1room[i].ocupated)
		{
			return true;
		}
	}

	for (int i = 0; i < size10; i++)
	{
		if (!hotel2room[0][i].ocupated)
		{
			return true;
		}
	}
}

bool OneRoomCheker(Resident* hotel1room, int& size5) // checks single numbers
{
	for (int i = 0; i < size5; i++)
	{
		if (!hotel1room[i].ocupated)
		{
			return true;
		}
	}
}

bool TwoRoomCheker(Resident** hotel2room, int& size, int& size10)// checks rooms for two
{
	for (int i = 0; i < size10; i++)
	{
		if (!hotel2room[0][i].ocupated)
		{
			return true;
		}
	}
}

int Settlement(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10, int room)// returns the digit of a free number
{
	if (room == 1)
	{
		for (int i = 0; i < size5; i++)
		{
			if (!hotel1room[i].ocupated)
			{
				return i;
			}
		}
	}
	else if (room == 2)
	{
		for (int i = 0; i < size10; i++)
		{
			if (!hotel2room[0][i].ocupated)
			{
				return i;
			}
		}
	}

}

void Error_No_Free_Rooms()
{
	cout << "\n\n\tAll rooms ocupated\n\n";
}

void AddResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10)
{
	string name;
	string surname;
	int chooce = 0;
	int room = 0;

	cout << "\n\n\tEnter name: "; cin >> name;
	name = NameCorrector(name);

	cout << "\n\tEnter surname: "; cin >> surname;
	surname = NameCorrector(surname);

	cout << "\n\tChooce room tipe\n\t1 -- One person\n\t2 -- Two Person\n\t"; cin >> chooce;

	switch (chooce)
	{
	case 1:
		if (OneRoomCheker(hotel1room, size5))
		{
			room = Settlement(hotel1room, size5, hotel2room, size, size10, 1);
			hotel1room[room].add(name, surname, true, "One person room ", room);
		}
		else
		{
			Error_No_Free_Rooms();
		}
		break;
	case 2:
		if (TwoRoomCheker(hotel2room, size, size10))
		{
			room = Settlement(hotel1room, size5, hotel2room, size, size10, 2);
			hotel2room[0][room].add(name, surname, true, "Two person room ", room);

			cout << "\n\n\tEnter second person name name: "; cin >> name;
			name = NameCorrector(name);
			cout << "\n\tEnter second person name surname: "; cin >> surname;
			surname = NameCorrector(surname);
			hotel2room[1][room].add(name, surname, true, "Two person room ", room);
		}
		else
		{
			Error_No_Free_Rooms();
		}
		break;
	default:
		break;
	}
}

void PrintHotel(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10)// displays a list of hotel guests
{
	cout << "\n\tOne person rooms:\n\t";
	for (int i = 0; i < size5; i++)
	{
		if (!hotel1room[i].ocupated)
		{
			cout << "\n\n\tRoom " << i + 1 << " Empty";
		}
		else if (hotel1room[i].ocupated)
		{
			hotel1room[i].print();
		}
	}

	cout << "\n\n\tTwo person rooms:\n\t";
	for (int i = 0; i < size10; i++)
	{
		if (!hotel2room[0][i].ocupated)
		{
			cout << "\n\n\tRoom " << i + 1 << " Empty";
		}
		else if (hotel2room[0][i].ocupated)
		{
			hotel2room[0][i].print();
			hotel2room[1][i].print();
		}
	}

}

void RemooveResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10)
{
	int chooice = 0;
	cout << "\n\n\tEnter room type\n\t1 -- One person room\n\t2 -- Two persons room\n\t";	cin >> chooice;
	int room = 0;
	switch (chooice)
	{
	case 1:
		cout << "\n\tEnter room number: "; cin >> room;
		hotel1room[room - 1].ocupated = false;
		break;
	case 2:
		cout << "\n\tEnter room number: "; cin >> room;
		hotel2room[0][room - 1].ocupated = false;
		hotel2room[1][room - 1].ocupated = false;
		break;
	default:
		break;
	}
}

void SearchResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10, int& type, int& room)
{
	string srarching;
	cout << "\n\n\tEnter surname to search: "; cin >> srarching;
	srarching = NameCorrector(srarching);

	for (int i = 0; i < size5; i++)
	{
		if (hotel1room[i].ocupated)
		{
			if (hotel1room[i].surname == srarching)
			{
				hotel1room[i].print();
				type = -1;
				room = i;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size10; j++)
		{
			if (hotel2room[i][j].ocupated)
			{
				if (hotel2room[i][j].surname == srarching)
				{
					hotel2room[i][j].print();
					type = i;
					room = j;
				}
			}
		}
	}
	if (room == -1)
	{
		cout << "\n\tNot found";
	}
}

void EditMenu()
{
	cout << "\n\n\t1 -- Edit name\n\t2 -- Edit surname\n\t";
}

void EditResident(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10, int& type, int& room)
{
	string name;
	string surname;
	int chooce = 0;

	if (type == -1 && room != -1)
	{
		EditMenu(); cin >> chooce;
		switch (chooce)
		{
		case 1:
			cout << "\n\n\tEnter name: "; cin >> name;
			name = NameCorrector(name);
			hotel1room[room].name = name;
			break;
		case 2:
			cout << "\n\tEnter surname: "; cin >> surname;
			surname = NameCorrector(surname);
			hotel1room[room].surname = surname;
			break;
		default:
			break;
		}
	}
	else if (type != -1 && room != -1)
	{
		EditMenu(); cin >> chooce;
		switch (chooce)
		{
		case 1:
			cout << "\n\n\tEnter name: "; cin >> name;
			name = NameCorrector(name);
			hotel2room[type][room].name = name;
			break;
		case 2:
			cout << "\n\tEnter surname: "; cin >> surname;
			surname = NameCorrector(surname);
			hotel2room[type][room].surname = surname;
			break;
		default:
			break;
		}
	}
}

void menu(Resident* hotel1room, int& size5, Resident** hotel2room, int& size, int& size10)
{
	int menu = 0;
	cout << "\n\n\t1 -- Add resident\n\t2 -- Remoove resident\n\t3 -- Search\n\t4 -- Edit\n\t5 -- Print\n\t";
	cin >> menu;

	int type = -1;
	int room = -1;

	switch ((Enum_Menu)menu)
	{
	case Add:
		if (HotelRoomCheker(hotel1room, size5, hotel2room, size, size10))
		{
			AddResident(hotel1room, size5, hotel2room, size, size10);
		}
		else
		{
			Error_No_Free_Rooms();
		}
		break;
	case Remoove:
		RemooveResident(hotel1room, size5, hotel2room, size, size10);
		break;
	case Search:
		SearchResident(hotel1room, size5, hotel2room, size, size10, type, room);
		break;
	case Edit:
		SearchResident(hotel1room, size5, hotel2room, size, size10, type, room);
		EditResident(hotel1room, size5, hotel2room, size, size10, type, room);
		break;
	case Print:
		PrintHotel(hotel1room, size5, hotel2room, size, size10);
		break;
	default:
		break;
	}
}
