// ...existing code...
#include <stdio.h>
#include <string.h>

void procesarOpcion(int opcion); 

int main(void) {
    char *options[] = {
        "1. Iniciar Juego",
        "2. Estadisticas De El Jugador",
        "3. Salir"
    };
    int n = sizeof(options) / sizeof(options[0]);

    /* calcular ancho del interior del marco */
    int max = 0;
    for (int i = 0; i < n; ++i) {
        int len = (int)strlen(options[i]);
        if (len > max) max = len;
    }

    int pad = 2;                     /* espacios a izquierda/derecha dentro del marco */
    int innerWidth = max + pad * 2;  /* ancho sin los bordes '=' */
    int totalWidth = innerWidth + 2; /* +2 para los bordes laterales '=' */

    /* borde superior */
    for (int i = 0; i < totalWidth; ++i) putchar('=');
    putchar('\n');

    /* líneas con opciones centradas/alineadas a la izquierda con padding */
    for (int i = 0; i < n; ++i) {
        int left = pad;
        int right = innerWidth - (int)strlen(options[i]) - left;

        putchar('=');
        for (int j = 0; j < left; ++j) putchar(' ');
        printf("%s", options[i]);
        for (int j = 0; j < right; ++j) putchar(' ');
        putchar('=');
        putchar('\n');
    }

    /* borde inferior */
    for (int i = 0; i < totalWidth; ++i) putchar('=');
    putchar('\n');

    /* prompt fuera del marco para permitir entrada del usuario */
    int opcion = 0;
    printf("\nSeleccione una opcion: ");
    if (scanf("%d", &opcion) == 1) {
        procesarOpcion(opcion); /* llamada a la función */
    }

    return 0;
}

void procesarOpcion(int opcion) {
    if (opcion == 1) {
        int portaviones = 0;
        int cruceros = 0;
        int patrulleros = 0;    
        for (int k = 0; k < 12; k++ ){
        for (int j = 0; j < 12; j++ )
        {
            if (k == 0)
            {
               if (portaviones < 12) 
            {
                if ((j == 3 || j == 4 || j == 5 || j == 6))
                {
                    printf("|_X|");
                    portaviones++;  
                }
                else if (j!= 3 || j!=4 || j!=5 || j!=6)
                {
                    printf("|__|");
                } 
            } 
            }
            
            if (k == 4)
            {
                if (cruceros < 12)
                {
                    if ((j == 9 || j == 10 || j == 11))
                    {
                        printf("|_X|");
                        cruceros++;  
                    }
                    if ((j == 0 || j == 1 || j == 2))
                    {
                        printf("|_X|");
                        cruceros++;  
                    }
                    else if (j!= 0 && j!=1 && j!=2 && j!=9 && j!=10 && j!=11)
                    {
                        printf("|__|");
                    } 
                }   
            } 
            if (k == 9)
            {
            if (patrulleros < 12)
                {
                    if ((j == 2 || j == 3))
                    {
                        printf("|_X|");
                        patrulleros++;  
                    }
                    if ((j == 7 || j == 8))
                    {
                        printf("|_X|");
                        patrulleros++; 
                    } 
                    if ((j == 10 || j == 11))
                    {
                        printf("|_X|");
                        patrulleros++;  
                    }
                    else if (j!= 2 && j!=3 && j!=7 && j!=8 && j!=10 && j!=11)
                    {
                        printf("|__|");
                    } 
                }   
            } 
            else if (k != 0 && k !=4 && k !=9)
            {
                printf("|__|");
            }             
        }
        printf("\n" );
    }
        printf("Mapa Generado\n");
        printf("Presiona Enter para continuar...\n");
    } else if (opcion == 2) {
        printf("Estadisticas Proximamente...\n");
    } else if (opcion == 3) {
        return;
    } else {
        printf("Opcion invalida\n");
    }
}