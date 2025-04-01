#include <iostream>

#define STACK_SIZE 8		//ogni volta che l computer vede STACK_SIZE lo sostituisce con 8, lo si usa per comodità e leggibilità

struct stack {					//struct è come un modello che ci dice quali pezzi servono per questa "pila"
    int     data[STACK_SIZE];	//posso mettere massimo 8 blocchi, quindi data è come un array che può contenere max 8 numeri int
    int     top;						//etichetta che dice dove si trova il blocco più in alto della pila

            stack();					//crea una pila vuota
            stack(const stack& other);	//copia un'altra pila
    void    push(int value);			//aggiunge in cima un numero intero
    int     pop();						//toglie il blocco in cima, Il comando ci restituisce il valore del blocco che abbiamo tolto.
    bool    empty();					//chiedo se la pila è vuota, e riceverò come risposta true o false
    bool    full();						//chiedo se la pila è piena, e riceverò come risposta true o false
};

stack::stack() {						//è una "ricetta" per costruire una nuova pila
    top = 0;		//top è come un'etichetta che ci dice dove si trova il blocco più in alto della pila. 
					//Quando la pila è vuota, vogliamo che l'etichetta punti a un posto che indica che non 
					//ci sono blocchi. In questo caso, impostiamo top a 0. Questo è un modo per dire: 
					//"La pila è vuota, quindi l'etichetta è all'inizio".
};

stack::stack(const stack& other) {			//"Costruisci una nuova pila, ma prendi un'altra pila (chiamata 'other') 
											//come modello". La parola "const" dice che non cambieremo la pila "other", la guardiamo solo.
    for (int i = 0; i < STACK_SIZE; i++)	//è un "ciclo". Immagina di dover copiare ogni blocco dalla pila "other" alla nostra nuova pila, 
											//uno per uno. "i" è come un contatore che ci aiuta a tenere traccia di quale blocco stiamo copiando. 
											//Iniziamo con il blocco in basso (i=0) e continuiamo fino all'ultimo blocco (i < STACK_SIZE). 
											//STACK_SIZE is the maximum number of blocks the stack can hold.
        data[i] = other.data[i];			//"data[i]" è il posto dove mettiamo il blocco nella nostra nuova pila. "other.data[i]" 
											//è il blocco corrispondente nella pila "other". 
											//Quindi, stiamo copiando il blocco dalla pila "other" alla nostra nuova pila.
};

void stack::push(int value) {			//Immagina di avere un nuovo blocco con un numero scritto sopra, e vuoi metterlo sulla pila. 
										//"push" è come un comando per dire "metti questo blocco in cima". 
										//"int value" è il numero scritto sul blocco che vuoi aggiungere. 
										//"void" significa che questa azione non restituisce un valore.
    if (top < STACK_SIZE)				//"top"? Ci dice dove si trova il blocco più in alto. "STACK_SIZE" è il numero massimo di blocchi 
										//che la pila può contenere. Quindi, questa riga controlla se c'è ancora spazio sulla pila. 
										//Se "top" è minore di "STACK_SIZE", significa che c'è spazio per un altro blocco.
        data[top++] = value;			//Questa è la parte dove mettiamo il blocco sulla pila
										//data[top]: Questo è il punto esatto dove metteremo il nuovo mattoncino. 
										//Pensa a "data" come allo spazio dove teniamo tutti i mattoncini, e "top" è come un numero 
										//che ci dice "metti il prossimo mattoncino qui".
										//value: Questo è il colore del mattoncino che stiamo aggiungendo.
										//top++: Questo è un trucchetto furbo! Fa due cose insieme:
										//Prima, usa il numero "top" per sapere dove mettere il mattoncino.
										//Poi, aggiunge 1 al numero "top", così la prossima volta sapremo dove mettere il mattoncino successivo.
};

int stack::pop() {						//"togli il blocco in cima". "int" significa che questo comando ci darà indietro 
										//il valore (il numero) del blocco che abbiamo tolto.
    if (top > 0)						//"top"? Ci dice dove si trova il blocco più in alto. Questa riga controlla se ci sono blocchi sulla pila. 
										//Se "top" è maggiore di 0, significa che c'è almeno un blocco da togliere.
        return data[--top];				//Questa è la parte dove togliamo il blocco.
										//--top: Questo è un altro trucchetto furbo! Fa due cose insieme. Prima, toglie 1 da "top". 
										//Poi usa il nuovo valore di "top" per accedere ai dati.
										//data[top]: Questo è il valore del blocco che stiamo togliendo.
										//return: Il comando restituisce il valore del blocco che abbiamo tolto.

    return 0;
};

bool stack::empty() {					//chiedo se la pila è vuota, e riceverò come risposta true o false
    return (top == 0);					//Se "top" è uguale a 0, significa che non ci sono blocchi sulla pila, quindi la pila è vuota.
										//"return" dice al programma di dare come risposta "vero" (true) se la pila è vuota, 
										//e "falso" (false) se la pila non è vuota.
};

bool stack::full() {					//chiedo se la pila è piena, e riceverò come risposta true o false
    return (top == 0);					//STACK_SIZE è il numero massimo di blocchi che la pila può contenere.
										//Se "top" è uguale a STACK_SIZE, significa che abbiamo riempito tutti gli spazi disponibili nella pila, quindi la pila è piena.
										//"return" dice al programma di dare come risposta "vero" (true) se la pila è piena, e "falso" (false) se la pila non è piena.

	return (top == STACK_SIZE);			//Controlla se il numero di blocchi nella pila è uguale al numero massimo di blocchi che può contenere. 
										//Se sono uguali, restituisci 'vero' (true), altrimenti restituisci 'falso' (false)
};

int main(void)
{
    stack s;																//Qui stiamo creando una nuova pila di mattoncini e la chiamiamo "s". 
																			//È come avere una scatola vuota pronta per essere riempita di mattoncini.
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";		//std::boolalpha: Questo è un modo per far stampare "true" o "false" invece di 1 o 0
																			//"\n" va a capo
	std::cout << "Pushing 10 and 20\n";
	s.push(10);																//aggiungiamo un mattoncino con il numero 10 in cima alla pila.
    s.push(20);																// Aggiungiamo un altro mattoncino, questa volta con il numero 20, in cima alla pila. 
																			//Ora la pila ha due mattoncini: 10 in basso e 20 in cima.
    std::cout << s.pop() << "\n";											//Togliamo il mattoncino in cima alla pila (che è il 20) e il programma ci dice qual era il suo numero.
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";		//Chiediamo di nuovo se la pila è vuota. Ora la pila ha solo un mattoncino (il 10), 
																			//quindi stamperà "Is empty: false".
    std::cout << s.pop() << "\n";
    std::cout << "Is empty: " << std::boolalpha << s.empty() << "\n";

    return 0;
}

