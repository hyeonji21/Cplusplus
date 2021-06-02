#include <iostream>
#include <string>
using namespace std;


class Account {
	string name;
	int id;
	int balance;

public:
	Account(string n, int i, int b);

	string getOwner();
	void deposit(int money);
	int withdraw(int money);
	int inquiry();

};

Account::Account(string n, int i, int b) {
	name = n;
	id = i;
	balance = b;

}
void Account::deposit(int money) {
	balance += money;
}
string Account::getOwner(){
	return name;
}
int Account::inquiry() {
	return balance;
}
int Account::withdraw(int money) {
	if (money > balance) { // 저축된 돈이 찾는 금액보다 작은 경우
		money = balance;
		balance = 0;
	}
	else
		balance -= money;

	return money;
}

int main(void) {

	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;

	return 0;

}