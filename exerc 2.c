#include <stdio.h>
#include <stdlib.h>

struct entrada {
    int usuario_id;
    int *hobbies;
};

int *solucao(struct entrada *entradas, int n, int h)
{
    int *ret = (int *) malloc(n * sizeof(int));
    int c1,c2,c3;
    int temp;
    struct entrada TEMP;
    int *intera;

    intera=calloc(sizeof(int),n);


    for(c1=0;c1<n;c1++)//repete o loop pra cada ID
    {
        for(c2=0;c2<h;c2++)//repete pra cada hobbie
        {
            for(c3=0;c3<h-c2;c3++)
            if(entradas[c1].hobbies[c2]>entradas[c1].hobbies[c2+1])
            {
                temp=entradas[c1].hobbies[c2+1];
                entradas[c1].hobbies[c2+1]=entradas[c1].hobbies[c2];
                entradas[c1].hobbies[c2]=temp;

                intera[c1]++;
            }
        }
    }

    for(c2=0;c2<n;c2++)
    {
     for(c1=0;c1<n-c2;c1++)
        {
            if(intera[c1]<intera[c1+1])
            {
                temp=intera[c1+1];
                intera[c2]=intera[c1];
                intera[c1]=temp;

                TEMP=entradas[c2];
                entradas[c2]=entradas[c1];
                entradas[c1]=TEMP;
            }
        }
    }

    for(c1=0;c1<n;c1++)
    {
        ret[c1]=entradas[c1].usuario_id;
    }

    return ret;
}

int main()
{
    int *ret;
    int t, i, j;
    int T, N, H;

    scanf("%d", &T);

    for (t = 0; t < T; t++) {

        scanf("%d %d", &N, &H);

        struct entrada *entradas = (struct entrada *) malloc(N * sizeof(struct entrada));

        for (i = 0; i < N; i++) {
            entradas[i].hobbies = (int *) malloc(H * sizeof(int));
            scanf("%d", &entradas[i].usuario_id);
            for (j = 0; j < H; j++)
                scanf(" %d", &entradas[i].hobbies[j]);
        }

        ret = solucao(entradas, N, H);

        for (i = 0; i < N; i++)
            if (i + 1 < N)
                printf("%d ", ret[i]);
            else
                printf("%d\n", ret[i]);
    }

    return 0;
}