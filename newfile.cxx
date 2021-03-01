#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
	string SAYI1,SAYI2,basamak,sonuc="";
	cin >> SAYI1 >> SAYI2;
	vector<string> strler;
	int carpan, carpilan,ekle,MBU=0;
	for(int i=SAYI2.size()-1;i>-1;i--)
	{
			basamak = "";
			carpan = (int)SAYI2[i]-48;
			for(int i2=SAYI1.size()-1;i2>-1;i2--)
			{
				carpilan = (int)SAYI1[i2]-48;
				if(i2==0)
				{
					basamak = to_string((carpan*carpilan+ekle))+basamak;
				}else
				{
					basamak = to_string((carpan*carpilan+ekle)%10)+basamak;
				}
		   	ekle = (carpan*carpilan+ekle)/10;
		   
			}
		strler.push_back(basamak);
	}
	// sona sifir koyma
	for(int basnum=0;basnum<strler.size();basnum++)
	{
		
		for(int i2=0;i2<basnum;i2++)
		{
			strler[basnum] = strler[basnum]+"0";;
		
		}
	}
	// max bas bulma
	for(int i=0;i<strler.size();i++)
	{
		if(MBU<strler.at(i).size())
		{
			MBU = strler.at(i).size();
		}
	}
	// basa sifir ekleme
	int yedeksize;
	for(int basnum=0;basnum<strler.size();basnum++)
	{
		yedeksize = MBU-strler[basnum].size();
		for(int i2=0;i2<yedeksize;i2++)
		{
		   strler[basnum] = "0"+strler[basnum];
		}
	}
	// basamaklaei toplama
	ekle=0;
	int basamakdeger=0;
	for(int saybas=strler[0].size()-1;saybas>-1;saybas--)
	{
		basamakdeger=0;
		for(int i2=0;i2<strler.size();i2++)
		{
		   basamakdeger+= (int)strler[i2][saybas]-48;
		}
		if(saybas == 0)
		{
			sonuc = to_string((basamakdeger+ekle))+sonuc;
		}else
		{
			sonuc = to_string((basamakdeger+ekle)%10)+sonuc;
			ekle =(basamakdeger+ekle)/10;
		}
	}
	cout <<endl<< "CARPIM "<< sonuc;
}