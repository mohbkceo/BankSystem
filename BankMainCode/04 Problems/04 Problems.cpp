#pragma warning (disable : 4996)
#include <iostream>
#include <string>;
#include "Lab.h";
#include <vector>
#include <iomanip>
using namespace std;

enum enStyle {eNo = 1, eRev = 2};

string ReplaceRecoredInStringS(string s, string toRplace ,  string replacment) {
    short pos = s.find(toRplace);
    while (pos != std::string::npos) {
        s.replace(pos, toRplace.length(), replacment);
        pos = s.find(toRplace);
    }
    return s;
}
string FormateDate(stDate d, string date = "dd/mm/yyyy") {
    string StringDateFormated = "";
    StringDateFormated = ReplaceRecoredInStringS(date, "dd", to_string(d.Day));
    StringDateFormated = ReplaceRecoredInStringS(StringDateFormated, "mm", to_string(d.Mounth));
    StringDateFormated = ReplaceRecoredInStringS(StringDateFormated, "yyyy", to_string(d.Year));
    return StringDateFormated;
}

short CulucdaysInPeriod(stPeriod p, stPeriod p2) {
   
    if (isDate2AfterDate1(p.d, p2.d) && isDate2AfterDate1(p2.d2, p.d2)) {
        return DiffernceBetwenTheDays(p.d, p.d2);
    }
    if (isDate2AfterDate1(p2.d, p.d) && isDate2AfterDate1(p.d2, p2.d2)) {
        return DiffernceBetwenTheDays(p2.d, p2.d2);
    }

    if (isDate2AfterDate1(p2.d, p.d2)) {
        return DiffernceBetwenTheDays(p2.d, p.d2);
    }
    if (isDate2AfterDate1(p.d, p2.d2)) {
        return DiffernceBetwenTheDays(p.d, p2.d2);
    }
    if (isDatesEqueal(p2.d, p.d2) || isDatesEqueal(p.d, p2.d2)) {
        return 1;
    }
}

int main()
{ 
    

    string date = ReadDateAsAstring();
    stDate d = ConvertStringDateToStruct(date);



    cout << "\nDay : " << d.Day;
    cout << "\nMounth : " << d.Mounth;
    cout << "\nYear: " << d.Year;

    cout << "\nThe date after converting : " << FormateDate(d);
    system("pause>0");

    
}