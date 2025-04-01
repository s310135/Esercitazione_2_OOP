#include <iostream>
#include <optional>

#define STACK_SIZE 8

template<typename T>
struct stack {
    T       data[STACK_SIZE];
    int     top;

    stack()
        : top(0)
    {}
    
    stack(const stack& other) {
        for (int i = 0; i < STACK_SIZE; i++)
            data[i] = other.data[i];
    }
    
    /* Better implementation: push can notify a failure */		//aggiungo e tolgo solo in cima
    bool push(const T& value) {					//aggiungi value in cima
												//dà true se ci è riuscito, false se non c'è più spazio
												//const T& value significa che può accettare qualsiasi tipo di valore, e non cambierà il valore originale
        if (top < STACK_SIZE) {					//controlla se c'è ancora spazio
            data[top++] = value;				//se c'è ancora spazio viene aggiunto value in cima
												//data è il "contenitore"
												//top++ prima usa il valore attuale di top, e poi aumenta il valore di top di uno.
            return true;						//se è stato aggiunto l'elemento
        }

        return false;							//se l'elemento non è stato aggiunto
    }
    
    /* Better implementation: pop can signal a failure by
     * returning an empty std::optional
     */
    std::optional<T> pop() {					//prende l'ultimo elemento aggiunto
												//std::optional<T> significa che potrebbe esserci un tipo qualsiasi o niente
        if (top > 0)							//cioè se la "scatola" non è vuota
            return data[--top];					//--top prima toglie 1 da top (quindi si sposta "giù" nella scatola), 
												//e poi usa quel nuovo valore di top per prendere l'elm da data. 
												//Quindi, prende l'ultimo elm, e poi abbassa il contatore top.
												//return manda l'elm dove richiesto
        return {};								//Se top era 0 (significa che la scatola era vuota), questa riga non restituisce niente
    }											//oppure restituisce il primo valore in cima

    bool empty() const {
        return (top == 0);
    }

    bool full() const {
        return (top == STACK_SIZE);
    }
};

struct meteo_data {
    std::string location;
    double      temperature;
    double      pressure;
};

int main(void)
{
    std::cout << "--- Stack of meteo_data ---" << std::endl;
    stack<meteo_data> sm;
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    sm.push({"Torino", 25.1, 1013.0});
    sm.push({"Milano", 23.1, 1015.0});
    std::cout << "Is empty: " << std::boolalpha << sm.empty() << "\n";
    std::optional<meteo_data> mdo = sm.pop();
    if (mdo) {															//controlla se dentro mdo c'è qualcosa
        meteo_data md = mdo.value();									//Se la scatola mdo ha qualcosa, questa riga prende le informazioni meteo dalla scatola e le mette in una variabile chiamata md
        std::cout << md.location << ", " << md.temperature << ", ";		//std::cout è il comando che stampa il testo sullo schermo.
																		//md.location sono le informazioni sulla posizione dei dati meteo.
																		//md.temperature sono le informazioni sulla temperatura.
																		//md.pressure sono le informazioni sulla pressione.
																		//std::endl significa andare alla riga successiva sullo schermo.
        std::cout << md.pressure << std::endl;
    } else {															//Se la scatola mdo era vuota (significa che non c'erano informazioni meteo), questa parte del codice viene eseguita
        std::cout << "Error: popped an empty stack" << std::endl;
        return 1;
    }
    
    return 0;
}

