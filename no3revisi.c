#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[4];//inisialisasi array untuk menampung thread dalam kasusu ini ada 2 thread
int angka=0;
int stat = 1;
int agmal = 0,iraj =100;
int bakmal = 0,bakraj = 0;
int length=0;//inisialisasi jumlah looping
char print[]=""; //="print";
int bangun=1;
int tidur=1;
void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
    int iter;
     
    if(pthread_equal(id,tid[0]))//thread untuk menjalankan counter
    {  while(stat){
	if(bakmal == 3){
		tidur = 0;
		
		bakmal =0;
		sleep(10);
		tidur = 1;
	
	}
	
	
	}
					
    }

    else if(pthread_equal(id,tid[1]))
    {	
	while(stat){
      if(bakraj == 3){
   		
		bangun = 0;
		
      	bakraj = 0;
      	sleep(10);
      	bangun = 1;
	  }
	}
	}
}


int main(void)
{
    int i=0;
    int err;
  
  printf("Anda Memiliki 3 fitur utama \n");
	printf("1. All Status \n");
	printf("2. Agmal Ayo Bangun \n");
	printf("3. Iraj Ayo Tidur \n");
	printf("\n");
	printf("Pilihlah pilihan yang ada di fitur utama :\n");	
    
  
  

  pthread_create(&(tid[0]),NULL,&playandcount,NULL);//membuat thread

pthread_create(&(tid[1]),NULL,&playandcount,NULL);//membuat thread
  while(1){
 	
	scanf("%[^\n]%*c",print);
  	
	  if(strcmp(print,"All Status")==0){
      	print[0]='\0';
	printf("Agmal WakeUp_Status = %d \nIraj Spirit_Status= %d\n",agmal,iraj);		
        printf("%s\n",print);
	}
 	


  	 if(strcmp(print,"Agmal Ayo Bangun")==0 && bangun ==1){
	agmal = agmal + 15;
	//printf("Agmal sekarang = %d\n",agmal);
	
	print[0]='\0';	
	bakmal = bakmal + 1;

	
	}

	else if(strcmp(print,"Iraj Ayo Tidur")==0 && tidur == 1){
	iraj = iraj - 20;
	
	print[0]='\0';	
	bakraj = bakraj + 1;

	
	}

	if(bakmal == 3){
		printf("Fitur Iraj ayo tidur disabled 10 s\n");}
		
      if(bakraj == 3){
   		
		printf("Fitur Agmal ayo bangun disabled 10 s\n");}
			
	if(iraj<=0){
	printf("Iraj Ikut Tidur,Dan Bangun Kesiangan Bersama Agmal");	
	exit(0);	
	}
	if(agmal>=100){
	printf("Agmal Terbangun, mereka bangun pagi dan berolahraga");
	exit(0);

	}

  
  }
  
  
  
  
  
  
    return 0;
}
