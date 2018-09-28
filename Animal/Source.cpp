#include <iostream>
#include <string>

using namespace std;
string type[3] = { "bird", "beast", "human" };

int buff = 0, curr = 0;

struct animal
{
	string name;
	int type_id;
	string color;
	union {
		double fl_speed;
		bool artiodactyl;
		int iq;
	} feature;

	void enter() {
		cout << "enter name: ";
		cin >> name;
		cout << "choose type (0-bird, 1-beast, 2-human): ";
		cin >> type_id;
		cout << "color: ";
		cin >> color;
		if (type_id == 0) {
			cout << "flying speed: ";
			cin >> feature.fl_speed;
		}
		if (type_id == 1) {
			cout << "is it artiodactyl (0-no, 1-yes): ";
			cin >> feature.artiodactyl;
		}
		if (type_id == 2) {
			cout << "iq: ";
			cin >> feature.iq;
		}
	}

	void print() {
		cout << name << " " << type[type_id] << " " << color << " ";
		if (type_id == 0) cout << "flying speed-" << feature.fl_speed << endl;
		if (type_id == 1) {
			if (feature.artiodactyl) cout << "artiodactyl" << endl;
			else cout << "cohort" << endl;
		}
		if (type_id == 2) cout << "IQ-" << feature.iq << endl;
	}


};

void add_list(animal* &arr, animal a) {
	if (buff == 0) {
		buff = 2;
		arr = new animal[buff];
	}
	else {
		if (curr >= buff) {
			animal* tmp = new animal[buff * 2];
			for (int i = 0; i<curr; i++)
				tmp[i] = arr[i];
			delete[] arr;
			arr = tmp;
			buff *= 2;
		}
	}
	arr[curr++] = a;
}

void edit_animal(animal* &arr, string ch_name) {
	bool f = false;
	for (int i = 0; i<curr; i++) {
		if (arr[i].name == ch_name) {
			f = true;
			int choice;
			cout << "what to edit (1-name, 2-type, 3-color, 4-features): ";
			cin >> choice;
			if (choice == 1) {
				cout << "enter new name: ";
				cin >> arr[i].name;
			}
			if (choice == 2) {
				cout << "choose type (0-bird, 1-beast, 2-human): ";
				cin >> arr[i].type_id;
				if (arr[i].type_id == 0) {
					cout << "flying speed: ";
					cin >> arr[i].feature.fl_speed;
				}
				if (arr[i].type_id == 1) {
					cout << "is it artiodactyl (0-no, 1-yes): ";
					cin >> arr[i].feature.artiodactyl;
				}
				if (arr[i].type_id == 2) {
					cout << "IQ: ";
					cin >> arr[i].feature.iq;
				}
			}
			if (choice == 3) {
				cout << "enter new color: ";
				cin >> arr[i].color;
			}
			if (choice == 4) {
				if (arr[i].type_id == 0) {
					cout << "enter new flying speed: ";
					cin >> arr[i].feature.fl_speed;
				}
				if (arr[i].type_id == 1) {
					cout << "is it artiodactyl (0-no, 1-yes): ";
					cin >> arr[i].feature.artiodactyl;
				}
				if (arr[i].type_id == 2) {
					cout << "enter new IQ: ";
					cin >> arr[i].feature.iq;
				}
			}
		}
	}
	if (f == false) cout << "not found, try again" << endl;
}

void search_animal(animal* arr, int t) {
	bool f = false;
	if (t == 1) {
		double c_bird;
		cout << "enter flying speed: ";
		cin >> c_bird;
		for (int i = 0; i<curr; i++) {
			if (arr[i].feature.fl_speed == c_bird) {
				arr[i].print();
				f = true;
			}
		}
	}
	if (t == 2) {
		bool c_beast;
		cout << "is that animal artiodactyl (0-no, 1-yes): ";
		cin >> c_beast;
		for (int i = 0; i<curr; i++) {
			if (arr[i].feature.artiodactyl == c_beast) {
				arr[i].print();
				f = true;
			}
		}
	}
	if (t == 3) {
		int c_human;
		cout << "enter IQ: ";
		cin >> c_human;
		for (int i = 0; i<curr; i++) {
			if (arr[i].feature.iq == c_human) {
				arr[i].print();
				f = true;
			}
		}
	}
	if (f == false) cout << "not found" << endl;
}

int main()
{
	//1.	–азработать структуру Ђ∆ивотноеї (скорость передвижени€, тип (птица, скот, человек), цвет,
	//характеристика (дл€ птицы Ц скорость полета, вещественное число, дл€ скота Ц парнокопытное, логическа€ переменна€,
	//дл€ человека Ц уровень IQ, цела€ переменна€).
	//–екомендации: характеристику реализовать как объединение, тип реализовать как перечислимый тип данных.
	//ј)** —оздать экземпл€р структуры Ђ∆ивотноеї и реализовать дл€ него следующие функции:
	//Х	¬вод информации
	//Х	ѕечать информации
	//Ѕ)*** —оздать массив из 10 экземпл€ров структуры Ђ∆ивотноеї и реализовать дл€ него следующие функции:
	//Х	–едактировать животное
	//Х	ѕечать всего списка
	//Х	ѕоиск животного по характеристике



	animal* arr = new animal;
	int choice;
	while (true) {
		cout << "choose (1-add, 2-edit, 3-print all, 4-search): ";
		cin >> choice;
		if (choice<1 || choice>4) break;
		if (choice == 1) {
			animal a;
			a.enter();
			add_list(arr, a);
		}
		if (choice == 2) {
			string ch_name;
			cout << "enter name: ";
			cin >> ch_name;
			edit_animal(arr, ch_name);
		}
		if (choice == 3) {
			for (int i = 0; i<curr; i++)
				arr[i].print();
		}
		if (choice == 4) {
			int t;
			cout << "choose searching way (1-by flying speed, 2-artiodactyl or not, 3-by IQ): ";
			cin >> t;
			search_animal(arr, t);
		}
	}

	delete[] arr;

	system("pause");
	return 0;
}
