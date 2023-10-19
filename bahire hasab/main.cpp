/*

//          ADDIS ABABA UNIVERSITY
    COLLEGE OF NATURAL AND COMPUTATIONAL SCIENCES
        computer science section - 1 Group - 8
        Computer Programming II Project

    Group Members                       ID No.
1. Asmare Zelalem ...................UGR/1874/13
2. Abrham Belayneh ..................UGR/3584/13
3. Helina Bikes .....................UGR/1490/13
4. Birtukan Addis ...................UGR/5759/13
5. Haileamlak Belachew ..............UGR/4204/13

                                    Submitted to: Instructor Axumawit
                                    Submission date:  May 4, 2022

*/
#include <iostream>
#include <fstream>
#include <conio.h>
#include <fcntl.h>    //for unicode
#include <windows.h>  //for color
// #include "Bahire_Hasab_lib.h"

using namespace std;

struct ቀን;                   // For Ethiopian
struct Date;                  // For Gregorian
int ወንበር(int), ጥንተ_ዮን(int), መባጃ_ሐመር(int), መደብ(int);                 // Basic informations for a year
int ተውሳክ(int Day, int month, int y), አበቅቴ(int), መጥቅዕ(int);           //
void ስቅለት(int y), ትንሳዔ(int y), ደብረ_ዘይት(int y), ሆሳዕና(int y), ጰራቅሊጦስ(int y), ዕርገት(int y); // Holidays
void ጾመ_ድኅነት(int y), ጾመ_ነነዌ(int y), ጾመ_ሐዋርያት(int y), ዓቢይ_ጾም(int y);                     // Fastings
bool በዓለ_መጥቅዕ(int), is_date(int d, int m, int y);                                       // Helper functions
void የቀን_መቁጠሪያ(ቀን), Holidays(int), Fastings(int);                                       // Menu elements
void Basic_Info(int), Date_Conversion(), Fixed_Holidays(), ዕለት(ቀን);                     //
void ዋና_ማውጫ(), መግቢያ(), ስንብት(), Help();
bool leap_year(int yy), ዘመነ_ዮሐንስ(int yy);
bool controls(); // for controlling the program

// useful constant datas
const int tewsak[7] = {7, 6, 5, 4, 3, 2, 8};
wstring greg_months[] = {L"January", L"February", L"March", L"April", L"May", L"June", L"July", L"August", L"September", L"October", L"November", L"December"};
wstring የሳምንቱ_ዕለታት[] = {L"ቅዳሜ", L"እሑድ", L"ሠኞ", L"ማግሠኞ", L"ረቡዕ", L"ሀሙስ", L"ዐርብ"};
wstring ወራት[] = {L"መስከረም", L"ጥቅምት", L"ኅዳር", L"ታኅሣሥ", L"ጥር", L"የካቲት", L"መጋቢት", L"ሚያዝያ", L"ግንቦት", L"ሰኔ", L"ሐምሌ", L"ነሐሴ", L"ጳጉሜ"};
const wstring line(40, '-');
//
wstring get_ወር(int month)
{
    return ወራት[month - 1];
}
wstring get_greg_month(int month)
{
    return greg_months[month - 1];
}

struct ቀን
{
    int day, month, year;
    ቀን(int d, int m, int y);
    ቀን() : day(01), month(01), year(2014) {}
};

