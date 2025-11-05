#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int sumaTowaru = 0;
    unsigned int liczbaZaglowcow = 0;

    Stocznia stocznia; //wywolujemy konstruktor domyslny stoczni

    while (sumaTowaru < towar)
    {
        //zamawiamy statki (losowe)    
        Statek* nowyStatek = stocznia(); //wywolanie metody specjalnej
		//(przeciazony operator()), ktory zwraca wskaznik do nowego statku
        //Transportujemy towar i zliczamy go do sumyTowaru
        sumaTowaru += nowyStatek->transportuj();

        if (dynamic_cast<Zaglowiec*>(nowyStatek))
        {
            liczbaZaglowcow++;
        };
        //zwalniamy pamiec - utylizujemy statek, ktory wykonal swoja robotwe
        delete nowyStatek;
    };

    

    return liczbaZaglowcow;
}
