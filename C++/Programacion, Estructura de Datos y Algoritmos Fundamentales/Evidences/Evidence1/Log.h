#include <iostream>
using namespace std;
#pragma once

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    //string key;
    int monthValue;
    int dayValue;
    int yearValue;
    int timeValue;
    
    int getMonthValue(string Mth);
    int getTimeValue(string LeTime);
    bool operator<(Log log);
    bool operator>(Log log);
    bool operator==(Log log);

    Log(string year, string month, string day, string time, string ip, string message);
};

/*Constructor de la estructura Log, recibe como parámetros de entrada cada uno de los atributos del objeto*/
Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    monthValue = getMonthValue(month);
    dayValue = stoi(day);
    yearValue = stoi(year);
    timeValue = getTimeValue(time);        
}

/*Método de la estructura Log que regresa un valor entero y recibe un string
    el entero que regresa corresponde a la posición en el año del més escrito en el string*/
int Log::getMonthValue(string Mth) {
    if (Mth == "Jan") {
        return 1;
    } else if (Mth == "Feb") {
        return 2;
    } else if (Mth == "Mar") {
        return 3;
    } else if (Mth == "Apr") {
        return 4;
    } else if (Mth == "May") {
        return 5;
    } else if (Mth == "Jun") {
        return 6;
    } else if (Mth == "Jul") {
        return 7;
    } else if (Mth == "Aug") {
        return 8;
    } else if (Mth == "Sep") {
        return 9;
    } else if (Mth == "Oct") {
        return 10;
    } else if (Mth == "Nov") {
        return 11;
    } else if (Mth == "Dec") {
        return 12;
    } else {
        return 0;
    }
}

/* Método de la estructura Log que recibe como argumento un string que representa el tiempo en formato 00:00:00 
 y regresa el valor del "tiempo" como un entero de 6 dígitos*/
int Log::getTimeValue(string LeTime) {
    return (LeTime[0] - '0') * 100000 + (LeTime[1] - '0') * 10000 + (LeTime[3] - '0') * 1000 + (LeTime[4] - '0') * 100 + (LeTime[6] - '0') * 10 + (LeTime[7] - '0');
}

/*Método del operador menor que (<) para la estructura Log, recibe otro objeto Log y regresa el resultado 
de comparar los valores necesarios de la fecha con el operador menor que (<)*/
bool Log::operator<(Log log) {
    
    if (yearValue != log.yearValue)
        return yearValue < log.yearValue;
    else if (monthValue != log.monthValue)
        return monthValue < log.monthValue;
    else if (dayValue != log.dayValue)
        return dayValue < log.dayValue;
    else if (timeValue != log.timeValue) {
        return timeValue < log.timeValue;
    } else {
        return false;
    }

}

/*Método del operador mayor que (>) para la estructura Log, recibe otro objeto Log y regresa el resultado 
de comparar los valores necesarios de la fecha con el operador mayor que (>)*/
bool Log::operator>(Log log) {
    if (yearValue != log.yearValue)
        return yearValue > log.yearValue;
    else if (monthValue != log.monthValue)
        return monthValue > log.monthValue;
    else if (dayValue != log.dayValue)
        return dayValue > log.dayValue;
    else if (timeValue != log.timeValue) {
        return timeValue > log.timeValue;
    } else {
        return false;
    } 
}

/*Método del operador igual a (==) para la estructura Log, recibe otro objeto Log y regresa el resultado 
de comparar todos los valores de la fecha con el operador igual a (==)*/
bool Log::operator==(Log log) {
    if (yearValue == log.yearValue && monthValue == log.monthValue && dayValue == log.dayValue && timeValue == log.timeValue)
        return true;
    else
        return false; 
}

/*función de sobrecarga del operador de inserción (<<)
recibe de valor de entrada un objeto ostream y un objeto Log
regresa el objeto ostream con la información que se quiere desplegar del objeto Log 
*/
std::ostream& operator<<(std::ostream& os, Log& log) {
    os << log.month << " " << log.day << " " << log.year << " " << log.time << " " << log.ip << " " << log.message;
    return os; 
}