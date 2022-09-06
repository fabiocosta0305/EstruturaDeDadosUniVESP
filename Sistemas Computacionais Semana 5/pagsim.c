#include <stdio.h>

typedef struct moldura
{
    int bv;
    char contentRAM;
} frame;

typedef struct pagina{
    int bv;
    char contentDISCO;
    frame *pv;
} page;

frame RAM[2];
page DISCO[20];

int i,j;

int main()
{
    for (i=0; i<2; i++)
    {
        RAM[i].bv=0;
    }

    for (i=0; i < 20; i++)
    {
        DISCO[i].contentDISCO= 'a' + i;
        DISCO[i].bv=1;
        DISCO[i].pv=NULL;

        if ((DISCO[i].contentDISCO == 'e') || (DISCO[i].contentDISCO == 'j'))
        {
            for (j=0; j<2; j++)
            {
                if ( RAM[j].bv == 0 )
                {
                    RAM[j].bv=1;
                    DISCO[i].pv=&RAM[j];
                    RAM[j].contentRAM=DISCO[i].contentDISCO; 
                    j=2;
                }
            }
        }


    }
	printf("visualização DISCO\n");

	for (i=0; i<20; i++)
	{
		printf("%d page[content: %c", i+1, DISCO[i].contentDISCO);
		printf(" BV: %d RAM: %d ]\n", DISCO[i].bv, DISCO[i].pv);
	}

	printf("visualização RAM\n");

	for (j=0; j<2; j++)
	{
		printf("%d frame [content: %c", j+1, RAM[j].contentRAM);
		printf(" BV: %d]\n",RAM[j].bv);
	}

	return (0);
}