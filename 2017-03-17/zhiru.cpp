#include "Time.hpp"
#include <string> 
#include <iostream>
using namespace std;

Time::Time(int hour1, int minute1, int second1) {
	hour = hour1;
	minute = minute1;
	second = second1;
}

Time::Time(const Time& time) {
	hour = time.hour;
	minute = time.minute;
	second = time.second;
}

Time::~Time() {
	cout << "Recycle time: ";
	string str1;
	if (hour >= 12) {
		int tmp = hour % 12;
		if (tmp >= 10) {
			str1 = tmp / 10 + '0';
			str1 += tmp % 10 + '0';
		}
		else {
			str1 = '0';
			str1 += tmp + '0';
		}
		str1 += ':';
		if (minute > 9) {
			str1 += minute / 10 + '0';
			str1 += minute % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += minute + '0';
		}
		str1 += ':';
		if (second > 9) {
			str1 += second / 10 + '0';
			str1 += second % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += second + '0';
		}
		str1 += " PM";
	}
	else {
		int tmp = hour;
		if (tmp >= 10) {
			str1 = tmp / 10 + '0';
			str1 += tmp % 10 + '0';
		}
		else {
			str1 = '0';
			str1 += tmp + '0';
		}
		str1 += ':';
		if (minute > 9) {
			str1 += minute / 10 + '0';
			str1 += minute % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += minute + '0';
		}
		str1 += ':';
		if (second > 9) {
			str1 += second / 10 + '0';
			str1 += second % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += second + '0';
		}
		str1 += " AM";
	}
	cout << str1<< endl;
}

void Time::setHour(int hour1) {
	hour = hour1;
}

void Time::setMinute(int minute1) {
	minute = minute1;
}

void Time::setSecond(int second1) {
	second = second1;
}

int Time::getHour() const {
	return hour;
}

int Time::getMinute() const {
	return minute;
}

int Time::getSecond() const {
	return second;
}

string Time::toString() const {
	string str1;
	if (hour >= 12) {
		int tmp = hour % 12;
		if (tmp >= 10) {
			str1 = tmp / 10 + '0';
			str1 += tmp % 10 + '0';
		}
		else {
			str1 = '0';
			str1 += tmp + '0';
		}
		str1 += ':';
		if (minute > 9) {
			str1 += minute / 10 + '0';
			str1 += minute % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += minute + '0';
		}
		str1 += ':';
		if (second > 9) {
			str1 += second / 10 + '0';
			str1 += second % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += second + '0';
		}
		str1 += " PM";
		return str1;
	}
	else {
		int tmp = hour;
		if (tmp >= 10) {
			str1 = tmp / 10 + '0';
			str1 += tmp % 10 + '0';
		}
		else {
			str1 = '0';
			str1 += tmp + '0';
		}
		str1 += ':';
		if (minute > 9) {
			str1 += minute / 10 + '0';
			str1 += minute % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += minute + '0';
		}
		str1 += ':';
		if (second > 9) {
			str1 += second / 10 + '0';
			str1 += second % 10 + '0';
		}
		else {
			str1 += '0';
			str1 += second + '0';
		}
		str1 += " AM";
		return str1;
	}
}

bool Time::isValid() const {
	if (hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59)
		return true;
	return false;
}

Time Time::after(int seconds) {
	int tmp = hour * 3600 + minute * 60 + second + seconds;
	hour = tmp / 3600;
	minute = (tmp % 3600) / 60;
	second = tmp % 60;
	return *this;
}

void Time::increment() {
	int tmp = hour * 3600 + minute * 60 + second + 1;
	hour = tmp / 3600;
	minute = (tmp % 3600) / 60;
	second = tmp % 60;
}

