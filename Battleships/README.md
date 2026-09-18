# Tema 2 - Programarea Calculatoarelor si Limbaje de Programare (PCLP)
## Battleships, Statistics & Hill Cipher

Autor: Tiepac Anduena-Maria  
Grupa: 311CB  

---

## Descriere Generala

Acest proiect reprezinta o aplicatie scrisa in limbajul C ce simuleaza jocul Battleships, calculeaza statistici avansate despre meciurile jucate si ofera securizarea datelor prin criptare si decriptare folosind algoritmul Hill Cipher.

Proiectul este structurat modular in 3 componente majore:
1. Battleships (Simularea Jocului)
2. Statistics (Analiza Performantei)
3. Hill Cipher (Criptare / Decriptare)

---

## 1. Problema Battleships

Aceasta componenta se ocupa cu gestionarea dinamica a tablelor de joc si simularea atacurilor dintre doi jucatori.

### Mod de implementare si Logica starii:
* Mecanismul de urmarire a navelor: Se folosesc doua variabile contor (gasit1, gasit2) ce retin numarul total de celule ocupate de nave pentru fiecare jucator. La fiecare atac reusit, valoarea contorului este decrementata pentru a detecta instant momentul in care un jucator ramane fara nave (sfarsitul jocului).
* Identificarea orientarii si a originii navelor:
  * Fiecarei tip de nava ii este asociat un identificator (1 - 5).
  * Pentru diferentierea capatului navei (punctul de start de la plasare) si determinarea orientarii:
    * Capatul unei nave orizontale este marcat cu id + 10.
    * Capatul unei nave verticale este marcat cu id + 20.
  * Acest mecanism permite distrugerea completa a navei dintr-o singura lovitura daca este lovit direct capatul ei.
* Eficientizarea memoriei: Matricele mat1 si mat2 folosesc alocare dinamica la nivel de linie doar cand este necesar, evitand alocarea inutila a resurselor nefolosite.
* Bucla principala de joc: In interiorul unei bucle while, atacurile sunt procesate alternativ pe 3 cazuri principale:
  1. Lovituri ratate: Linia nu e alocata, pozitia este goala sau celula a fost deja distusa.
  2. Lovituri repetate: Coordonatele au fost atacate anterior.
  3. Lovituri reusite: 
     * Lovitura pe corp de nava (nr < 9).
     * Lovitura pe capat orizontal (10 < nr < 20) - elimina intreaga nava pe orizontala.
     * Lovitura pe capat vertical (nr > 20) - elimina intreaga nava pe verticala.

---

## 2. Problema Statistics

Componenta de statistici analizeaza acuratetea atacurilor pe parcursul unuia sau mai multor meciuri.

### Analiza pe un singur meci:
* Se calculeaza acuratetea din meciul specificat folosind formula din cerinta (nr_lovituri_nimerite / total_lovituri).
* MIN: Determinarea numarului minim de lovituri suplimentare necesare pentru a atinge o acuratete tinta >= X%. Se simuleaza adaugarea succesiva de lovituri reusite pana la indeplinirea conditiei.
* MAX: Determinarea numarului maxim de lovituri ce pot fi ratate fara ca acuratetea sa scada sub X%. Se simuleaza adaugarea de lovituri nereusite si se ajusteaza limita maxima.

### Analiza pe intregul joc (toate meciurile):
* Se calculeaza acuratetea totala ca medie ponderata a meciurilor in functie de numarul de nave Ki.
* MAX (Numar maxim de meciuri cu 0% acuratete): Se sorteaza vectorul ponderat al acurateilor in ordine crescatoare pentru a elimina mai intai meciurile cu impact minim asupra mediei totale.
* MIN (Numar minim de meciuri cu 100% acuratete): Se sorteaza meciurile descrescator in functie de potentialul de meci de a creste acuratetea (diferenta pana la 100%), inlocuind succesiv acuratetea meciurilor cu 100% pana la atingerea pragului cerut.

---

## 3. Problema Hill Cipher

Implementarea algoritmului de criptare si decriptare pe matrice bazat pe un alfabet extins de 37 de caractere (A-Z, 0-9, .).

### Detalii de calcul:
* Presupune utilizarea unei chei de lungime 9 (matrice 3x3).
* Criptare: Mesajul este impartit in blocuri de dimensiune 1, 2 sau 3 caractere si inmultit la stanga cu matricea cheii (sau sub-matricea corespunzatoare), aplicand operatia modulo 37.
* Decriptare: Pentru procesarea blocurilor de 2 sau 3 caractere se calculeaza inversa matricii cheii in Z_37 (calculand determinantul, inversul multiplicativ modulo 37 si matricea adjuncta).

---

## Compilare si Rulare

Proiectul contine un fisier Makefile cu urmatoarele reguli:

* Compilare proiect:
  ```bash
  make build