# Portofoliu Teme C - Programarea Calculatoarelor (PCLP)

---

## Descriere Generala

Acest repository contine o colectie de proiecte dezvoltate in limbajul C, realizate in cadrul cursului de Programarea Calculatoarelor si Limbaje de Programare (PCLP). Proiectele pun in practica concepte fundamentale si avansate de programare: manipularea tablourilor si a sirurilor de caractere, alocarea dinamica a memoriei, operatii pe biti, parsarea fisierelor (text si binar) si arhitectura codului pe module.

---

## Structura Repository-ului

Repository-ul este impartit in trei directoare principale, fiecare corespunzand unui set specific de aplicatii:

### 1. Window join & Akari & Helicopters
Acest modul se concentreaza pe manipularea matricilor, a vectorilor si utilizarea functiilor algoritmice pe seturi de date[cite: 9].
* **Window Join:** Procesarea unui flux de date temporale pentru calculul CMMDC si CMMMC pe ferestre glisante.
* **Akari (Light Up):** Simularea jocului de puzzle pe grid, incluzand logica de propagare a luminii si validarea regulilor de plasare a surselor.
* **Helicopters:** Analiza geometrica a matricilor pentru calcularea zonelor de umbra generate de ipotenuzele elicopterelor.

### 2. Battleships
Proiect complex axat pe alocare dinamica si criptare[cite: 9].
* **Jocul Battleships:** Simularea jocului pe table alocate dinamic, cu gestionarea coordonatelor si a orientarii navelor.
* **Statistics:** Calculul acuratetei atacurilor, determinand scenariile minime/maxime necesare pentru a atinge un prag procentual dorit.
* **Hill Cipher:** Securizarea rezultatelor folosind un algoritm de criptare/decriptare pe matrice 3x3, aplicat pe un alfabet extins de 37 de caractere.

### 3. L-Systems & Turtle Graphics & Fonts
O aplicatie interactiva de procesare a imaginilor (PPM P6) bazata pe gestiunea starii in memorie cu sistem Undo/Redo.
* **Grafeme fractale (L-Systems):** Parsarea fisierelor de reguli si derivarea axiomelor lingvistice.
* **Turtle Graphics:** Desenarea liniilor pe matricea de pixeli folosind algoritmul lui Bresenham pe baza orientarii curente.
* **Fonturi BDF:** Citirea si randarea fonturilor bitmap Adobe pentru scrierea textelor cu offset calculat.
* **Detectia Erorilor:** Manipulare la nivel de bit (BITCHECK) pentru identificarea secventelor predispuse la corupere.

---

## Compilare si Rulare

Fiecare proiect contine un fisier `Makefile` dedicat pentru automatizarea procesului de compilare. Pentru a compila si testa oricare dintre teme, navigati in directorul corespunzator si rulati comanda de build:

```bash
cd "Nume Folder"
make build
