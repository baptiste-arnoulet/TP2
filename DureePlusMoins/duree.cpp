#include <iostream>
#include <iomanip>
#include "duree.h"

using namespace std;

#define DUREE nsUtil::Duree

void DUREE::normaliser (void)
{
    mySecond = myDuree % 60;
    myDays = myDuree / 86400;
    myHours = (myDuree % 86400) / 3600;
    myMinuts = (myDuree % 3600) / 60;
} //normaliser

DUREE DUREE::operator + (const Duree & D) const
{
    return DUREE (getDuree() + D.getDuree());
}//operator +

DUREE DUREE::operator - (const Duree & D) const
{
    if (getDuree() < D.getDuree())
        return 0;
    else
        return DUREE (getDuree() - D.getDuree());
}//operator -
DUREE::Duree (unsigned long long duree) : myDuree (duree)//const
{
    normaliser ();
    display ();

    cout << "créé" << endl;
}  //Duree

unsigned long long DUREE::getDuree (void) const {return myDuree;}

void DUREE::display (void) const
{
    cout << "[" << setw (10) << myDays << ":"
         << setfill ('0') << setw (2) << myHours << ":"
                          << setw (2) << myMinuts << ":"
                          << setw (2) << mySecond << ":"
         << setfill (' ');
}//display

void DUREE::incr (unsigned long long delta)
{
    myDuree += delta;
    normaliser ();
}// incr

void DUREE::decr (unsigned long long delta)
{
    myDuree -= delta > myDuree ? myDuree : delta;
    normaliser ();
}//decr

#undef DUREE
