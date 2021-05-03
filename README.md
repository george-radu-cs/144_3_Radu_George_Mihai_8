# Proiect 3 POO

Nume: Radu

Prenume: George-Mihai

Grupa: 144

## Cerinte generale

### Cerințe comune tuturor temelor

- utilizarea sabloanelor

- utilizarea STL

- utilizarea variabilelor, funcțiilor statice, constantelor și a unei functii const

- utilizarea conceptelor de RTTI raportat la templat-uri (ex: upcast & dynamic_cast)

- tratarea excepțiilor

- citirea informațiilor complete a n obiecte, memorarea și afișarea acestora

### Cerințe generale aplicate fiecărei teme din acest fișier

- să se identifice și să se implementeze ierarhia de clase;

- clasele să conțină constructori, destructori, =, supraincarcare pe >> si <<
pentru citire si afisare;

- clasa de baza sa conțină funcție virtuala de afisare si citire, rescrisa în
clasele derivate, iar operatorul de citire si afisare să fie implementat ca
funcție prieten (în clasele derivate să se facă referire la implementarea
acestuia în clasa de baza).

## Subiect - tema 8

Pizzeria X testează un nou soft, dezvoltat în maniera OOP, pentru gestionarea
activității sale. Codul propriu-zis contine o clasa abstracta care contine doar
metoda virtuala pura de calcul al prețului unui produs, iar din aceasta clasa
deriva clasa Pizza. În realizarea oricărui produs intra un anumit număr de
ingrediente pentru care se cunosc denumirile, cantitatile și prețul unitar.
Prețul unui produs finit este data de prețul ingredientelor plus manopera (o
suma constanta fixată de producător). Daca pizza este comandata OnLine, la preț
se mai adaugă și 5% din pret la fiecare 10 km parcursi de angajatul care
livrează la domiciliu.

Structura de date: unordered_map sau unordered_set
<id_pizza, list sau vector \<ingredient>>

### Cerința suplimentară

- Să se adauge toate campurile relevante pentru modelarea acestei probleme.

- Să se construiască clasa template Meniu care sa gestioneze tipurie de pizza
comercializate. Clasa trebuie sa contina indexul unui produs (incrementat
automat la vanzarea unui produs  prin supraincarcarea operatorului +=) și o
structură de date, alocata dinamic.

- Să se construiască o specializare pentru tipul Comanda_Online care sa trateze
tipurile de pizza vegetariana într-un document contabil separat din care sa
rezulte valoarea totala incasata din vanzarea acestora.

## Format fisier de intrare

- pe fiecare linie se afla cate o comanda de pizza
- la inceputul fiecarei linii se afla un string care specifica tipul comenzii(local/online)
- indiferent de comanda citim numarul ingredientelo n, trebuie sa fie de tip int
- pentru fiecare ingredient ii citim denumirea, cantitatea si pretul unitar
- daca comanda este online la final citim distanta

## TODO

- completeaza fisierul de intrare cu mai multe comenzi
- adauga inca o specializare de pizza vegetariana
- transforma codul din main intr-o clasa singleton demo
