#pragma once
#include <iostream>
#include <string>;
#include <vector>
using namespace std;

namespace std {

    int ReadNum(string text) {
        int num = 0;
        cout << "\n" << text;
        cin >> num;
        return num;
    }
    bool isisLeapYear(int year) {

        bool Cheacker = year % 400 == 0 ? true : year % 4 == 0 && year % 100 != 0 ? true : false;
        return Cheacker;
    }
    short NumOfDaysInYear(int year) {
        short Day = isisLeapYear(year) ? 366 : 365;
        return Day;
    }
    short NumOfHouursInYear(int Year) {
        return NumOfDaysInYear(Year) * 24;
    }
    int NumOfMunitesInYear(int Year) {
        return NumOfHouursInYear(Year) * 60;
    }
    int NumOfSecondsInYear(int Year) {
        return NumOfMunitesInYear(Year) * 60;
    }
    // Mounth
    short MounthNum(int Num) {
        int arr[12] = { 31 , 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31 };
        return arr[Num - 1];
    }
    short NumOfDaysInMounth(int year, int Mounth) {
        short Day = isisLeapYear(year) && Mounth == 2 ? 29 : Mounth == 2 ? 28 : MounthNum(Mounth);
        return Day;
    }
    short NumOfHouursInMounth(int Year, int Mounth) {
        return NumOfDaysInMounth(Year, Mounth) * 24;
    }
    int NumOfMunitesInMounth(int Year, int Mounth) {
        return NumOfHouursInMounth(Year, Mounth) * 60;
    }
    int NumOfSecondsInMounth(int Year, int Mounth) {
        return NumOfMunitesInMounth(Year, Mounth) * 60;
    }
    void PrintTheDetiales(int Year, int Mounth) {
        cout << "\n Numbers of Days in [" << Mounth << "] is: " << NumOfDaysInMounth(Year, Mounth);
        cout << "\n Numbers of Hours in [" << Mounth << "] is: " << NumOfHouursInMounth(Year, Mounth);
        cout << "\n Numbers of Munites in [" << Mounth << "] is: " << NumOfMunitesInMounth(Year, Mounth);
        cout << "\n Numbers of Secondes in [" << Mounth << "] is: " << NumOfSecondsInMounth(Year, Mounth);
    }

    struct stCulcs {
        int a;
        int y;
        int m;
    };
    stCulcs CuclTheDate(short year, short mounth, short day) {
        stCulcs sNum;
        sNum.a = (14 - mounth) / 12;
        sNum.y = year - sNum.a;
        sNum.m = mounth + 12 * (sNum.a) - 2;

        return sNum;
    }
    short GorgianCalender(short year, short mounth, short day) {
        stCulcs sNum = CuclTheDate(year, mounth, day);
        short d = (day + sNum.y + (sNum.y / 4) - (sNum.y / 100) + (sNum.y / 400) + ((31 * sNum.m) / 12)) % 7;
        return d;
    }
    string ShortDay(short day) {
        string arr[7] = { "Sun", "Mon", "Tue" , "Wed", "Thu", "Fri", "Sat" };
        return arr[day];
    }
    void PrintTheDate(short year, short mounth, short day) {
        short DaySorts = GorgianCalender(year, mounth, day);


        cout << "\nThe date: " << day << " | " << mounth << " | " << year;
        cout << "\nThe order : " << DaySorts + 1;
        cout << "\nThe Day: " << ShortDay(DaySorts);
    }

    // Claender Mounth

