#include <iostream>
#include <fstream>

using namespace std;

// Struktura reprezentujaca jeden element (wagonik) kolejki
struct kolejka
{
    int a;
    kolejka* next;
};

// Klasa odpowiedzialna za obsluge kolejki
class sortowanie
{
private:
    kolejka* poczatek;
    int liczba_elementow;

public:
    // Konstruktor
    sortowanie()
    {
        poczatek = nullptr;
        liczba_elementow = 0;
    }

    // Destruktor
    ~sortowanie()
    {
        kolejka* temp;

        while (poczatek != nullptr)
        {
            temp = poczatek;
            poczatek = poczatek->next;
            delete temp;
        }
    }

    // Wczytywanie liczb z pliku liczby.txt
    void wczytaj_z_pliku()
    {
        ifstream plik("liczby.txt");

        if (!plik)
        {
            cout << "Nie mozna otworzyc pliku liczby.txt!" << endl;
            return;
        }

        int liczba;

        // Wczytywanie wszystkich liczb z pliku
        while (plik >> liczba)
        {
            // Tworzenie nowego wagonika
            kolejka* nowy = new kolejka;

            nowy->a = liczba;
            nowy->next = nullptr;

            // Jezeli kolejka jest pusta
            if (poczatek == nullptr)
            {
                poczatek = nowy;
            }
            else
            {
                // Szukanie ostatniego wagonika
                kolejka* ostatni = poczatek;

                while (ostatni->next != nullptr)
                {
                    ostatni = ostatni->next;
                }

                // Dolaczenie nowego wagonika na koniec
                ostatni->next = nowy;
            }

            // Zwiekszenie licznika elementow
            liczba_elementow++;
        }

        plik.close();

        cout << "Wczytano " << liczba_elementow << " liczb." << endl;
    }

    // Sortowanie babelkowe rosnaco
    // Sortowanie odbywa sie przez przepinanie wskaznikow
    void sortowanie_babelkowe()
    {
        if (poczatek == nullptr || poczatek->next == nullptr)
        {
            cout << "Za malo elementow do sortowania." << endl;
            return;
        }

        bool zamiana;

        do
        {
            zamiana = false;

            kolejka* poprzedni = nullptr;
            kolejka* aktualny = poczatek;

            while (aktualny != nullptr && aktualny->next != nullptr)
            {
                kolejka* nastepny = aktualny->next;

                // Jezeli aktualny element jest wiekszy od nastepnego,
                // przepinamy wagoniki
                if (aktualny->a > nastepny->a)
                {
                    aktualny->next = nastepny->next;
                    nastepny->next = aktualny;

                    // Jezeli przepinamy pierwszy element
                    if (poprzedni == nullptr)
                    {
                        poczatek = nastepny;
                    }
                    else
                    {
                        poprzedni->next = nastepny;
                    }

                    poprzedni = nastepny;
                    zamiana = true;
                }
                else
                {
                    poprzedni = aktualny;
                    aktualny = aktualny->next;
                }
            }

        } while (zamiana);

        cout << "Sortowanie zakonczone." << endl;
    }

    // Zapisywanie liczb do pliku zapisane.txt
    void zapisz_do_pliku()
    {
        ofstream plik("zapisane.txt");

        if (!plik)
        {
            cout << "Nie mozna utworzyc pliku zapisane.txt!" << endl;
            return;
        }

        kolejka* aktualny = poczatek;

        while (aktualny != nullptr)
        {
            plik << aktualny->a << endl;
            aktualny = aktualny->next;
        }

        plik.close();

        cout << "Zapisano liczby do pliku zapisane.txt." << endl;
    }

    // Wypisywanie liczb w konsoli
    void wypisz()
    {
        if (poczatek == nullptr)
        {
            cout << "Kolejka jest pusta." << endl;
            return;
        }

        kolejka* aktualny = poczatek;

        cout << "Liczby w kolejce: ";

        while (aktualny != nullptr)
        {
            cout << aktualny->a << " ";
            aktualny = aktualny->next;
        }

        cout << endl;
        cout << "Liczba elementow: " << liczba_elementow << endl;
    }
};


int main()
{
    // Utworzenie obiektu klasy sortowanie
    sortowanie sort;

    // Wczytanie liczb z pliku
    sort.wczytaj_z_pliku();

    int wybor;

    do
    {
        cout << endl;
        cout << "1. Wypisz liczby" << endl;
        cout << "2. Sortowanie babelkowe" << endl;
        cout << "3. Zapisz do pliku" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybierz opcje: ";

        cin >> wybor;

        switch (wybor)
        {
            case 1:
                sort.wypisz();
                break;

            case 2:
                sort.sortowanie_babelkowe();
                break;

            case 3:
                sort.zapisz_do_pliku();
                break;

            case 0:
                cout << "Koniec programu." << endl;
                break;

            default:
                cout << "Nieprawidlowy wybor!" << endl;
        }

    } while (wybor != 0);

    return 0;
}
