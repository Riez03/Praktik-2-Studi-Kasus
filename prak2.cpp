#include<iostream>
#include<fstream>
using namespace std;
int main(){
	int menu,total,ulang=0,jarak,ongkir1=0,ongkir2=0;
	string makanan[100];
	int kuantitas[100],hargaS[100],hargaP[100];
	float diskon=0, hasil;
	int bayar, kembalian;
	ofstream myFile;
	cout<<"Menu Makanan: \n";
	cout<<"1. Ayam Geprek : 21000\n";
	cout<<"2. Ayam Goreng : 17000\n";
	cout<<"3. Udang Goreng: 19000\n";
	cout<<"4. Cumi Goreng: 20000\n";
	cout<<"5. Ayam Bakar : 25000\n";
	for(int i=0;i<100;i++){
		cout<<"-------Menu Utama-------\n";
		cout<<"1. Masukkan Pesanan\n";
		cout<<"2. Keluar\n";
		cout<<"Pilih Menu Utama: ";cin>>menu;
		cin.ignore();
		if(menu==1){
			cout<<"Makanan     : ";getline(cin,makanan[i]);
			cout<<"Kuantitas   : ";cin>>kuantitas[i];
			cout<<"Harga Satuan: ";cin>>hargaS[i];
			hargaP[i]=kuantitas[i]*hargaS[i];
			cout<<"Total Biaya : "<<hargaP[i]<<endl<<endl;
			ulang+=1;
		}else if(menu==2){
			for(int i=0;i<ulang;i++){
				total+=hargaP[i];
			}
			cout<<"\nTotal Keseluruhan Biaya : "<<total<<endl;
			cout<<"Masukkan Jarak Rumah (km): ";cin>>jarak;
			if(jarak<3){
				ongkir1=15000;
			}
			else{
				ongkir1=25000;
			}
			if(total<=25000){
				ongkir2=ongkir1;
				hasil=total+ongkir1;
				cout<<"Jadi Anda Harus membayar "<<hasil<<endl;
				cout<<"Bayar= ";cin>>bayar;
				kembalian=bayar-hasil;
				cout<<"Kembalian= "<<kembalian<<endl;
			}
			else if(total>150000){
				cout<<"Mendapat Potongan Ongkir 8000 dan diskon belanja 35%.\n";
				ongkir2=ongkir1-8000;
				diskon=total*35/100;
				hasil=total+ongkir2-diskon;
				cout<<"Jadi Anda Harus membayar "<<hasil<<endl;
				cout<<"Bayar= ";cin>>bayar;
				kembalian=bayar-hasil;
				cout<<"Kembalian= "<<kembalian<<endl;
			}
			else if(total>50000){
				cout<<"Mendapat Potongan Ongkir 5000 dan diskon belanja 15%.\n";
				ongkir2=ongkir1-5000;
				diskon=total*15/100;
				hasil=total+ongkir2-diskon;
				cout<<"ongkir="<<ongkir2<<endl;
				cout<<"diskon="<<diskon<<endl;
				cout<<"Jadi Anda Harus membayar "<<hasil<<endl;
				cout<<"Bayar= ";cin>>bayar;
				kembalian=bayar-hasil;
				cout<<"Kembalian= "<<kembalian<<endl;
			}
			else if(total>25000){
				cout<<"Mendapat Potongan Ongkir 3000.\n";
				ongkir2=ongkir1-3000;
				hasil=total+ongkir2;
				cout<<"Jadi Anda Harus membayar "<<hasil<<endl;
				cout<<"Bayar= ";cin>>bayar;
				kembalian=bayar-hasil;
				cout<<"Kembalian= "<<kembalian<<endl;
			}
			cout<<"Keluar";
			break;
		}
	}
	myFile.open("prak1.txt", ios::trunc);
	myFile<<"======Struct Belanja======\n\n";
	for(int i=0;i<ulang;i++){
		myFile<<"Nama Pesanan : ";
		myFile<<makanan[i]<<endl;
		myFile<<"Kuantitas   : ";
		myFile<<kuantitas[i]<<endl;
		myFile<<"Harga Satuan: ";
		myFile<<hargaS[i]<<endl;
	}
	myFile<<"\nTagihan Awal : ";
	myFile<<total<<endl;
	myFile<<"Ongkir = "<<ongkir2<<endl;
	myFile<<"Diskon = "<<diskon<<endl;
	myFile<<"Tagihan akhir = "<<hasil<<endl;
	myFile<<"Anda membayar="<<bayar<<endl;
	myFile<<"Kembalian="<<kembalian;
	
	myFile.close();	
}
