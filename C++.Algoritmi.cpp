//Maximul si minimul, algoritmii cu min, max pot fi convertiti la max, min
@Dintre 2 varoabile
if (a>b) max=a; 
else max=b;  //tot asa putem afla si minimul
@Unumar mai mare de variabile
if(m > n)
        if(m > p)
            m = max;
        else
            max = p;
    else
        if(n > p)
            max = n;
        else
            max = p; //tot asa si cu minimul
@Un numar n de variabile 
initializarea cu prima valoare
Ex:
cin >> n >> x;
min = x;
for(int i =1 ; i < n ; i ++)
{
    cin >> x;
    if(x < min)
        min = x;
}
initializarea cu o valoare mare
Ex:
cin >> n;
min = 1<<30; //2^30 > 1000000000
for(int i =1 ; i <= n ; i ++)
{
    cin >> x;
    if(x < min)
        min = x;
}


//Determinarea cifrelor unui numar
Ex:
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n != 0) // cat timp n este nenul - mai are cifre
    {
        int uc = n % 10; //determinam ultima cifra a lui n
        cout << uc << " "; // prelucram ultima cifra
        n /= 10;    //  eliminam ultima cifra (trunchiem numarul)
    }
    return 0;
}
*In urma determinarii cifrelor lui n prin procedeul de mai sus, valoarea initiala a lui n se pierde – devine 0.
de ea, trebuie sa o copiem intr-o alta variabila.


//Construirea unui numar cu cifre date
Sa consideram urmatorul sir de cifre, in ordine: 2 8 5 3
Daca cifrele se adauga la sfarsit, procedam astfel:
R = 0
c = 2. R = 10 * R + c, adica R devine 10 * 0 + 2 = 2
c = 8. R = 10 * R + c, adica R devine 10 * 2 + 8 = 28
c = 5. R = 10 * R + c, adica R devine 10 * 28 + 5 = 285
c = 3. R = 10 * R + c, adica R devine 10 * 285 + 3 = 2853
Daca cifrele se insereaza la inceput, procedam astfel:
R = 0
c = 2. R = R + 1 * c, adica R devine 0 + 1 * 2 = 2
c = 8. R = R + 10 * c, adica R devine 2 + 8 * 10 = 82
c = 5. R = R + 100 * c, adica R devine 82 + 100 * 5 = 582
c = 3. R = R + 1000 * c, adica R devine 582 +1000 * 3 = 3582


//Cifra de control a unui numar
@Suma cifrelor:
Ex:
while (n>9)
{
    s=0;
    while (n>0)
    {
        s+=n%10;
        n/=10;
    }
    n=s;
}
@Trunchiere:
Ex:
while(n>9)
{
    n=n/10+n%10;
}
@Restul impartirii la 9:
Ex:
r=n%9;
if (r==0) 
    cc =  9; //Daca restul impartirii la 9 este 0
else
    cc = r;


//Daca n divide pe m, spunem ca n este divizor al lui m, iar m este multiplu al lui n.


//Divizorii unui numar
@Algoritmul naiv:
Ex:
int n;
cin >> n;
for(int d =1 ; d <= n ; d ++ )
    if(n % d == 0)
        cout << d << " "; 
@Observam ca pentru orice n, de la n/2 la n nu mai sunt divizori. Solutia acceptabila este sa observam ca divizorii oricarui numar n sunt in pereche,
daca d este divizor al lui n, atunci si n/d este divizor al lui n. Constatam ca este suficient sa parcurgem numerele de la 1 la radical din n.
Un caz special il constituie patratele perfecte. In cazul lor trebuie evitata analizarea de doua ori a lui radical din n, care este divizor al lui n.
Ex:
	Pentru 36:                                          Pentru 75:
	1 in pereche cu 36									1 este divizor 75, atunci si 75/1 = 75 este divizor al lui 75;
	2 in pereche cu 18									2 nu este divizor al lui 75
	3 in pereche cu 12									3 este divizor 75, atunci si 75/3 = 25 este divizor al lui 75;
	4 in pereche cu 9									4 nu este divizor al lui 75
	5 nu este divizor al lui 36							5 este divizor 75, atunci si 75/5 = 15 este divizor al lui 75;
	6 in pereche cu 6. 6 trebuie luat o singura data!	6 nu este divizor al lui 75
	7*7>36, ne oprim!									7 nu este divizor al lui 75
														8 nu este divizor al lui 75
														9 nu este divizor al lui 75. Mai mult, 9 * 9 > 75, alti divizori nu vom mai gasi.
Ex:
int n;
cin >> n;
for(int d=1;d*d<=n;d++)
    if(n%d==0){
        cout << d << " ";
        if(d*d<n) // daca d != sqrt(n)
           	cout << n / d <<" ";
    }
Singurele numere cu numar impar de divizori sunt patratele perfecte.
Cel mai mic divizor propriu al unui numar natural (diferit de 1 si de numarul insusi) este numar prim.


//CMMDC
Fie a si b doua numere naturale. Un numar natural d se numeste cel mai mare divizor comun (pe scurt cmmdc) al lui a si b daca indeplineste conditiile
d|a si d|b(d divide b);
daca c|a si c|b, atunci c|d.
Cel mai mare divizor comun al numerelor a si b se noteaza (a,b) sau gcd(a,b) – greatest common divisor.
Daca (a,b)=1, spunem ca a si b sunt prime intre ele sau relativ prime, sau ca a este prim cu b.
Cel mai mare divizor comun al numerelor naturale are proprietatile:
((a,b),c)=(a,(b,c)),pentru orice a,b,c apartine numerelor naturale
(a,b)=1,(a,c)=1 rezulta (a,bc)=1
a|bc si (a,b)=1 rezulta a|c
a|c,b|c si (a,b)=1 rezulta ab|c
Algoritmul lui Euclid cu scaderi se bazeaza pe ideea ca cele mai mare divizor a doua numere divide si diferenta acestora. Algoritmul este:
Cat timp numerele sunt diferite, se scade numarul mai mic din numarul mai mare.
Cand numerele devin egale, valoare comuna este cel mai mare divizor comun al valorilor initiale.
Algoritmul nu poate fi aplicat daca unul dintre numere este 0.
Ex:
int n , m;
cin >> n >> m;
while(n != m)
    if(n > m)
        n -= m;
    else
        m -= n;
    cout << n << endl;
Algoritmul lui Euclid cu impartiri se bazeaza pe ideea ca cel mai mare divizor a doua numere divide si restul impartirii acestora, conform teoremei impartirii cu rest. Algoritmul este:
Cat timp m != 0:
Determinam restul impartirii lui n la m.
In continuare n devine m, iar m devine restul calculat.
Valoarea actuala a lui n este cel mai mare divizor comun a valorilor initiale
Ex:
int n , m;
cin >> n >> m;
while(m != 0){
    int r = n % m;
    n = m;
    m = r;
}
cout << n << endl;
}


//CMMMC
Cel mai mic multiplu comun al numerelor a si b se noteaza [a,b] sau lcm(a,b) – least common multiple.
Observatie: Produsul a doua numere naturale nenule este egal cu produsul dintre cel mai mare divizor comun al lor si cel mai mic multiplu comun al lor.
a·b=(a,b)·[a,b]
a·b=gcd(a,b)·lcm(a,b)
Determinarea cmmmc folosind un algoritm de tip Euclid:
Fie a si b valorile date. Vom construi valorile m si n, astfel:
initial n = a, m = b;
cat timp m != n:
daca m < n, atunci m creste cu valoarea lui a: n = n + a
daca m > n, atunci n creste cu valoarea lui b: m = m + b
valoarea finala, comuna, a lui n si m este cel mai mic multiplu comun pentru a si b
Observatie: Algoritmul poate fi aplicat similar pentru trei sau mai multe numere!
Ex:
int n, m, a, b;
cin>>a>>b;
n=a; m=b;
while (m!=n)
if (n<m) n+=a;
else if (m<n) m+=b;
cout<<n;


