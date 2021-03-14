// HareAndHound.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>


static unsigned int HOUND_POS_VALUES[11] = { 2147483648, 1073741824, 536870912, 268435456, 134217728, 67108864, 33554432, 16777216, 8388608, 4194304 };


struct t_houndMove {
    int from, to;
};

class t_gameState {


    private:

        int hounds[3] = { 0,0,0 };
        int hare;
        int repetitions;

        std::vector<t_houndMove> houndMoves;
        std::vector<int> hareMoves;

    public:

        // creates a state object from a state integer
        t_gameState(unsigned int state_data) {

            int ch = 0;
            int shift = 0;
            while (ch < 3) {
                if ((state_data >> 21 + shift) % 2 == 1) {
                    hounds[ch] = 10 - shift;
                    ch++;
                }
                shift++;
            }

            hare = ((state_data << 16) >> 24);

            repetitions = ((state_data << 24) >> 24);

        }

        void debug_stuff() {
            
            hounds[0] = 3;
            hounds[1] = 6;
            hounds[2] = 8;

            hare = 7;

            repetitions = 8;

        }

        // builds the game state integer from the object.
        unsigned int get_state_data() {
            unsigned int res = 0;
            for (int i = 0; i < 3; i++) {
                res += HOUND_POS_VALUES[hounds[i]];
            }
            res += (hare << 8);
            res += repetitions;
            return res;
        }

        void update_hound_moves() {

        }

        void update_hare_moves() {

        }

        // returns:
        // -1 if the hare wins
        // 0 if the game is not over
        // 1 if the hounds win
        int get_state_result() {

            // if num_rep >= 10 : return -1

            // get hound positions h1 h2 h3

            // get hare position hare

            // if each adjacent position 

        }

        void print_state() {
            std::cout << "STATE - hounds: " << hounds[0] << " " << hounds[1] << " " << hounds[2] << " hare: " << hare << " repetitions: " << repetitions << "\n";
        }

};


int main()
{

    unsigned int initial_case = 0b01001001'00000000'00000101'00000011;

    t_gameState myState(initial_case);
    myState.print_state();
    myState.debug_stuff();
    myState.print_state();
    std::cout << myState.get_state_data() << std::endl;

    unsigned int x = 0b00010010'10000000'00000111'00001000;


}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
