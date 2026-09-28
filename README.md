SORTOWANIE W KOLEJCE C++

Opis ogólny

Program napisany w języku C++ służy do odczytu ciągu liczb z pliku tekstowego, przechowywania ich w dynamicznej strukturze danych typu kolejka (lista powiązana), sortowania elementów w porządku rosnącym za pomocą algorytmu bąbelkowego opartego na bezpośrednim przepinaniu wskaźników (bez użycia funkcji zamiany wartości swap), a także do wypisywania wyników na konsolę oraz zapisywania ich z powrotem do pliku.

Opis funkcji w programie

Struktura kolejka

Reprezentuje pojedynczy element (tzw. "wagonik") w strukturze kolejki.

Zawiera pole całkowite a (przechowujące wartość liczbową) oraz wskaźnik next wskazujący na kolejny element w kolejce.

Klasa sortowanie

Grupuje zmienne oraz operacje związane z zarządzaniem dynamiczną kolejką.

Konstruktor sortowanie(): Inicjalizuje wskaźnik początkowy poczatek wartością NULL.

Destruktor ~sortowanie(): Odpowiada za poprawne zwolnienie pamięci (usuwanie węzłów) po zakończeniu działania obiektu.

wczytaj_z_pliku(): Otwiera plik liczby.txt, odczytuje pierwszą liczbę określającą ilość elementów, a następnie w pętli pobiera kolejne wartości, tworzy nowe węzły i dołącza je do końca kolejki.

sortowanie_babelkowe(): Sortuje elementy rosnąco. Modyfikuje bezpośrednio powiązania wskaźników (next) między węzłami w trakcie sortowania bąbelkowego zamiast kopiować wartości.

zapisz_do_pliku(): Przechodzi przez całą kolejkę i zapisuje aktualny porządek liczb do pliku wyjściowego zapisane.txt.

wypisz(): Wyświetla zawartość wszystkich elementów aktualnie znajdujących się w kolejce na ekranie konsoli.
