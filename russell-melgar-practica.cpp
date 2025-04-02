/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Función para limpiar la pantalla (multi-plataforma)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Función para validar entrada del usuario
int getValidInput(int minOption, int maxOption) {
    int choice;
    while (true) {
        cout << "Elige una opción (" << minOption << "-" << maxOption << "): ";
        cin >> choice;
        
        if (cin.fail() || choice < minOption || choice > maxOption) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Opción inválida. Por favor intenta de nuevo.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

// Función para el combate con el mayordomo
bool fightButler() {
    int attempts = 3;
    int playerChoice;
    
    cout << "\nEl mayordomo te ataca! Tienes 3 intentos para derrotarlo.\n";
    
    while (attempts > 0) {
        cout << "\nIntentos restantes: " << attempts << endl;
        cout << "1. Golpear con el candelabro\n";
        cout << "2. Esquivar y empujar\n";
        cout << "3. Usar el crucifijo\n";
        
        playerChoice = getValidInput(1, 3);
        
        if (playerChoice == 3) {
            cout << "\nEl mayordomo retrocede al ver el crucifijo! Parece tener miedo de él.\n";
            cout << "Logras derrotarlo y huye por la ventana.\n";
            return true;
        } else {
            cout << "\nEl mayordomo esquiva tu ataque y te golpea!\n";
            attempts--;
        }
    }
    
    cout << "\nEl mayordomo te ha derrotado! Te ata y llama a la policía.\n";
    return false;
}

int main() {
    clearScreen();
    
    // Introducción
    cout << "=== EL MISTERIO DE LA MANSION BLACKWOOD ===\n\n";
    cout << "Eres un detective investigando la desaparición de Lord Blackwood.\n";
    cout << "Una noche tormentosa, decides entrar a la mansión abandonada...\n";
    cout << "Al entrar, escuchas un ruido proveniente de la cocina y ves una escalera que sube al segundo piso.\n\n";
    
    int mainChoice;
    bool hasClue = false;
    
    // Primer punto de decisión
    while (true) {
        cout << "\n¿Qué deseas hacer?\n";
        cout << "1. Investigar el ruido en la cocina\n";
        cout << "2. Subir las escaleras\n";
        cout << "3. Salir de la mansión (abandonar el caso)\n";
        
        mainChoice = getValidInput(1, 3);
        
        if (mainChoice == 1) {
            // Opción 1: Investigar el ruido
            clearScreen();
            cout << "\nAvanzas sigilosamente hacia la cocina...\n";
            cout << "De repente, el mayordomo de Blackwood aparece frente a ti con una mirada amenazante!\n";
            
            int kitchenChoice;
            cout << "\n¿Qué haces?\n";
            cout << "1. Intentar huir de la mansión\n";
            cout << "2. Enfrentar al mayordomo\n";
            
            kitchenChoice = getValidInput(1, 2);
            
            if (kitchenChoice == 1) {
                // Final 1: Huir
                clearScreen();
                cout << "\nCorres hacia la puerta principal y logras escapar de la mansión.\n";
                cout << "Pero el misterio de la desaparición de Lord Blackwood queda sin resolver...\n";
                cout << "\n=== FINAL 1: ESCAPAS PERO SIN RESPUESTAS ===\n";
                return 0;
            } else {
                // Combate con el mayordomo
                bool wonFight = fightButler();
                
                if (wonFight) {
                    // Final 2: Resuelves el misterio
                    clearScreen();
                    cout << "\nAl derrotar al mayordomo, encuentras un diario escondido.\n";
                    cout << "El diario revela que Lord Blackwood descubrió que su mayordomo era un vampiro.\n";
                    cout << "El mayordomo lo encerró en la cripta familiar para convertirlo.\n";
                    cout << "Llamas a la policía y rescatan a Lord Blackwood a tiempo.\n";
                    cout << "\n=== FINAL 2: RESUELVES EL MISTERIO ===\n";
                    return 0;
                } else {
                    // Final 3: Capturado
                    clearScreen();
                    cout << "\nEl mayordomo te ha capturado. Te lleva al sótano donde encuentras a Lord Blackwood.\n";
                    cout << "Ahora ambos son prisioneros del mayordomo vampiro...\n";
                    cout << "\n=== FINAL 3: CAPTURADO ===\n";
                    return 0;
                }
            }
        } else if (mainChoice == 2) {
            // Opción 2: Subir las escaleras
            clearScreen();
            cout << "\nSubes las escaleras que crujen bajo tus pies...\n";
            cout << "En el pasillo hay dos puertas: una a la izquierda y otra a la derecha.\n";
            
            int upstairsChoice;
            cout << "\n¿Qué puerta eliges?\n";
            cout << "1. Habitación izquierda (antiguo estudio)\n";
            cout << "2. Habitación derecha (biblioteca)\n";
            
            upstairsChoice = getValidInput(1, 2);
            
            if (upstairsChoice == 1) {
                // Habitación izquierda
                clearScreen();
                cout << "\nEntras al antiguo estudio de Lord Blackwood.\n";
                cout << "Un cuadro en la pared parece estar torcido...\n";
                cout << "Al ajustarlo, descubres un compartimiento secreto con documentos!\n";
                cout << "Has encontrado una pista importante!\n";
                hasClue = true;
            } else {
                // Habitación derecha (biblioteca)
                clearScreen();
                cout << "\nEntras a la biblioteca, llena de libros antiguos.\n";
                cout << "Un libro en particular llama tu atención: 'De Vampiris' de Ludovico Fuscus.\n";
                
                int bookChoice;
                cout << "\n¿Qué haces con el libro?\n";
                cout << "1. Leer el libro prohibido\n";
                cout << "2. Ignorarlo y seguir investigando\n";
                
                bookChoice = getValidInput(1, 2);
                
                if (bookChoice == 1) {
                    // Final 4: Maldición
                    clearScreen();
                    cout << "\nAl abrir el libro, una extraña energía te envuelve.\n";
                    cout << "Las palabras parecen moverse y quemarse en tu mente...\n";
                    cout << "Sientes cómo tu alma es consumida por la maldición del libro.\n";
                    cout << "Ahora eres otro sirviente de la oscuridad en la mansión Blackwood.\n";
                    cout << "\n=== FINAL 4: MALDITO ===\n";
                    return 0;
                } else {
                    cout << "\nDecides no tentar al destino y dejas el libro donde estaba.\n";
                }
            }
            
            // Volver al punto de decisión principal
            cout << "\nRegresas al vestíbulo principal.\n";
        } else {
            // Opción 3: Salir (Final 1)
            clearScreen();
            cout << "\nDecides que este caso es demasiado peligroso y abandonas la mansión.\n";
            cout << "El misterio de la desaparición de Lord Blackwood queda sin resolver...\n";
            cout << "\n=== FINAL 1: ESCAPAS PERO SIN RESPUESTAS ===\n";
            return 0;
        }
        
        // Si el jugador tiene la pista, puede terminar la historia
        if (hasClue) {
            clearScreen();
            cout << "\nCon la pista encontrada en el estudio, llamas a la policía.\n";
            cout << "Regresan contigo a la mansión y arrestan al mayordomo.\n";
            cout << "Encuentran a Lord Blackwood encerrado en la cripta familiar.\n";
            cout << "Has resuelto el caso con éxito!\n";
            cout << "\n=== FINAL ALTERNATIVO: DETECTIVE EXITOSO ===\n";
            return 0;
        }
    }
    
    return 0;
}