//Determinarea numarului prim
Pentru a stabili daca un numar p este prim:
-numaram divizorii sai. Daca sunt 2 divizori, p este prim.
-determinam suma divizorilor. Daca suma este p + 1, numarul este prim.
-cautam divizori ai sai diferiti de 1 si de el insusi. Daca nu gasim, numarul este prim.
Ex:
int n;
cin >> n;
bool prim = true; 
if(n < 2)
	prim = false; 
for(int d =2 ; d * d <= n ; d ++)
   	if(n % d == 0) {
       	prim = false;
       	break;
   }
if(prim)
	cout << n << " este prim";
else
	cout << n << " nu este prim";
	
	
//Descompunerea in factori primi
Ex:
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int d = 2,  // d va fi, pe rand, fiecare factor prim din descompunere
        p;      // p va fi puterea lui d in descompunere
    // il  im partim pe n la d in mod repetat, pana cand devine 1
    while(n > 1)
    {
        // numaram de cate ori se imparte n la d. Aceasta va fi puterea lui d in descompunere
        p = 0;
        while(n % d == 0)
        {
            ++p;
            n /= d;
        }
        // daca s-a facut cel putin o impartire, afisam factorul si puterea
        if(p)
            cout << d << " " << p << endl;
        ++ d;
        //  daca d * d il depaseste pe n si n nu este 1, decidem ca n este prim,
        //  si este factor in descompunerea valorii initiale a lui n
        if(n>1 && d * d > n){
            d = n; // trecem direct la n, urmatorul factor din descompunere
        }
    }
    return 0;
}


//Aplicatii ale descompuneri in factori primi
Orice numar natural n mai mare decat 1 se poate scrie in mod unic sub forma n=p1e^1*p2^e2*...*pk^ek, unde p1<p2<...<pk sunt numere prime, iar ei>0,i=1...k;
@Numarul de divizori
Proprietate: Pentru un numar natural care are descompunerea in factori primi: n=p1^e1*p2^e2*...*pk^ek, numarul de divizori este: (e1+1)*(e2+1)*...*(ek+1).
Exemplu: Fie n=12. Divizorii sunt 1,2,3,4,6,12 – 6 divizori.
Descompunerea in factori este: n=12=2^2*3^1.
Aplicand formula de mai sus obtinem (2+1)*(1+1)=3*2=6.
@Suma divizorilor
Proprietate: Pentru un numar natural care are descompunerea in factori primi:n=p1^e1*p2^e2*...*pk^ek, suma divizorilor este: 
(p1^(e1+1)-1)/(p1-1)*(p2^(e2+1)-1)/(p2-1)*...*(pk^(ek+1)-1)/(pk-1).
Exemplu:
Fie n=12. Suma divizorilor este 1+2+3+4+6+12=28.
Descompunerea in factori este: n=12=2^2*3^1.
Aplicand formula de mai sus obtinem (2^(2+1)-1)/(2-1)*(3^(1+1)-1)/(3-1)=28.
@Indicatorul lui Euler: https://www.pbinfo.ro/articole/67/aplicatii-ale-descompunerii-in-factori-primi


//Sirul Fibonacci
@Reprezantare
Ex:
int a, b, c, n;
cout<<"Numarul de numere Fibonacci: "; cin>>n;
a=1; b=1;
if (n==1) cout<<a;
if (n==2) cout<<a<<" "<<b;
if (n>=3){
    cout<<a<<" "<<b<<" ";
    for (int i=3;i<=n;i++){
    	c=a+b;
    	cout<<c<<" ";
    	a=b; b=c;
	}
}


//Sortarea vectorului prin booble sort
@De la 1 la n(lungimea vectorului);
Ex:
bool sortat;
int k=n;
do{
sortat=1;
int l=k;
for(int i=1;i<l;i++)
    if(a[i]>a[i+1]){
      	swap(a[i],a[i+1]);
      	sortat=0;
      	k=i;
    }
}
while(!sortat);
@De la 0 la n-1(n - lungimea vectorului)
Ex:
bool sortat;
int k = n-1;
do
{
sortat = 1;
int l = k;
for(int i = 0 ; i < l ; i ++)
    if(a[i] > a[i+1]){
      	swap(a[i], a[i+1]);
      	sortat = 0;
      	k = i;
    }
}
while(!sortat);


//Sortarea vectorului prin selectie
@De la 0 la n-1:
Ex:
	for(int i=0;i<n-1;i++){
    	int k=i;
    	for(int j=i+1;j<n;j++)
        	if(a[j]<a[k])
            	k=j;
    	swap(a[i],a[k]);
	}
@De la 1 la n:
Ex:
	for(int i=1;i<n;i++){
    	int k=i;
    	for(int j=i+1;j<=n;j++)
        	if(a[j]<a[k])
            	k=j;
    	swap(a[i],a[k]);
	}


//Sortarea vectorului prin insertie
@De la 0 la n-1:
Ex:
	for (int i=1;i<n;i++){
    int k=i;
    while (k>0 && a[k]<a[k-1]){
    	swap(a[k],a[k-1]);
        k--;
    }
@De la 1 la n:
Ex:
	for (int i=2;i<=n;i++){
    int k=i;
    while (k>1 && a[k]<a[k-1]){
    	swap(a[k],a[k-1]);
        k--;
    }
    
    
//Functia sort
@Ordonare crescatoare:
*Functia sort permite sortarea unei secvente a tabloului. Pentru a sorta in tabloul A secventa delimitata de indicii s si d (inclusiv acettia), se face apelul:
Ex:
	sort(A + s, A + d + 1);
*Daca se doreste sortarea unui tablou A cu n elemente, indexate de la 0 la n-1, apelul va fi:
Ex:
	sort(A, A + n);
*Daca tabloul este indexat de la 1 la n, apelul va fi:
Ex:
	sort(A + 1, A + n + 1);
@Ordonare descrescatoare:
*Pentru a sorta descrescator elementele secventei delimitate de indicii s si d in tabloul A cu elemente de tip int, se transmite functiei sort un parametru suplimentar, astfel:
Ex:
	sort(A + s, A + d + 1, greater<int>());
*Daca elementele tabloului A sunt de tip double, apelul va fi:
Ex:
	sort(A + s, A + d + 1, greater<double>());
@Ordonarea dupa alte criterii:
	https://www.pbinfo.ro/articole/10743/stl-sort
@STL vector sortare:
Ex:
sort(P[i].begin() , P[i].end());


//Interclasarea tablourilor
@De la 0 la n-1 elemente
Ex:
//citirea tabourilor a[] cu n elemete si b[] cu m elemtente
	int i=0, j=0;
	p=0;
	while(i<n && j<m)
    	if(a[i]<b[j])
        	c[p++]=a[i++];
    	else
        	c[p++]=b[j++];
	while(i<n)
    	c[p++]=a[i++];
	while(j<m)
    	c[p++]=b[j++];
@De la 1 la n elemente
Ex:
//citirea tabourilor a[] cu n elemete si b[] cu m elemtente
	int i=1, j=1;
	p=1;
	while(i<=n && j<=m)
    	if(a[i]<b[j])
        	c[p++]=a[i++];
    	else
        	c[p++]=b[j++];
	while(i<=n)
    	c[p++]=a[i++];
	while(j<=m)
    	c[p++]=b[j++];


//Secvente in vectori
Exemplu de cautare a celei mai mari secvente de numere impare:
@De la 0 la n-1 elemente:
Ex:
//Citire a[] cu n elemente
	int smax=1, dmax=0;
	for(int i=0;i<n;i++)
    	if(a[i]%2==1)
    	{
        	int j=i;
        	while(j+1<n && a[j+1]%2==1)
            	j++;
        	if(j-i+1>dmax-smax+1)
            	smax=i, dmax=j;
        	i=j;
    	}
    for(int i=smax;i<=dmax;i++) cout<<a[i]<<" ";
@De la 1 la n elemente:
Ex:
//Citire a[] cu n elemente
	int smax=2, dmax=1;
	for(int i=1;i<=n;i++)
    	if(a[i]%2==1)
    	{
        	int j=i;
        	while(j+1<=n && a[j+1]%2==1)
            	j++;
        	if(j-i+1>dmax-smax+1)
            	smax=i, dmax=j;
        	i=j;
    	}
    for(int i=smax;i<=dmax;i++) cout<<a[i]<<" ";
    
    
//Sume partiale in tablouri
De la 1 la n+1 elemente a tabloului:
@Vector:
Ex:
	int n;
	cout<<"n="; cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
	int st, dr;
	cout<<"st="; cin>>st;
	cout<<"dr="; cin>>dr;
	long long int s[n+1];
	s[0]=0;
	for(int i=1;i<=n;i++)
    	s[i]=s[i-1]+a[i];
	cout<<"Suma secventei="<<s[dr]-s[st-1];
@Matrice:
Ex:
	//Se include biblioteca <iomanip>
	int n,m;
	cout<<"n(randuri)="; cin>>n;
	cout<<"m(coloane)="; cin>>m;
	int a[n+1][m+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}
	cout<<"Avem matricea:"<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<setw(8)<<left<<a[i][j];
		cout<<endl;
	}
	int is, js, ij, jj; 
	cout<<"is="; cin>>is;
	cout<<"js="; cin>>js;
	cout<<"ij="; cin>>ij;
	cout<<"jj="; cin>>jj;
	long long int s[n+1][m+1];
	for(int i=0;i<=n;i++)
    	s[i][0]=0;
	for(int j=0;j<=m;j++)
    	s[0][j]=0;
	for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
        	s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	cout<<"Suma submatricei="<<s[ij][jj]-s[is-1][jj]-s[ij][js-1]+s[is-1][js-1];
	
	
//Secventa de suma maxima algoritmul optimal O(n)
Tablou de la 1 la n+1 elemente:
Ex:
	int st, dr, Smax=-2147483648, S=-1, start, n;
	cout<<"n="; cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cout<<"a["<<i<<"]=";
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
    	if(S<0)
        	S=0, start=i;
    	S+=a[i];
    	if(S>Smax)
        	Smax=S, st=start, dr=i;
	}
	cout<<"Suma secventei de sume maxime= "<<Smax<<"\n";
	cout<<"Secventa: "<<st<<" "<<dr;
