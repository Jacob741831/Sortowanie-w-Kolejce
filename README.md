Jasne — poniżej masz gotowy `README.md` opisujący działanie programu, strukturę kodu, pliki wejściowe/wyjściowe i sposób uruchomienia.

 README.md

# Sortowanie liczb za pomocą kolejki

 Program napisany w języku **C++**, którego zadaniem jest wczytanie liczb z pliku tekstowego, przechowywanie ich w strukturze jednokierunkowej oraz posortowanie metodą **sortowania bąbelkowego**.

 Program wykorzystuje dynamicznie tworzoną strukturę danych przypominającą kolejkę, w której każdy element przechowuje jedną liczbę oraz wskaźnik do następnego elementu.

 ## Funkcjonalności

 Program umożliwia:

 - wczytanie liczb z pliku `liczby.txt`,
- wyświetlenie wszystkich liczb znajdujących się w kolejce,
- posortowanie liczb rosnąco metodą bąbelkową,
- zapisanie wyników do pliku `zapisane.txt`,
- sprawdzenie liczby elementów znajdujących się w kolejce,
- obsługę programu za pomocą prostego menu tekstowego.

 ## Wykorzystane technologie

 - **C++**
- biblioteka `iostream` – obsługa wejścia i wyjścia,
- biblioteka `fstream` – obsługa plików,
- dynamiczna alokacja pamięci (`new` / `delete`),
- jednokierunkowa struktura danych,
- sortowanie bąbelkowe.

 ## Struktura danych

 Każdy element kolejki jest reprezentowany przez strukturę:

```
struct kolejka
{
    int a;
    kolejka* next;
};
```

 Element składa się z:

 - `a` – liczby całkowitej,
- `next` – wskaźnika na następny element kolejki.

 Klasa `sortowanie` przechowuje:

```
kolejka* poczatek;
int liczba_elementow;
```

 `poczatek` wskazuje na pierwszy element kolejki, natomiast `liczba_elementow` przechowuje liczbę wszystkich elementów.

 ## Wczytywanie danych

 Program automatycznie próbuje odczytać liczby z pliku:

```
liczby.txt
```

 Liczby mogą znajdować się w osobnych wierszach lub być oddzielone spacjami.

 Przykładowa zawartość pliku:

```
45
12
78
3
19
7
32
```

 Podczas wczytywania każda liczba jest umieszczana w nowym elemencie struktury.

 ## Sortowanie

 Do sortowania wykorzystywany jest **algorytm sortowania bąbelkowego**.

 Program porównuje sąsiednie elementy. Jeżeli pierwszy element jest większy od drugiego, elementy są zamieniane miejscami.

 W tym programie zamiana odbywa się poprzez **przepinanie wskaźników**, a nie przez zamianę wartości znajdujących się w elementach.

 Przykład:

```
45 12 78 3 19
```

 po posortowaniu:

```
3 12 19 45 78
```

 Sortowanie odbywa się rosnąco.

 ### Złożoność

 Dla sortowania bąbelkowego:

 - średnia złożoność czasowa: `O(n²)`,
- pesymistyczna złożoność czasowa: `O(n²)`,
- najlepszy przypadek: `O(n)` – gdy dane są już posortowane,
- złożoność pamięciowa: `O(1)` dodatkowej pamięci.

 ## Zapisywanie wyników

 Posortowane liczby można zapisać do pliku:

```
zapisane.txt
```

 Każda liczba zostanie zapisana w osobnym wierszu.

 Przykładowa zawartość:

```
3
7
12
19
32
45
78
```

 ## Menu programu

 Po uruchomieniu programu wyświetlane jest menu:

```
1. Wypisz liczby
2. Sortowanie babelkowe
3. Zapisz do pliku
0. Wyjscie
Wybierz opcje:
```

 ### Opcja 1 – Wypisz liczby

 Wyświetla wszystkie liczby znajdujące się aktualnie w kolejce oraz ich liczbę.

 Przykład:

```
Liczby w kolejce: 45 12 78 3 19
Liczba elementow: 5
```

 ### Opcja 2 – Sortowanie bąbelkowe

 Uruchamia sortowanie liczb rosnąco.

 Po zakończeniu wyświetlany jest komunikat:

```
Sortowanie zakonczone.
```

 ### Opcja 3 – Zapisz do pliku

 Zapisuje aktualną zawartość kolejki do pliku `zapisane.txt`.

 ### Opcja 0 – Wyjście

 Kończy działanie programu.

 ## Zarządzanie pamięcią

 Elementy kolejki są tworzone dynamicznie za pomocą operatora `new`.

 Przykładowo:

```
kolejka* nowy = new kolejka;
```

 Po zakończeniu działania obiektu klasy `sortowanie` wywoływany jest destruktor, który usuwa wszystkie elementy kolejki:

```
delete temp;
```

 Dzięki temu pamięć zaalokowana dynamicznie jest zwalniana.

 ## Obsługa błędów

 Program sprawdza, czy można otworzyć plik `liczby.txt`.

 Jeżeli plik nie istnieje lub nie można go otworzyć, wyświetlany jest komunikat:

```
Nie mozna otworzyc pliku liczby.txt!
```

 Program sprawdza również możliwość utworzenia pliku `zapisane.txt`.

 ## Wymagania

 Do uruchomienia programu potrzebny jest:

 - kompilator obsługujący **C++**,
- np. `g++`, MinGW lub Visual Studio,
- plik `liczby.txt` znajdujący się w katalogu uruchamianego programu.

 ## Kompilacja

 Jeżeli plik z kodem nazywa się `main.cpp`, można skompilować program za pomocą:

```
g++ main.cpp -o sortowanie
```

 Następnie program można uruchomić poleceniem:

 ### Windows

```
sortowanie.exe
```

 ### Linux / macOS

```
./sortowanie
```

 ## Przykładowe użycie

 Plik `liczby.txt`:

```
10
5
23
1
17
8
```

 Po uruchomieniu i wybraniu opcji `1`:

```
Liczby w kolejce: 10 5 23 1 17 8
Liczba elementow: 6
```

 Po wybraniu opcji `2`:

```
Sortowanie zakonczone.
```

 Ponowne wybranie opcji `1`:

```
Liczby w kolejce: 1 5 8 10 17 23
Liczba elementow: 6
```

 Po wybraniu opcji `3` dane zostaną zapisane do `zapisane.txt`.

 ## Autor

 Projekt wykonany w języku **C++** w ramach ćwiczenia dotyczącego:

 - dynamicznych struktur danych,
- wskaźników,
- obsługi plików,
- sortowania bąbelkowego,
- zarządzania pamięcią dynamiczną.