    string ShortMounth(short mounth) {
        string arr[12] = { "Jan", "Fev", "Mar", "Avr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec" };
        return arr[mounth - 1];
    }
    void PrintShortDays() {
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
    }
    void PrintShortDaysWithNum(short mounth, short year) {
        short DaysInMounth = NumOfDaysInMounth(year, mounth);
        PrintShortDays();
        for (short i = 1; i <= DaysInMounth; i++) {
            short count = 0;
            short DayPos = GorgianCalender(year, mounth, i);
            while (ShortDay(count) != ShortDay(DayPos)) {
                count++;
                if (i == 1) {
                    printf("     ");
                }
            }
            printf("%5d", i);
            if (count == 6) {
                cout << endl;
            }
        }
    }
    void PrintCalenderOfTheMounth(short mounth, short year) {
        cout << "\n  ------------" << ShortMounth(mounth) << "-------------------\n";
        cout << "  ----------------------------------\n";
        PrintShortDaysWithNum(mounth, year);
        cout << "\n\n  ----------------------------------\n";
    }
    // Per Year 
    void PrintCalenderOfTheYear(short Year) {
        printf("\n\n -------- -------- -------- \n");
        printf("       Calender * %d        ", Year);
        printf("\n -------- -------- -------- \n");
        for (short i = 1; i <= 12; i++) {
            PrintCalenderOfTheMounth(i, Year);
            cout << "\n";
        }
    }

    short CulcTheDaysFromTheBeg(short Year, short Mounth, short Day) {
        short NumberOfDays = 0;
        for (short i = 1; i < Mounth; i++) {
            NumberOfDays += NumOfDaysInMounth(Year, i);
        }
        return NumberOfDays + Day;
    }
    struct stDate {
        short Year;
        short Mounth;
        short Day;
    };
    stDate GetDateFromDayNumsOrder(short numDays, short& Year) {
        stDate date;
        date.Year = Year;
        short ReaminigDays = numDays;
        short CurrentMounth = 1;
        while (true) {
            short DayInmounth = NumOfDaysInMounth(Year, CurrentMounth);
            if (ReaminigDays > DayInmounth) {
                ReaminigDays -= DayInmounth;
                CurrentMounth++;

                if (CurrentMounth > 12) {
                    date.Year++;
                    CurrentMounth = 1;
                }

            }
            else {
                date.Day = ReaminigDays;
                break;
            }



        }
        date.Mounth = CurrentMounth;
        return date;
    }

    bool isDate2AfterDate1(stDate sOne, stDate sTwo) {
        return (sOne.Year < sTwo.Year) ? true : ((sOne.Year == sTwo.Year) ? (sOne.Mounth < sTwo.Mounth ? true : (sOne.Mounth == sTwo.Mounth ? sOne.Day < sTwo.Day : false)) : false);

    }
    bool isDatesEqueal(stDate sOne, stDate sTwo) {
        return (sOne.Year == sTwo.Year) && (sOne.Mounth == sTwo.Mounth) && (sOne.Day == sTwo.Day);
    }
    void PrintTheCompare(stDate sOne, stDate sTwo) {
        bool isGrather = isDate2AfterDate1(sOne, sTwo);
        bool IsEqual = isDatesEqueal(sOne, sTwo);
        IsEqual ? cout << "The sOne is Equal to Date 2 " : isGrather ? cout << " The First date is Earleir ." : cout << "The Second Date  is Earlier !.";
    }

    bool isLastInMounth(stDate date) {
        short lastDayInMounth = NumOfDaysInMounth(date.Year, date.Mounth);
        return (date.Day == lastDayInMounth);
    }
    bool isLastInYear(stDate date) {
        return (date.Mounth == 12);
    }
    stDate IncreaseDayByOne(stDate date) {
        bool IsLastInMounth = isLastInMounth(date);
        bool IsLastInYear = isLastInYear(date);
        if (IsLastInMounth) {
            if (IsLastInYear) {
                date.Day = 1;
                date.Mounth = 1;
                date.Year++;
            }

            else {
                date.Mounth++;
                date.Day = 1;
            }
        }
        else {
            date.Day++;
        }
        return date;

    }
    void SwapDates(stDate& d1, stDate& d2) {
        stDate Td;
        Td.Year = d1.Year;
        Td.Mounth = d1.Mounth;
        Td.Day = d1.Day;

        d1.Year = d2.Year;
        d1.Mounth = d2.Mounth;
        d1.Day = d2.Day;

        d2.Year = Td.Year;
        d2.Mounth = Td.Mounth;
        d2.Day = Td.Day;
    }
    stDate DateOfNow() {
        stDate date;
        time_t t = time(0);
        tm* now = localtime(&t);
        date.Year = now->tm_year + 1900;
        date.Mounth = now->tm_mon + 1;
        date.Day = now->tm_mday;
        return date;
    }
  
