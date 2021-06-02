#include <iostream>
#include <string>
using namespace std;

class Date {
	int year, month, day;
	
public:
	Date(int y, int m, int d);
	Date(string s);

	int getYear() {
		return year;
	}
	int getMonth() {
		return month;
	}
	int getDay() {
		return day;
	}

	void show();

};

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
};


Date::Date(string s) {
	year = stoi(s.substr(0, 4));
	month = stoi(s.substr(5, 1));
	day = stoi(s.substr(7, 2));
}

void Date::show(){
	cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
}


int main(void) {

	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << "," << birth.getMonth() << ',' << birth.getDay() << endl;

	return 0;

}