ቀን::ቀን(int d, int m, int y)
    : day(d), month(m), year(y)
{
    if (d <= 0 || d > 30 || m <= 0 || m > 13 || (m == 13 && !ዘመነ_ዮሐንስ(y) && d > 5) || (m == 13 && ዘመነ_ዮሐንስ(y) && d > 6))
    {
        wcerr << L"error : Invalid date!\n";
        exit(1);
    }
}
bool ዘመነ_ዮሐንስ(int yy)
{
    if (yy % 4 == 0)
        return true;
    return false;
}
wistream &operator>>(wistream &is, ቀን &x)
{
    int d, m, y;
    wchar_t ch1, ch2;
    is >> d >> ch1 >> m >> ch2 >> y;
    if (ch1 != '/' || ch2 != '/')
    {
        wcout << "error : invalid date format";
        is.clear();
        return is;
    }
    x = ቀን{d, m, y};
    return is;
}
wostream &operator<<(wostream &os, ቀን &x)
{
    wcout << get_ወር(x.month) << L" " << x.day << L" " << x.year << L" ዓ.ም";
    return os;
}
struct Date
{
    int d, m, y;
    Date(int dd, int mm, int yy);     // check for valid date and initialize
    Date() : d{01}, m{01}, y{2022} {} // default constructor
};
Date::Date(int dd, int mm, int yy)
    : d{dd}, m{mm}, y{yy}
{
    if (!is_date(dd, mm, yy))
    {
        wcout << "error : invalid date format";
        exit(5);
    }
}
bool leap_year(int yy)
{
    if (yy % 400 == 0)
        return true;
    if (yy % 4 == 0 && yy % 100 != 0)
        return true;
    return false;
}
bool is_date(int d, int m, int y)
{
    if (d <= 0 || m < 1 || 12 < m)
        return false;
    int days_in_month = 31; // most months have 31 days
    switch (m)
    {
    case 2: // the length of February varies
        days_in_month = (leap_year(y)) ? 29 : 28;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days_in_month = 30; // the rest have 30 days
        break;
    }
    if (days_in_month < d)
        return false;
    return true;
}

int main()
{
    _setmode(fileno(stdout), _O_U8TEXT);
    _setmode(fileno(stdin), _O_U8TEXT);
    መግቢያ();
    system("pause");
    Help();
    system("pause");
    return 0;
}

