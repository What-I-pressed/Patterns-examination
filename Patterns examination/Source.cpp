#include <iostream>
#include <vector>

using namespace std;

class User {
	string name;
	string phoneNumber;
	string email;
public:
	User() : name("No name"), phoneNumber("000000000"), email("No email") {};

	User(string n, string pN, string e) : name(n), phoneNumber(pN), email(e) {};

	void operator()(string n, string pN, string e) {
		this->name = n;
		this->phoneNumber = pN;
		this->email = e;
	}

	void info()const {
		cout << "____________________\n";
		cout << "Name : " << name << endl;
		cout << "Phone number : " << phoneNumber << endl;
		cout << "Email : " << email << endl;
	}
};

class Model {
	vector<User> users;

	Model() {};
public:
	static Model& getInstance() {
		static Model mod;
		return mod;
	}

	void AddUser(string name, string phoneNumber, string email) {
		users.push_back(User(name, phoneNumber, email));
	}

	void DeleteUser(int pos) {
		users.erase(users.begin() + pos);
	}

	void EditAt(int pos, string name, string phoneNumber, string email) {
		users[pos](name, phoneNumber, email);
	}

	User operator[](int pos) {
		return users[pos];
	}

	size_t GetSize()const {
		return users.size();
	}
};

class View {
public:
	void info(Model users) {
		for (int i = 0; i < users.GetSize(); i++) {
			cout << "____________________ user#" << i;
			users[i].info();
		}
	}
};

class Controller {
	Model model = model.getInstance();
	View view;
public:
	void AddUser(string name, string phoneNumber, string email) {
		model.AddUser(name, phoneNumber, email);
	}

	void DeleteUser(int pos) {
		model.DeleteUser(pos);
	}

	void EditAt(int pos, string name, string phoneNumber, string email) {
		model.EditAt(pos, name, phoneNumber, email);
	}

	void info() {
		view.info(model);
	}
};

void main() {
	Controller cont;
	cont.AddUser("Vova", "0975034323", "xz@gmail.com");
	cont.AddUser("Kolye", "64276267236", "someone@gmail.com");
	cont.AddUser("Vika", "84000004323", "idk@gmail.com");
	cont.AddUser("Lilia", "00743634323", "htos@gmail.com");
	cont.AddUser("Sergii", "0985045980", "sergo@gmail.com");
	cont.AddUser("Dima", "0975034323", "bebebe@gmail.com");
	cont.AddUser("Natalia", "0975058823", "rotate@gmail.com");
	cont.info();
	cont.DeleteUser(2);
	cont.EditAt(1, "Vsevold", "9820000000", "litopes@gmail.com");
	cout << endl << endl;
	cont.info();
}