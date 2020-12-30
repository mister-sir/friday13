// Find when Friday the 13th happens
/* Attribution:
Most of the date-calculating code comes from "calendar_gen_III - Copy - Copy.cpp"
	which was written by Brian Ulrich on 22 March 2014. If I recall correctly,
	most of the math in that code is based on information in a (really old) book
	called "Speed and Fun with Figures". (Incidentally, that book has a huge section
	on the theory and operation of slide rules.) :)
*/

/* 
 * Copyright 2018 Brian Ulrich
 * 
 * This file is part of friday13.
 * 
 * friday13 is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License 
 * as published by the Free Software Foundation, either 
 * version 3 of the License, or (at your option) any later 
 * version.
 * 
 * friday13 is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty 
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See 
 * the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public 
 * License along with friday13. If not, see 
 * http://www.gnu.org/licenses/.
 */

#include <iostream>
#include <cstdlib> // For atoi() parsing of arguments
using namespace std;

int dayofYear(int date, int month, int year/*, bool gregorian = true*/);
int dayofWeek(int dayofYear, int year);
void printcalendar(int startDay, int numDays);
void printDayofWeek(int dayNumber);
void printNameOfMonth(int month);
int daysinMonth(int month);

int main(int argc, char *argv[]){
	int startYear, endYear;

/*	if(argc == 1){

		cerr << "Entering interactive mode...\n";

		cout << "What year should we start on? ";
		cin >> startYear;

		cout << "What year should we end on? ";
		cin >> endYear;
	}*/
	/*else */if(argc == 2){
		startYear = abs(atoi(argv[1]));
		endYear = startYear;
	}
	else if(argc == 3){
		startYear = abs(atoi(argv[1]));
		endYear = abs(atoi(argv[2]));
	}
	else{
		cerr << "Usage: " << argv[0] << " start-year [end-year]\n";
		return 1;
	}

	if(endYear < startYear){
		cerr << "Start year must be less than or equal to end year.\n";
		return 2;
	}

	for (int year = startYear; year <= endYear; year++){
		cout << year << ": ";
		for (int month = 1; month <= 12; month++){
			if(dayofWeek(dayofYear(13, month, year),year) == 4){
				printNameOfMonth(month);
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}

bool isLeapYear(int year){
	if ( year % 4 == 0 ) {
		if ( year % 100 == 0 ) {
			if ( year % 400 == 0 ) { return true; }
			else { return false; }
		}
		else { return true; }
	}
	else { return false; }
}

void printNameOfMonth(int monthNumber){
	switch(monthNumber){
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			cout << "July";
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
		default:
			cerr << "That's not a month";
			break;
	}
	return;
}

void printDayofWeek(int dayNumber){
	switch(dayNumber){
		case 0:
			cout << "Monday";
			break;
		case 1:
			cout << "Tuesday";
			break;
		case 2:
			cout << "Wednesday";
			break;
		case 3:
			cout << "Thursday";
			break;
		case 4:
			cout << "Friday";
			break;
		case 5:
			cout << "Saturday";
			break;
		case 6:
			cout << "Sunday";
			break;
		default:
			cerr << "Not able to be determined...";
			break;
	}
	return;
}

int dayofYear(int date, int month, int year/*, bool gregorian = true*/){
	int dayofYear;

	switch(month){ //Set the day of the year for the beginning of each month
		case 1:
			dayofYear = 1;
			break;
		case 2:
			dayofYear = 32;
			break;
		case 3:
			dayofYear = 60;
			break;
		case 4:
			dayofYear = 91;
			break;
		case 5:
			dayofYear = 121;
			break;
		case 6:
			dayofYear = 152;
			break;
		case 7:
			dayofYear = 182;
			break;
		case 8:
			dayofYear = 213;
			break;
		case 9:
			dayofYear = 244;
			break;
		case 10:
			dayofYear = 274;
			break;
		case 11:
			dayofYear = 305;
			break;
		case 12:
			dayofYear = 335;
			break;
		default:
			dayofYear = 1;
			cerr << "Day of year set to one due to an error. Probably an invalid month.";
			break;
	}

	if( isLeapYear(year) ){ // If it's a leap year
		if(month > 2) dayofYear++; // Add one to dayofYear if later than February
	}

	dayofYear += (date - 1); //Add the date...
	return dayofYear;
}

int dayofWeek(int dayofYear, int year){ // 0 = Mon, 1 = Tue, 2 = Wed, etc
	int temp; // Temporary work variable
	temp = year + dayofYear + ((year-1)/4) + ((year-1)/400) - ((year-1)/100); //0 is Sat, 1 in Sun, 2 in Mon, etc
	temp = (temp + 5) % 7; //Makes Monday 0, Tuesday 1, etc
	return temp;
}

void printcalendar(int startDay, int numDays){
	int column = 0;
	cout << " M  Tu   W  Th   F  Sa  Su\n";
	for(int x = startDay; x >= 1; x--){
		cout << "    ";
		column++;
	}
	for(int i = 1; i <= numDays; i++){
		if(column >= 7){
			cout << endl;
			column = 0;
		}
		cout.width(2);
		cout << i;
		if(column <= 6) cout << "  "; // Column spacing
		column++;
	}
	return;
}

int daysinMonth(int month, int year){
	int mdays;
	switch(month){
		case 1:
			mdays = 31;
			break;
		case 2:
			if( isLeapYear(year) ) mdays = 29;  // Leap year!
			else mdays = 28;
			break;
		case 3:
			mdays = 31;
			break;
		case 4:
			mdays = 30;
			break;
		case 5:
			mdays = 31;
			break;
		case 6:
			mdays = 30;
			break;
		case 7:
			mdays = 31;
			break;
		case 8:
			mdays = 31;
			break;
		case 9:
			mdays = 30;
			break;
		case 10:
			mdays = 31;
			break;
		case 11:
			mdays = 30;
			break;
		case 12:
			mdays = 31;
			break;
		default:
			mdays = 1;
			break;
	}
	return mdays;
}
