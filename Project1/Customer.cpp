#pragma once

#include <vector>
#include "Movie.cpp"
#include "Rental.cpp"

class Customer
{
private:
    string strName;
    vector<Rental> aRantalList;

    string ToStringWithShortPrecision(double nPrice)
    {
        char buf[20] = { 0 };
        sprintf_s(buf, sizeof(buf), "%.1f", nPrice);
        return string(buf);
    }

public:
    Customer(const string& strName) : strName(strName) {}

    void addRental(Rental arg)
    {
        aRantalList.push_back(arg);
    }

    string getName()
    {
        return strName;
    }

    string statement()
    {
        double nTotalPrice = 0;
        int nPoint = 0;
        string result = "Rental Record for " + getName() + "\n";

        for (Rental each : aRantalList)
        {
            double nPrice = 0;
            string title = each.getMovie().getTitle();
            ENUM_PRICE_CODE ePriceCode = each.getMovie().getPriceCode();
            int nDaysRented = each.getDaysRented();
            double nBaseFee = each.GetBaseFee(ePriceCode);
            double nLateFeeMult = each.GetLateFeeMult(ePriceCode);
            int nDefaultRentDays = each.GetDefaultRantDays(ePriceCode);

            nPrice = GetPrice(nBaseFee, nDaysRented, nDefaultRentDays, nLateFeeMult);

            nPoint += GetPoint(ePriceCode, nDaysRented);

            result += "\t" + title + "\t" + ToStringWithShortPrecision(nPrice) + "\n";
            nTotalPrice += nPrice;
        }

        result += "Amount owed is " + ToStringWithShortPrecision(nTotalPrice) + "\n";
        result += "You earned " + to_string(nPoint) + " frequent renter points";

        return result;
    }

    int GetPoint(ENUM_PRICE_CODE ePriceCode, int nDaysRented)
    {
        int nPoint = 0;

        nPoint++;
        if (ePriceCode == ePC_NEW_RELEASE && nDaysRented > 1)
        {
            nPoint++;
        }

        return nPoint;
    }

    double GetPrice(double nBaseFee, int nDaysRented, int nDefaultRentDays, double nLateFeeMult)
    {
        double nPrice = 0;

        nPrice += nBaseFee;

        if (nDaysRented > nDefaultRentDays)
        {
            nPrice += (nDaysRented - nDefaultRentDays) * nLateFeeMult;
        }

        return nPrice;
    }
};
