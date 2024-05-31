#include "Menu.h"
#include <math.h>

Menu::Menu(vector<string> &itens, string title, string message) : title(title), message(message), itens(itens)
{
    this->setWidth();
    this->setRepeatList();
    this->setSymbol();
};

Menu::~Menu()
{
}


void Menu::setWidth(int width)
{
    this->width = width;
}


const bool Menu::isNotAValidChoice(unsigned long choice) const
{
    return ((choice < 0) || (choice > (itens.size() - 1)));
}

const string Menu::makeDecorator()
{
    if (!width)
    {
        width = max(title.length(), message.length());

        for (string item : itens)
        {
            width = ((unsigned long int)width >= item.length()) ? width : item.length();
        }
        width += 4 + (log10(itens.size()));
        width = (width / symbol.length()) + ((width % symbol.length()) ? 1 : 0);
    }
    return (replicate(symbol, width));
}

const string Menu::replicate(string text, int times) const
{
    string buffer;
    for (int count = 0; count < times; count++)
    {
        buffer += text;
    }
    return (buffer);
}
void Menu::setSymbol(const string &symbol)
{
    this->symbol = symbol;
}

const int Menu::getChoice()
{
    unsigned long choice;
    bool firstTime = true;
    string decorator = makeDecorator();

    do
    {
        if (repeatList || firstTime)
        {
            unsigned long index = 0;
            cout << decorator << endl;
            cout << title << endl;
            cout << decorator << endl;

            for (index = 0; index < ((itens.size() - (zeroForLastOpt ? 1 : 0))); index++)
            {
                cout << (index + (zeroForLastOpt ? 1 : 00)) << " - " << itens.at(index) << endl;
            }
            cout << decorator << endl;

            if (zeroForLastOpt)
            {
                cout << 0 << " - " << itens.at(index) << endl;
                cout << decorator << endl;
            }

            firstTime = false;
        }
        cout << message << endl;
        cin >> choice;
    } while (isNotAValidChoice(choice));
    cin.ignore();

    return (choice);
}

bool Menu::isRepeatList() const
{
    return repeatList;
}

void Menu::setRepeatList(bool repeatList)
{
    this->repeatList = repeatList;
}

void Menu::setZeroForLastOpt(bool zeroForLastOpt)
{
    this->zeroForLastOpt = zeroForLastOpt;
}