    // Increaseing 
    stDate IncreaseDayByXdays(stDate d, short numDays) {
        for (short i = 1; i <= numDays; i++) {
            d = IncreaseDayByOne(d);
        }
        return d;
    }
    stDate IncreaseByOneWeek(stDate d) {
        return IncreaseDayByXdays(d, 7);
    }
    stDate IncreaseByXWeeks(stDate d, short numWeeks) {
        for (short i = 1; i <= numWeeks; i++) {
            d = IncreaseByOneWeek(d);
        }
        return d;
    }
    stDate IncreaseByOneMounth(stDate d) {
        if (d.Mounth == 12) {
            d.Mounth = 1;
            d.Day = 1;
            d.Year++;
        }
        else {
            d.Mounth++;
        }
        short NumDayInMounth = NumOfDaysInMounth(d.Mounth, d.Year);
        if (d.Day > NumDayInMounth) {
            d.Day = NumDayInMounth;
        }
        return d;
        return d;
    }
    stDate IncreaseByXMounth(stDate d, short numMounths) {
        for (short i = 1; i <= numMounths; i++) {
            d = IncreaseByOneMounth(d);
        }
        return d;
    }
    stDate IncreaseByOneYear(stDate d) {
        d.Year += 1;
        return d;
    }
    stDate IncreaseByXYears(stDate d, short numYears) {
        for (short i = 0; i <= numYears; i++) {
            d = IncreaseByOneYear(d);
        }
        return d;
    }
    stDate IncreaseByXYearsFaster(stDate d, short numYears) {
        d.Year = d.Year + numYears;
        return d;
    }
    stDate IncreaseByXDecate(stDate d, short numDecate) {
        for (short i = 1; i <= numDecate; i++) {
            d = IncreaseByXYearsFaster(d, 10);
        }
        return d;
    }
    stDate IncreaseByXDecateFaster(stDate d, short numDecates) {
        d.Year = d.Year + numDecates * 10;
        return d;
    }
    stDate IncreaseByCentury(stDate d) {
        return IncreaseByXDecateFaster(d, 10);
    }
    stDate IncreaseByMillennim(stDate d) {
        d.Year = d.Year + 1000;
        return d;
    }

    // Decreasing 
    stDate DecreaseingOneDay(stDate d) {
        if (d.Day == 1) {
            if (d.Mounth == 1) {
                d.Mounth = 12;
                d.Day = 31;
                d.Year--;
            }
            else {
                d.Mounth--;
                short NumOfDaysInMouth = NumOfDaysInMounth(d.Year, d.Mounth);
                d.Day = NumOfDaysInMouth; 
            }
        }
        else {
            d.Day--;
        }
        return d;
    }
    stDate DecreaseeByXDays(stDate d, short NumDays) {
        for (short i = 0; i < NumDays; i++) {
            d = DecreaseingOneDay(d);
        }
        return d;
    }
    stDate DecreaseeOneWeek(stDate d) {
        return DecreaseeByXDays(d, 7);
    }
    stDate DecreaseeByXWeeks(stDate d, short numOfWeeks) {
        for (short i = 0; i < numOfWeeks; i++) {
            d = DecreaseeOneWeek(d);
        }
        return d;
    }
    stDate DecreaseeOneMounth(stDate d) {
        if (d.Mounth == 1) {
            d.Mounth = 12;
        }
        else {
            d.Mounth--;
            if (d.Day == 30 || d.Day == 31) {
                d.Day = NumOfDaysInMounth(d.Year, d.Mounth);
            }
        }
        if (d.Mounth == 2) {
            if (d.Day == 29)
                d.Day = NumOfDaysInMounth(d.Year, d.Mounth);
        }
        return d;
    }
    stDate DecreasereByXMounths(stDate d, short numMounths) {
        for (short i = 1; i <= numMounths; i++) {
            d = DecreaseeOneMounth(d);
        }
        return d;
    }
    stDate DecreaseeOneYear(stDate d) {
        d.Year--;
        return d;
    }
    stDate DecreaseByXYear(stDate d, short numYears) {
        d.Year = d.Year - numYears;
        return d;
    }
    stDate DecreaseOneDecade(stDate d) {
        d.Year -= 10;
        return d;
    }
    stDate DecreaseByXdecades(stDate d, short numDecades) {
        d.Year -= numDecades * 10;
        return d;
    }
    stDate DecreaseByOneCentry(stDate d) {
        d.Year -= 100;
        return d;
    }
    stDate DecreaseByOneMillennium(stDate d) {
        d.Year -= 100;
        return d;
    }

