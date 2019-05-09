// trikotniki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int smer(int i,string b, int v){
int smer;
	int p=0;
	for (int h=v-1; h>=0; h--){
		smer=0;
		for (int l=0; l<(h*2+1); l++){
			p++;
			if (p<=i){
				smer++;
			}else
				return smer;
		}
	}
}


int vis(int i,string b, int v, int &l){
	int* pol;
	pol=new int [v];
	pol[v-1]=1;
	for (int h=v-2; h>=0; h--){
		pol[h]=(pol[h+1]+2);
	}

	int vis=1;
	l=i;
	while (l>=0){
		if(l>=pol[vis-1]){
			l-=pol[vis-1];
			vis++;
		}
		else{
			return vis;
		}
		}
	return vis;
}

bool vrstag(string b,int l,int pom, int visina, int v){
	double kje;
	kje=(v-visina)*(v-visina);
	kje=b.size()-kje-l-(pom)*(pom)+1;
	int koliko=(pom)*2+1;
	if (v-visina>=v-2)
		return false;
		
	if (kje-koliko<=0)
		return false;
	for (int i=kje-2; i>kje-koliko-2; i--){
		if (i<0)
			return false;
		if (b[i]=='#')
			return false;
	}
	return true;
		
}

bool vrstad(string b,int l,int pom, int visina, int v){
	double kje;
	kje=(v-visina)*(v-visina)+1;
	kje=b.size()-kje-l+(pom)*2+3;
	cout << kje << endl;
	int koliko=(pom)*2+1;

//	if (visina<=v)
	//	return false;
	if (kje+koliko>=b.size()-1)
		return false;
	for (int i=kje; i<kje+koliko; i++){
		//cout << i << " ";
		if (i>=b.size()-1)
			return false;
		if (b[i]=='#')
			return false;
		
	}
	return true;
		
}



int trikotnik(int i,string b, int v){
	if (b[i]=='#')
		return 0;

	
	int l;
	int r=0;
	int s=smer(i,b,v);
	int visina = vis(i,b,v,l);
	if (s%2==0){
		cout << "gor" << endl;
		if (visina==1)
			return 1;
		int pom=1;
		r=1;
		while (vrstag(b,l,pom, visina,v)){
			pom++;
			r=(pom)*(pom);
		}
		return r;

	}
	else{
		cout << "dol" << endl;
		if (visina==v-1)
			return 1;
		if (l==1 || l==(v-visina)*2-1)
			return 1;
		int pom=1;
		r=1;
		while (vrstad(b,l,pom, visina,v)){
			pom++;
			r=(pom)*(pom);
			cout << r << endl;
		}
		return r;
	}
	return r;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int v;
	do{
	cout << "vnesi visino: " << endl;
	cin >> v;
	if (v==0)
		break;
	cin.ignore();

	string a;
	string b;
	cout << "Vnesi trikotnik (# izrezano, - papir, presledek da ostane oblika):" << endl;
	for (int i=0; i<v; i++){
		getline(cin,a);
		b+=a;
	}

	while (b.find(" ")!=string::npos){
		int j=b.find(" ");
		b.erase(j, 1);
	}
	int r=0;
	int p;
	for (int i=0; i<b.size(); i++){
		p=trikotnik(i,b, v);
		if(p>r)
			r=p;
	}
		

	cout << b << endl;
	cout << "Najvecji trikotnik ima ploscino " << r << "." << endl; 

	}while(v!=0);

	cin.ignore();
	cin.get();
	return 0;
}

