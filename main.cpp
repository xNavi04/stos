#include <iostream>

bool przepelnienie(int maksymalny_rozmiar_stosu, int rozmiar_stosu)
{
    if(maksymalny_rozmiar_stosu == rozmiar_stosu)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void dodaj_do_stosu(int& rozmiar_stosu, int maksymalny_rozmiar_stosu, int tabela[])
{
    if (przepelnienie(maksymalny_rozmiar_stosu, rozmiar_stosu))
    {
        return;
    }

    int nowy_element;

    std::cout << "Nowy element: ";
    std::cin >> nowy_element;

    tabela[rozmiar_stosu] = nowy_element;

    rozmiar_stosu++;

}

void odejmij_od_stosu(int& rozmiar_stosu, int tabela[])
{
    if(rozmiar_stosu == 0)
    {
        return;
    }
    tabela[rozmiar_stosu-1] = NULL;
    rozmiar_stosu--;
}

void wyswietl_stos(int tabela[], int rozmiar_stosu)
{
    if(rozmiar_stosu == 0)
    {
        return;
    }
    for (int i=rozmiar_stosu-1; i>=0; i--)
    {
        std::cout << tabela[i];
    }
}

int main()
{
    int tabela[5];
    int maksymalny_rozmiar_stosu = 5;
    int rozmiar_stosu = 0;
    int wlaczone = 1;
    int wybor;

    while(wlaczone)
    {
        std::cout << "1. Dodaj element do kolejki." << std::endl <<
             "2. Zwolnij element z kolejki." << std::endl <<
             "3. Wyswietl elementy." << std::endl << std::endl;
        std::cin >> wybor;
        switch (wybor) {
            case 1:
                dodaj_do_stosu(rozmiar_stosu, maksymalny_rozmiar_stosu, tabela);
                break;
            case 2:
                odejmij_od_stosu(rozmiar_stosu, tabela);
                break;
            case 3:
                wyswietl_stos(tabela, rozmiar_stosu);
                break;
            case 0:
                wlaczone = 0;
                break;
            default:
                std::cout << "Error" << std::endl;
                wlaczone = 0;
        }
    }
    return 0;
}
