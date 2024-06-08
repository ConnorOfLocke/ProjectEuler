#include "Euler19_CountingSundays.h"
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std::chrono;

Euler19_CountingSundays::Euler19_CountingSundays()
{
}

Euler19_CountingSundays::~Euler19_CountingSundays()
{
}

std::string Euler19_CountingSundays::Name()
{
	return "Euler 19 Counting Sundays";
}

void Euler19_CountingSundays::Run()
{
	//Needs to be revisited. Gets an answer that's one off the correct one.

	//Calculate how many sundays there are from 
	// (1 Jan 1901) to (31 Dec 2000)
	//				jan, feb,	mar,	apr, may,	jun,	jul,	aug,	sept,  oct,	nov, dec
	int monthes[] = {31, 28,	 31,	30,	 31,	 30,	31,		31,		30,		31, 30 ,31};
	//leap years on the year being divided by four
	std::string dayNames[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	int sundayCount = 0;

	int day = 7;
	int dayNameIndex = 0;
	int month = 1;
	int year = 1900;

	for (; year < 2001; day += 7)
	{		
		//leap year check
		if (month == 2)
		{
			//leap year
			if (year % 4 == 0 && year % 400 != 0)
			{
				if (day > 29)
				{
					month++;
					day = day - 29;
				}
			}
			//not as leap year
			else 
			{
				if (day > 28)
				{
					month++;
					day = day - 28;
				}
			}
		}
		else if (day > monthes[month-1])
		{
			day = day - monthes[month-1];

			month++;
			if (month > 12)
			{
				year++;
				month = 1;
			}
		}

		printf("\n%d %d %d", day, month, year);

		if (day == 1)
		{
			printf(" - 1st Sunday of the month");
			sundayCount++;
		}

	}
	printf("\n\nSunday Count ends at %d ", sundayCount);

	

	//Does not quite work since epoch time stops dates beofre 1970
	/*
	const char* dateFormat = "%b %d %Y %H:%M:%S";

	std::stringstream fromDate("Jan 1 1901 12:00:00");
	std::stringstream toDate("Dec 31 2000 12:00:00");

	std::tm fromTime = {};
	std::tm toTime = {};
	fromDate >> std::get_time(&fromTime, dateFormat);
	toDate >> std::get_time(&toTime, dateFormat);
	system_clock::time_point fromTimePoint = system_clock::from_time_t(std::mktime(&fromTime));
	system_clock::time_point toTimePoint = system_clock::from_time_t(std::mktime(&toTime));

	//const auto start{}
	printf("Check");
	*/

}
