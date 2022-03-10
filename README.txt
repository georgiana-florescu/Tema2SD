Cerința 1

	Pentru rezolvarea acestei cerințe am folosit o structură de arbore în care 
fiecare nod reține un vector de nouă caractere reprezentând tabla de joc și poate 
avea maxim nouă copii (cazul în care tabla de joc e goală). Funcția create_Tree 
inserează recursiv nodurile în arbore și primește ca argumente nodul rădăcină, 
numărul de fii pe care urmează să îi aibă rădăcina, caracterul care urmează să fie 
plasat și un vector de caractere ce va fi conținut de rădăcina. După crearea nodului 
rădăcina, verifică dacă există un câștigător și în caz negativ caută următoarea poziție
liberă, plasează caracterul curent și repetă procedeul pentru nodul fiu. Pentru
a opri jocul în cazul în care există deja un câștigător am scris funcția endgame care
returnează 1 dacă avem trei caractere identice pe orizontală, verticală sau diagonală. 

Cerința 2

	În cadrul acestei rezolvări am folosit arborele rezultat în urma primului exercițiu
și un arbore în care fiecare nod (TNode) reține un singur număr (0-F si 1-T). Funcția 
create_TTree inserează recursiv nodurile în arbore. Pentru un nod din arbore, dacă 
c == curr (jucătorul curent este și cel care vrem să caștige), valoarea nodului (p-ul din
program) va fi egală cu 1 dacă cel puțin un nod copil are valoarea 1, altfel valoarea 
acestuia va fi egală cu 1 doar dacă toate valorile copiilor sunt egale cu 1. Dacă nodul
este o frunză, valoarea lui va fi 1 doar dacă endgame(root) returnează 1 și jucătorul 
curent este adversarul. 

Cerința 3

	Pentru a rezolva cerința 3 am folosit din nou o funcție recursivă create_MMTree. 
Deoarece nu știam numărul maxim de copii pe care îi poate avea un nod am folosit alocarea 
dinamică. Funcția new_MMNode returnează un nod cu nodes (argumentul functiei) copii. 
Am folosit un vector tab de dimensiune egală cu înalțimea arborelui în care am reținut
poziția din fișier de unde trebuie sa citească (tab[i] - începutul liniei i+1) și care după
fiecare apelare a funcției create_MMTree tab[nivel] este actualizat. Minmax indică dacă 
nodul va avea valoarea maximă sau minimă a nodurilor copii iar pos indică nivelul pe care
se află nodul. 
 	