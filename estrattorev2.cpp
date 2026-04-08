#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    
    string studenti[27] = {
        "acierno vito", "alfano andrea", "attrotto giovanni pio", "baroni andrea",
        "belletti davide", "cagnacci dario", "chafqi mohammed", "decataldo samuele",
        "di donna raffaele", "dioguardi gabriele", "el jihad imane", "ezziymy rayane",
        "ferrari luca", "lotierzo gabriele", "martinelli mattia", "niscio paolo",
        "restino marco", "rima lorenzo", "siwek kamil", "tarasco alessandro",
        "tramontana ernesto", "turci luca", "ventura federico", "vicini emilio ruggero",
        "vicini lorenzo", "wang yi nicky", "zarra matteo"
    };
    
    bool presenti[27];
    for (int i = 0; i < 27; i++) {
        presenti[i] = true;
    }

    int scelta;
    
    do {
        cout << "\n--- menu ---\n";
        cout << "1. visualizza tutti gli studenti\n";
        cout << "2. elimina momentaneamente gli assenti\n";
        cout << "3. visualizza studenti presenti\n";
        cout << "4. estrai studenti presenti\n";
        cout << "0. esci\n";
        cout << "scelta: ";
        cin >> scelta;
        
        switch (scelta) {
            case 1:
                cout << "\nregistro completo:\n";
                for (int i = 0; i < 27; i++) {
                    cout << i + 1 << " - " << studenti[i] << "\n";
                }
                break;
                
            case 2:
                int num_assente;
                cout << "\ninserisci il numero dello studente assente (0 per terminare): ";
                cin >> num_assente;
                while (num_assente != 0) {
                    if (num_assente >= 1 && num_assente <= 27) {
                        presenti[num_assente - 1] = false;
                        cout << "studente rimosso.\n";
                    } else {
                        cout << "numero non valido.\n";
                    }
                    cout << "inserisci un altro assente (0 per terminare): ";
                    cin >> num_assente;
                }
                break;
                
            case 3:
                cout << "\nstudenti presenti:\n";
                for (int i = 0; i < 27; i++) {
                    if (presenti[i]) {
                        cout << i + 1 << " - " << studenti[i] << "\n";
                    }
                }
                break;
                
            case 4:
                int num_estrarre;
                cout << "\nquanti studenti vuoi estrarre? (da 1 a 10): ";
                cin >> num_estrarre;
                
                if (num_estrarre < 1) {
                    num_estrarre = 1;
                }
                if (num_estrarre > 10) {
                    num_estrarre = 10;
                }
                
                int conta_presenti;
                conta_presenti = 0;
                for (int i = 0; i < 27; i++) {
                    if (presenti[i]) {
                        conta_presenti++;
                    }
                }
                
                if (num_estrarre > conta_presenti) {
                    num_estrarre = conta_presenti;
                }
                
                if (conta_presenti == 0) {
                    cout << "errore: nessun studente presente.\n";
                } else {
                    bool estratti[27];
                    for (int i = 0; i < 27; i++) {
                        estratti[i] = false;
                    }
                    
                    cout << "\nstudenti estratti:\n";
                    for (int i = 0; i < num_estrarre; i++) {
                        int r;
                        do {
                            r = rand() % 27;
                        } while (presenti[r] == false || estratti[r] == true);
                        
                        estratti[r] = true;
                        cout << r + 1 << " - " << studenti[r] << "\n";
                    }
                }
                break;
                
            case 0:
                cout << "\nuscita dal programma.\n";
                break;
                
            default:
                cout << "\nscelta non valida, riprova.\n";
        }
    } while (scelta != 0);

    return 0;
}