#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <random>
using namespace std;
uint8_t make_seed() {
	int a;
	return (uint8_t)((uintptr_t)&a >> 9);
}

uint32_t x = make_seed();

uint32_t static xorui32() {
	x ^= x << 7;
	x ^= x >> 19;
	x ^= x << 23;
	return x;
}
int main() {
	setlocale(LC_ALL, "ru");
	short choise;
	short right_number = (int8_t)(xorui32());
	string alarm = " При этом всём у тебя осталось попыток: ";
	string going_beyond = "Произошла ошибка, напомню: число находится в в интервале [-128; 127]. Попробуй ещё раз!" + alarm;
	string cheers = "Привет, это игра, где ты должен угадать число, находящееся в интервале [-128; 127], удачи! Всего у тебя имеется 10 попыток на отгадывание, Начнём!";
	string last_attemp_alarm = "Внимание, у тебя осталась последняя попытка, постарайся!";
	string right_predict = "Ты угадал, поздравляю! Ты победил с попытки: ";
	string wrong_predict = "Ты не угадал." + alarm;
	string suspected_predict = "Совпадение, ты угадал число и оно являлось порядковым номером твоей попытки, ты угадал!" + alarm;
	string input = "Введите свой ответ: ";

	for (int i = 1; i <= 10; i++) {
		if (i == 1) { cout << cheers << endl; }
		if (i == 10) { cout << last_attemp_alarm << endl; break; }

		cout << input; cin >> choise; cout << endl;

		if (choise == 5239) { cout << right_number << endl; };

		if (choise == i) {
			cout << suspected_predict << 10 - i << endl;
		}
		switch (choise) {

		case(666):
			cout << going_beyond << 10 - i << endl;
		}
		if (choise == right_number) {
			cout << right_predict << 10 - i << endl; break;
		}
		if (choise != right_number) {
			cout << wrong_predict << 10 - i << endl;
		}
	}
};