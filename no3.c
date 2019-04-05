#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[4];

int agmal = 0;
int iraj =100;
int statusa = 0;
int statusi = 0;
char cetak[]="";

void* playandcount(void *arg)
{
    unsigned long i=0;
    pthread_t id=pthread_self();
     
    if(pthread_equal(id,tid[0]))
    {  while(1){
	scanf("%[^\n]%*c",cetak);
}
					
    }

    else if(pthread_equal(id,tid[1]))
    {	
	
	while(1){
      if(strcmp(cetak,"All Status")==0){
      	cetak[0]='\0';

	printf("Agmal = %d \nIraj = %d\n",agmal,iraj);		
	  printf("%s\n",cetak);
	}
	}
	}
   else if(pthread_equal(id,tid[2]))
    {	
	
	while(1){
	
		if(agmal >=100){
		printf("Agmal Bangun,Dan Berangkat Bersama Agmal");	
		exit(0);	
		}

      if(strcmp(cetak,"Agmal Ayo Bangun")==0){
		int a=15;
		agmal = agmal + a;
		
		
		cetak[0]='\0';	
		statusa ++;

	
	}
	if(statusa == 3){
		printf("Fitur Agmal ayo bangun disabled 10 s\n");
		sleep(10);
		statusa = 0;
	}
	}
}
    else if(pthread_equal(id,tid[3]))
    {	
	
	while(1){
	
	if(iraj <=0){

		printf("Iraj Ikut Tidur,Dan Bangun Kesiangan Bersama Agmal");	
		exit(0);	
		}

      if(strcmp(cetak,"Iraj Ayo Tidur")==0)
		{
			int b=20;
			iraj = iraj - b;
			
			
			cetak[0]='\0';	
			statusi ++;
		}
	if(statusi == 3){
		printf("Fitur Iraj ayo tidur disabled 10 s\n");
		sleep(10);
		statusi = 0;
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
    
for (i =0; i<4; i++)
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
//            printf("\n create thread success");
        }
       
    }
for(i = 0;i<4;i++){
    pthread_join(tid[i],NULL);
	}   
 return 0;
}
