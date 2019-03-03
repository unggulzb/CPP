/*
1. Buatlah fungsi utama untuk menjalankan queue pada modul dengan menggunakan   menu. untuk alurnya, hampir sama dengan flowchart untuk stack (lihat di Modul). Hanya saja fungsi diganti dengan fungsi-fungsi queue

2. Carilah total, rata-rata, nilai terkecil, nilai terbesar dari nilai yang telah di inputkan pada queue
*/
#include <iostream>
#define MAX 20 //maksimum data queue
using namespace std;

//Deklarasi struct antrian
struct Queue {
	int front, rear, data[MAX];
}Q;
bool isFull() {
	return Q.rear == MAX;
}
bool isEmpty() {
	return Q.rear == 0;
}
void printQueue() {
	system("cls");
	if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
	else {
		cout << "QUEUE data : ";
		for (int i = Q.front; i < Q.rear; i++)
		//menambahkan koma jika data tidak terdapat di antrian pertama
			cout << Q.data[i] << ((Q.rear-1 == i) ? "" : ",");
		cout << endl;
  }
}
void enqueue() {
	if (isFull())
	{
		cout << "Antrian penuh!"<<endl;
	}
	else {
		int data;
		cout << "Masukkan Data : ";cin >> data;
		Q.data[Q.rear] = data;
		Q.rear++;
		cout << "Data ditambahkan\n";
		printQueue();
	}
}

void dequeue() {
	if (isEmpty())
	{
		cout << "Antrian kosong"<<endl;
	}
	else{
		cout << "Mengambil data \"" << Q.data[Q.front] << "\"..." << endl;
		for (int i = Q.front; i < Q.rear; i++)
			Q.data[i] = Q.data[i + 1];
		Q.rear--;
		printQueue();
	}
}
void statistik(){
	system("cls");
	int  max, min;
	float trt=0,rata;
		if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
	else {
		cout << "QUEUE data : ";
		for (int i = Q.front; i < Q.rear; i++){
			cout << Q.data[i] << ((Q.rear-1 == i) ? "" : ",");
			trt = trt+Q.data[i];
			if ( i == 0 ) {
             min = Q.data[i];
             max = Q.data[i];
            }
            else if ( min > Q.data[i] ) {
               min = Q.data[i];
            }
            else if ( max < Q.data[i]) {
               max = Q.data[i];
           }
           else {} 
		}
		rata = trt/(Q.rear);
		cout << endl;
		cout<<	"Rata Rata                : " <<  rata<<endl;
       	cout << "Nilai terkecil           : " <<  min << endl;
       	cout << "Nilai terbesar           : " <<  max << endl;
		cout << endl;
  }
  
}

int main() {
	
	int choose;
	do
	{
		
		cout << "================================\n"
			<< "   Menu Pilihan\n"
			<< "================================\n"
			<< " [1] Enqueue \n"
			<< " [2] Dequeue\n"
			<< " [3] Statistika(mean,min,max) \n"
			<< " [4] Keluar \n\n"
			<< "================================\n"
			<< "Masukkan pilihan : "; cin >> choose;
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			statistik();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
		
	} while (choose !=4);
	system("cls");
	return 0;
//	==============================================================================================================================================================pinggo
}
