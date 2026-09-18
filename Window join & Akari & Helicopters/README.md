# Tema 1 - Programarea Calculatoarelor si Limbaje de Programare (PCLP)
## Functii, Vectori si Matrici

Autor: Tiepac Anduena-Maria  
Grupa: 311CB  

---

## Descriere Generala

Acest proiect contine rezolvarea a trei probleme algoritmice complexe in limbajul C, axate pe manipularea vectorilor, a matricilor multidimensionale, utilizarea functiilor si aplicarea structurilor repetitive si conditionale.

Proiectul este structurat pe 3 module principale:
1. **Window Join** - Procesarea unui flux temporal de date si calcularea CMMDC/CMMMC pe ferestre glisante.
2. **Akari** - Simularea si validarea starii jocului de puzzle pe grid cu surse de lumina (Light Up).
3. **Helicopters** - Analiza geometrica a zonelor de umbra si a aterizarii elicopterelor pe matrice.

---

## 1. Problema 1 - Window Join

Aceasta problema proceseaza un flux continuu de intrari (timestamp $t$ si valoare $x$) pe o fereastra glisanta de timp de dimensiune `window`.

### Mod de implementare:
* **Citirea si structura datelor:** Citirea incepe cu parametrul `window` si prima pereche $(t, x)$. Prima citire se face separat inaintea buclei `while` pentru a asigura existenta a cel putin doua elemente la prima comparatie. Oprirea citirii se face la intalnirea marcului `0 0`.
* **Gestionarea ferestrei glisante:**
  * Se mentin doi indici: `j` pentru inceputul ferestrei si `i` pentru pozitia curenta (ultimul element adaugat).
  * Cand diferenta dintre timpul ultimului element si timpul primului element depaseste dimensiunea `window`, primul element este eliminat din vector, iar indicele se ajusteaza.
* **Calculul CMMDC si CMMMC:**
  * Pentru perechile valide din fereastra, se calculeaza CMMDC si CMMMC folosind o copie a indicelui ultimei pozitii care avanseaza dupa fiecare comparatie valida.
* **Golirea ferestrei la final:** Dupa finalizarea citirii, se foloseste o bucla suplimentara pentru a parcurge si procesa ultimele elemente ramase in vector prin incrementarea indicelui `j`.

---

## 2. Problema 2 - Akari

Modulul rezolva cerintele jocului Akari (Light Up) pe un grid bidimensional de dimensiuni $N \times M$.

### Opțiunea 1 - Completarea grid-ului neiluminat:
* **Propagarea luminii:** Se parcurge matricea, iar pentru fiecare bec (`'L'`) se extinde lumina pe orizontala si verticala (in sus, jos, stanga, dreapta) folosind copii ale indicilor. Drumul luminii se opreste la intalnirea unui zid (`'#'` sau numere) sau a marginii matricei, marcand celulele libere cu `'x'`.
* **Marcarea celulelor negre completate:** Dupa propagarea tuturor becurilor, se reevalueaza matricea pentru celulele negre cu numere. Daca numarul de becuri adiacente atinge valoarea maxima ceruta de celula neagra, spatiile libere ramase in jurul ei sunt completate cu `'x'`.

### Opțiunea 2 - Validarea grid-ului:
* **Verificarea regulilor:**
  * Se simuleaza propagarea luminii pentru a identifica daca doua becuri se ilumineaza reciproc pe aceeasi linie sau coloana fara un zid intre ele. Daca se gaseste un astfel de caz, starea devine invalida (`gresit = 1`).
  * Se numara becurile adiacente fiecarui zid cu numar. Daca un zid are mai multe becuri decat numarul indicat sau daca nu mai exista suficiente celule libere disponibile langa el pentru a atinge numarul necesar, configuratia este marcata ca invalida.
* **Rezultat:** Daca nicio regula nu a fost incalcata (`gresit == 0`), se afiseaza `"ichi"`, altfel se afiseaza `"zero"`.

---

## 3. Problema 3 - Helicopters

Modulul analizeaza pozitionarea si aterizarea elicopterelor ale caror baze formeaza triunghiuri dreptunghice isoscele pe o matrice de gazon $N \times M$.

### Mod de implementare:
* **Modularizare:** S-au creat functii auxiliare pentru citire, precum si pentru determinarea minimului si maximului pe linii si coloane pe baza coordonatelor $(r1, c1, r2, c2)$.
* **Validarea orientarii ipotenuzei:** Elicopterele ale caror ipotenuze sunt paralele cu axele matricei ($r1 = r2$ sau $c1 = c2$) sunt marcate direct ca pozitionate necorespunzator, afisand mesajul de eroare specificat.
* **Incadrarea in cazuri geometrice:**
  * **Cazul 1 (Diagonala principala):** Coordonatele maxime pentru linie si coloana apartin aceluiasi capat al ipotenuzei.
  * **Cazul 2 (Diagonala secundara):** Coordonatele maxime apartin unor capete diferite ale ipotenuzei.
  * Fiecare caz se imparte in subcazurile $s = 1$ (varful deasupra ipotenuzei) si $s = -1$ (varful sub ipotenuza).
* **Calculul umbrei:** Pentru fiecare triunghi valid se numara celulele totale acoperite si celulele afectate de umbra (cu valoarea `0`). Un elicopter este marcat ca aterizat gresit daca mai mult de 50% din suprafata sa este umbrita.

---

## Compilare si Rulare

Proiectul utilizeaza un fisier **Makefile** cu regulile de compilare standard:

* **Compilare proiect (genereaza executabilele `window_join`, `akari`, `helicopters`):**
  ```bash
  make build