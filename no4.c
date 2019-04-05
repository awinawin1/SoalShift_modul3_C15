#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>

#include<stdlib.h>
#include<string.h>

pthread_t tid[10];

void* proses1(){

	system("mkdir -p /home/awin/Documents/FolderProses1");
	system("ps -aux|head -10>>/home/awin/Documents/FolderProses1/SimpanProses1.txt");
}

void* proses2(){

	system("mkdir -p ~/home/awin/Documents/FolderProses2");
	system("ps -aux|head -10>>/home/awin/Documents/FolderProses2/SimpanProses2.txt");
}

void* zip1(){

	system("zip -j /home/awin/Documents/FolderProses1/KompresProses1.zip /home/awin/Documents/FolderProses1/SimpanProses1.txt");
	system("rm /home/awin/Documents/FolderProses1/SimpanProses1.txt");
	sleep(15);

		printf("Menunggu 15 detik untuk mengekstrak kembali");
		printf("\n");
		system("unzip /home/awin/Documents/FolderProses1/KompresProses1.zip -d /home/awin/Documents");
		system("rm ~/Documents/FolderProses1/KompresProses1.zip");
	
}

void* zip2(){
	system("zip -j /home/awin/Documents/FolderProses2/KompresProses2.zip /home/awin/Documents/FolderProses2/SimpanProses2.txt");
	system("rm /home/awin/Documents/FolderProses2/SimpanProses2.txt");
	sleep(15);


		printf("Menunggu 15 detik untuk mengekstrak kembali");
		printf("\n");
		system("unzip /home/awin/FolderProses2/KompresProses2.zip -d /home/awin/Documents");
		system("rm /home/awin/Documents/FolderProses2/KompresProses2.zip");
	
}

int main()
{
int i=0;
while(i<2){
	pthread_create(&(tid[i]),NULL,&proses1,NULL);
	pthread_join(tid[i],NULL);
//	pthread_create(&(tid[1]),NULL,&proses2,NULL);
	//pthread_join(tid[1],NULL);
}

while(i<2){

	pthread_create(&(tid[i]),NULL,&zip1,NULL);
	pthread_create(&(tid[i]),NULL,&zip2,NULL);
	}
while(i<2){
	pthread_join(tid[i],NULL);
	pthread_join(tid[i],NULL);
}
}
