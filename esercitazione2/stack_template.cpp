#include <iostream>

#define STACK_SIZE 8

template<typename T>							//"Questa scatola può contenere qualsiasi tipo di cosa. Chiameremo quel tipo 'T' 
												//(come 'tipo generico')". Quindi, "T" può essere un numero intero, una parola, o qualsiasi altra cosa.
struct stack {									// "ricetta" per costruire la nostra scatola magica
    T       data[STACK_SIZE];					//mettiamo gli oggetti nella scatola. "data" è come una fila di scomparti, 
												//e "T" dice che ogni scomparto può contenere un oggetto del tipo che abbiamo scelto. 
												//"STACK_SIZE" è il numero massimo di scomparti che la scatola ha.
    int     top;								//ci dice qual è l'ultimo scomparto usato nella scatola.

    stack()
        : top(0)								//modo speciale per costruire una scatola vuota. Quando creiamo una nuova scatola, 
												//l'etichetta "top" viene impostata a 0, il che significa che non ci sono oggetti nella scatola.
    {}
    
    stack(const stack& other) {					//modo per fare una copia esatta di un'altra scatola magica.
        for (int i = 0; i < STACK_SIZE; i++)	//Questo è un "ciclo" che ci permette di copiare ogni oggetto dalla scatola "other" alla nostra nuova scatola, uno per uno.
            data[i] = other.data[i];			//è dove copiamo l'oggetto dalla scatola "other" alla nostra nuova scatola.
    }
    
    /* Not a good implementation: push should signal a failure */
    void push(const T& value) {					//Immagina di avere un nuovo oggetto (di qualsiasi tipo, ricordi? "T") e vuoi metterlo nella scatola. 
												//"push" è come un comando per dire "metti questo oggetto nella scatola". 
												//"const T& value" significa che stiamo prendendo l'oggetto senza modificarlo. 
												//"void" significa che questa azione non restituisce niente.
        if (top < STACK_SIZE)					//questa riga controlla se c'è ancora spazio nella scatola. Se "top" è minore di "STACK_SIZE", 
												//significa che c'è spazio per un altro oggetto.
            data[top++] = value;				//è la parte dove mettiamo l'oggetto nella scatola. 
												//data[top]: Questo è lo scomparto dove metteremo il nuovo oggetto.
												//value: Questo è l'oggetto che stiamo aggiungendo.
												//top++: Questo è un trucchetto furbo! Fa due cose insieme. Prima, usa il valore attuale di "top". 
												//Poi, aggiunge 1 a "top". Così, la prossima volta che aggiungiamo un oggetto, andrà nello scomparto successivo.
    }
    
    /* Not a good implementation: pop should signal a failure */
    T pop() {									// "pop" è come un comando per dire "prendi l'ultimo oggetto". 
												//"T" significa che questo comando ci darà indietro un oggetto del tipo che abbiamo scelto (qualsiasi cosa!).
        if (top > 0)							//Questa riga controlla se ci sono oggetti nella scatola. Se "top" è maggiore di 0, significa che c'è almeno un oggetto da togliere.
            return data[--top];					//togliamo l'oggetto.
												//--top: Questo è un altro trucchetto furbo! Fa due cose insieme. Prima, toglie 1 da "top". 
												//Poi usa il nuovo valore di "top" per accedere ai dati.
												//data[top]: Questo è l'oggetto che stiamo togliendo.
												//return: Il comando restituisce l'oggetto che abbiamo tolto.

        return {};								//Se non ci sono oggetti nella scatola (se "top" è 0 o meno), restituiamo una "scatola vuota". 
												//Questo è come dire "non c'era niente da togliere".
    }

    bool empty() const {						//La scatola è vuota?". "bool" significa che la risposta sarà "vero" (true) o "falso" (false). 
												//"const" significa che questa azione non cambierà la scatola.
        return (top == 0);						//Se "top" è uguale a 0, significa che non ci sono oggetti nella scatola, quindi la scatola è vuota.
												//"return" dice al programma di dare come risposta "vero" (true) se la scatola è vuota, e "falso" (false) se la scatola non è vuota.
    }

    bool full() const {							//"La scatola è piena?". "bool" vuol dire che la risposta sarà "vero" (true) o "falso" (false). 
												//"const" significa che questa azione non cambierà la scatola.
        return (top == STACK_SIZE);				//Se "top" è uguale a STACK_SIZE, vuol dire che abbiamo riempito tutti gli spazi disponibili nella scatola, quindi la scatola è piena.
												//"return" dice al programma di dare come risposta "vero" (true) se la scatola è piena, e "falso" (false) se la scatola non è piena.
    }
};

struct meteo_data {								//è come la "ricetta" per creare una pagina del quaderno. "struct" è un modo per raggruppare diverse informazioni insieme.
    std::string location;						//è la prima cosa che vogliamo scrivere sulla pagina: il nome della città. "std::string" è come un modo per dire "testo". 
												//Quindi, qui scriveremo il nome della città, come "Roma" o "Milano".
    double      temperature;					//scriveremo la temperatura
    double      pressure;						//scriveremo la ptessione	
};

int main(void)
{
    std::cout << "--- Stack of integers ---" << std::endl;					// è come dire "Stiamo iniziando a lavorare con una scatola che contiene numeri!".
    stack<int> si;															//Creiamo una scatola magica chiamata "si" che può contenere solo numeri interi
    std::cout << "Is empty: " << std::boolalpha << si.empty() << "\n";		//"La scatola 'si' è vuota?". La risposta sarà "true" (vero) perché l'abbiamo appena creata.
    std::cout << "Pushing 10 and 20\n";
    si.push(10);															//metto il 10 in alto
    si.push(20);
    std::cout << si.pop() << "\n";											//prendo il primo numero (20) e lo mostro
    std::cout << "Is empty: " << std::boolalpha << si.empty() << "\n";		//Chiediamo di nuovo se la scatola è vuota. La risposta sarà "false" (falso) perché c'è ancora il numero 10.
    std::cout << si.pop() << "\n";											//prendo l'ultimo numero (10) e lo mostro
    std::cout << "Is empty: " << std::boolalpha << si.empty() << "\n";		// Chiediamo di nuovo se la scatola è vuota. La risposta sarà "true" (vero) perché l'abbiamo svuotata.

    std::cout << "--- Stack of meteo_data ---" << std::endl;
    stack<meteo_data> sm;													//Creiamo una scatola magica chiamata "sm" che può contenere le schede meteo.
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    sm.push({"Torino", 25.1, 1013.0});										//Mettiamo una scheda meteo per Torino nella scatola.
    sm.push({"Milano", 23.1, 1015.0});
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    meteo_data md = sm.pop();												//Prendiamo l'ultima scheda (quella di Milano) e la mettiamo in una "scatola temporanea" chiamata "md".	
    std::cout << md.location << ", " << md.temperature << ", ";				//Mostriamo le informazioni della scheda di Milano
    std::cout << md.pressure << std::endl;
    
    return 0;
}

