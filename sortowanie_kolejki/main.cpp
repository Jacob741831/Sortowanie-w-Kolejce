#include <iostream>
#include <fstream>

using namespace std;

// Struktura reprezentuj¹ca pojedynczy element (wagonik) w kolejce
struct kolejka
{
    int a;
    kolejka* next;
};

// Klasa zarz¹dzaj¹ca kolejk¹ oraz operacjami na niej
class sortowanie
{
private:
    kolejka* poczatek;
    int liczba_elementow; // Zmienna przechowuj¹ca informacjê, ile jest liczb w kolejce

public:
    // Konstruktor inicjalizuj¹cy pocz¹tek wartoœci¹ NULL oraz licznik elementów na 0
    sortowanie() : poczatek(nullptr), liczba_elementow(0) {}

    // Destruktor zwalniaj¹cy pamiêæ zajmowan¹ przez wszystkie wêz³y kolejki
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

    // Funkcja wczytuj¹ca liczby z pliku liczby.txt
    void wczytaj_z_pliku()
    {
        ifstream plik("liczby.txt");

        if (!plik.is_open())
        {
            cout << "Nie znaleziono pliku liczby.txt!" << endl;
            cout << "Sprawdz, czy plik znajduje sie w odpowiednim folderze." << endl;
            return;
        }

        int ile;
        plik >> ile; // Wczytanie liczby elementów

        kolejka* ostatni = nullptr;
        int wczytane = 0;

        for (int i = 0; i < ile; i++)
        {
            int liczba;

            if (!(plik >> liczba))
            {
                cout << "Blad odczytu liczby z pliku!" << endl;
                break;
            }

            kolejka* nowy = new kolejka;
            nowy->a = liczba;
            nowy->next = nullptr;

            if (poczatek == nullptr)
            {
                poczatek = nowy;
            }
            else
            {
                ostatni->next = nowy;
            }

            ostatni = nowy;
            wczytane++;
        }

        liczba_elementow = wczytane;
        plik.close();

        cout << "Wczytano " << liczba_elementow << " liczb." << endl;
    }

    // Funkcja sortowania b¹belkowego rosn¹co przez przepinanie wskaŸników (wagoników) z licznikiem iteracji 'i'
    void sortowanie_babelkowe()
    {
        if (poczatek == nullptr || poczatek->next == nullptr)
        {
            cout << "Za malo elementow do sortowania." << endl;
            return;
        }

        bool zamiana;
        int i = 0; // Licznik wykonanych przejœæ b¹belkowych

        do
        {
            zamiana = false;
            kolejka* poprzedni = nullptr;
            kolejka* aktualny = poczatek;

            while (aktualny != nullptr && aktualny->next != nullptr)
            {
                kolejka* nastepny = aktualny->next;

                // Jeœli aktualny element jest wiêkszy od nastêpnego -> przestawiamy wskaŸniki (wpinamy wagonik)
                if (aktualny->a > nastepny->a)
                {
                    aktualny->next = nastepny->next;
                    nastepny->next = aktualny;

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

            i++; // Zwiêkszamy licznik przejœæ (iteracji)

        } while (zamiana);

        cout << "Sortowanie zakonczone. Liczba przejsc petli (i) = " << i << endl;
    }

    // Funkcja zapisuj¹ca posortowane liczby do pliku zapisane.txt
    void zapisz_do_pliku()
    {
        ofstream plik("zapisane.txt");

        if (!plik.is_open())
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

    // Funkcja wypisuj¹ca liczby w konsoli
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
    }
};

// G³ówna funkcja programu z menu typu switch-case
int main()
{
    // Ustawienie poliskich znaków w konsoli (opcjonalnie)
    setlocale(LC_ALL, "Polish");

    sortowanie sort;

    cout << "Program: SORTOWANIE W KOLEJCE" << endl;
    cout << "=============================" << endl;

    // Automatyczne wczytanie danych przy starcie programu
    sort.wczytaj_z_pliku();

    int wybor;

    do
    {
        cout << endl;
        cout << "========= MENU =========" << endl;
        cout << "1. Wypisz liczby" << endl;
        cout << "2. Sortowanie babelkowe" << endl;
        cout << "3. Zapisz do pliku" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "========================" << endl;
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
                cout << "Koniec programu. Do widzenia!" << endl;
                break;

            default:
                cout << "Nieprawidlowy wybor! Wybierz opcje od 0 do 3." << endl;
        }

    } while (wybor != 0);

    return 0;
}
