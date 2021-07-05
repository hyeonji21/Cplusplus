#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {

protected:
	double convert(double src) {
		double result;
		result = src / ratio;
		return result;
	}
	string getSourceString() {
		string result1 = "��";
		return result1;
	}
	string getDestString() {
		string result2 = "�޷�";
		return result2;
	}
public:
	WonToDollar(double ratio) : Converter(ratio) {};
};

int main() {

	WonToDollar wd(1010);
	wd.run();

	return 0;
}