## 1.SOAL3
Agmal dan Iraj merupakan 2 sahabat yang sedang kuliah dan hidup satu kostan, 
sayangnya mereka mempunyai gaya hidup yang berkebalikan, dimana Iraj merupakan laki-laki yang sangat sehat,
rajin berolahraga dan bangun tidak pernah kesiangan sedangkan Agmal hampir menghabiskan setengah umur hidupnya hanya untuk tidur 
dan ‘ngoding’. Dikarenakan mereka sahabat yang baik, Agmal dan iraj sama-sama ingin membuat satu sama lain mengikuti gaya hidup 
mereka dengan cara membuat Iraj sering tidur seperti Agmal, atau membuat Agmal selalu bangun pagi seperti Iraj. Buatlah suatu 
program C untuk menggambarkan kehidupan mereka dengan spesifikasi sebagai berikut:

Terdapat 2 karakter Agmal dan Iraj
Kedua karakter memiliki status yang unik
Agmal mempunyai WakeUp_Status, di awal program memiliki status 0
Iraj memiliki Spirit_Status, di awal program memiliki status 100
```
int agmal = 0;
int iraj =100;

```
Terdapat 3 Fitur utama
All Status, yaitu menampilkan status kedua sahabat
```
while(1){
      if(strcmp(cetak,"All Status")==0){
      	cetak[0]='\0';

	printf("Agmal = %d \nIraj = %d\n",agmal,iraj);		
	  printf("%s\n",cetak);
	}
```
“Agmal Ayo Bangun” menambah WakeUp_Status Agmal sebesar 15 point
```
  if(strcmp(cetak,"Agmal Ayo Bangun")==0){
		int a=15;
		agmal = agmal + a;
		
		
		cetak[0]='\0';	
		statusa ++;

```
“Iraj Ayo Tidur” mengurangi Spirit_Status Iraj sebanyak 20 point
```
if(strcmp(cetak,"Iraj Ayo Tidur")==0)
		{
			int b=20;
			iraj = iraj - b;
			
			
			cetak[0]='\0';	
			statusi ++;
		}
```
Terdapat Kasus yang unik dimana:
Jika Fitur “Agmal Ayo Bangun” dijalankan sebanyak 3 kali, maka Fitur “Iraj Ayo Tidur” Tidak bisa dijalankan selama 10 detik 
(Dengan mengirim pesan ke sistem “Fitur Iraj Ayo Tidur disabled 10 s”)
```
if(statusi == 3){
		printf("Fitur Iraj ayo tidur disabled 10 s\n");
		sleep(10);
		statusi = 0;
		}
```

Jika Fitur  “Iraj Ayo Tidur” dijalankan sebanyak 3 kali, maka Fitur “Agmal Ayo Bangun” Tidak bisa dijalankan selama 10 detik 
(Dengan mengirim pesan ke sistem “Agmal Ayo Bangun disabled 10 s”)

```
if(statusa == 3){
		printf("Fitur Agmal ayo bangun disabled 10 s\n");
		sleep(10);
		statusa = 0;
	}
```
Program akan berhenti jika Salah Satu :
WakeUp_Status Agmal >= 100 (Tampilkan Pesan “Agmal Terbangun,mereka bangun pagi dan berolahraga”)
```
if(agmal >=100){

		printf("Iraj Ikut Tidur,Dan Bangun Kesiangan Bersama Agmal");	
		exit(0);	
		}
```
Spirit_Status Iraj <= 0 (Tampilkan Pesan “Iraj ikut tidur, dan bangun kesiangan bersama Agmal”)
```
if(iraj <=0){

		printf("Iraj Ikut Tidur,Dan Bangun Kesiangan Bersama Agmal");	
		exit(0);	
		}
```

## 2. no2
membuat client server dari pembeli dan penjual
-client pembeli
ketika scan "beli" maka akan di send ke server dan menerima pesan dari server pembeli.
-server pemebeli
meread beli, ketika stok masi ada maka jumlah -1 dan mengirim pesan pada client bahwa telah terbeli

