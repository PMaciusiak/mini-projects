#include<iostream>
#include<fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class wykladowca 
{
	private:
		string Imie_m, Nazwisko_m, Indeks_m, przedmiot_m;
		int ocena_m;
	public:
		wykladowca(string Imie="Jan",string Nazwisko="Kowalski",string Indeks="112233", string przedmiot="matematyka", int ocena=2 )
		{
			Imie_m=Imie;
			Nazwisko_m=Nazwisko;
			Indeks_m=Indeks;
			przedmiot_m=przedmiot;
			ocena_m=ocena;
		}
	void dodajocene() //metoda umo¿liwiaj¹ca dodanie oceny przez porwadz¹cego
	{
		fstream plikIn,plikOut;
		cout<<"Podaj imie studenta: ";
		cin>>Imie_m;
		cout<<endl<<"Podaj nazwisko studenta: ";
		cin>>Nazwisko_m;
		cout<<endl<<"Podaj numer indeksu studenta: ";
		cin>>Indeks_m;
		cout<<endl<<"Nazwa przdemiotu: ";
		cin>>przedmiot_m;
		cout<<endl<<"Podaj ocene uzyskan¹ przez studenta: ";
		cin>>ocena_m;
		plikOut.open("lista ocen.txt",ios::out | ios::app); //otiweramy plik do którego wpisujemy póŸniej dane
		plikOut<<Imie_m<<" "<<Nazwisko_m<<" "<<Indeks_m<<" "<<przedmiot_m<<" "<<ocena_m<<endl;
		plikOut.close();	
	}
	void listastudnetow() //metoda umo¿liwiaj¹ca wyœwietlenie listy studentów oraz sprawdzenie ocen z poszczególnych przedmiotów
	{
		fstream plikIn,plikOut;
		plikIn.open("lista ocen.txt",ios::in); // otiweramy plik a nastêpnie wyœwietalmy dane w odpowiedni sposób
		 while(plikIn>>Imie_m>>Nazwisko_m>>Indeks_m>>przedmiot_m>>ocena_m) 
		{
			cout<<"Imiê: "<<Imie_m<<endl<<"Nazwisko: "<<Nazwisko_m<<endl<<"Numer Indeksu: "<<Indeks_m<<endl<<"Przedmiot: "<<przedmiot_m<<endl<<"Ocena: "<<ocena_m<<endl<<endl<<endl;
		}
	
		  plikIn.close();
	}
	void zmienocene() // metoda umo¿liwiaj¹ca zmiane oceny przez prowadz¹cego
	{
		string Indeks, przedmiot, linia, ocena;
		int gdzie;
		cout<<"Prosze podac numer indeksu studenta: ";
		cin>>Indeks;
		cout<<endl<<"Prosze podac nazwe przedmiotu: ";
		cin>>przedmiot;
		fstream plikIn,plikOut;
		vector<string> tab;
		plikIn.open("lista ocen.txt",ios::in);
		 while(plikIn.good()==true)
		{
			plikIn>>Imie_m>>Nazwisko_m>>Indeks_m>>przedmiot_m>>ocena_m;
			string ocena_mm = to_string(ocena_m);
			tab.push_back(Imie_m);
			tab.push_back(Nazwisko_m);
			tab.push_back(Indeks_m);	
			tab.push_back(przedmiot_m);
			tab.push_back(ocena_mm);	
			if(Indeks_m==Indeks && przedmiot_m==przedmiot )
			{
				cout<<"Imiê: "<<Imie_m<<endl<<"Nazwisko: "<<Nazwisko_m<<endl<<"Numer Indeksu: "<<Indeks_m<<endl<<"Przedmiot: "<<przedmiot_m<<endl<<"Aktualna ocena: "<<ocena_m<<endl<<endl<<endl;
				
			}
			
		} // zapisujemy wszystkie dane z pliku do wektora a nastepnie wysweitalmy dane studenta któremy chcemy zmienic ocene
		
		plikIn.close();
		plikIn.open("lista ocen.txt", std::ofstream::out | std::ofstream::trunc); // czyœcimy plik
		plikIn.close();
		 
		cout<<"Podaj now¹ ocene: ";
		cin>>ocena;
		for( int i = 0; i <=tab.size()-1; i++)
		{
			if(tab[i]==Indeks && tab[i+1]==przedmiot)
				{
					gdzie = i+2;
				}
			
		} //wyszukujemy w którym miejscu w wektorze jest ocena któr¹ zmieniamy
		tab.erase(tab.begin()+gdzie);//usuwamy star¹ ocene
		tab.insert(tab.begin()+gdzie,ocena);//dodajemy now¹ ocene
		plikOut.open("lista ocen.txt",ios::out | ios::app);
	
		for(int i=0; i<=tab.size()-1; i++)
		plikOut<<tab[i]<<" "; // wpisujemy zmienione dane do pliku
		
		
		plikOut.close();
	}
};
class student
{
	private:
		string Imie_m, Nazwisko_m, Indeks_m, przedmiot_m;
		int ocena_m;
	public:
		student(string Imie="Jan",string Nazwisko="Kowalski",string Indeks="112233", string przedmiot="matematyka", int ocena=2 )
		{
			Imie_m=Imie;
			Nazwisko_m=Nazwisko;
			Indeks_m=Indeks;
			przedmiot_m=przedmiot;
			ocena_m=ocena;
		}
		void wyswietl() // metoda dla studenta wyswietlajaca jego oceny oraz œredni¹
		{
		string indeks;
		fstream plikIn,plikOut;
		plikIn.open("lista ocen.txt",ios::in);
		cout<<"Podaj numer swojego indeksu: ";
		cin>>indeks;
		int p=0;
		float k=0;
		
		vector<float> tab;
	
		 while(plikIn>>Imie_m>>Nazwisko_m>>Indeks_m>>przedmiot_m>>ocena_m)
		{
			
			if(Indeks_m==indeks) 
			{
				if (p == 0)
				{
				cout<<"Imiê: "<<Imie_m<<endl<<"Nazwisko: "<<Nazwisko_m<<endl<<"Numer Indeksu: "<<Indeks_m<<endl<<endl<<endl; // wyswietalmy dane stundeta
				p++;
				}
				cout<<"Przedmiot: "<<przedmiot_m<<endl<<"Ocena: "<<ocena_m<<endl<<endl<<endl;
				tab.push_back(ocena_m); // dodajemy kolejne oceny do wektora
			}	
			else
			{
				cout<<"..."<<endl;
			}
			
		}
		plikOut.close();
		for (int i = 0; i<=tab.size()-1; i++ )
			{
				k = k + tab[i];//wyliczamy œredni¹ dziêki dynamicznej alokacji pamieci przez wektor
			}
		cout<<"Œrednia Twoich ocen to: "<<k/tab.size()<<endl;
	
	}


};
void teacher() {// metoda zabezpieczaj¹ca dostêp do funckji prowadz¹cego
    int choiceT;
    wykladowca Ja; 
    string pwd, opcja="N";
    cout << "Podaj haslo." << endl;
    cin >> pwd;
    if (pwd == "haslo") {
    	while(opcja == "N")
        {
        cout << "Co chcesz teraz zrobic?" << endl << "1. Dodawanie oceny" << endl << "2. Zmiana oceny" << endl << "3. Wyswietlanie ocen" << endl;
        cin >> choiceT;
        
		
        switch (choiceT)
        {
        case 1:
            cout << "Dodawanie oceny" << endl;
			 Ja.dodajocene(); // wywoalnie metody
            break;
        case 2:
            cout << "Zmiana oceny" << endl; 
        	Ja.zmienocene(); // wywoalnie metody
        	break;
        case 3:
            cout << "Wyswietlanie oceny" << endl; 
            Ja.listastudnetow(); // wywoalnie metody
            break;
        default:
            cout<<"Bledny klawisz!" << endl;
            break;
        }
        cout<<"Opuœæ program T/N"<<endl; // dodajemy mo¿liwoœæ kolejnego wyboru
        cin>>opcja;
       
        
    }
    }
    else {
        cout << "Haslo nieprawidlowe. Sprobuj jeszcze raz." << endl;
        teacher();
    }
 
}

int main()
{
	setlocale(LC_CTYPE,"Polish"); // mo¿liwoœæ wyœiwetlania polskich znaków w konsoli
	student student1;
 int choice1;
 
    cout << "Wybierz typ konta: " << endl << "1. Nauczyciel" << endl << "2. Student" << endl;
    cin >> choice1;
 
    switch (choice1)
    {
    case 1:
        cout << "Witaj nauczycielu!" << endl;
        teacher();
        break;
    case 2:
        cout << "Witaj studencie! Ponizej twoje oceny." << endl;
    	student1.wyswietl();
        break;
    default:
        cout << "Ten klawisz nie jest aktywny. Sprobuj jeszcze raz." << endl;
        break;
    }
	return 0;
}
