#include "Money.h"

int main()
{
	setlocale(LC_ALL, "RU");
	Money firstMoney(15, 20); //Конструктор со значениями
	firstMoney.getMoney(); //Получение значения
	firstMoney.setMoney(26, 15); //Установка значения
	firstMoney.getMoney(); //Получение значения

	std::cout << "---------------------" << std::endl;

	Money secondMoney(20, 35); //Конструктор со значениями
	secondMoney.getMoney(); //Получение значения

	firstMoney += secondMoney;
	secondMoney += 15.80;
	showMoney(firstMoney); //Дружественная функция
	showMoney(secondMoney); //Дружественная функция
	
	Money thirdMoney = firstMoney + secondMoney;
	showMoney(thirdMoney);

	std::cout << "---------------------" << std::endl;
	Money fourthMoney(46, 50);

	std::cout << (thirdMoney < secondMoney) << std::endl;
	std::cout << (firstMoney > secondMoney) << std::endl;
	std::cout << (firstMoney == secondMoney) << std::endl;
}