void ዋና_ማውጫ()
{
    system("cls");
    wcout << L"\t\t\tዋና ማውጫ\n";
    wifstream Read_Menu{"Menu.txt"};
    wstring line;
    while (getline(Read_Menu, line))
        wcout << line << endl;
    wcout << L"ምርጫህን አስገባ : ";
    int ch;
    wcin >> ch;
    switch (ch)
    {
    case 1:
    {
    there_1:
        system("cls");
        ቀን day_1;
        wcout << L"ቀን አስገባ ( ቀን/ወር/ዓመት ) : ";
        wcin >> day_1;
        የቀን_መቁጠሪያ(day_1);
        if (controls())
            goto there_1;
        break;
    }
    case 2:
    {
    there_2:
        system("cls");
        wcout << L"አመተ ምሕረት አስገባ : ";
        int year;
        wcin >> year;
        system("cls");
        Holidays(year);
        if (controls())
            goto there_2;
        break;
    }
    case 3:
    {
    there_3:
        system("cls");
        wcout << L"አመተ ምሕረት አስገባ : ";
        int year;
        wcin >> year;
        system("cls");
        Fastings(year);
        if (controls())
            goto there_3;
        break;
    }
    case 4:
    {
    there_4:
        system("cls");
        wcout << L"አመተ ምሕረት አስገባ : ";
        int year;
        wcin >> year;
        system("cls");
        Basic_Info(year);
        if (controls())
            goto there_4;
        break;
    }
    case 5:
    {
    there_5:
        system("cls");
        Date_Conversion();
        if (controls())
            goto there_5;
        break;
    }
    case 6:
    {
    there_6:
        system("cls");
        wcout << L" ዕለቱን ለማዎቅ የሚፈልጉትን ቀን ያስገቡ (ቀን/ወር/አመት) : ";
        ቀን y;
        wcin >> y;
        system("cls");
        ዕለት(y);
        if (controls())
            goto there_6;
        break;
    }
    case 7:
    {
    there_7:
        system("cls");
        Fixed_Holidays();
        if (controls())
            goto there_7;
        break;
    }
    case 8:
    {
    there_8:
        system("cls");
        Help();
        if (controls())
            goto there_8;
        break;
    }
    default:
        wcerr << L"error : Invalid input!\n";
        ስንብት();
        exit(6);
        break;
    }
}
bool controls()
{
    wcout << "\nR - refresh\tM - Main Menu\tH - Help\tExit\n";
    if (_kbhit)
    {
        switch (getch())
        {
        case 'm':
        case 'M':
            ዋና_ማውጫ();
            break;
        case 'r':
        case 'R':
            return true;
        case 'h':
        case 'H':
            Help();
        default:
            ስንብት();
            exit(7);
        }
        return false;
    }
}
void Help()
{
there:
    system("cls");
    wstring line;
    wfstream Read_Help{"Help.txt"};
    while (getline(Read_Help, line))
        wcout << line << endl;
    if (controls())
        goto there;
}
void የቀን_መቁጠሪያ(ቀን day_1)
{
    HANDLE console_color;
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    wcout << L"\n\n\n\t\t\t" << get_ወር(day_1.month) << L" " << day_1.year << L" ዓ.ም\n";
    int ዕለት_ማስያ = (1 + 2 * day_1.month + ጥንተ_ዮን(day_1.year)) % 7;
    int temp_ቀን = ዕለት_ማስያ == 0 ? -5 : 2 - ዕለት_ማስያ;
    SetConsoleTextAttribute(console_color, 131); // green
    wcout << L"\t\t ************************************** \t\n"
          << L"\t\t||  እሁድ  ሠኞ  ማግሠኞ ረቡዕ  ሀሙስ  ዐርብ  ቅዳሜ  ||\t\n";
    for (int i = 0; i < 6; i++)
    {
        if (i == 1)
            SetConsoleTextAttribute(console_color, 134); // yellow
        if (i == 4)
            SetConsoleTextAttribute(console_color, 133); // red
        wcout << L"\t\t|| ";
        for (int j = temp_ቀን; j <= temp_ቀን + 6; j++)
        {
            if (j < 1 || j > 30 || (ዘመነ_ዮሐንስ(day_1.year + 1) && day_1.month == 13 && j > 6) || (!ዘመነ_ዮሐንስ(day_1.year + 1) && day_1.month == 13 && j > 5))
                wcout << L"     ";
            else
            {
                wcout << L" ";
                if (j < 10 && j > 0)
                    wcout << 0;
                wcout << j << L"  ";
            }
        }
        temp_ቀን += 7;
        wcout << L"||\t" << endl;
        if (day_1.month == 13 && i == 1)
            break;
    }
    wcout << L"\t\t **************************************\n";
    SetConsoleTextAttribute(console_color, 129);
    wcout << L"\tprevious - '<' \t\t\t\t   '>' - next \n";
    if (_kbhit)
    {
        switch (getch())
        {
        case '>':
        case '.':
        {
            if (day_1.month == 13)
            {
                day_1.month = 1;
                day_1.year++;
            }
            else
                day_1.month++;
            የቀን_መቁጠሪያ(day_1);
            break;
        }
        case '<':
        case ',':
        {
            if (day_1.month == 1)
            {
                day_1.month = 13;
                day_1.year--;
            }
            else
                day_1.month--;
            የቀን_መቁጠሪያ(day_1);
            break;
        }
        default:
            break;
        }
    }
}
void Holidays(int year)
{
    wcout << L"የ " << year << L" ዓ.ም በዓላት ዝርዝር :-" << endl
          << ::line << endl;
    ደብረ_ዘይት(year);
    ሆሳዕና(year);
    ስቅለት(year);
    ትንሳዔ(year);
    ጰራቅሊጦስ(year);
    ዕርገት(year);
    wcout << endl
          << ::line << endl;
}
void Fastings(int year)
{
    wcout << L"የ " << year << L" ዓ.ም አጽዋማት ዝርዝር :-" << endl
          << ::line << endl;
    ጾመ_ድኅነት(year);
    ጾመ_ነነዌ(year);
    ጾመ_ሐዋርያት(year);
    ዓቢይ_ጾም(year);
    wcout << endl
          << ::line << endl;
}
void Basic_Info(int year)
{
    wcout << L"የ " << year << L" ዓ.ም መሰረታዊ ስሌቶች ዝርዝር :-" << endl
          << ::line << endl;
    wcout << L"ወንበር = " << ወንበር(year) << endl;
    wcout << L"ጥንተ ዮን = " << ጥንተ_ዮን(year) << endl;
    wcout << L"መባጃ ሐመር = " << መባጃ_ሐመር(year) << endl;
    wcout << L"መደብ = " << መደብ(year) << endl;
    wcout << L"አበቅቴ = " << አበቅቴ(year) << endl;
    wcout << L"መጥቅዕ = " << መጥቅዕ(year) << endl;
    wcout << endl
          << ::line << endl;
}
void ዕለት(ቀን y)
{
    int yy = (y.day + 2 * y.month + ጥንተ_ዮን(y.year)) % 7;
    wcout << ::line << endl
          << y << L" ዕለተ " << የሳምንቱ_ዕለታት[yy] << L" ይውላል።\n"
          << endl
          << ::line << endl;
}
void Date_Conversion()
{
    wcout << L"ቀን አስገባ (ቀን/ወር/አመት) : ";
    int pagume_n, leap_c;
    ቀን input;
    Date output;
    wcin >> input;
    leap_c = ዘመነ_ዮሐንስ(input.year) ? 1 : 0;
    pagume_n = ዘመነ_ዮሐንስ(input.year + 1) ? 6 : 5;
    if (input.month == 1)
    {
        if (input.day >= 1 && input.day <= 20 - leap_c)
            output = Date{input.day + 10 + leap_c, 9, input.year + 7};
        else if (input.day >= 21 - leap_c && input.day <= 30)
            output = Date{input.day - 20 + leap_c, 10, input.year + 7};
    }
    if (input.month == 2)
    {
        if (input.day >= 1 && input.day <= 21 - leap_c)
            output = Date{input.day + 10 + leap_c, 10, input.year + 7};
        else if (input.day >= 21 - leap_c && input.day <= 30)
            output = Date{input.day - 21 + leap_c, 11, input.year + 7};
    }
    if (input.month == 3)
    {
        if (input.day >= 1 && input.day <= 21 - leap_c)
            output = Date{input.day + 9 + leap_c, 11, input.year + 7};
        else if (input.day >= 22 - leap_c && input.day <= 30)
            output = Date{input.day - 21 + leap_c, 12, input.year + 7};
    }
    if (input.month == 4)
    {
        if (input.day >= 1 && input.day <= 22 - leap_c)
            output = Date{input.day + 9 + leap_c, 12, input.year + 7};
        else if (input.day >= 23 - leap_c && input.day <= 30)
            output = Date{input.day - 22 + leap_c, 1, input.year + 8};
    }
    if (input.month == 5)
    {
        if (input.day >= 1 && input.day <= 23 - leap_c)
            output = Date{input.day + 8 + leap_c, 1, input.year + 8};
        else if (input.day >= 24 - leap_c && input.day <= 30)
            output = Date{input.day - 23 + leap_c, 2, input.year + 8};
    }
    if (input.month == 6)
    {
        if (input.day >= 1 && input.day <= 21)
            output = Date{input.day + 7 + leap_c, 2, input.year + 8};
        else if (input.day >= 22 && input.day <= 30)
            output = Date{input.day - 21, 3, input.year + 8};
    }
    if (input.month == 7)
    {
        if (input.day >= 1 && input.day <= 22)
            output = Date{input.day + 9, 3, input.year + 8};
        else if (input.day >= 23 && input.day <= 30)
            output = Date{input.day - 22, 4, input.year + 8};
    }
    if (input.month == 8)
    {
        if (input.day >= 1 && input.day <= 22)
            output = Date{input.day + 8, 4, input.year + 8};
        else if (input.day >= 23 && input.day <= 30)
            output = Date{input.day - 22, 5, input.year + 8};
    }
    if (input.month == 9)
    {
        if (input.day >= 1 && input.day <= 23)
            output = Date{input.day + 8, 5, input.year + 8};
        else if (input.day >= 24 && input.day <= 30)
            output = Date{input.day - 23, 6, input.year + 8};
    }
    if (input.month == 10)
    {
        if (input.day >= 1 && input.day <= 23)
            output = Date{input.day + 7, 6, input.year + 8};
        else if (input.day >= 24 && input.day <= 30)
            output = Date{input.day - 23, 7, input.year + 8};
    }
    if (input.month == 11)
    {
        if (input.day >= 1 && input.day <= 24)
            output = Date{input.day + 7, 7, input.year + 8};
        else if (input.day >= 25 && input.day <= 30)
            output = Date{input.day - 24, 8, input.year + 8};
    }
    if (input.month == 12)
    {
        if (input.day >= 1 && input.day <= 25)
            output = Date{input.day + 6, 8, input.year + 8};
        else if (input.day >= 26 && input.day <= 30)
            output = Date{input.day - 25, 9, input.year + 8};
    }
    if (input.month == 13)
    {
        if (input.day >= 1 && input.day <= pagume_n)
            output = Date{input.day + 5, 9, input.year + 8};
    }
    system("cls");
    wcout << line << endl
          << endl;
    wcout << "In Ethiopian calendar : " << input << endl
          << endl;
    wcout << "In Gregorian calendar : " << get_greg_month(output.m) << L" " << output.d << L" " << output.y << endl
          << endl;
    wcout << line << endl;
}
void Fixed_Holidays()
{
    wstring line;
    wifstream Fixed{"fixed_holidays.txt"};
    wcout << ::line << "\n\n";
    while (getline(Fixed, line))
        wcout << line << endl;
    wcout << endl
          << ::line << endl;
}
void መግቢያ()
{
    wstring line;
    wfstream Read_መግቢያ{"greeting.txt"};
    while (getline(Read_መግቢያ, line))
        wcout << line << endl;
}
void ስንብት()
{
    system("cls");
    wcout << ::line << L"\n\n"
          << L"\t\tእናመሰግናለን።\n\n"
          << ::line;
}
int ወንበር(int y)
{
    return (5500 + y) % 19 - 1;
}
int መደብ(int y)
{
    return (5500 + y) % 19;
}
int አበቅቴ(int y)
{
    return (11 * ወንበር(y)) % 30;
}
int መጥቅዕ(int y)
{
    if (አበቅቴ(y) == 0)
        return 30;
    return (19 * ወንበር(y)) % 30;
}
bool በዓለ_መጥቅዕ(int y)
{
    if (መጥቅዕ(y) > 14)
        return 1;
    return 0;
}
int ጥንተ_ዮን(int y)
{
    int yon;
    yon = ((5500 + y) + (5500 + y) / 4) % 7 - 1;
    if (yon == 0)
        yon = 7;
    if (yon == -1)
        yon = 1;
    return yon;
}
int መባጃ_ሐመር(int y)
{
    if (በዓለ_መጥቅዕ(y))
        return (መጥቅዕ(y) + ተውሳክ(መጥቅዕ(y), 1, y)) % 30;
    return (መጥቅዕ(y) + ተውሳክ(መጥቅዕ(y), 2, y)) % 30;
}
int ተውሳክ(int Day, int month, int y)
{
    int sereke;
    sereke = Day + 2 * month + ጥንተ_ዮን(y);
    if (sereke > 7)
    {
        sereke %= 7;
        if (sereke == 0)
            return 0;
    }
    return tewsak[sereke - 1];
}
void ጾመ_ነነዌ(int y)
{
    if (በዓለ_መጥቅዕ(y))
        wcout << L"ጾመ ነነዌ ጥር " << መባጃ_ሐመር(y) << L" ይውላል።!\n";
    else
        wcout << L"ጾም ነነዌ የካቲት " << መባጃ_ሐመር(y) << L" ይውላል።!\n";
}
void ዓቢይ_ጾም(int y)
{
    int d;
    d = (14 + መባጃ_ሐመር(y));
    if (d > 30)
        wcout << L"ዓቢይ ጾም መጋቢት " << d % 30 << L" ይውላል።!\n";
    else
    {
        if (በዓለ_መጥቅዕ(y))
            wcout << L"ዓቢይ ጾም ጥር " << d << L" ይውላል።!\n";
        else
            wcout << L"ዓቢይ ጾም የካቲት " << d << L" ይውላል።!\n";
    }
}
void ደብረ_ዘይት(int y)
{
    int d;
    d = 27 + ((14 + መባጃ_ሐመር(y)) % 30);
    if (d <= 30)
        wcout << L"ደብረ ዘይት Yekatit " << d << L" ይውላል።!\n";
    else if (30 < d && d <= 60)
    {
        d = d % 30;
        if (d == 0)
            wcout << L"ደብረ ዘይት መጋቢት 30 ይውላል።!\n";
        else
            wcout << L"ደብረ ዘይት መጋቢት " << d << L" ይውላል።!\n";
    }
    else if (d > 60)
        wcout << L"ደብረ ዘይት ሚያዝያ " << d % 30 << L" ይውላል።!\n";
}
void ሆሳዕና(int y)
{
    int d;
    d = 18 + ((14 + መባጃ_ሐመር(y)) % 30);
    if (d > 30)
        wcout << L"ሆሳዕና ሚያዝያ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ሆሳዕና መጋቢት " << d << L" ይውላል።!\n";
}
void ስቅለት(int y)
{
    int d;
    d = 23 + ((14 + መባጃ_ሐመር(y)) % 30);
    if (d > 30)
        wcout << L"ስቅለት ሚያዝያ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ስቅለት መጋቢት " << d << L" ይውላል።!\n";
}
void ትንሳዔ(int y)
{
    int d;
    d = 25 + ((14 + መባጃ_ሐመር(y)) % 30);
    if (d > 30)
        wcout << L"ትንሳዔ ሚያዝያ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ትንሳዔ መጋቢት " << d << L" ይውላል።!\n";
}
void ዕርገት(int y)
{
    int d;
    d = 18 + መባጃ_ሐመር(y);
    if (d > 30)
        wcout << L"ዕርገት ሰኔ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ትንሳዔ ግንቦት " << d << L" ይውላል።!\n";
}
void ጰራቅሊጦስ(int y)
{
    int d;
    d = 28 + መባጃ_ሐመር(y);
    if (d > 30)
        wcout << L"ጰራቅሊጦስ ሰኔ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ጰራቅሊጦስ ግንቦት " << d << L" ይውላል።!\n";
}
void ጾመ_ሐዋርያት(int y)
{
    int d;
    d = 29 + መባጃ_ሐመር(y);
    if (d > 30)
        wcout << L"ጾመ_ሐዋርያት ሰኔ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ጾመ_ሐዋርያት ግንቦት " << d << L" ይውላል።!\n";
}
void ጾመ_ድኅነት(int y)
{
    int d;
    d = 1 + መባጃ_ሐመር(y);
    if (d > 30)
        wcout << L"ጾመ_ድኅነት ሰኔ " << d % 30 << L" ይውላል።!\n";
    else
        wcout << L"ጾመ_ድኅነት ግንቦት " << d << L" ይውላል።!\n";
}