    void GetDate(stDate d, string Massage = "Today is ") {
        short OrderdDay = GorgianCalender(d.Year, d.Mounth, d.Day);

        cout << Massage << ShortDay(OrderdDay) << ", ";
        cout << d.Day << " / " << d.Mounth << " / " << d.Year << " \n";
    }

    bool isItEndOfWeek(stDate d) {
        short OrderdDay = GorgianCalender(d.Year, d.Mounth, d.Day);
        if (OrderdDay == 6) {
            return 1;
        }
        return 0;
    }
    bool isItWeekend(stDate d) {
        short OrderdDay = GorgianCalender(d.Year, d.Mounth, d.Day);
        if (OrderdDay == 6 || OrderdDay == 5) {
            return 1;
        }
        return 0;
    }
    bool isItBusinessDay(stDate d) {
        return !isItWeekend(d);
    }
    short DaysUntilendOfWeek(stDate d) {
        short OrderdDay = GorgianCalender(d.Year, d.Mounth, d.Day);
        return 6 - OrderdDay;
    }
    short DaysUntilEndoFMounths(stDate d) {
        short numOfdayinMounth = NumOfDaysInMounth(d.Year, d.Mounth);
        return numOfdayinMounth - d.Day;
    }
    short DaysUntilEndOfYear(stDate d) {
        short numDaysYear = isisLeapYear(d.Year) ? 366 : 365;
        return numDaysYear - CulcTheDaysFromTheBeg(d.Year, d.Mounth, d.Day);
    }
    int DiffernceBetwenTheDays(stDate d1, stDate d2, bool WithPlusDay = 1) {
        int DiffNum = 0;
        short Mark = 1;
        if (isDate2AfterDate1(d1, d2) == 0) {
            SwapDates(d1, d2);
            Mark = -1;
        }

        while (isDate2AfterDate1(d1, d2)) {
           
            DiffNum++;
   
            d1 = IncreaseDayByOne(d1);
        }

        return WithPlusDay ? DiffNum * Mark : DiffNum++ * Mark;
    }
    short CulcDaysInPeriod(stDate d, stDate d2, bool inc = 0) {
        int DiffNum = 0;

        while (isDate2AfterDate1(d, d2)) {
            d = IncreaseDayByOne(d);
            DiffNum++;
        }
        return inc ? DiffNum++ : DiffNum;
    
    }
    void PrintFromToDate(stDate d, stDate d2) {
        GetDate(d, "Vaction From: ");
        GetDate(d2, "Vaction To: ");

        cout << "\n \n Actucal vacation Days is : " << DiffernceBetwenTheDays(d, d2) << "\n";
    }

