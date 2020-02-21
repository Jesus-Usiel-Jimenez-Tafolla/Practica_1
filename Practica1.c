#include <stdio.h>
#include <stdlib.h>
#define tam 10
clear_screen()
{
    setbuf(stdin, NULL);
    getchar();
    system("clear");
}
char *elementos[tam]= {"Guitarra española", "Guitarra acustica", "Guitarra clasica", "Guitarra flamenca", "Amplificador       ",
"Fundas            ", "Cuerdas de acero", "Cuerdas de nylon", "Afinador             ", "Cable para amplificar"};
int precios [tam]= {5000, 4500, 3900, 2500, 1500, 500, 400, 300, 300, 50};
int disponibles [tam]= {12, 15, 21, 13, 11, 7, 4, 10, 10, 27};
int carrito [tam]={0,0,0,0,0,0,0,0,0,0};
int i, n, p, cant;
void menu ();
int main ()
{
menu ();
}
void menu ()
{
void mostrar();
void elecar();
void agrecar();
void elimicar();
short op;

while (1)
{
printf ("\n\nBienvenido a IVEVs Guitar.\n");
printf ("Este es el menu principal.\n¿Que desea hacer?\nContamos con:\n");
printf ("1)Mostrar elementos de la tienda.\n2)Mostrar elementos agregados al carrito.\n3)Agregar elemento al carrito.\n4)Quitar algun elemento del carrito\n5)Salir de la aplicacion.\n");
if (scanf ("%i", &op)==1)
{
switch (op)
{
case 1:
{
mostrar();
}break;
case 2:
{
 elecar();
}break;
case 3:
{
 agrecar();
}break;
case 4:
{
elimicar();
}break;
case 5:
    {
        printf("Muchas gracias por visitarnos, vuelve pronto y no olvides recomendarnos.\n\n");
        return;
    }break;
default:
    {
        printf("Selecionaste opcion incorrecta, vuelve al inicio.\n");
    }
}
}else{
	return;
      }
}
}

void mostrar ()
{
    printf ("Los elementos de la tienda son\n");
    printf ("ID  \tNombre               \tPrecio\tP. en almacen  \n");
    for(i=0; i<tam; i++)
    {
        printf("%i\t%s\t $%i\t [%i]\n", i+1, elementos[i], precios[i], disponibles[i]);
    }
    clear_screen();
}

void elecar ()
{
    int tot=0;
    printf ("Los elementos del carrito son:\n");
    printf ("ID  \tNombre               \t  Piezas  \tPrecio U.\tP. TOTAL  \n");
    for (i=0; i<tam; i++)
    {
        if (carrito [i] != 0)
        {
            printf("%i\t%s\t %i\t \t%i  %i\n", i+1, elementos[i], carrito[i], precios[i], precios[i]*carrito[i]);
            tot+=precios[i]*carrito[i];
        }
    }
    printf ("El total a pagar es: $%i\n", tot);
    clear_screen();
}
void agrecar ()
{
        mostrar ();
        printf("\n¿Cual deseas comprar? Selecciona su ID.\n");
        scanf("%i", &n);
        if (n<=tam)
            {
            printf ("Deseas comprar este objeto? Digita 1 si asi lo deseas.\n");
            scanf("%i", &p);
            }else{
                printf("No contamos con ese elemento\n");
            }
            if (p==1)
                {
                    printf ("Cuantas piezas deseas comprar?\n");
                    scanf ("%i", &cant);
                    if (cant<=disponibles[n-1])
                        {
                            carrito [n-1]+=cant;
                            disponibles[n-1]-=cant;
                        }else{
                    printf("No contamos con la cantidad necesaria de productos para satisfacer tu pedido, lo sentimos\n");
                     }
                }else{
                printf("Lo sentimos, no escogiste comprar, no te vayas sin hacerlo\n");
                }
	    elecar();
}
void elimicar ()
{
        elecar();
        printf("\n¿Cual deseas eliminar? Selecciona su ID.\n");
        scanf("%i", &n);
        if (n<=tam)
            {
            printf ("Deseas eliminar este objeto? Digita 1 si asi lo deseas.\n");
            scanf("%i", &p);
            }else{
                printf("No contamos con ese elemento\n");
            }
            if (p==1)
                {
                    printf ("Cuantas piezas deseas eliminar?\n");
                    scanf ("%i", &cant);
                    if (cant<=carrito[n-1])
                        {
                            carrito [n-1]-=cant;
                            disponibles[n-1]+=cant;
                        }else{
                    printf("No cuentas con toda esa cantidad en tu carrito.\n");
                     }
                }else{
                printf("Lo sentimos, no escogiste eliminar, revisa lo que deseas hacer y regresa.\n");
                }
                elecar();

}
