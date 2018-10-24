#include <iostream>

using namespace std;

class number_ {
	int *num;

public:
	explicit number_(int number = 0) {
		this->num = new int(number);
	}

	void setNumber(int number) {
		*num = number;
	}

	int getNumber() const { return *num; }

	number_(const number_ &obj) {
		this->num = new int(*obj.num);
	}

	//оператор присваивания
	number_& operator=(const number_&obj) {
		//защита от самоприсваивания
		if (this == &obj) return *this;
		this->~number_();
		this->num = new int(*obj.num);
		return*this;
	}
	number_& operator=(int n) {
		*this->num = n;
		return *this;
	}

	number_&operator+=(const number_&obj) {
		*this->num += *obj.num;
		return *this;
	}
	number_&operator-=(const number_&obj) {
		*this->num -= *obj.num;
		return *this;
	}
	number_&operator*=(const number_&obj) {
		*this->num *= *obj.num;
		return *this;
	}
	number_&operator/=(const number_&obj) {
		if (*obj.num == 0) {
			cout << "/0" << endl;
			return *this;
		}
		*this->num /= *obj.num;
		return *this;
	}
	number_&operator+=(int number) {
		*this->num += number;
		return *this;
	}
	number_&operator*=(int number) {
		*this->num *= number;
		return *this;
	}
	number_&operator-=(int number) {
		*this->num -= number;
		return *this;
	}
	number_&operator/=(int number) {
		*this->num /= number;
		return *this;
	}

	number_&operator++() {
		*this->num++;
		return *this;
	}
	number_ operator++(int) {
		number_ tmp;
		*tmp.num = *this->num;
		*this->num++;
		return tmp;
	}

	~number_() {
		delete num;
	}

	operator int() {
		return *this->num;
	}
};

#pragma region Operators
	ostream & operator<<(ostream&os, const number_&num) {

		os << num.getNumber();
		return os;
	}
	istream & operator>>(istream&is, number_&num) {
		int x;
		is >> x;
		num.setNumber(x);
		return is;
	}

	number_ operator+(const number_&a, const number_&b) {
		number_ tmp(a.getNumber());
		tmp += b.getNumber();
		return tmp;
	}
	number_ operator+(const number_&a, int number) {
		number_ tmp(a.getNumber());
		tmp += number;
		return tmp;
	}
	number_ operator+(int number, const number_&a) {
		number_ tmp(number);
		tmp += a.getNumber();
		return tmp;
	}

	number_ operator-(const number_&a, const number_&b) {
		number_ tmp(a.getNumber());
		tmp -= b.getNumber();
		return tmp;
	}
	number_ operator-(const number_&a, int number) {
		number_ tmp(a.getNumber());
		tmp -= number;
		return tmp;
	}
	number_ operator-(int number, const number_&a) {
		number_ tmp(number);
		tmp -= a.getNumber();
		return tmp;
	}

	number_ operator*(const number_&a, const number_&b) {
		number_ tmp(a.getNumber());
		tmp *= b.getNumber();
		return tmp;
	}
	number_ operator*(const number_&a, int number) {
		number_ tmp(a.getNumber());
		tmp *= number;
		return tmp;
	}
	number_ operator*(int number, const number_&a) {
		number_ tmp(number);
		tmp *= a.getNumber();
		return tmp;
	}

	number_ operator/(const number_&a, const number_&b) {
		number_ tmp(a.getNumber());
		tmp /= b.getNumber();
		return tmp;
	}
	number_ operator/(const number_&a, int number) {
		number_ tmp(a.getNumber());
		tmp /= number;
		return tmp;
	}
	number_ operator/(int number, const number_&a) {
		number_ tmp(number);
		tmp /= a.getNumber();
		return tmp;
	}

	bool operator<(const number_&a, const number_&b) {
		return a.getNumber() < b.getNumber();
	}
	bool operator<(int numb, const number_&b) {
		return numb < b.getNumber();
	}
	bool operator<(const number_&a, int numb) {
		return a.getNumber() < numb;
	}

	bool operator>(const number_&a, const number_&b) {
		return a.getNumber() > b.getNumber();
	}
	bool operator>(int numb, const number_&b) {
		return numb > b.getNumber();
	}
	bool operator>(const number_&a, int numb) {
		return a.getNumber() > numb;
	}

	bool operator==(const number_&a, const number_&b) {
		return a.getNumber() == b.getNumber();
	}
	bool operator<=(const number_&a, const number_&b) {
		return a.getNumber() <= b.getNumber();
	}
	bool operator>=(const number_&a, const number_&b) {
		return a.getNumber() >= b.getNumber();
	}
	bool operator!=(const number_&a, const number_&b) {
		return a.getNumber() <= b.getNumber();
	}

#pragma endregion



void main() {
	number_ n;
	number_ n2;

	cin >> n >> n2;

	n += n2;


	cout << n;

	system("pause");
}