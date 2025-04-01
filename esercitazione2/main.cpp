#include <iostream>

template<typename T>							//T è un tipo di dato qualsiasi
class complex_number{							//sto definendo la nuova classe complex_number
private:										//definisco le variabili di tipo T
	T real;
	T imaginary;
public:											// tutto ciò che segue è accessibile dall'esterno della classe.
	//costruttore di default
	complex_number(T partereale=0, T parteimmaginaria=0):real(partereale), imaginary(parteimmaginaria) {}
	//se non fornisco parametri vengono presi di default 0 e 0, altrimenti userà quelli che fornirò successivamente
	
	//coniugato
	complex_number<T> conjugate() const {				//la funzione non modifica complex_number su cui viene chiamata
		return complex_number<T>(real, -imaginary);
	}
	
	//parte reale
	T getReal() const {					//restituisce la parte reale senza modificare l'oggetto
		return real;
	}
	
	//parte immaginaria
	T getImaginary() const {			//restituisce la parte immaginaria senza modificare l'oggetto	
		return imaginary;
	}
	
	//stampa con funzione
	std::string funzione() const {							//funzione() converte un numero complesso in una stringa per stamparlo
		std::string risultato = std::to_string(real);		//ho convertito la parte reale in stringa
		if (imaginary >=0) 
		{
			risultato = risultato + " + " + std::to_string(imaginary) + "i";			//aggiungo a risultato una concatenazione di stringhe
		}
		else 
		{
			risultato = risultato + " - " + std::to_string(-imaginary) + "i";
		}
		return risultato;
	}
		
	
	//overload operatore +=
	complex_number<T> operator+=(const complex_number<T> number) {
		real += number.real;										//ho aggiunto la parte reale di number alla parte reale del numero con cui sto lavorando
		imaginary += number.imaginary;								//ho aggiunto la parte immaginaria di number alla parte immaginaria del numero con cui sto lavorando
		return (*this);												//restituisce l'oggetto corrente che contiene la somma
	}
	
	//overload operatore +
	complex_number<T> operator+(const complex_number<T> number) const {					//operator+ somma due numeri complessi
																						//ho preso umber in input, ma la funzione non modifica il numero
		complex_number<T> risultato(real+number.real, imaginary+number.imaginary);		//ho creato un nuovo numero complesso chiamato risultato
		return risultato;
	}
	
	//caso T + complex_number<T>:
	complex_number<T> operator+ (T valore) const {							//la funzione prende come input il valore T
		complex_number<T> risultato (real + valore, imaginary);
		return risultato;
	}
	
	//overload operatore *=
	complex_number<T> operator*=(const complex_number<T> number) {
		T numreale = real * number.real - imaginary * number.imaginary;
		imaginary = real * number.imaginary + imaginary * number.real;
		real = numreale;
		return (*this);
	}
	
	//overload operatore *
	complex_number<T> operator*(const complex_number<T> number) const {
		T nreale = real * number.real - imaginary * number.imaginary;			//dati (a+ib), (c+id), reale=(ac-bd)
		T nimm = real * number.imaginary + imaginary * number.real;				//dati (a+ib), (c+id), immaginaria=(ad+bc)
		complex_number<T> risultato(nreale, nimm);
		return risultato;
	}
	
	//caso T * complex_number<T>
	complex_number<T> operator* (T valore) const {
		complex_number<T> risultato (real * valore, imaginary * valore);
		return risultato;
	}

	//overload dell'operatore <<
	std::ostream& operator<<(std::ostream& complesso) const {
		complesso << funzione();
		return complesso;
	}
};

int main(){
	complex_number<float> numero_default;
	std::cout << "Valore di default: " << numero_default.funzione() << std::endl;
	float a,b;
	std::cout << "Inserisci la parte reale del primo numero che sia float o double: " << std::endl;
    std::cin >> a;
	std::cout << "Inserisci la parte immaginaria del primo numero che sia float o double: " << std::endl;
    std::cin >> b;
	complex_number<float> numero1(a, b);
	//stampa con <<
	std::cout << "il numero è: " << a << " + i" << b << std::endl;
	std::cout << numero1.funzione() << std::endl;
	std::cout << "Coniugato: " << numero1.conjugate().funzione() << std::endl;
	std::cout << "Parte reale: " << numero1.getReal() << std::endl;
	std::cout << "Parte immaginaria: " << numero1.getImaginary() << std::endl;
	float c,d;
	std::cout << "Inserisci la parte reale del secondo numero che sia float o double: " << std::endl;
    std::cin >> c;
	std::cout << "Inserisci la parte immaginaria del secondo numero che sia float o double: " << std::endl;
    std::cin >> d;
	complex_number<float> numero2(c, d);
	std::cout << numero2.funzione() << std::endl;
	std::cout << "Coniugato: " << numero2.conjugate().funzione() << std::endl;
	std::cout << "Parte reale: " << numero2.getReal() << std::endl;
	std::cout << "Parte immaginaria: " << numero2.getImaginary() << std::endl;
	std::cout << "Somma di " << numero1.funzione() << " e " << numero2.funzione() <<" : " << (numero1 + numero2).funzione() << std::endl;
	std::cout << "Prodotto di " << numero1.funzione() << " e " << numero2.funzione() <<" : " << (numero1 * numero2).funzione() << std::endl;
	numero1 += numero2;			//ho aggiornato il numero 1
	std::cout << "Somma dei due numeri utilizzando +=: " << numero1.funzione() << std::endl;
	numero1 *= numero2; 		//NOTA BENE: il numero1 ora è dato da numero1 + numero2, se volessi solo il numero1 dovrei fare numero1 = numero1 - numero2
	std::cout << "Prodotto dei due numeri utilizzando *=: " << numero1.funzione() << std::endl;
	return 0;
}

