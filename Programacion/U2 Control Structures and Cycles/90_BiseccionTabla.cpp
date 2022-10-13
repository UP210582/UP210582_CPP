#include <stdio.h>
#include <math.h>

#define RAIZ(x) ((x)+2) // Definimos la funcion de la que se busca la raiz

int main() {
float xi, xu, xr, xa, ea;
int iteraciones;
printf("Limite superior de la raiz: ");
scanf("%f", &xi);
printf("Limite inferior de la raiz: ");
scanf("%f", &xu);

iteraciones = 0;
xa = 0.0;
ea = 0;
printf("%12s %10s %10s %10s %10s\n", "Iteraciones", "Xi", "Xu", "Xr", "Ea");

do{
iteraciones++;
xr = (xi + xu) / 2;
if(iteraciones >= 2) {
ea = ((xr - xa) / xr) * 100; // Calculamos el error aproximado a partir de la segunda iteración
}
ea = fabs(ea); // Calculamos el valor absoluto del número
printf("%12d %10f %10f %10f %10f\n", iteraciones, xi, xu, xr, fabs(ea));
xa = xr;
if(RAIZ(xr) > 0) {
xi = xr;
} else{
xu = xr;
}

} while(ea > 0.5 || (ea == 0.0 && iteraciones == 1));

printf("\nLa raiz es de f(x) = x + 2; es: %f\n", xr);

return 0;
}