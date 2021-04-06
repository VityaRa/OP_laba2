#pragma once
#include <iostream>

class Value {
private:
	int long rubles;
	unsigned char penny;
public:
	Value(int long rubles, unsigned char penny);
	Value();
	void setValue(int long rubles = 0, unsigned char penny = 0);
	void setRuble(int long rubles);
	void setPenny(unsigned char penny);

	int long getRuble();
	unsigned char getPenny();
	friend std::ostream& operator<< (std::ostream& out, const Value& value);
	friend std::istream& operator>> (std::istream& in, Value& value);
};

class Money {
	Value currentValue;
public:
	Money();
	Money(int long rubles, unsigned char penny);

	void setMoney(int long rubles = 0, unsigned char penny = 0);
	void setMoneyInput();
	void getMoney();

	bool operator>(Money& rightValue);
	bool operator<(Money& rightValue);
	bool operator==(Money& rightValue);

	const Money& operator+(Money& rightValue);
	const Money& operator+(double anotherValue);
	const Money& operator+=(Money& rightValue);
	const Money& operator+=(double anotherValue);

	friend std::ostream& operator<< (std::ostream& out, const Value& value);
	friend std::istream& operator>> (std::istream& in, Value& value);
	friend void showMoney(Money& money);
};

void showMoney(Money& money);