Solutia de mai sus poate fi utilizata pentru valori mai mari ale lui n, de exemplu 100000 sau 1000000. De asemenea, poate fi usor modificata incat sa se evite folosirea tabloului,
determinand rezultatul direct din citire. Astfel, complexitatea spatiu a algoritmului devine O(1).


//Smenul lui Mars - Difference Array
Tablou cu elemente de la 1 la n+1;
Ex:
	int n;
	cout<<"n="; cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cout<<"a["<<i<<"]=", cin>>a[i];
	int b[n+1];
	b[1]=a[1];
	for(int i=2;i<=n;i++)
		b[i]=a[i]-a[i-1];
	int s, d, x;
	cout<<"s="; cin>>s; //indicile de stanga
	cout<<"d="; cin>>d; //indicile de dreapta
	cout<<"x="; cin>>x; //valoarea cu care se va creste elementele de secventa s d
	b[s]+=x;
	b[d+1]-=x;
	a[1]=b[1];
	for(int i=2;i<=n;i++)
		a[i]=a[i-1]+b[i];
	cout<<"Tabloul cu secventa modificata: \n";
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
		
		
//Cautarea binara
@Metoda iterativa:
Tablou de la 1 la n+1 el.:
Ex:
	int n;
	cout<<"n="; cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cout<<"a["<<i<<"]=", cin>>a[i]; //Tabloul trebuie sa fie strict crescator
	int x; cout<<"x="; cin>>x; //Elementul care trebuie gasit
	int st=1, dr=n, poz=0, m;
	while(st<=dr && poz==0){
		m=(st+dr)/2;
		if(x==a[m])
			poz=m;
		else
			if(x>a[m])
				st=m+1;
			else
				dr=m-1;
	}
	if(poz!=0)
		cout<<x<<" are pozitia "<<poz;
	else
		cout<<x<<" nu exista in tablou";
@Metoda recursiva(Divide et impera):
Ex:
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}


//Vector caracteristic, vecetorul ce pastreaza aparitiile cifrelor dintrun sir dat
Avem vectorii caracteristici v[] si u[], care indica aparitiile elemetelor unui tablou in problema: Se dau doua siruri de cifre zecimale(0...10). 
Sa se determine cifrele comune, in ordine crescatoare.
Tabloul de la 0 la n elemente;
Ex:
	int n; cout<<"n="; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cout<<"a["<<i<<"]=", cin>>a[i];//se citesc elemente de la 1 la 9
	int m; cout<<"m="; cin>>m;
	int b[n];
	for(int i=0;i<m;i++)
		cout<<"b["<<i<<"]=", cin>>b[i];//se citesc elemente de la 1 la 9
	while(n>=0 || m>=0){
		if(n>=0)
			v[a[n-1]]=1;
		if(m>=0)
			u[b[m-1]]=1;
		n--;
		m--;
	}
	for(int i=0;i<=9;i++)
		cout<<v[i]<<" "<<u[i]<<"\n";
	//Aparitiile elementelor comune in ordine crescatoare
	for(int i=0;i<=9;i++)
		if(v[i] && u[i])
			cout<<i<<" ";
			
			
//Vector de frecventa
Sa consideram din nou un sir de cifre zecimale. Sa se determine cifra care apare de cele mai multe ori. Daca sunt mai multe cifre care apar de numar maxim de ori,
sa se determine cea mai mica (sau cea mai mare, sau toate, etc.). 
De aceasta data nu putem folosi un vector caracteristic, dar putem folosi un vector de frecventa, adica un vector cu acelasi numar de
elemente ca numarul posibil de valori distincte din sirul dat (adica 10), cu semnificatia: v[c] =  numarul de aparitii ale cifrei c in sirul dat.
Dupa construirea acestui vector, valoarea maxima din el va reprezenta numarul maxim de aparitii ale unei cifre, iar indicii pentru care
elementul corespunzator are valoare maxima reprezinta cifrele care apar de numar maxim de ori.


//Ciurul lui Eratostene
Ex:
void sieve() {
	int n;
	cin >> n;
	vector<bool> p(n + 1);
	p[1] = p[0] = 1;
	for(int i = 2; i * i <= n; i ++) {
		if(p[i] == 0)
			for(int m = i * i; m <= n; m += i)
				p[m] = 1;
	}
	int cnt = 0;
	for(int i = 2; i <= n; i ++)
		if(p[i] == 0)
			cout << i << " ", cnt ++;
	cout << "\n" << cnt;
}

void sieve_divisors() {
	int n;
	cin >> n;
	vector<int> p(n + 1), v[n + 1];
	p[0] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int m = i; m <= n; m += i)
			p[m] ++, v[m].push_back(i);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i ++) {
		cout << i << " " << p[i] << ":\n";
		for(auto x : v[i])
			cout << x << " ";
		cout << "\n";
	}
}
			
			
//Numarul de divizori prin ciurul lui Eratostene
*construim un vector Nr[]. La final, Nr[x] va fi numarul de divizori ai lui x;
*initializam elementele vectorului Nr[] cu 0;
*parcurgem vectorul si pentru fiecare element Nr[i] marim valorile elementelor Nr[k], unde k = i * j este multiplu al lui i – daca i este divizor al lui k, atunci trebuie numarat 
ca atare.
OBS: Un numar x este prim daca si numai daca la final Nr[x] este egal cu 2.
Ex:
	int n;
	cout<<"n="; cin>>n;
	int Nr[n+1];
	for(int i=1;i<=n;i++)
		Nr[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j*i<=n;j++)
			Nr[i*j]++;
	cout<<"Numarul de divizori="<<Nr[n];