    void PrintEvryThink(stDate d)    {
        GetDate(d);
        cout << "\n";
        cout << "\n\nIs it EndOFWeek? \n";
        if (isItEndOfWeek(d))
            cout << "Yes!, it is end of week\n";
        else
            cout << "NO!, its not end of Week \n ";


        cout << "\n\nIs it Weekend \n";
        if (isItWeekend(d))
            cout << "Yes!, it is Weekend\n";
        else
            cout << "NO!, its not Weekend \n ";


        cout << "\n\nIs it Business Day \n";
        if (isItBusinessDay(d))
            cout << "Yes!, it is a Business Day\n";
        else
            cout << "NO!, its not a Business Day \n\n\n";


        cout << "Days Until end Of Week : " << DaysUntilendOfWeek(d) << "\n";
        cout << "Days Until end Of Mounth : " << DaysUntilEndoFMounths(d) << "\n";
        cout << "Days Until end Of Year : " << DaysUntilEndOfYear(d) << "\n";
    }
    stDate CulclateVacution(stDate d, short NumOfDays) {
        for (short i = 0; i < NumOfDays; i++) {
            while (isItWeekend(d)) {
                d = IncreaseDayByOne(d);
            }
            d = IncreaseDayByOne(d);
        }
        return d;
    }
    enum enTime { eBefore = -1, eEqual = 0, eAfter = 1 };
    enTime CheackTimePosition(stDate d, stDate d2) {
        if (isDatesEqueal(d, d2))
            return enTime::eEqual;
        else {
            switch (isDate2AfterDate1(d, d2))
            {
            case true:
                return enTime::eBefore;
            case false:
                return enTime::eAfter;
            }
        }
    }
    struct stPeriod {
        stDate d;
        stDate d2;
    };
    bool isOverlap(stPeriod p1, stPeriod p2) {

        if (isDatesEqueal(p1.d2, p2.d))
            return 1;
        if (isDate2AfterDate1(p2.d, p1.d2))
            return 1;
        if (isDate2AfterDate1(p1.d, p2.d2))
            return 1;
        else
            return 0;
    }
    bool isDateExist(stPeriod p, stDate d) {
        if (isDate2AfterDate1(p.d, d) && isDate2AfterDate1(d, p.d2))
            return 1;
        else
            return 0;
    }
    bool ChaeckDateValidity(stDate d) {
        if (d.Year < 0)
            return 0;


        short DayInMounth = NumOfDaysInMounth(d.Year, d.Mounth);

        if (d.Day > DayInMounth)
            return 0;

        if (d.Mounth > 12 || d.Mounth < 0)
            return 0;

        return 1;
    }
    string ReadDateAsAstring() {

        string date = "";

        do
        {
            cout << "\nPlease enter a date: ";
            getline(cin >> ws, date);
        } while (date.length() < 8);

        return date;
    }
    vector <int> SplitTheWords(string text, string dilmet = "/") {
        vector <int> vTokens;
        short pos = 0;
        string sWord = "";
        while ((pos = text.find(dilmet)) != std::string::npos) {
            sWord = text.substr(0, pos);
            //cout << sWord << "\n";
            if (sWord != "") {


                vTokens.push_back(stoi(sWord));

            }
            text.erase(0, pos + dilmet.length());
        }
        if (text != "") {


            vTokens.push_back(stoi(text));

        }
        return vTokens;
    }
    stDate ConvertStringDateToStruct(string text) {
        vector <int> vDate = SplitTheWords(text);
        stDate d;
        d.Day = vDate.at(0);
        d.Mounth = vDate.at(1);
        d.Year = vDate.at(2);
        return d;
    }
    string ConvertStructsToString(stDate d, string dilmet = "/") {
        return to_string(d.Day) + dilmet + to_string(d.Mounth) + dilmet + to_string(d.Year);
    }


    stDate ReadeDateOne() {
        stDate date;
        bool isValid = true;
        do
        {
            date.Day = ReadNum("Please enter the Day: ");
            date.Mounth = ReadNum("Please enter the Mounth: ");
            date.Year = ReadNum("Please Enter a Year: ");
            isValid = ChaeckDateValidity(date);
            if (!isValid)
                cout << "\nInvalid Date, enter a valid date: \n";
        } while (!isValid);



        return date;
    }
    stPeriod ReadePeriod() {
        stPeriod p;
        cout << "\nFirst date: \n";
        p.d = ReadeDateOne();
        cout << "\nSeconde date: \n";
        p.d2 = ReadeDateOne();

        return p;
    }

}





