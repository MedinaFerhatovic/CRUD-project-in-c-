#include <iostream> 
#include <cstring>
#include <iomanip>
#include <fstream>
using namespace std;
struct registracija{
	string username;
	string password;
};
struct Predmeti{
	float njemackiUspjeh;
	float engleskiUspjeh;
	float matematikaUspjeh;
};
struct Student{
	char ime[10];
	char prezime[20];
	char razred[10];
	int rezultat;
	float ukupanRezultat;
	float uspjeh;
	float kontrolneTacke;
	Predmeti predmet;
} m[100];
static int e=0;
int n=100;
void  sort ();

bool prijava(string user, string password){
	string userTemp, passwordTemp;
	int brojac=3;
	system("color F1");
	while(brojac>0){
		cout << "Username: ";
		cin >> userTemp;
		cout << "Password: ";
		cin >> passwordTemp;
		if(userTemp.compare(user)!=0 || passwordTemp.compare(password)!=0){
			if(brojac==1){
				return 0;
			}else{
				cout << "\n\tUneseni podaci su pogresni. Pokusajte ponovo!\n";
				cout << "\n\tPreostali broj pokusaja: " << --brojac << endl;
				cout << endl;
			}
		}else{
			return 1;
		}
	}
}
void prikaz(){
	system("cls");
	ifstream ispis("student.txt");
	if(!ispis.is_open()){
		cout << "Datoteka se ne moze otvoriti!" << endl;
	}
	cout << left << fixed << setw(8) << "Broj" << setw(10) << "Ime" << setw(15) << "Prezime" << setw(12) << "Razred" << setw(10) << "Engleski" 
	     << setw(10) << "Njemacki" << setw(15) << "Matematika" << setw(19) << "Ukupan rezultat" << setw(8) << "Prosjek" << setw(8) << "Variance" << endl;
	     for(int i=0; i<e; i++){
	     	m[i].ukupanRezultat = (m[i].predmet.engleskiUspjeh + m[i].predmet.njemackiUspjeh + m[i].predmet.matematikaUspjeh);
	     	m[i].uspjeh = m[i].ukupanRezultat/3;
	     	m[i].kontrolneTacke = (((m[i].predmet.engleskiUspjeh - m[i].uspjeh) * (m[i].predmet.engleskiUspjeh - m[i].uspjeh)) + ((m[i].predmet.njemackiUspjeh - m[i].uspjeh) * (m[i].predmet.njemackiUspjeh - m[i].uspjeh))
	     	+ ((m[i].predmet.matematikaUspjeh - m[i].uspjeh) * (m[i].predmet.matematikaUspjeh - m[i].uspjeh)))/3;
	     	cout << setiosflags (ios::left) << setw(5) << m[i].rezultat << " " << setw(10) << m[i].ime << setw(20) << m[i].prezime << setw(14) << m[i].razred 
	     	     << setw(8) << m[i].predmet.engleskiUspjeh << setw(8) << m[i].predmet.njemackiUspjeh << setw(8) << m[i].predmet.matematikaUspjeh << setw(8)
	     	     << m[i].ukupanRezultat << setw(10) << m[i].uspjeh << setw(10) << m[i].kontrolneTacke << endl;
	     	if(m[i].rezultat==0){
	     		break;
			 }
		 }
}
void unos(){
	system("cls");
	cout << "--------------------------------------------------\n";
	cout << "Unesite informacije o studentu" << endl;
	cout << "--------------------------------------------------\n";
	cout << "\t\nMolimo vas unesite podatke,a ako zelite zavrsiti unos, unesite 0!" << endl;
	for(int i=e; i<n; i++){
		cout << "\nUnesite rezultat: ";
		cin >> m[i].rezultat;
		if(m[i].rezultat==0){
			break;
		}
		cout << "\nUnesite ime ucenika: ";
		cin >> m[i].ime;
		cout << "\nUnesite prezime ucenika: ";
		cin >> m[i].prezime;
		cout << "\nUnesite razred ucenika: ";
		cin >> m[i].razred;
		cout << "\nUnesite uspjeh iz engleskog: ";
		cin >> m[i].predmet.engleskiUspjeh;
		cout << "\nUnesite uspjeh iz njemackog: ";
		cin >> m[i].predmet.njemackiUspjeh;
		cout << "\nUnesite uspjeh iz matematike: ";
		cin >> m[i].predmet.matematikaUspjeh;
		e++;
	}
}
void brisanje(){
	prikaz();
	int a;
	cout << "\n\tUnesite ID ucenika kojeg zelite obrisati: ";
	cin >> a;
	for(int i=0; i<e; i++){
		if(a==m[i].rezultat){
			for(int j=i; j<e-1; j++){
				strcpy(m[j].ime, m[j+1].ime);
				strcpy(m[j].prezime, m[j+1].prezime);
				strcpy(m[j].razred, m[j+1].razred);
				m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
				m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
				m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
				m[j].rezultat = m[j+1].rezultat;
				m[j].ukupanRezultat = m[j+1].ukupanRezultat;
				m[j].uspjeh = m[j+1].uspjeh;
				m[j].kontrolneTacke = m[j+1].kontrolneTacke;
			}
			for(int i=0; i<e-1; i++){
				cout << setw(5) << m[i].rezultat << setw(10) << m[i].ime << setw(20) << m[i].prezime << setw(15) << m[i].razred
                     << setw(10) << m[i].predmet.engleskiUspjeh << setw(10) << m[i].predmet.njemackiUspjeh << setw(10) << m[i].predmet.matematikaUspjeh
                     << setw(8) << m[i].ukupanRezultat << setw(10) << m[i].uspjeh << setw(10) << m[i].kontrolneTacke << endl;
			}
			cout << "\n\t-------Uspjesno izbrisane informacije o uceniku!-------" << endl;
			break;
		}
	}
}
void pretragaPoBroju(){
	int a;
    prikaz();
    cout << "Unesite ID ucenika kojeg trazite: " << endl;
    cin >> a;
    int BOOL=0 ;
    for( int i=0; i<n; i++){
      if (a==m[i].rezultat ){
         cout << setiosflags (ios::left) << setw(2) << " Broj ucenika " << "    " << setw(10) << " Ime " << setw(10) << " Prezime "
              << setw(10) << " Razred " << setw(10) << " Engleski " << setw(10) << " Njemacki " << setw ( 10 ) << " Matematika " << endl;
         cout << setiosflags (ios::left) << setw (5) << m[i].rezultat << "   " << setw(10) << m[i].ime << setw(10) << m[i].prezime
              << setw(10) << m[i].razred << setw(10) << m[i].predmet.engleskiUspjeh << setw(10) << m[i].predmet.njemackiUspjeh
              << setw(10) << m[i].predmet.matematikaUspjeh << endl;
         cout << endl;
         BOOL = 1 ;
      }
   }
   if(BOOL == 0 ){
      cout << " --- Ovdje nema informacija koje zelite provjeriti! --- " << endl;
   }
}
void pretragaPoImenu(){
   prikaz();
   string a;
   cout << " Upisite ime koje zelite: " << endl;
   cin >> a;
   int BOOL=0 ;
   for( int i=0 ; i<n; i++){
      if(a == m[i].ime){
         cout << setiosflags (ios::left) << setw(2) << " Broj ucenika " << "    " << setw(10) << " Ime " << setw(10) << " Prezime "
              << setw(10) << " Razred " << setw(10) << " Engleski " << setw(10) << " Njemacki " << setw ( 10 ) << " Matematika " << endl;
         cout << setiosflags (ios::left) << setw (5) << m[i].rezultat << "   " << setw(10) << m[i].ime << setw(10) << m[i].prezime
              << setw(10) << m[i].razred << setw(10) << m[i].predmet.engleskiUspjeh << setw(10) << m[i].predmet.njemackiUspjeh
              << setw(10) << m[i].predmet.matematikaUspjeh << endl;
         cout << endl;
         BOOL = 1 ;
      }
   }
   if (BOOL == 0 ){
      cout << " --- Nema informacija o imenu koje trazite ili to ime ne postoji u sistemu! --- " << endl;
   }
}