//Suma divizorilor prin ciurul lui Eratostene
*construim un vector S[]. La final, S[x] va reprezenta suma divizorilor lui x;
*initializam elementele vectorului S[] cu 0;
*parcurgem vectorul si pentru fiecare element S[i] marim valorile elementelor S[k] cu i, unde k = i * j este multiplu al lui i –
daca i este divizor al lui k, atunci trebuie adunat la suma divizorilor lui k.
OBS: Un numar x este prim daca si numai daca la final S[x] este egal cu x+1.
Ex:
	int n;
	cout<<"n="; cin>>n;
	int Nr[n+1];
	for(int i=1;i<=n;i++)
		Nr[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j*i<=n;j++)
			Nr[i*j]+=i;
	cout<<"Suma divizorilor="<<Nr[n];
	
	
//Cel mai mic divizor prim prin ciurul lui Eratostene
*construim un vector M[]. La final, M[x] va reprezenta cel mai mic divizor (factor) prim al lui x;
*initializam elementele vectorului M[x] cu x – pentru numerele prime cel mai mic factor prim sunt ele insele;
*parcurgem numerele incepand de la 2 si pentru fiecare numar i prim (pentru care M[i] = i) modificam, daca este cazul, cel mai mic factor prim pentru toti multipli k = i * j lui i.
Un numar x este prim daca si numai daca la final M[x] este egal cu x.
Ex:
	int n;
	cout<<"n="; cin>>n;
	int M[n+1];
	for(int i=1;i<=n;i++)
		M[i]=i;
	for(int i=2;i<=n;i++)
		if(M[i]==i)
			for(int j=2;j*i<=n;j++)
				if(M[i*j]==i*j)
					M[i*j]=i;
	cout<<"Cel mai mic divizor prim="<<M[n]; //1 nu are divizori primi


//Cel mai mare divizor prim prin ciurul lui Eratostene
*La parcurgerea multiplilor lui i, vom modifica multiplul k = i * j numai daca M[k] este inca k. De exemplu, pentru i=3, nu-l mai modifica pe M[6] – a fost deja modificat pentru i=2.
*Daca modificam M[k] de pentru fiecare i, deoarece i este considerat in ordine crescatoare, la final M[k] va memora cel mai mare
 va memora cel mai mare divizor prim al lui k. Urmatoarea secventa obtine acest rezultat – observati ca modificarile sunt minore:
Ex:
	int n;
	cout<<"n="; cin>>n;
	int M[n+1];
	for(int i=1;i<=n;i++)
		M[i]=i;
	for(int i=2;i<=n;i++)
		if(M[i]==i)
			for(int j=2;j*i<=n;j++)
				M[i*j]=i;
	cout<<"Cel mai mare divizor prim="<<M[n]; //1 nu are divizori primi
	
	
//Indicatorul lui Euler
Indicatorul lui Euler sau functia lui Euler, sau totient se noteaza cu fi(n) (unde n este un numar natural nenul )
si reprezinta numarul de numere mai mici sau egale cu n si prime cu acesta.
*Proprietate: Pentru un numar natural n care are descompunerea in factori primi: n=p1^e1*p2^e2*...*p^kek, are loc relatia: fi(n)=(p1-1)*p1^(e1-1)*(p2-1)*p2^(e2-1)*...*(pk-1)*pk^(ek-1).
*O scriere echivalenta este:  fi(n)=n*(1-(1/p1))*(1-(1/p2))*...*(1-(1/pk)) sau fi(n)=n*((p1-1)/p1)*((p2-1)/p2)*...*((pk-1)/pk);
*Observatie: Daca n este numar prim, atunci f(n)=n-1.
@Urmatoarea functie se bazeaza pe formula de mai sus si pe algoritmul descompunerii in factori primi, el determina indicatorul lui Euler:
Ex:
int phi(int n)
{
    int r = n , d = 2;
    while(n > 1)
    {
        if(n % d == 0)
        {
            r = r / d * (d - 1);
            while(n % d == 0)
                n /= d;
        }
        d ++;
        if(d * d > n)
            d = n;
    }
    return r;
}
@Algoritmul de tip euclid:
Ex:
int F[DIM + 1];
for(int i = 1 ; i <= DIM ; i ++)
    F[i] = i;
for(int i = 2;  i <= DIM ; i ++)
    if(F[i] == i)
    {
        F[i] --;
        for(int j =2 ; j * i <= DIM ; j ++)
            F[j * i] = F[j * i] / i * (i - 1);
    }


//Initializarea numerelor mari
Vom folosi in acest scop un vector, care sa contina pe prima pozitie v[0] lungimea numarului mare (numarul de cifre), iar pe pozitiile 1, 2, ... , v[0] vom memora cifrele numarului, 
in ordine inversa.
Ex:
	//Avem numarul 15207
   i  0  1  2  3  4  5  6  7 
v[i]  5  7  0  2  5  1  0  0 	
ATENTIE! Este important ca v[0] sa memoreze corect lungimea numarului, fara a fi luate in considerare zerourile nesemnificative (cele de la inceputul numarului, respectiv sfarsitul 
vectorului).
Pentru rezolvarea problemei vom defini tipul NrMare, pentru a clarifica operatiile care urmeaza.
Ex:
typedef int NrMare[1010];
Un numar mare se poate initializa cu alt numar mare sau cu un numar mic – adica un numar ce face parte dintr-un tip de date intreg predefinit; in cele ce urmeaza, il vom considera int.
Ex:
void AtribMic(NrMare x, int n)
{
  x[0]=0;
  if(n==0)
    x[(x[0]=1)]=0;
  else
    for(;n;n/=10)
      x[++x[0]]=n%10;
}

void AtribMare(NrMare Dest, NrMare Sursa)
{
  int i;
  for(i=0;i<=Sursa[0];i++)
    Dest[i]=Sursa[i];
}


//Compararea numerelor mari
*daca un numar are mai multe cifre decat celalalt, este mai mare;
*daca nu, se compara cifrele incepand cu cele mai semnificative, pana la capat (in cazul egalitatii) sau pana se deduce relatia
dintre cele doua numere. Aici este foarte importanta corectitudinea numarului de cifre (memorata in v[0]).
Functia care urmeaza compara doua numere mari, returnand 0 daca numerele sunt egale, -1 daca primul este mai mic decat al doilea si 1 in cealalta situatie.
Ex:
int Compara(NrMare x, NrMare y)
{
  while(x[0]>1 && x[x[0]]==0)
    x[0]--; //ma asigur ca nu sunt zerouri nesemnificative
  while(y[0]>1 && y[y[0]]==0)
    y[0]--;
  if(x[0]!=y[0])
    return (x[0]<y[0]?-1:1);
  int i=x[0];
  while(x[i]==y[i] && i>0) 
    i--;
  if(i==0)
    return 0;
  if(x[i]<y[i])
    return -1;
  return 1;
}


//Adunarea numerelor mari
*Urmatoarele functii realizeaza de fapt atribuirea A = A + B, dar poate fi realizat si A = B + C sau altceva.
Algoritmul de adunare este cel folosit la adunarea numerelor pe hartie: se aduna cifrele corespunzatoare intre ele si cu eventualul	
transport. Daca suma este mai mare decat 10, aflam cifra corespunzatoare si recalculam transportul.
Ex:
void Adunare(NrMare x,NrMare y)
// x = x + y
{
  int i,t=0;
  if(x[0]<y[0]) 
    x[0]=y[0];
  for(i=1;i<=x[0];i++,t/=10)
  {
    t=x[i]+y[i]+t;
    x[i]=t%10;
    // echivalent x[i]=(t+=x[i]+y[i])%10
  }
  if(t)
    x[++x[0]]=t;
}


