///Nama 	: Habiib Iqbal Sobari
///Nim   	: A11.2018.11458


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void new_enkripsi (char *filldata,char *direct, int move);

int main () {
printf("\tPetunjuk penggunaan \n1. Masukkan kalimat = bla bla bla\n2. Masukkan angka = 1,2,3...26\n3. kanan/kiri\n\n");

	int a;
	char *b, filldata[255], move [7];
	char *moving=move;
	printf ("Masukkan Kalimat : ");
	scanf ("%[^\n]", filldata);
	do {
	    printf ("Besarnya Pergerakan dari karakter : ");
    	scanf ("%d", &a);
	} while (a<0);
	do {
        printf ("Arah Pergeseran : ");
	    scanf ("%s", move);
	    while (*moving!='\0') {
	        *moving=tolower (*moving);
	        moving++;
	        }
	    moving=move;
	}

	/* Arah pergeseran*/
    while ((strcmp (move, "kanan") !=0) && (strcmp (move, "kiri") !=0));
    if (a>0) {
		b=filldata;
		for ( ; *b!='\0'; b++) {
			*b=tolower(*b);
    		}
		new_enkripsi (filldata, move, a);
		printf ("Kalimat setelah dienkripsi : %s\n", filldata);
	    }
	return EXIT_SUCCESS;
}


/* New_enkripsi */
void new_enkripsi (char *filldata, char *direct, int move) {
int x;

/* Kanan */
if ((strcmp (direct, "kanan"))==0)
    {   for ( ; *filldata!='\0'; filldata++)
        {   if(*filldata==' ') continue;
            else
            {   for (x=0; x<move; x++)
                {   if((*filldata)>='z')
                    {
					(*filldata)-=26;
					(*filldata)++;
                    } else
                    {   (*filldata)++;  }
				}
			}
		}
		/* Kiri */
	} else if ((strcmp (direct, "kiri"))==0)
	{   for ( ; *filldata!='\0'; filldata++)
        {   if (*filldata==' ') continue;
			else {  for (x=0; x<move; x++)
                    {   if ((*filldata)<='a')
                        {
						(*filldata)+=26;
						(*filldata)--;
                        } else
                            {   (*filldata)--;  }
                    }
                }
		}
	}
}
