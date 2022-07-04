#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define a 400 //plegma megethous x shmainei x tetragwna, x+1 shmeia. plegma 400->x+1 shmeia
#define radius 200 //o kyklos peftei panw sta tetragwna toy plegmatos oxi sta shmeia tomhs twn akmwn
const int min=0;
const int max=a;

int main()
{
  int i,j,dx,xpart,ypart,xtemp,ytemp;
  double num;

  int (*plegma)[a]=malloc(sizeof(int[a][a]));
  /*int **plegma;
  plegma= (int**)malloc(a*sizeof(int*));
  for (int i=0; i <= a; i++)
  plegma[i] = (int*)malloc(a*sizeof(int)); */
  
  srand(4366);

  FILE *data;
  FILE *datac;
  data=fopen("datadla.txt","w");
  datac=fopen("datadlacircle.txt","w");
  
  dx=(a-2*radius)/2; //Auto gia na kentrarw ton kuklo se periptwsh poy einai mikroteros kai den efaptetai sto plegma
  for(i=0;i<=2*radius;i++)
    {
      for(j=0;j<=2*radius;j++)
	{
	  double distance=sqrt((a/2-i)*(a/2-i)+(a/2-j)*(a/2-j));
	  if(distance<radius+0.5 && distance>radius-0.5)
	    {
	      plegma[i+dx][j+dx]=-1;
	      //fprintf(datac,"%d\t%d\n",i+dx,j+dx);
	    }
	  else
	    {
	      plegma[i+dx][j+dx]=0; //midenizw ta shmeia tou plegmatos poy den antistoixoyn sto kyklo
	    }
	}
    }
  plegma[a/2][a/2]=1; //Pagideyw to 1o shmeio, to kentriko shmeio
  
  /* for(int i=0;i<a;i++)  //Gia na dw to plegma me to 1o pagideymeno shmeio
    {
      for(int j=0;j<a;j++)
	{
	  printf("%d ",plegma[i][j]);
	}
      printf("\n");
      } 
  */
  
 
   /* Arxizei o sximatismos tou fractal  */
     
  do
    {
      
      do
	{ //synthhkh gia na xekinaei apo thn perifereia tou kyklou
	  xpart=(min+(float)rand()/(float)(RAND_MAX)*(max-min)); // xekina apo tyxaia
	  ypart=(min+(float)rand()/(float)(RAND_MAX)*(max-min)); // thesh panw ston kyklo
	}  while(plegma[xpart][ypart]!=-1);
      
      //while(plegma[xpart][ypart]!=1 && xpart>0 && xpart<a && ypart>0 && ypart<a)
      // ti ginetai gyrw apo to plegma? yparxoyn arithmoi kai paei kai kollaei?
      while(plegma[xpart][ypart]!=1 && xpart>1 && xpart<a-1 && ypart>1 && ypart<a-1)
	{ //kineitai mexri na kollhsei h na bgei ektos plegmatos
	  num=1.0*rand()/RAND_MAX;
	  if(num>0.00 && num<=0.25) xpart=xpart-1; //...metakineitai
	  if(num>0.25 && num<=0.50) xpart=xpart+1;
	  if(num>0.50 && num<=0.75) ypart=ypart-1;
	  if(num>0.75 && num<=1.00) ypart=ypart+1;
	  if (plegma[xpart+1][ypart]==1 || plegma[xpart-1][ypart]==1 || plegma[xpart][ypart+1]==1 || plegma[xpart][ypart-1]==1)
	    {
	      fprintf(data, "%d\t%d\n",xpart,ypart);
	      plegma[xpart][ypart]=1;
	      xtemp=xpart;
	      ytemp=ypart;
	    }
	  //if (plegma[xtemp+1][ytemp]==-1 || plegma[xtemp-1][ytemp]==-1 || plegma[xtemp][ytemp+1]==-1 || plegma[xtemp][ytemp-1]==-1) break; 
	}
    }
  while (plegma[xtemp+1][ytemp]!=-1 && plegma[xtemp-1][ytemp]!=-1 && plegma[xtemp][ytemp+1]!=-1 && plegma[xtemp][ytemp-1]!=-1);
  // telos fractal
 
  free(plegma);
  fclose(datac);
  fclose(data);

  return 0;
}
