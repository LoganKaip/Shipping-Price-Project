// Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm> 

using namespace std;

//setting constant variable
const int linesize = 55;
const string s0 = "Invalid entry, Exiting program";
const string s1 = "ITCS 2530 - Programming Assignment for week #3";
const string s2 = "Please enter the item name (no spaces) ";
const string s3 = "Is the item fragile? (y = yes / n = no) ";
const string s4 = "Please enter your order total ";
//nep is for neptune
const string s5 = "Please enter your destination. (usa/can/aus/nep) ";
const string s6 = "Your item is ";
const string s7 = "Your shipping cost is ";
const string s8 = "You are shipping to ";
const string s9 = "You total shipping cost is ";
const string s10 = "Thank You!";

int main()
{
    //variables
    string item;
    string isfragile;
    double ordertotal;
    string destination;
    double shipcost;
    double totalship;

    //title
    cout << left << setw(linesize) << setfill('.') << '.' << endl;
    cout << s1 << endl; 
    cout << left << setw(linesize) << setfill('.') << '.' << endl;

    //inputs
    cout << left << s2 << setw(linesize - s2.length()) << right << ':' ;
    cin >> item;
    //change input lettering to uppercase
    transform(item.begin(), item.end(), item.begin(), ::toupper);

    cout << left << s3 << setw(linesize - s3.length()) << right << ':';
    cin >> isfragile;
    //change input lettering to uppercase
    transform(isfragile.begin(), isfragile.end(), isfragile.begin(), ::toupper); 

    //make sure input is y or n otherwise will end the program
    if (isfragile != "y"
        && isfragile != "n"
        && isfragile != "Y"
        && isfragile != "N")
    {
        cout << s0 << endl;
        return 0;
    }
    //next set of inputs
    cout << left << s4 << setw(linesize - s4.length()) << right << ':';
    cin >> ordertotal;
    cout << left << s5 << setw(linesize - s5.length()) << right << ':';
    cin >> destination;

    //change input lettering to uppercase
    transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

    //make sure that the destination input is one of the choices listed
    if (destination != "usa"
        && destination != "USA"
        && destination != "can"
        && destination != "CAN"
        && destination != "aus"    
        && destination != "AUS"
        && destination != "nep"
        && destination != "NEP")
    {
        cout << s0 << endl;
        return 0;
    }

    //if statements doing all the math and calculating based off inputs
    shipcost = 0.0;
    //if price is ... and destination is ... then the ship cost will be
    if (ordertotal < 150.00) {

        if (ordertotal > 100.00) {

            if (destination == "USA" ) {
                shipcost = shipcost + 12.00;
            }
            if (destination == "CAN" ) {
                shipcost = shipcost + 15.00;
            }
            if (destination == "AUS" ) {
                shipcost = shipcost + 17.00;
            }
            if (destination == "NEP") {
                shipcost = shipcost + 220.00;
            }
        }
        else if (ordertotal > 50.00) {
            if (destination == "USA" ) {
                shipcost = shipcost + 9.00;
            }
            if (destination == "CAN" ) {
                shipcost = shipcost + 12.00;
            }
            if (destination == "AUS" ) {
                shipcost = shipcost + 14.00;
            }
            if (destination == "NEP") {
                shipcost = shipcost + 200.00;
            }
        }
        else {
            if (destination == "USA" ) {
                        shipcost = shipcost + 6.00;
            }
            if (destination == "CAN" ) {
                        shipcost = shipcost + 8.00;
            }
            if (destination == "AUS" ) {
                        shipcost = shipcost + 10.00;
            }
            if (destination == "NEP") {
                shipcost = shipcost + 180.00;
            }
        }
    }
        
    

    //adding extra if item is fragile
    if (isfragile == "Y") {
        shipcost = shipcost + 2.0;
    }
    //add up total
    totalship = shipcost + ordertotal;

    //get a blank line to separate code
    cout << endl;

    //output within the linesize of program
    cout << left << s6 << setw(linesize - s6.length() - item.length()) << '.' << right << item << endl;
    //must add a +1 to line length so the $ can be added without changing the line length too much
    cout << left << s7 << setw(1 + linesize - s7.length() - item.length()) << right << '$' << fixed << setprecision(2) << shipcost << endl;
    cout << left << s8 << setw(linesize - s8.length() - item.length()) << '.' << right << destination << endl;
    cout << left << s9 << setw(1 + linesize - s9.length() - item.length()) <<  right << '$' << fixed << setprecision(2) << totalship << endl;

    //final thank you line
    cout << left << setw(linesize) << setfill('-') << right << s10 << endl;

    //end of program
    return 0;

}


