#ifndef DUREE_H
#define DUREE_H
namespace nsUtil
{
    class Duree
    {
        unsigned long long myDuree;
        unsigned long long myDays;
        unsigned short myHours;
        unsigned short myMinuts;
        unsigned short mySecond;
        void normaliser (void);

      public :
        Duree (unsigned long long duree); //dest

        Duree operator + (const Duree & D)const;
        Duree operator - (const Duree & D)const;

        unsigned long long getDuree (void) const;
        void display (void) const;

        void incr (unsigned long long delta);
        void decr (unsigned long long delta);
    }; //Duree

} //nsUtile
#endif // DUREE_H
