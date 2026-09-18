# Tema 3 - Programarea Calculatoarelor si Limbaje de Programare (PCLP)
## Runic Engine: Grafeme fractale, Turtle Graphics, Fonturi si Undo/Redo

Autor: Tiepac Anduena-Maria  
Grupa: 311CB  

---

## Descriere Generala

Acest proiect reprezinta o aplicatie interactiva in limbajul C destinata manipularii si generarii de imagini PPM. Programul implementeaza prelucrarea grafemelor fractale (L-Systems), desenarea vectoriala prin Turtle Graphics, randarea de text folosind fonturi si un mecanism de Undo/Redo pentru controlul starii.

---

## Arhitectura si Implementare

### 1. Grafeme fractale (L-Systems)
* **lsystem:** Incarca si memoreaza informatiile dintr-un fisier `.lsys`. Foloseste un contor (si o copie a acestuia) pentru a gestiona alocarile dinamice si eliberarile de memorie cand un lsystem nou este incarcat sau cand se efectueaza un undo.
* **deriv:** Executa derivarea axiomei. Parcurge secventa si inlocuieste fiecare element care are o regula de productie asociata, pastrandu-le intacte pe celelalte. Rezultatul este salvat in `copie_axioma` pentru eventuale re-derivari si este afisat la ecran.

### 2. Turtle Graphics
* **load:** Incarca imaginea initiala. Functioneaza similar cu `lsystem`, folosind contoare pentru gestionarea memoriei. In plus, creeaza copii ale imaginii pentru a facilita operatiile de undo si redo.
* **turtle_inceput:** Valideaza existenta unui L-system si a unei imagini incarcate. Salveaza imaginea pentru un eventual undo si apeleaza functia interna de derivare (fara afisare la ecran) pentru a pregati traseul.
* **turtle:** Executa desenarea propriu-zisa pe baza lui `copie_axioma`:
  * `F`: Calculeaza coordonatele finale si deseneaza linia pe matrice folosind algoritmul Bresenham, apoi actualizeaza pozitia.
  * `[` si `]`: Salveaza (push), respectiv extrage (pop) pozitia si orientarea curenta din stiva de stari.
  * `+` si `-`: Mareste, respectiv micsoreaza unghiul curent cu pasul unghiular.
* **save:** Salveaza stadiul actual al imaginii in fisierul specificat.

### 3. Fonturi si Text
* **font:** Incarca si salveaza detaliile unui font. Gestionarea memoriei se face la fel ca la `lsystem` si `load`, folosind contoare de resurse.
* **type & deseneaza_text:** Valideaza resursele, salveaza imaginea pentru undo si parcurge litera cu litera textul primit. Functia `desen_caracter` identifica simbolul in memoria fontului, calculeaza offset-ul pentru a-l desena pe imagine si muta cursorul pentru urmatorul caracter.

### 4. Gestiunea Starii (Undo / Redo) si Memorie
Pentru a urmari ce actiune trebuie anulata sau refacuta, tipul acesteia este pastrat in variabila `ultima_operatie`. Sistemul functioneaza pentru o singura operatie consecutiva.
* **undo_functie:**
  * Pentru `lsystem` / `load`: Scade contorul si restaureaza structurile din fisierele incarcate anterior.
  * Pentru `turtle` / `type`: Salveaza stadiul in `img_pt_redo` si restaureaza matricea de pixeli din `img_pt_undo`.
* **redo:** Reface operatia, efectuand actiunile inverse fata de `undo`.
* **functie_free:** Parcurge si elibereaza toata memoria alocata dinamic pe parcursul executiei, prevenind memory leak-urile.

---

## Compilare si Rulare

* Compilare proiect:
  ```bash
  make build