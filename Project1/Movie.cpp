#pragma once
#include <string>

using namespace std;

typedef enum
{
    ePC_REGULAR,
    ePC_NEW_RELEASE,
    ePC_CHILDRENS,
    ePC_CNT,
} ENUM_PRICE_CODE;

class Movie
{
public:
    Movie(const string& strTitle, ENUM_PRICE_CODE ePriceCode)
        : strTitle(strTitle), ePriceCode(ePriceCode)
    {
    }

    string getTitle()
    {
        return strTitle;
    }

    ENUM_PRICE_CODE getPriceCode()
    {
        return ePriceCode;
    }

private:
    string strTitle;
    ENUM_PRICE_CODE ePriceCode;
};