//Scaderea numerelor mari
In cazul scaderii A = A - B, se considera ca A este mai mare sau egal cu B, chestiune ce poate fi verificata cu ajutorul functiei descrise mai sus.
Scaderea se face si ea la fel ca pe hartie.
Ex:
void Scadere(NrMare x, NrMare y)
// x <-- x-y
{
  int i,j, t = 0;
  for (i = 1; i <= x[0]; i++)
    if(x[i]>=y[i]) 
      x[i]-=y[i];
    else
    {
      j=i+1;
      while(x[j]==0)
        x[j++]=9;
      x[j]--;
      x[i]=10+x[i]-y[i];
    }
  for (; x[0] > 1 && !x[x[0]]; x[0]--); // sa n-am zerouri nesemnificative
}


//Tablouri patratice
https://www.pbinfo.ro/articole/5626/tablouri-patratice


//Factorial. Zerouri factorial
https://www.pbinfo.ro/articole/10944/factorial


//Functii
@Caracterul & inainte de parametrul formal:
*Acesta transforma parametrul formal intr-un alias al parametrului actual, iar modificarile facute asupra parametrului formal n au loc de fapt asupra parametrului actual k din main;
Ex:
#include <iostream>
using namespace std;
void N(int & x){
	x ++;
}
int main(){
	int n;
	cin >> n;
	N(n);
	cout << n;
}
* In cazlu tablourilor nu e nevoie de &, schimbarile si asa se produc. Pe langa asta toate variantele de mai jos sunt corecte:
Ex:
void afisare(int n, int  x[]); // nu se precizeaza dimensiunea reala a tabloului
void afisare(int n, int  x[10]); // se precizeaza dimensiunea reala a tabloului
void afisare(int n, int  *x); // parametrul este un pointer la tipul elementelor tabloului
@Pentru un tablou multidimensional, regula este ca prima dimensiune a parametrului nu trebuie sa fie in concordanta cu cea a parametrului actual.
Toate celelalte dimensiuni ale parametrului formal trebuie sa fie identice cu dimensiunile corespunzatoare ale parametrului actual.
De exemplu, pentru o matrice urmatoarele secvente sunt corectet:
Ex:
void F(int n, int m, int A[][25]); //prototipul functiei
...
int n , m , A[25][25]; //declaratii de variabile
F(n,m,A); //apelul functiei
sau
Ex:
void F(int n, int m, int A[25][25]); //prototipul func?iei
...
int n , m , A[25][25]; //declaratii de variabile
F(n,m,A); //apelul functiei
*Urmatoare secventa este insa gresita, deoarece a doua dimensiune a parametrului actual (numarul de coloane) nu corespunde cu cea a parametrului formal:
Ex:
void F(int n, int m, int A[][25]); //prototipul func?iei
...
int n , m , A[20][20]; //declaratii de variabile
F(n,m,A); //apelul functiei


//Functii cu parametru implicit, variabile statice, functii cu acelasi nume
https://www.pbinfo.ro/articole/3667/mai-mult


//Algoritmul FILL recursiv
Ex:
#include <iostream>
using namespace std;
const int di[]={-1, 0, 1, 0},
          dj[]={ 0, 1, 0,-1};
int A[101][101], n , m, istart , jstart;
void Fill(int i ,int j ,int v){
    // i,j - elementul curent, v - valoarea cu care facem Fill
    if(i >= 1 && i <= n && j >= 1 && j <= m && A[i][j] == 0)
    {   // in matrice, element liber si nemarcat
        A[i][j] = v;
        for(int k = 0 ; k < 4 ; k ++)
            Fill(i + di[k] , j + dj[k], v);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ;i ++)
        for(int j = 1 ; j <= m ; j ++)
            cin >> A[i][j];
    cin >> istart >> jstart;
    Fill(istart, jstart, 2);
    for(int i =1 ; i <= n ;i ++, cout << endl)
        for(int j = 1; j <= m ; j ++)
            cout << A[i][j] << " ";
    return 0;
}


//Algoritmul FILL cu coada simulata prin tablou
Ex:
const int di[]={-1, 0, 1, 0},
          dj[]={ 0, 1, 0,-1};
int A[101][101], n , m, istart , jstart;
struct Coordonate{
    int linie, coloana;
};
Coordonate Q[100 * 100 + 1];
void Fill(int istart ,int jstart ,int v){
    int st = 1 , dr = 0;
    //initializare coada
    dr ++;
    Q[dr].linie = istart, Q[dr].coloana = jstart;
    //marcare pozitie de start
    A[istart][jstart] = v;
    while(st <= dr) // cat timp coada este nevida
    {   
        int i = Q[st].linie, j = Q[st].coloana; // determinam elementul de la inceputul cozii
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = i + di[k], jv = j + dj[k]; // coordonatele vecinului
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m // element Ã®n matrice
                && A[iv][jv] != 1 // element liber
                && A[iv][jv] != v) // nemarcat
            {
                // marcam elementul vecin
                A[iv][jv] = v;
                // il adaugam in coada
                dr ++;
                Q[dr].linie = iv , Q[dr].coloana = jv;
            }
        }
        st ++; // eliminam din coada
    }
}


//FILL cu coada STL queue
Containerul STL queue permite gestionarea unei cozi, avand definite toate operatiile necesare.
* pentru a folosi containerul, trebuie incluse headerul queue: #include <queue>
* declaram o variabila pentru coada: @ queue<pair<int,int> Q;
*elementele cozii vor fi gestionate dinamic, memoria alocata lor fiind in HEAP, nu in STACK;
pentru algoritmul de umplere, in coada trebuie sa memoram coordonatele unor elemente din matrice. In acest scop putem folosi clasa C++ pair, care incapsuleaza doua valori. 
Accesul la cele doua valori se face prin campurile first si second. Crearea unei variabile de tip pair se poate face prin intermediul functiei: @ make_pair(v1,v2);
* In gestionarea cozii se folosesc patru operatii:
 - verificarea faptului ca in coada avem sau nu elemente (coada este nevida sau vida): @ Q.empty() – returneaza true sau false;
 - Identificare elementului de la inceputul cozii: @ Q.front();
 - Adaugarea unui element in coada: @ Q.push(valoare);
 - Eliminarea unui element din coada: @ Q.pop().
Ex:
void Fill(int istart ,int jstart ,int v)
{
    queue<pair<int,int>> Q;
    //initializare coada
    Q.push(make_pair(istart , jstart));
    //marcare pozitie de start
    A[istart][jstart] = v;
    while(! Q.empty()) // cat timp coada este nevida
    {   
        int i = Q.front().first, j = Q.front().second; // determinam elementul de la inceputul cozii
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = i + di[k], jv = j + dj[k]; // coordonatele vecinului
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m // element în matrice
                && A[iv][jv] != 1 // element liber
                && A[iv][jv] != v) // nemarcat
            {
                // marcam elementul vecin
                A[iv][jv] = v;
                // il adaugam in coada
                Q.push(make_pair(iv , jv));
            }
        }
        Q.pop(); // eliminam din coada
    }
}


//Divide et impera
@Suma unei secvente de vector
Ex:
int Suma(int V[], int st, int dr){
    if(st == dr)
        return V[st]; // problema elementara
    else{
        int m = (st + dr) / 2; // împartim problema în subprobleme
        int s1 = Suma(V, st, m); // rezolvam prima subproblema
        int s2 = Suma(V, m + 1, dr); // rezolvam a doua subproblema
        return s1 + s2; // combinam rezultatele
    }
}
int main(){
    int V[101], n;
    //citire n si V
    cout << Suma(V,1,n);
    return 0;
}
@Suma unei portiuni a unei matrici:
Ex:
#include <iostream>

using namespace std;