-client penjual
ketika scan "tambah" maka akan di send ke server, menerima pesan dari server dan meng-print stok yang ada setiap 5 detik
-server penjual
meread tambah, maka jumlah +1dan mengirim pesan berhasil menambah pada client

## 3. no1
fungsi faktorial
```
void* factorial(void* arg)
{
    int* nump = (int*) arg; //mengcasting mnjdi integer
    int num = *nump;//nilai num
    int i;
    unsigned long long facto = 1;
    for( i=num; i>0; i--){//faktorisasi
        facto = facto*i;
    }
    hasil[num] = facto;//hasil faktorial dimasukkan ke array hasil
}
```
fungsi swap
```
void swap(int *a, int *b)//template swap
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
```
fungsi selectionsort
```
void selectionSort(int arr[], int size)//templtae SelectionSort
{
    int i, j;
    for (i = 0 ;  i < size;i++)
    {
        for (j = i ; j < size; j++)
        {
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
        }
    }
}
```
main
```
int main(int argc, char *argv[])
{//argc: menghitung jumlah input, //argv: menyimpan input 
    int n;
    n = argc-1; //inputan
    pthread_t tid[n];//membuat thread sesuai inputan
    int i;
    int ar[n];
    for(i=0;i<n;i++){
       ar[i] = atoi(argv[i+1]);//mengambil inputan tanpa ./blabla, atau asci to integer
    }
    for(i=0;i<n;i++){
        pthread_create(&tid[i],NULL,&factorial,&ar[i]);
    }
    for(i=0;i<n;i++){
        pthread_join(tid[i],NULL);
    }
    selectionSort(ar,n);//memanggil fungsi selectionsort
    for(i=0;i<n;i++){
        printf("%d! = %llu\n",ar[i],hasil[ar[i]]);
    }//mengoutputkan nilai faktorial pada setiap thread
    
}

```
## 4. no4
ntuk membuat FolderProses1 (folder) dan SimpanProses1.txt (file proses)
menyimpan list proses yang sedang berjalan (ps -aux)  10 list prosesA
```
void* proses1(){
	system("mkdir -p ~/Documents/FolderProses1");
	system("ps -aux|head -10>>~/Documents/FolderProses1/SimpanProses1.txt");
}

void* proses2(){
	system("mkdir -p ~/Documents/FolderProses2");
	system("ps -aux|head -10>>~/Documents/FolderProses2/SimpanProses2.txt");
}
```
untuk membuat zip dan ekstrak zip tersebut
```
void* zip1(){
	system("zip -j ~/Documents/FolderProses1/KompresProses1.zip ~/Documents/FolderProses1/SimpanProses1.txt");
	system("rm ~/Documents/FolderProses1/SimpanProses1.txt");
	sleep(15);

		printf("Menunggu 15 detik untuk mengekstrak kembali\n");
		system("unzip ~/Documents/FolderProses1/KompresProses1.zip -d ~/Documents");
		system("rm ~/Documents/FolderProses1/KompresProses1.zip");
	
}

void* zip2(){
	system("zip -j ~/Documents/FolderProses2/KompresProses2.zip ~/Documents/FolderProses2/SimpanProses2.txt");
	system("rm ~/Documents/FolderProses2/SimpanProses2.txt");
	sleep(15);
```

Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
```
		printf("Menunggu 15 detik untuk mengekstrak kembali\n");
		system("unzip ~/Documents/FolderProses2/KompresProses2.zip -d ~/Documents");
		system("rm ~/Documents/FolderProses2/KompresProses2.zip");
	
}
```
main
```
int main()
{
//Multithreading
	pthread_create(&(tid[0]),NULL,&proses1,NULL);
	pthread_join(tid[0],NULL);
	pthread_create(&(tid[1]),NULL,&proses2,NULL);
	pthread_join(tid[1],NULL);
	pthread_create(&(tid[0]),NULL,&zip1,NULL);
	pthread_create(&(tid[1]),NULL,&zip2,NULL);
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
}
```
## no5 soal5
penjelasan ada di file, di commentnya