void sacuvaj(){
	ofstream unos("student.txt", ios::out);
	if(!unos){
      cout << "Datoteka se ne moze otvoriti!" << endl;
      exit(1);
   }
   unos << e << endl;
   for(int i=0 ; i<e; i++){
      unos << m[i].rezultat << ' ';
      unos << m[i].ime << ' ';
      unos << m[i].prezime << ' ';
      unos << m[i].razred<< ' ';
      unos << m[i].predmet.engleskiUspjeh << ' ';
      unos << m[i].predmet.njemackiUspjeh << ' ';
      unos << m[i].predmet.matematikaUspjeh << ' ';
      unos << m[i].ukupanRezultat << ' ';
      unos << m[i].uspjeh << ' ';
      unos << endl;
   }
   unos. close ();
   cout << endl;
   cout << " --- Podaci su uspjesno sacuvani! --- " << endl;
}
void  pretragaPoPredmetu(){
   prikaz();
   string a;
   cout << " --- Unesite predmet koji trazite: --- " << endl;
   cout << " 1. Engleski " << endl;
   cout << " 2. Njemacki " << endl;
   cout << " 3. Matematika " << endl;
   cin >> a;
   cout << setiosflags (ios::left) << setw(2) << setw(10) << " Ime " << setw(10) << " Rezultat: " << endl;
   int BOOL = 0 ;
   for(int i=0 ; i<e; i++){
      if (a=="1"){
         cout << setiosflags (ios::left) << setw(5) << setw(10) << m[i].ime << setw(10) << m[i].predmet.engleskiUspjeh << endl;
         BOOL = 1 ;
      }else  if(a=="2"){
         cout << setiosflags (ios::left) << setw(5) << setw(10) << m[i].ime << setw(10) << m[i].predmet.njemackiUspjeh << endl;
         BOOL = 1 ;
      }else  if(a=="3"){
         cout << setiosflags (ios::left) << setw(5) << setw(10) << m[i].ime << setw(10) << m[i].predmet.matematikaUspjeh << endl;
         BOOL = 1 ;
      }
   }
   if (BOOL==0){
      cout << " --- Nema informacija koje ste trazili da provjerite! --- " << endl;
   }
}
void  sortUspjehEngleski(){
   char t1[20], t2[20];
   int t4, t5, t6;
   float t7;
   for(int i=0; i<e- 1; i++){
      for(int j=0; j<e-i-1; j++){
         if(m[j].predmet.engleskiUspjeh<=m[j+1].predmet.engleskiUspjeh){
            strcpy (t1, m[j].ime );
            strcpy (t2, m[j].razred);
            t4 = m[j].predmet.engleskiUspjeh;
            t5 = m[j].predmet.njemackiUspjeh;
            t6 = m[j].predmet.matematikaUspjeh;
            t7 = m[j].rezultat;
            strcpy (m[j].ime, m[j+1].ime);
            strcpy (m[j].razred, m[j+1].razred);
            m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
            m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
            m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
            m[j].rezultat = m[j+1].rezultat;
            strcpy (m[j+1].ime , t1);
            strcpy (m[j+1].razred , t2);
            m[j+1].predmet.engleskiUspjeh = t4;
            m[j+1].predmet.njemackiUspjeh = t5;
            m[j+1].predmet.matematikaUspjeh = t6;
            m[j+1].rezultat = t7;
         }
       }
   }
   prikaz();
   cout << " Sortiranje uspjesno! " << endl;
   cout << endl;
   sort();
}
void  sortUspjehNjemacki(){
   char t1[20], t2[20];
   int t4, t5, t6;
   float t7;
   for(int i=0; i<e- 1; i++){
      for(int j=0; j<e-i-1; j++){
         if(m[j].predmet.njemackiUspjeh<=m[j+1].predmet.njemackiUspjeh){
            strcpy (t1, m[j].ime );
            strcpy (t2, m[j].razred);
            t4 = m[j].predmet.engleskiUspjeh;
            t5 = m[j].predmet.njemackiUspjeh;
            t6 = m[j].predmet.matematikaUspjeh;
            t7 = m[j].rezultat;
            strcpy (m[j].ime, m[j+1].ime);
            strcpy (m[j].razred, m[j+1].razred);
            m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
            m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
            m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
            m[j].rezultat = m[j+1].rezultat;
            strcpy (m[j+1].ime , t1);
            strcpy (m[j+1].razred , t2);
            m[j+1].predmet.engleskiUspjeh = t4;
            m[j+1].predmet.njemackiUspjeh = t5;
            m[j+1].predmet.matematikaUspjeh = t6;
            m[j+1].rezultat = t7;
         }
       }
   }
   prikaz();
   cout << " Sortiranje uspjesno! " << endl;
   cout << endl;
   sort();
}
void  sortUspjehMatematika(){
   char t1[20], t2[20];
   int t4, t5, t6;
   float t7;
   for(int i=0; i<e- 1; i++){
      for(int j=0; j<e-i-1; j++){
         if(m[j].predmet.matematikaUspjeh<=m[j+1].predmet.matematikaUspjeh){
            strcpy (t1, m[j].ime );
            strcpy (t2, m[j].razred);
            t4 = m[j].predmet.engleskiUspjeh;
            t5 = m[j].predmet.njemackiUspjeh;
            t6 = m[j].predmet.matematikaUspjeh;
            t7 = m[j].rezultat;
            strcpy (m[j].ime, m[j+1].ime);
            strcpy (m[j].razred, m[j+1].razred);
            m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
            m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
            m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
            m[j].rezultat = m[j+1].rezultat;
            strcpy (m[j+1].ime , t1);
            strcpy (m[j+1].razred , t2);
            m[j+1].predmet.engleskiUspjeh = t4;
            m[j+1].predmet.njemackiUspjeh = t5;
            m[j+1].predmet.matematikaUspjeh = t6;
            m[j+1].rezultat = t7;
         }
       }
   }
   prikaz();
   cout << " Sortiranje uspjesno! " << endl;
   cout << endl;
   sort();
}
void  sortBroj(){
   char t1[20], t2[20];
   int t4, t5, t6;
   float t7;
   for(int i=0; i<e- 1; i++){
      for(int j=0; j<e-i-1; j++){
         if(m[j].rezultat<=m[j+1].rezultat){
            strcpy (t1, m[j].ime );
            strcpy (t2, m[j].razred);
            t4 = m[j].predmet.engleskiUspjeh;
            t5 = m[j].predmet.njemackiUspjeh;
            t6 = m[j].predmet.matematikaUspjeh;
            t7 = m[j].rezultat;
            strcpy (m[j].ime, m[j+1].ime);
            strcpy (m[j].razred, m[j+1].razred);
            m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
            m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
            m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
            m[j].rezultat = m[j+1].rezultat;
            strcpy (m[j+1].ime , t1);
            strcpy (m[j+1].razred , t2);
            m[j+1].predmet.engleskiUspjeh = t4;
            m[j+1].predmet.njemackiUspjeh = t5;
            m[j+1].predmet.matematikaUspjeh = t6;
            m[j+1].rezultat = t7;
         }
       }
   }
   prikaz();
   cout << " Sortiranje uspjesno! " << endl;
   cout << endl;
   sort();
}
void  sortUkupanRezultat1(){                  //najmanji ka najvecem
   char t1[20], t2[20];
   int t4, t5, t6;
   float t7;
   for(int i=0; i<e- 1; i++){
      for(int j=0; j<e-i-1; j++){
         if((m[j].predmet.engleskiUspjeh + m[j].predmet.njemackiUspjeh + m[j].predmet.matematikaUspjeh )>=(m[j+1].predmet.engleskiUspjeh + m[j+1].predmet.njemackiUspjeh + m[j+1].predmet.matematikaUspjeh )){
            strcpy (t1, m[j].ime );
            strcpy (t2, m[j].razred);
            t4 = m[j].predmet.engleskiUspjeh;
            t5 = m[j].predmet.njemackiUspjeh;
            t6 = m[j].predmet.matematikaUspjeh;
            t7 = m[j].rezultat;
            strcpy (m[j].ime, m[j+1].ime);
            strcpy (m[j].razred, m[j+1].razred);
            m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
            m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
            m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
            m[j].rezultat = m[j+1].rezultat;
            strcpy (m[j+1].ime , t1);
            strcpy (m[j+1].razred , t2);
            m[j+1].predmet.engleskiUspjeh = t4;
            m[j+1].predmet.njemackiUspjeh = t5;
            m[j+1].predmet.matematikaUspjeh = t6;
            m[j+1].rezultat = t7;
         }
       }
   }
   prikaz();
   cout << " Sortiranje uspjesno! " << endl;
   cout << endl;
   sort();
}
void  sortUkupanRezultat2(){                   //najveci ka najmanjem
   char t1[20], t2[20];
   int t4, t5, t6;
   float t7;
   for(int i=0; i<e- 1; i++){
      for(int j=0; j<e-i-1; j++){
         if((m[j].predmet.engleskiUspjeh + m[j].predmet.njemackiUspjeh + m[j].predmet.matematikaUspjeh )<=(m[j+1].predmet.engleskiUspjeh + m[j+1].predmet.njemackiUspjeh + m[j+1].predmet.matematikaUspjeh )){
            strcpy (t1, m[j].ime );
            strcpy (t2, m[j].razred);
            t4 = m[j].predmet.engleskiUspjeh;
            t5 = m[j].predmet.njemackiUspjeh;
            t6 = m[j].predmet.matematikaUspjeh;
            t7 = m[j].rezultat;
            strcpy (m[j].ime, m[j+1].ime);
            strcpy (m[j].razred, m[j+1].razred);
            m[j].predmet.engleskiUspjeh = m[j+1].predmet.engleskiUspjeh;
            m[j].predmet.njemackiUspjeh = m[j+1].predmet.njemackiUspjeh;
            m[j].predmet.matematikaUspjeh = m[j+1].predmet.matematikaUspjeh;
            m[j].rezultat = m[j+1].rezultat;
            strcpy (m[j+1].ime , t1);
            strcpy (m[j+1].razred , t2);
            m[j+1].predmet.engleskiUspjeh = t4;
            m[j+1].predmet.njemackiUspjeh = t5;
            m[j+1].predmet.matematikaUspjeh = t6;
            m[j+1].rezultat = t7;
         }
       }
   }
   prikaz();
   cout << " Sortiranje uspjesno! " << endl;
   cout << endl;
   sort();
}
void sort(){
   cout << "----------------------------------------------------------------------------\n";
   cout << "\t\tDobro dosli u program za sortiranje ucenika" << endl;
   cout << "----------------------------------------------------------------------------\n";
   cout << "* 1. Sortiranje prema rezultatima iz engleskog * " << endl;
   cout << "* 2. Sortiranje prema rezultatima iz njemackog * " << endl;
   cout << "* 3. Sortiranje prema rezultatima iz matematike * " << endl;
   cout << "* 4. Sortiranje prema broju ucenika * " << endl;
   cout << "* 5. Sortiranje prema ukupnom rezultatu od najmanjeg ka najvecem * " << endl;
   cout << "* 6. Sortiranje prema ukupnom rezultatu od najveceg ka najmanjem * " << endl;
   cout << "* 7. Izlaz iz programa * " << endl;
   cout << "----------------------------------------------------------------------------\n";
   cout << endl;
   cout << "*Odaberite funkciju koju zelite(1-7): * " << endl;
   int r;
   cin >> r;
   switch (r){
   case 1:
   	  system("cls");
      sortUspjehEngleski();
      system("pause");
	  system("cls");
      break;
   case 2:
   	  system("cls");
      sortUspjehNjemacki();
      system("pause");
	  system("cls");
      break;
   case 3:
   	  system("cls");
      sortUspjehMatematika();
      system("pause");
	  system("cls");
      break;
   case 4:
   	  system("cls");
      sortBroj();
      system("pause");
	  system("cls");
      break;
   case 5:
   	  system("cls");
      sortUkupanRezultat1();
      system("pause");
	  system("cls");
      break;
   case 6:
   	  system("cls");
      sortUkupanRezultat2();
      system("pause");
	  system("cls");
      break ;
   case 7:
      cout << " --- Izlaz na pocetnu stranicu! --- " << endl;
      return;
      break;
   default:
      cout << "GRESKA!" << endl;
      break;
   }
} 
void statistika(){                                         // 8. Statisticke informacije o uceniku, najveci rezultat, najmanji rezultat, prosjecan rezultat, varianca
   system("cls");
   float sume = 0, sumn=0, summ=0 ;
   static float sum=0 ;
   static float prosjek= 0 ;
   static float varianca= 0 ;
   int brojac=0;
   char max_razred[20], max_ime[20], min_razred[20], min_ime[20];
   float brojac1=0 , brojac2=0 , brojac3=0;
   float maxe=m[0].predmet.engleskiUspjeh, mine=m[0].predmet.engleskiUspjeh,                         // maksimum i minimum engleski
         pe,
         maxn = m[0].predmet.njemackiUspjeh, minn = m[0].predmet.njemackiUspjeh,                         
         pn,
         maxm = m[0].predmet.matematikaUspjeh, minm = m[0].predmet.matematikaUspjeh,                            
         pm,
         max_score = maxe + maxn + maxm,                  // Maksimalni ukupni rezultat
         min_score = mine + minn + minm,                  // Minimalni ukupni rezultat
         max_engleskiUspjeh = 0, max_njemackiUspjeh = 0, max_matematikaUspjeh = 0, max_rezultat,
         min_engleskiUspjeh = 0, min_njemackiUspjeh = 0, min_matematikaUspjeh = 0, min_rezultat;


   for(int i=1; i<e; i++){        // Maximum, mnimum, maximalni ukupni rezultat, minimalni ukupni rezultat, proracun ucenikovih rezultata
      if(mine>m[i].predmet.engleskiUspjeh){
         mine = m[i].predmet.engleskiUspjeh;
      }
      if(maxe<m[i].predmet.engleskiUspjeh){
         maxe = m[i].predmet.engleskiUspjeh;
      }
      if(minn>m[i].predmet.njemackiUspjeh){
         minn = m[i].predmet.njemackiUspjeh;
      }
      if(maxn<m[i].predmet.njemackiUspjeh){
         maxn = m[i].predmet.njemackiUspjeh;
      }
      if(minm>m[i].predmet.matematikaUspjeh){
         minm = m[i].predmet.matematikaUspjeh;
      }
      if(maxm<m[i].predmet.matematikaUspjeh){
         maxm = m[i].predmet.matematikaUspjeh;
      }
      /* Proracun maksimalne vrijednosti */
      
      if(max_score<(m[i].predmet.engleskiUspjeh + m[i].predmet.njemackiUspjeh + m[i].predmet.matematikaUspjeh)){
         max_score = m[i].predmet.engleskiUspjeh+ m[i].predmet.njemackiUspjeh + m[i].predmet.matematikaUspjeh;
         max_rezultat = m[i].rezultat;
         strcpy (max_ime, m[i].ime);
         strcpy (max_razred, m[i].razred);
         max_engleskiUspjeh = m[i].predmet.engleskiUspjeh;
         max_njemackiUspjeh= m[i].predmet.njemackiUspjeh;
         max_matematikaUspjeh = m[i].predmet.matematikaUspjeh;
        }
      /* Proracun minimalne vrijednosti */

      if(min_score<(m[i].predmet.engleskiUspjeh + m[i].predmet.njemackiUspjeh + m[i].predmet.matematikaUspjeh)){
         min_score = m[i].predmet.engleskiUspjeh + m[i].predmet.njemackiUspjeh + m[i].predmet.matematikaUspjeh;
         min_rezultat = m[i].rezultat;
         strcpy (min_ime, m[i].ime);
         strcpy (min_razred, m[i].razred);
         min_engleskiUspjeh = m[i].predmet.engleskiUspjeh;
         min_njemackiUspjeh= m[i].predmet.njemackiUspjeh;
         min_matematikaUspjeh = m[i].predmet.matematikaUspjeh;
        }
    }
   /* Proracun prolaznosti*/
   
   for(int j=0; j<e; j++){
      sume = sume + m[j].predmet.engleskiUspjeh;
      if(m[j].predmet.engleskiUspjeh>=60){
         ++brojac1;                                      //engleski rezultat
      }                 
      sumn = sumn + m[j].predmet.njemackiUspjeh;
      if(m[j].predmet.njemackiUspjeh>=60){
         ++brojac2;                                      //njemacki rezultat
      }            
      summ = summ + m[j].predmet.matematikaUspjeh;
      if(m[j].predmet.matematikaUspjeh>=60){
         ++brojac3;                                     //matematika rezultat
      }                  
   }
   pe = brojac1;          //Engleski rezultat se dodjeljuje pe
   pn = brojac;          //Njemacki rezultat se dodjeljuje pn
   pm = brojac;          //Matematika rezultat se dodjeljuje pm

   cout << "1. Izracunajte ukupan rezultat, prosjecan rezultat i varijansu ucenika " << endl;
   cout << "2. Izracunajte ukupni uspjeh za cijeli razred" << endl;
   int k;
   cin >> k;                 
   if(k==1){
      cout << " Upisite ID ucenika: " << endl;
      int t;
      cin >> t;
      for (int i=0 ; i<e; i++){
         if(t==m[i].rezultat){
            sum = m[i].predmet.engleskiUspjeh + m[i].predmet.njemackiUspjeh + m[i].predmet.matematikaUspjeh;
            prosjek = sum/3;
            varianca = ((m[i].predmet.engleskiUspjeh-prosjek) * (m[i].predmet.engleskiUspjeh-prosjek) +
                       (m[i].predmet.njemackiUspjeh-prosjek) * (m[i].predmet.njemackiUspjeh-prosjek) +
                       (m[i].predmet.matematikaUspjeh-prosjek) * (m[i].predmet.matematikaUspjeh-prosjek))/3;
            cout << " Ime: " << m[i].ime << "  Ukupan rezultat: " << sum<< " Prosjecan rezultat: " << prosjek << "  Varianca: " << varianca << endl;
            brojac++;
         }
      }
      if (brojac==0){
         cout << "GRESKA!!" << endl;
      }
   }else{         
      cout << "------------------------------------------------\n";                                                         //najveca i najniza prolaznost svakog predmeta
      cout << " 1. Engleski rezultati " << endl;
      cout << " 2. Njemacki rezultati" << endl;
      cout << " 3. Matematika rezultati " << endl;
      cout << " 4. Razred rezultati " << endl;
      cout << " 5. Izlaz " << endl;
      cout << "------------------------------------------------\n"; 
      cout << " Unesite broj funkcije koju zelite: " << endl;
      int r;
      cin >> r;
      switch (r){
      case 1:
      	 system("cls");
         cout << " Najveci rezultat na Engleskom: " << maxe << endl;
         cout << " Najnizi rezultat na Engleskom: " << mine << endl;
         cout << " Prosjecan rezultat cijelog razreda na Engleskom: " << sume/e << endl;
         cout << " Stopa prolaznosti: " << pe/e << endl;
         system("pause");
		 system("cls");
         break ;
      case 2:
      	 system("cls");
         cout << " Najveci rezultat na Njemackom: " << maxn << endl;
         cout << " Najnizi rezultat na Njemackom: " << minn << endl;
         cout << " Prosjecan rezultat cijelog razreda na Njemackom: " << sumn/e << endl;
         cout << " Stopa prolaznosti: " << pn/e << endl;
         system("pause");
		 system("cls");
         break ;
      case 3:
         cout << " Najveci rezultat na Matematici: " << maxm << endl;
         cout << " Najnizi rezultat na Matematici: " << minm << endl;
         cout << " Prosjecan rezultat cijelog razreda na Matematici: " << summ/e << endl;
         cout << " Stopa prolaznosti: " << pm/e << endl;
         system("pause");
	     system("cls");
         break ;
      case 4:
      	 system("cls");
         cout << " Najveci rezultat u razredu: " << max_score << endl;
         cout << " Njegove informacije: " << endl;
         cout << setiosflags (ios::left) << setw(2) << " Broj ucenika " << "    " << setw(10) << " Ime " << setw(10) << " Prezime "
              << setw(10) << " Razred " << setw(10) << " Engleski " << setw(10) << " Njemacki " << setw(10) << " Matematika " << endl;
         cout << setiosflags (ios::left) << setw(5) << max_rezultat<< "   " << setw(10) << max_ime << setw(10) << max_razred
              << setw(10) << max_engleskiUspjeh << setw(10) << max_njemackiUspjeh << setw(10) << max_matematikaUspjeh << endl;
         cout << "Najniži rezultat u cijelom razredu: " << min_score << endl;
         cout << " Njegove informacije: " << endl;
         cout << setiosflags (ios::left) << setw(2) << " Broj ucenika " << "    " << setw(10) << " Ime " << setw(10) << " Prezime "
              << setw(10) << " Razred " << setw(10) << " Engleski " << setw(10) << " Njemacki " << setw(10) << " Matematika " << endl;
         cout << setiosflags (ios::left) << setw(5) << min_rezultat<< "   " << setw(10) << min_ime << setw(10) << min_razred
              << setw(10) << min_engleskiUspjeh << setw(10) << min_njemackiUspjeh << setw(10) << min_matematikaUspjeh << endl;
        system("pause");
		system("cls");
         break ;
      case 5:
      	 system("cls");
         cout << " --- Izlaz --- " << endl;
         return ;
         break ;
      default:
         cout << "Greska!!" << endl;
         break ;
      }
   }
}
void ucitaj(){
   system("cls");
   cout << setiosflags (ios::left) << setw(2) << " Broj ucenika " << "    " << setw(10) << " Ime " << setw(10) << " Prezime "
              << setw(10) << " Razred " << setw(10) << " Engleski " << setw(10) << " Njemacki " << setw(10) << " Matematika " << endl;
   ifstream ispis("student.txt",ios::in);
   if(!ispis){
      cout << "Datoteka se ne moze otvoriti!"<<endl;
      exit(1);
   }
   ispis >> e;
   for( int i=0; i<e; i++){
      ispis >> m[i].rezultat;
      ispis >> m[i].ime;
      ispis >> m[i].prezime;
      ispis >> m[i].razred;
      ispis >> m[i].predmet.engleskiUspjeh;
      ispis >> m[i].predmet.njemackiUspjeh;
      ispis >> m[i].predmet.matematikaUspjeh;
      ispis >> m[i].ukupanRezultat;
      ispis >> m[i].uspjeh;
   }
}
void meni(){
	system("cls");
	cout << "----------------------------------------------------------------------------\n";
	cout << "\tDobro dosli u program za upravljanje postignucima ucenika\n";
	cout << "----------------------------------------------------------------------------\n";
	cout << "\t\t|Osnovne funkcije|" << endl;
	cout << "----------------------------------------------------------------------------\n";
	cout << "\n1. Pregled informacija o postignucima ucenika" << endl;
	cout << "\n2. Unos informacija o postignucima ucenika" << endl;
	cout << "\n3. Brisanje informacija o postignucima ucenika" << endl;
	cout << "\n4. Rezultati upita za informacije o ID-u ucenika" << endl;
	cout << "\n5. Rezultati upita za informacije o imenu ucenika" << endl;
	cout << "\n6. Rezultati upita za informacije o predmetu" << endl;
	cout << "----------------------------------------------------------------------------\n";
	cout << "\t\t|Ostale funkcije|" << endl;
	cout << "----------------------------------------------------------------------------\n";
	cout << "\n7. Sortiranje ocjena ucenika" << endl;
	cout << "\n8. Statistika uspjesnosti ucenika" << endl;
	cout << "\n9. Upisivanje rezultata ucenika u datoteku" << endl;
	cout << "\n0. Izlaz iz programa" << endl;
	cout << "----------------------------------------------------------------------------\n";
	cout << endl;
}
int main(){
	system("cls");
	system("color F1");
	registracija r;
	int n;
	bool registrovan=false;
	cout << "----------------------------------------------------------------------------------------\n";
	cout << "\t\t\n| Dobro dosli u program za evidenciju studenata i njihovog uspjeha! |\n\n";
	cout << "----------------------------------------------------------------------------------------\n";
	while(!registrovan){
		system("cls");
        cout << "\t--------------------------\n";
        cout << "\t|\tREGISTRACIJA\t |\n";
        cout << "\t--------------------------\n";
        cout << "Unesite username: ";
        cin >> r.username;
        cout << "Unesite password: ";
        cin >> r.password;
        cout << "\n\t----------------------------";
        cout << "\n\tRegistracija je uspjesna!";
        cout << "\n\t----------------------------\n";
        cout << "\n[ENTER] za nastavak!";
        cout << endl;
        registrovan=true;
        system("pause");
    }
    system("cls");
    cout << "\t----------------------------------\n";
    cout << "\t|\tMolimo vas prijavite se:\t | " << endl;
    cout << "\t----------------------------------\n";
    if(prijava(r.username,r.password)==1){
    	meni();
    	for(;;){
    	do{
    		cout << "Odaberite funkciju koju zelite(1-9): ";
    		cin >> n;
		}while(n<1 || n>9);
		switch(n){
			case 1:
				system("cls");
				prikaz();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				unos();
				sacuvaj();
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				brisanje();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				pretragaPoBroju();
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");
				pretragaPoImenu();
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				pretragaPoPredmetu();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				sort();
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				statistika();
				system("pause");
				system("cls");
				break;
			case 9:
				system("cls");
				sacuvaj();
				system("pause");
				system("cls");
				break;
			case 0:
				system("cls");
				cout << "\t\tHvala vam na koristenju programa!" << endl;
				break;
			default:
				break;
		}
		cout << endl;
	}
    }else{
	   registrovan=false;
    }
	return 0;
}
