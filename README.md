# pageRank

Implémentation de l'algorithme de pageRank amelioré avec la méthode de la puissance.

![Plot Exemple](./plot/plot_clock_0.000010.png)

----
### Script

```
bash ./script/script.sh
```
Ce script éxecute la compilation, l'éxecution de lexécutable et la création des courbes.

---
### Compilation

```
make
```
---
### Executable

```
./pageRank
```
### Plot

```
gnuplot -c ./script/gnuplot.gp data/"..." > ./plot/plot_"...".png
```
