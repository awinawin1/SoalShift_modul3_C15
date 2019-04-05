## 1.SOAL1
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