int a[101][101], m, n;
long long sum(int l1,int c1,int l2,int c2){
    if (l2<l1 || c2<c1) return 0;
    if (l1==l2 && c1==c2)
        if (a[l1][c1]%2==0)
            return a[l1][c1];
        else
            return 0;
    else{
        int lm=(l1+l2)/2;
        int cm=(c1+c2)/2;
        long long s=0;
        s=s+sum(l1,c1,lm,cm);
        s=s+sum(l1,cm+1,lm,c2);
        s=s+sum(lm+1,c1,l2,cm);
        s=s+sum(lm+1,cm+1,l2,c2);
        return s;
    }
}
int main()
{
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    cout<<sum(1,1,m,n);

    return 0;
}
@CMMDC a unei secvente de vector
Ex:
int CMMDC(int A[], int st, int dr){
	if(st == dr)
		return A[st];
	else{
		int m = (st + dr)/2;
		int a = CMMDC(A, st, m);
		int b = CMMDC(A, m + 1, dr);
		while(a){
			int r = b % a;
			b = a;
			a = r;
		}
		return b;
	}
}


//Mergesort
Ex:
void MergeSort(int v[], int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		MergeSort(v, st , m);
		MergeSort(v, m + 1 , dr);
		//Interclasare
		int i = st, j = m + 1, k = 0;
		while( i <= m && j <= dr )
			if( v[i] < v[j])
				tmp[++k] = v[i++];
			else
				tmp[++k] = v[j++];
		while(i <= m)
			tmp[++k] = v[i++];
		while(j <= dr)
			tmp[++k] = v[j++];
		for(i = st , j = 1 ; i <= dr ; i ++ , j ++)
			v[i] = tmp[j];
	}
}


//Quicksort
Ex:
void QuickSort(int a[], int st, int dr){
	if(st < dr){
		int pivot = a[dr], i = st - 1;
		for(int j=st; j<=dr-1; j++){
			if(a[j] < pivot){
				i ++;
				swap(a[i], a[j]);
			}
		}
		swap(a[i + 1], a[dr]);
		QuickSort(a, st, i);
		QuickSort(a, i + 2, dr);
	}
}


//Liste simplu inlantuite alocate dinamic
@Elementele listei sunt de tipul dat:
Ex:
struct nod{
  int info; //informatia utila, in cazul dat integer
  nod * urm; //avem un pointer de acelasi tip nod, reprezinta informatia de legatura, adica adresa variabilei urmatoare
};
nod * prim = NULL; //primul element
@Crearea variabilei nod
Ex:
nod * p = new nod;
p->info = ..... ; // cin >> p->info;
p->urm = NULL;
@Adaugarea unui element la final
Ex:
void AdaugaFinal(nod * & prim , int x)
{
  // cream nod nou
  nod * q = new nod;
  q -> info = x;
  q -> urm = NULL;
  // adauga noul nod la lista
  if(prim == NULL)
  { // lista este vida
    prim = q;
  }
  else
  { // lista nu este vida
    nod * t = prim;
    while(t -> urm != NULL)
      t = t -> urm;
    t -> urm = q;
  }
}
@Adaugarea uni element la inceput
Ex:
void AdaugaFinal(nod * & prim , int x)
{
  // cream nod nou
  nod * t = new nod;
  t -> info = x;
  // legam nodul de lista
  t -> urm = prim;
  // valoarea lui prim se modifica, pentru a ie?i din func?ie cu valoarea corecta
  prim = t;
}
@Parcurgerea listei
Ex:
void Parcurgere(nod *  prim)
{
  nod * p = prim;
  while(p != NULL)
  {
    //prelucram nodul curent
    // trecem la urmatorul nod
    p = p->urm;
  }
}
@Citire
Ex:
void citire(nod * & prim){
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int x;
		cin >> x;
		AdaugaFinal(prim, x);
	}
}
@Sterge
Ex:
void StergeN(nod * & prim){ 
	int n;
	cin >> n;//n trebuie sa fie admisibil conform listei definite
	if(n == 1){
		nod * t = prim;
		prim = prim->urm;
		delete t;
	}
	else{
		nod * p = prim, * t;
		int i = 1;
		while(++i < n)
			p = p->urm;
		t = p->urm;
		p->urm = t->urm;
		delete t;
	}
}
@Inserare
Ex:
void InserareN(nod * & prim){
	int n;
	cin >> n; //n trebuie sa fie admisibil conform listei definite
	//n == 0 inainte primului element, n == lungimea liste - dupa ultimul elemet
	if(n == 0){
		int x;
		cin >> x;
		nod * t = new nod;
		t->info = x;
		t->urm = prim;
		prim = t;
	}
	else{
		int i = 0, x;
		nod * p = prim, * t = new nod;
		cin >> x;
		t->info = x;
		while(++i < n)
			p = p->urm;
		t->urm = p->urm;
		p->urm = t;
	}
}


//Folosirea containerului STL stack - STIVA
@Declaratii
Ex:
#include <stack>
@Initializarea stivei – crearea unei stive vide
Ex:
stack<int> S;
@Verificarea faptului ca stiva este vida
Ex:
Q.empty() // true daca stiva este vida, false în caz contrar
@Adaugarea unui element – PUSH
Ex:
Q.push( _VALOARE );
@Eliminarea unui element – POP
Ex:
Q.pop();
@Identificarea valorii din varful stivei – TOP
Ex:
Q.top();


//Folosirea containerului STL stack - COADA
@Declaratii
Ex:
#include <queue>
@Initializarea cozii – crearea unei cozi vide
Ex:
queue<int> Q;
@Verificarea faptului ca este vida coada
Ex:
Q.empty() // true daca este vida, false în caz contrar
@Adaugarea unui element – PUSH
Ex:
Q.push( _VALOARE );
@Eliminarea unui element – POP
Ex:
Q.pop();
@Identificarea valorii de la inceputul cozii – TOP
Ex:
Q.front()
@Declararea unei cozi cu 2 campuri
Ex:
queue<pair<int,int>> Q;
+ *Accesul
Ex:
Q.front().first; 
Q.front().second;
@Priority_queue:
Ex:
priority_queue<pair<int, int> > q; //q.top() va fi elementul cu q.first maximal
Ex:
typedef pair<int, int> pi
priority_queue<pi, vector<pi>, greater<pi> > p; //q.top() va fi elementul cu q.first minimal


//Algoritmul lui Lee
@Implimentare
Ex:
void Lee(int istart ,int jstart)
{
    queue<pair<int,int>> Q;
    //initializare coada
    Q.push(make_pair(istart , jstart));
    //marcare pozitie de start
    A[istart][jstart] = 1;
    while(! Q.empty()) // cat timp coada este nevida
    {   
        int i = Q.front().first, j = Q.front().second; // determinam elementul de la inceputul cozii
        for(int k = 0 ; k < 4 ; k ++)
        {
            int iv = i + di[k], jv = j + dj[k]; // coordonatele vecinului
            if(iv >= 1 && iv <= n && jv >= 1 && jv <= m // element în matrice
                && A[iv][jv] == 0) // element liber si nemarcat
            {
                // marcam elementul vecin cu o valoare mai mare
                A[iv][jv] = A[i][j] + 1;
                // il adaugam in coada
                Q.push(make_pair(iv , jv));
            }
        }
        Q.pop(); // eliminam din coada
    }
}
@Reconstruire recursiva
Ex:
void Traseu(int i, int j , int lg)
{
    if(A[i][j] == 1)
    {
        cout << lg << "\n";
        cout << i << " " << j << "\n";
    }
    else
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(A[i][j] == A[i+di[k]][j+dj[k]] + 1)
                p = k;
        Traseu1(i + di[p] , j + dj[p] , lg + 1);
        cout << i << " " << j << "\n";
    }
}
@Reconstruire nerecrusiva, cu biblioteca vector
Ex:
void Traseu2(int istop, int jstop)
{
    vector<pair<int,int>> V;
    int i = istop , j = jstop;
    V.push_back(make_pair(i , j));
    do
    {
        int p = -1;
        for(int k = 0 ; k < 4 && p == -1 ; k ++)
            if(A[i][j] == A[i+di[k]][j+dj[k]] + 1)
                p = k;
        i = i + di[p] , j = j + dj[p];
        V.push_back(make_pair(i , j));
    }
    while(A[i][j] != 1);
    cout << V.size() << '\n';
    for(vector<pair<int,int>>::reverse_iterator I = V.rbegin() ; I != V.rend() ; I ++)
        cout << I->first << " " << I->second << '\n';
}


