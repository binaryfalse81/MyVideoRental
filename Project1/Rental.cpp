#pragma once
#include "Movie.cpp";

class Rental
{
public:
    Rental(Movie& movie, int nDaysRented)
        : movie(movie),
        nDaysRented(nDaysRented)
    {
    }

    int getDaysRented()
    {
        return nDaysRented;
    }

    Movie getMovie()
    {
        return movie;
    }

    double GetBaseFee(ENUM_PRICE_CODE ePriceCode)
    {
        return anBaseFee[ePriceCode];
    }

    double GetLateFeeMult(ENUM_PRICE_CODE ePriceCode)
    {
        return anLateFeeMult[ePriceCode];
    }

    int GetDefaultRantDays(ENUM_PRICE_CODE ePriceCode)
    {
        return anDefaultRentDays[ePriceCode];
    }

private:
    Movie movie;
    int nDaysRented;
    double anBaseFee[ePC_CNT] = { 2, 0, 1.5 };
    double anLateFeeMult[ePC_CNT] = { 1.5, 3, 1.5 };
    int anDefaultRentDays[ePC_CNT] = { 2, 0, 3 };
};
