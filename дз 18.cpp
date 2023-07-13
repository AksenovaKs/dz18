#include <iostream>
#include <fstream>
#include <sys/stat.h>

using namespace std;

class User {
private:
	string _name;
	string _login;
	string _pass;

public:
	User(string name, string login, string pass)
		: _name(name), _login(login), _pass(pass) {}

	void saveToFile(const string& filename) {
		ofstream file(filename);
		if (file.is_open()) {
			file << _name << endl;
			file << _login << endl;
			file << _pass << endl;
			file.close();
			// Ограничиваем доступ к файлу только для пользователя
			chmod(filename.c_str(), S_IRUSR | S_IWUSR);
		}
		else {
			cout << "Не удалось открыть файл для записи: " << filename << endl;
		}
	}
};

class Message {
private:
	string _text;
	string _sender;
	string _receiver;

public:
	Message(string text, string sender, string receiver)
		: _text(text), _sender(sender), _receiver(receiver) {}

	void saveToFile(const string& filename) {
		ofstream file(filename);
		if (file.is_open()) {
			file << _text << endl;
			file << _sender << endl;
			file << _receiver << endl;
			file.close();
			// Ограничиваем доступ к файлу только для пользователя
			chmod(filename.c_str(), S_IRUSR | S_IWUSR);
		}
		else {
			cout << "Не удалось открыть файл для записи: " << filename << endl;
		}
	}
};

int main() {
	User user("John Doe", "johndoe", "password");
	user.saveToFile("user.txt");

	Message message("Hello!", "johndoe", "janedoe");
	message.saveToFile("message.txt");

	return 0;
}