//Exponentiere rapida
@Implimentare recursiva
Ex:
int Putere(int A , int n)
{
    if(n == 0)
        return 1;
    if(n % 2 == 1)
        return A * Putere(A , n - 1);
    int P = Putere(A , n / 2);
    return P * P;
}
@Implimentare interativa
Ex:
int Putere(int A , int n)
{
    int P = 1;
    while(n)
    {
        if(n % 2 == 1)
            P = P * A;
        A = A * A;
        n /= 2;
    }
    return P;
}
@Implimentare iterativa pe biti
Ex:
int Putere(int A , int n)
{
    int P = 1;
    for(int k = 1 ; k <= n ; k <<= 1)
    {
        if((n & k))
            P *= A;
        A = A * A;
    }
    return P;
}


//Algoritmul lui euclid recursiv
Ex:
void euclid(int a, int b, int *d)
{
    if (b == 0) {
        *d = a;
    } else
        euclid(b, a % b, d);
}


//Algoritmul lui euclid extins
Ex:
void euclid(int a, int b, int *d, int *x, int *y)
{
    if (b == 0) {
        *d = a;
        *x = 1;
        *y = 0;
    } else {
        int x0, y0;
        euclid(b, a % b, d, &x0, &y0);
        *x = y0;
        *y = x0 - (a / b) * y0;
    }
}


//Implimentarea dinamica a problemei scarii sau a surului lui Fibonacci
@Bootom-up
Ex:
V[1] = 1, V[2] = 2;
for(int i = 3 ; i <= n ; i ++)
    V[n] = V[n-1] + V[n-2];
cout << V[n];
@Top-down
Ex:
long long V[100];
long long T(int n)
{
    if(V[n] != 0)
        return V[n];        
    if(n < 3)
        V[n] = n;
    else
        V[n] = T(n-1) + T(n-2);
    return V[n];
}


//Numarul de drumuri in matrice
@Bootom-up
Ex:
for(int i = 1 ; i <= n ; ++ i)
	A[i][1] = 1;
for(int j = 1 ; j <= m ; ++ j)
	A[1][j] = 1;
for(int i = 2 ; i <= n ; ++ i)
	for(int j = 2 ; j <= m ; ++ j)
		A[i][j] = (A[i-1][j] + A[i][j-1]) % 9901;
cout << A[n][m];
@Top-down
Ex:
int n, m, A[NN][NN];
int F(int i , int j)
{
    if(A[i][j] != 0)
        return A[i][j];
    if(i == 1 || j == 1)
        A[i][j] = 1;
    else
        A[i][j] = (F(i-1,j) + F(i,j-1)) % 9901;
    return A[i][j];
}


//Subsirul de lungime maxima
@Metoda dinamica complexitate O(n^2)
Ex:
int pmax = n;
LG[n] = 1, next[n] = -1;
for(int i=n-1; i; i--){
	LG[i] = 1;
	next[i] = -1;
	for(int j=i+1; j<=n; j++)
		if(a[i] <= a[j] && LG[i] < LG[j] + 1){
			LG[i] = LG[j] + 1;
			next[i] = j;
		}
	if(LG[i] >= LG[pmax])
		pmax = i;
}
cout << LG[pmax] << "\n";
int p = pmax;
do{
	cout << p << " ";
	p = next[p];
}
while(p != -1);
@Metoda greedy complexitate O(n * log n)
Ex:
k = 1;
D[k] = A[1];
P[1] = 1;
for(int i = 2 ; i <= n ; i ++)
    if(A[i] >= D[k])
        D[++k] = A[i], P[i] = k;
    else
    {
        int st = 1 , dr = k , p = k + 1;
        while(st <= dr)
        {
            int m = (st + dr) / 2;
            if(D[m] > A[i])
                p = m, dr = m - 1;
            else
                st = m + 1;
        }
        D[p] = A[i];
        P[i] = p;
    }
int j = n;
for(int i = k ; i >= 1 ; i --)
{
    while(P[j] != i)
        j --;
    I[i] = j;
}


//BFS cu STL queue
Ex:
void bfs(int x){
	queue<int> Q;
	v[x] = 1;
	Q.push(x);
	while(!Q.empty()){
		int aux = Q.front();
		fout << aux << " ";
		Q.pop();
		for(int i = 1; i <= n; i ++)
			if(a[aux][i] == 1 && !v[i]){
				v[i] = 1;
				Q.push(i);
			}
	}
}


//STL - vector
@Header:
#include <vector>
@Declarare:
* vector<T> V; // T - tipul de date
Ex:
vector<int> A; // se creaza un vector A cu zero elemente
* vector<T> V(n); // n - intreg. Vector cu n elemente. Valorile elementelor create sunt implicite tipului T, pentru T numerice implicit e 0.
Ex:
cin >> n;
vector<int> B(n); // se creaza un vector B cu n elemente, egale cu 0
* vector<T> V(n, vT); // cele n valori ale vecorului sunt copii ai lui vT
Ex:
vector<int> C(n , x); // se creaza un vector B cu n elemente, egale cu x
Ex:
vector<int> v;
v = vector<int> (100) // se poate executa asa o atribuire
@Atribuirea se face in orice moment:
Ex:
vector<int> A , B = {2 , 4, 6 , 8};
A = B;
A = {1 , 2 , 3 , 4 , 5};
@Functiile: size(), capacity(), resize();
* V.size() - returneazea numarul de elemente din vector;
Ex:
vector<int> A = {2 , 4 , 6 , 8};
cout << A.size(); // 4
* V.capacity() - returneaza numarul de elemnte pe care le poate avea vectorul la momentul curent;
* V.resize(n) - redimensioneaza vecoril astfel incat sa aiba n elemente daca n < V.size(), in vector vor ramane primele n elemente, celelalte vor fi sterse,
daca n > V.size(), in vector se vor adauga n - V.size() elemente; // n - intreg;
* V.resize(n, x) - valorile create vor fi egare cu x;
@Functia push_back():
V.push_back(n) - adaugarea elementului n la sfarsitul vectorului;
Ex:
vector<int> A;
for(int i = 1 ; i <= 5 ; i ++)
    A.push_back(2 * i);
cout << A.size();
@Accesarea unui element:
* Elementele pot fi accesate prin intermediul indicilor cu ajutorul operatorului [];
Ex:
vector<int> A;
for(int i = 1 ; i <= 5 ; i ++)
    A.push_back(2 * i);
for(int i = 0 ; i < A.size() ; i ++)
    cout << A[i] << ' '; // 0 2 4 6 8
* Se poate folosi functia at() - Aceasta returneaza o referinta la elementul de la pozitia data, iar daca acesta nu exista ridica o exceptie care poate 
fi capturata prin mecanismul try ... catch;
* Deasemenea si poate folosi for-ul de forma for(auto x : A), de exmplu, unde A este un vector, aceasta prin intermediul lui x parcurge vectorul in intregime 
de la inceput la sfarsit;
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
A.at(1) = 20; //A = {2 , 20 , 6 , 8 , 10}
for(auto x : A)
    cout << x << " ";
* Primul si ultimul element poate fi accesat prin intemediul functiilor front() si back(). Ele returneaza referinte la primul, respectiv
ultimul element al vectorului. Comportamentul este impredictibil daca vectorul este vid;
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
A.at(1) = 20; //A = {2 , 20 , 6 , 8 , 10}
A.front() = 7; //A = {7 , 20 , 6 , 8 , 10}
A.back() = 5; //A = {7 , 20 , 6 , 8 , 5}
for(auto x : A)
    cout << x << " ";
