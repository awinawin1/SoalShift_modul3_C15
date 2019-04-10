#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
void main()
{
        key_t key = 1234;
        int *value;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
     	int hay=1;
	int pilih;	
	while(hay=1){
	   value = shmat(shmid, NULL, 0);
	printf("Food Stock = %d\n1.Restock\n2.Exit\n",*value);
	scanf("%d",&pilih);        
		if(pilih==1) *value = *value + 10;
		else if(pilih==2) exit(0);
	
	}       
	 shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
