#include <iostream>
#include "Money.h"

Value::Value(int long rubles, unsigned char penny) {
	setValue(rubles, penny);
}
Value::Value() {
	setValue();
}
void Value::setValue(int long rubles, unsigned char penny) {
	setRuble(rubles);
	setPenny(penny);
}
void Value::setRuble(int long rubles) {
	this->rubles = rubles;
}
void Value::setPenny(unsigned char penny) {
	this->penny = penny;
}

int long Value::getRuble() {
	return this->rubles;
}
unsigned char Value::getPenny() {
	return int(this->penny);
}
std::ostream& operator<< (std::ostream& out, const Value& value);
std::istream& operator>> (std::istream& in, Value& value);

Money::Money() {
	this->currentValue.setValue(0, 0);
}
Money::Money(int long rubles, unsigned char penny) {
	this->currentValue.setValue(rubles, penny);
}

void Money::setMoney(int long rubles, unsigned char penny) {
	this->currentValue.setValue(rubles, penny);
}
void Money::setMoneyInput() {
	std::cin >> this->currentValue;
}
void Money::getMoney() {
	std::cout << this->currentValue;
}

bool Money::operator>(Money& rightValue) {
	return (this->currentValue.getRuble() > rightValue.currentValue.getRuble()
		&& this->currentValue.getPenny() > rightValue.currentValue.getPenny());
}
bool Money::operator<(Money& rightValue) {
	return (this->currentValue.getRuble() < rightValue.currentValue.getRuble()
		&& this->currentValue.getPenny() < rightValue.currentValue.getPenny());
}
bool Money::operator==(Money& rightValue) {
	return (this->currentValue.getRuble() == rightValue.currentValue.getRuble()
		&& this->currentValue.getPenny() == rightValue.currentValue.getPenny());
};

const Money& Money::operator+(Money& rightValue) {
	short unsigned int removeOverPenny = 0;
	short unsigned int extraOverFill = 0;

	if (this->currentValue.getPenny() + rightValue.currentValue.getPenny() >= 100) {
		extraOverFill = 1;
		removeOverPenny = 100;
	}
	return (Money(this->currentValue.getRuble() + rightValue.currentValue.getRuble() + extraOverFill,
		this->currentValue.getPenny() + rightValue.currentValue.getPenny() - removeOverPenny));

}
const Money& Money::operator+(double anotherValue) {
	Value rightValue(int(anotherValue), int((anotherValue - int(anotherValue)) * 100));
	int removeOverPenny = 0;
	int extraOverFill = 0;

	if (this->currentValue.getPenny() + rightValue.getPenny() >= 100) {
		extraOverFill = 1;
		removeOverPenny = 100;
	}
	return (Money(this->currentValue.getRuble() + rightValue.getRuble() + extraOverFill,
		this->currentValue.getPenny() + rightValue.getPenny() - removeOverPenny));

}
const Money& Money::operator+=(Money& rightValue) {
	short unsigned int removeOverPenny = 0;
	short unsigned int extraOverFill = 0;

	if (this->currentValue.getPenny() + rightValue.currentValue.getPenny() >= 100) {
		extraOverFill = 1;
		removeOverPenny = 100;
	}

	long int newRuble = this->currentValue.getRuble();
	unsigned char newPenny = this->currentValue.getPenny();
	this->currentValue.setValue(newRuble + rightValue.currentValue.getRuble() + extraOverFill,
		newPenny + rightValue.currentValue.getPenny() - removeOverPenny);
	return (Money(newRuble += rightValue.currentValue.getRuble() + extraOverFill,
		newPenny += rightValue.currentValue.getPenny() - removeOverPenny));

}
const Money& Money::operator+=(double anotherValue) {
	Value rightValue(int(anotherValue), int((anotherValue - int(anotherValue)) * 100));
	int removeOverPenny = 0;
	int extraOverFill = 0;

	if (this->currentValue.getPenny() + rightValue.getPenny() >= 100) {
		extraOverFill = 1;
		removeOverPenny = 100;
	}
	long int newRuble = this->currentValue.getRuble();
	unsigned char newPenny = this->currentValue.getPenny();
	this->currentValue.setValue(newRuble + rightValue.getRuble() + extraOverFill,
		newPenny + rightValue.getPenny() - removeOverPenny);

	return (Money(newRuble += rightValue.getRuble() + extraOverFill,
		newPenny += rightValue.getPenny() - removeOverPenny));

};

std::ostream& operator<< (std::ostream& out, const Value& value);
std::istream& operator>> (std::istream& in, Value& value);
void showMoney(Money& money);

std::ostream& operator<< (std::ostream& out, const Value& value) {
	out << value.rubles << "," << int(value.penny) << std::endl;
	return out;
}
std::istream& operator>> (std::istream& in, Value& value) {
	in >> value.rubles;
	in >> value.penny;
	return in;
}
void showMoney(Money& money) {
	money.getMoney();
}