@Iteratori:
* Iteratorii sunt similari cu pointerii. Cu ajutorul lor putem identifica adresa elementelor din vector. Iteratorii pot fi dereferen?ia?i (obtinând
referin?e la elemente), pot fi incrementa?i/decrementa?i ?i pot fi aduna?i cu scalari.
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
vector<int>::iterator I;
for(I = A.begin() ; I < A.end() ; I ++)
    cout << *I << " "; // 2 4 6 8 10
*Clasa vector con?ine ?i func?iile rbegin() ?i rend(), care returneaza iteratori de tip reverse iterator, care permit parcurgerea vectorului în ordien inversa
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
for(vector<int>::reverse_iterator I = A.rbegin() ; I < A.rend() ; I ++)
    cout << *I << " ";
@Parcurgere:
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
for(auto I = A.begin() ; I < A.end() ; I ++)
    cout << *I << " ";
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
for(int x : A)
    cout << x << " ";
* Daca se dore?te modificare elemenelor din A, atunci x trebuie sa fie o referin?a:
Ex:
vector<int> A = {2 , 4 , 6 , 8 , 10};
for(int & x : A)
    x *= 2;
@Functia insert():
* V.insert(pos , x) – insereaza în vectorul V, în fa?a iteratorului pos un nou element cu valoarea x;
* V.insert(pos , cnt , x) insereaza în vectorul V, în fa?a iteratorului pos, cnt noi elemente egale cu x;
* V.insert(pos , st , dr) insereaza în vectorul V, în fa?a iteratorului pos, dr-st noi elemente, având valorile egale cu cele ale
Ex:
v.insert(v.begin()+2,10);
elementelor din secven?a [st, dr) dintr-un container oarecare. Daca vectorul V ?i secven?a [st,dr) se suprapun rezultatul este impredictibil.
@Stergere:
* V.pop_back() - sterge ultimul element;
* V.clear() - sterge toate elementele;
* erase();
* v.empty() - true if the container size is 0, false otherwise.
Ex:
v.erase(v.begin()+2);
@vector<pair<int,int>> v; // vector de perechi, elementele se aceseaza ca fiind de exemplu v[1].first, v[1].second dintr-o pereche.
Ex:
vector<pair<int, int>> p;
for(int i = 1; i <= 5; i ++)
	p.push_back({i, i});
for(auto x : p)
	cout << x.first << " " << x.second << "\n";
vector<vector<int>> v; // matrici
vector <int> G[50001];
Ex:
vector<vector<int>> v;
v = vector<vector<int>> (100);
@STL vector sortare:
Ex:
sort(P[i].begin() , P[i].end());


//Matricea drumurilor(unui graf orientat)
Ex:
// D este matricea de adiacenta de tip bool
for(int k = 1 ; k <= n ; ++k)
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= n ; ++j)
        	D[i][j] = D[i][j] || (D[i][k] && D[k][j]);	
			

//Algoritmul roy-floyd
Ex:
//D[][] este ini?ial matricea costurilor arcelor
//INF este un numar mare
for(int k = 1 ; k <= n ; k ++)
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            if(D[i][j] > D[i][k] + D[k][j] && D[i][k] != INF && D[k][j] != INF)
                D[i][j] = D[i][k] + D[k][j];	
//Daca punem INF relativ mare dar nu exageram putem omite conditiile D[i][k] != INF && D[k][j] != INF, de exemplu INF = 0x3f3f3f3f = 1061109567


//Dijkstra's algorithm
Ex:
void dijikstra(int G[MAX][MAX], int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i,j;
	for(i=0;i < n;i++)
		for(j=0;j < n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];
	
	for(i=0;i< n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count < n-1){
		mindistance=INFINITY;
		for(i=0;i < n;i++)
			if(distance[i] < mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
		visited[nextnode]=1;
		for(i=0;i < n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i] < distance[i])
				{
					distance[i]=mindistance+cost[nextnode][i];
					pred[i]=nextnode;
				}
			count++;
	}
 
	for(i=0;i < n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of %d = %d", i, distance[i]);
			printf("\nPath = %d", i);
			j=i;
			do
			{
				j=pred[j];
				printf(" <-%d", j);
			}
			while(j!=startnode);
		}
}

//Dijkstra`s algorithm using vector of pairs and priority queue
Ex:
void dijkstra(ll src) {
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(make_pair(0, src));
	d[src] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		for (pii x : g[u]) {
			ll v = x.first;
			ll w = x.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push(make_pair(d[v], v));
			}
		}
	}
}


//Tarjan's algorithm
Ex:
/* Complexity: O(E + V)
 Tarjan's algorithm for finding strongly connected
components.
 *d[i] = Discovery time of node i. (Initialize to -1)
 *low[i] = Lowest discovery time reachable from node
 i. (Doesn't need to be initialized)
 *scc[i] = Strongly connected component of node i. (Doesn't
 need to be initialized)
 *s = Stack used by the algorithm (Initialize to an empty
 stack)
 *stacked[i] = True if i was pushed into s. (Initialize to
 false)
 *ticks = Clock used for discovery times (Initialize to 0)
 *current_scc = ID of the current_scc being discovered
 (Initialize to 0)
*/
vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
    }while (u != v);
    current_scc++;
  }
} //https://tutoriale-pe.net/problema-3365-digrafulctc-rezolvari-pbinfo/


//memset
se include:
#include <cstring>
Ex:
memset(a, 0, sizeof(a)); //seteaza toate elementele 0
sizeof(a) - memoria in dependenta de tipul tabloului
memset(a, 0x3f, sizeof(a)) // seteaza toate elementele cu valoarea 1061109567


//INF
putem utiliza numarul 0x3f3f3f3f ca infinit, acesta este 1061109567
Ex:
#define INF 0x3f3f3f3f


//Algoritmul lui Prim + vectorul de tati
Ex:
typedef pair<int, int> pi;
typedef vector<pi> vpi;
vpi G[101];
vector<int> v(101), t(101), d(101, INF);
/*citire*/
priority_queue<pi, vpi, greater<pi> > Q;
Q.push(make_pair(0, 1));
t[1] = 0;
while(!Q.empty()){
	pi p;
	p = Q.top();
	Q.pop();
	if(!v[p.second]){
		cost += p.first;
		v[p.second] = 1;
		for(auto x : G[p.second])
			if(!v[x.second] && d[x.second] > x.first){
				Q.push(x);
				t[x.second] = p.second;
				d[x.second] = x.first;
			}
	}
}


//Algoritmul lui Kruskal
Ex:
struct muchie{
	int x, y, c;
} G[200001];
 
int t[200001], r[200001];
 
bool compara(muchie a, muchie b){
	return a.c < b.c;
}
 
int tata(int a){
	if(t[a])
		return t[a] = tata(t[a]);
	return a;
}
 
int main(){
	int n, m, S = 0;
	vector<int> a;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++)
		cin >> G[i].x >> G[i].y >> G[i].c;
	sort(G + 1, G + m + 1, compara);
	for(int i = 1; i <= m; i ++){
		int tx = tata(G[i].x);
		int ty = tata(G[i].y);
		if(tx != ty){
			a.push_back(i);
			S += G[i].c;
			if(r[tx] > r[ty])
				t[ty] = tx;
			else{
				t[tx] = ty;
				if(r[tx] == r[ty])
					r[ty] ++;
			}
		}
	}
	cout << S << "\n";
	for(int i = 0; i < n - 1; i ++)
		cout << G[a[i]].x << " " << G[a[i]].y << "\n";
}


//Paduri de multimi disjuncte
Ex:
int t[...];

int Radacina(int k){
    if(T[k] == 0)
        return k;
    else
    {
        int x = Radacina(T[k]);
        T[k] = x;
        return x;
    }
}

void Unire(int k, int p)
{
    int rk = Radacina(k), rp = Radacina(p);
    if(rk != rp)
    {
        if(Rang[rk] > Rang[rp])
            T[rp] = rk;
        else
        {
            T[rk] = rp;
            if(Rang[rk] == Rang[rp])
                Rang[rp] ++;
        }
    }
}















