#include <iostream>
#include "cstdlib"
#include "ctime"
#include "algorithm"
#include "fstream"
#include <unistd.h>
#include "random"


using namespace std;
string typicalError="nie możemy kontynuować programu cos poszło nie tak w procesie produkcji :)";//nie powinno sie tak przechowywać kodów błędów
int main() {
#pragma region zmienne
    int linesInFile = 0;//zmienna do sprawdzenia ilości linijek
    char dec;
    string answer;
    char username[10];
    string currentLine;
    ifstream dataBase("pytania.txt");
    string qaTable[1000];
    string linie;
    int round = 0;
    srand((int)time(0));
    bool friendNumberUsage = 0;
    bool halfToHalfUsage = 0;
    bool askAudienceUsage = 0;
    string friendPhone[10];
    string halfToHalf[3];
    string askAudience[3];
    string endKey;
    int cash[13] = { 500, 1000, 2000, 5000, 10000, 20000, 40000, 75000, 125000, 250000, 50000, 1000000};
    int nums[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                    11, 12, 13, 14, 15,};
#pragma endregion zmienne
#pragma region Powitanie
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$                                           $$" << endl;
    cout << "$$                                           $$" << endl;
    cout << "$------------------Milioners------------------$" << endl;
    cout << "$$                                           $$" << endl;
    cout << "$$                                           $$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$PRACA WYKONANA PRZEZ$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$Lukasz Gańczarczyk$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "Podaj swoje imię: " << endl;
    cin >> username;
    cout << "Witaj  " << username << endl;
    cout << "Przed tobą 12 pytań do miliona" << endl << "Posiadasz 3 koła ratunkowe:" << endl
         << "1-Telefon do przyjaciela" << endl
         << "2-Publiczność" << endl << "3-Pol na pol" << endl << endl;
    cout << "W takim razie zaczynamy: " << username << endl;
#pragma endregion Powitanie
#pragma region rozpoczęcie gry
    po1:
    cout << "Naciśnij T aby zacząć" << endl;
    cin >> dec;
    if (dec == 't' && 'T') {
        goto po2;
    } else if (!dec == 't' && 'T') {
        cout << "Po prostu wciśnij T jak będziesz gotowy: " << endl;
        goto po1;
    }
#pragma endregion
#pragma region obsługa pliku i przypisanie pytań w tablicy
    po2:        /*sprawdzenie czy na pewno ilości linijek w teksie jest podzielna przez 6
                 * dla zapewnienia  ze algorytm będzie dial poprawnie*/
    int a = 1;
    if (dataBase.is_open()) {
        while (!dataBase.eof()) {
            getline(dataBase, qaTable[a]);
            linesInFile++;
            a++;
        }
        //dataBase.close();
        if (linesInFile / 6 == 16) {/*jeżeli znamy ilości pytań w puli sprawdzam czy na pewno plik został stworzony poprawnie można
            zastąpić wartość 16 jakimś int deklarowanym na początku przez huberta Urbańskiego lub produkcje*/
            cout << "Inicjalizacja przebiegła poprawnie" << endl;
            dataBase.close();
            goto po3;
        } else
            throw logic_error(typicalError);//obsługa bledu złej ilości wierszy w  pliku
    } else {
        throw logic_error(typicalError);
    }
#pragma endregion PO2
#pragma region losowanie pytań
    po3:
    cout << "LosowanieTwoichPytań" << endl;
    for (int i = 3; i > 0; --i) {
        cout << i << endl;
        sleep(1);
    }
    random_shuffle(nums, nums + 16);
    cout << "znam juz twoje pytania zapewne teraz ty tez chcesz je poznać" << endl;
    goto po4;
#pragma endregion
#pragma region Wlaściwa gra
    po4:
    int y;
    string gwarantowana = "Nie osiągnięto żadnej sumy gwarantowanej";
    if (cash[round] == 2000) {//Gwarantowana 1
        cout << "Zdobywasz gwarantowane: " << endl << "1000" << endl;
        gwarantowana = "1000";
    }
    if (cash[round] == 70000) {
        cout << "zdobywasz gwarantowane: " << endl << "40000" << endl;
        gwarantowana = "40000";
    }//Gwarantowana 2
    string conversion;
    y = nums[round] * 6;
    cout << "Grasz teraz o: " << cash[round] << endl << " Powodzenia!!!!" << endl;
    cout << "Pytanie: " << round + 1 << endl;
    cout << qaTable[y + 1] << endl;
    cout << qaTable[y + 2] << endl;
    cout << qaTable[y + 3] << endl;
    cout << qaTable[y + 4] << endl;
    cout << qaTable[y + 5] << endl;
    exit_function:
    cout << "Twoja odpowiedz to: " << endl;
    cin >> answer;
    if (answer == qaTable[y + 6]) {
        cout << "Dobra odpowiedz zdobywasz: " << endl << cash[round] << endl;
        if (cash[round]==1000000){
            goto end_Win;
        }
        round++;
        goto po4;
        }
    else if (answer == "1" & friendNumberUsage==0) {
        cout << "Użyłeś koła ratunkowego :" << endl<<"Telefon do przyjaciela"<<endl;
        friendNumberUsage=1;
        if(qaTable[y+6]=="A"){
        friendPhone[0] = {"A"};
        friendPhone[1] = {"A"};
        friendPhone[2] = {"A"};
        friendPhone[3] = {"A"};
        friendPhone[4] = {"A"};
        friendPhone[5] = {"A"};
        friendPhone[6] = {"A"};
        friendPhone[7] = {"B"};
        friendPhone[8] = {"C"};
        friendPhone[9] = {"D"};
        int randNumbA=(rand()%10);
        cout<<"Podpowiedz od przyjaciela to: "<<friendPhone[randNumbA]<<endl;
        }
        else if(qaTable[y+6]=="B"){
            friendPhone[0] = {"B"};
            friendPhone[1] = {"B"};
            friendPhone[2] = {"B"};
            friendPhone[3] = {"B"};
            friendPhone[4] = {"B"};
            friendPhone[5] = {"B"};
            friendPhone[6] = {"B"};
            friendPhone[7] = {"A"};
            friendPhone[8] = {"C"};
            friendPhone[9] = {"D"};
            int randNumbB=(rand()%10);
            cout<<"Podpowiedz od przyjaciela to: "<<friendPhone[randNumbB]<<endl;
        }
        else if(qaTable[y+6]=="C"){
            friendPhone[0] = {"C"};
            friendPhone[1] = {"C"};
            friendPhone[2] = {"C"};
            friendPhone[3] = {"C"};
            friendPhone[4] = {"C"};
            friendPhone[5] = {"C"};
            friendPhone[6] = {"C"};
            friendPhone[7] = {"A"};
            friendPhone[8] = {"B"};
            friendPhone[9] = {"D"};
            int randNumbC=(rand()%10);
            cout<<"Podpowiedz od przyjaciela to: "<<friendPhone[randNumbC]<<endl;
        }
        else if(qaTable[y+6]=="D"){
            friendPhone[0] = {"D"};
            friendPhone[1] = {"D"};
            friendPhone[2] = {"D"};
            friendPhone[3] = {"D"};
            friendPhone[4] = {"D"};
            friendPhone[5] = {"D"};
            friendPhone[6] = {"D"};
            friendPhone[7] = {"B"};
            friendPhone[8] = {"C"};
            friendPhone[9] = {"A"};
            int randNumbD=(rand()%10);
            cout<<"Podpowiedz od przyjaciela to: "<<friendPhone[randNumbD]<<endl;
        }
        goto exit_function;
    }//Telefon do przyjaciela 70% na poprawna odpowiedz
    else if (answer=="1" & friendNumberUsage==1) {
        cout << "Telefon do przyjaciela został już przez ciebie użyty"<<endl;
        goto exit_function;
    }//Telefon do przyjaciela po raz 2
    else if (answer == "2" & askAudienceUsage==0) {
        cout << "Użyłeś koła ratunkowego: " << endl<<"pytanie do publiczności"<<endl;
        string answerAudience;
        if (qaTable[y+6]=="A"){
            answerAudience="A";
            askAudience[0]="B";
            askAudience[1]="C";
            askAudience[2]="D";
            random_shuffle(askAudience,askAudience+3);
            goto audienceRandom;
        }
        if (qaTable[y+6]=="B"){
            answerAudience="B";
            askAudience[0]="A";
            askAudience[1]="C";
            askAudience[2]="D";
            random_shuffle(askAudience,askAudience+3);
            goto audienceRandom;
        }
        if (qaTable[y+6]=="C"){
            answerAudience="C";
            askAudience[0]="B";
            askAudience[1]="A";
            askAudience[2]="D";
            random_shuffle(askAudience,askAudience+3);
            goto audienceRandom;
        }
        if (qaTable[y+6]=="D"){
            answerAudience="D";
            askAudience[0]="B";
            askAudience[1]="C";
            askAudience[2]="A";
            random_shuffle(askAudience,askAudience+3);
            goto audienceRandom;
        }
        audienceRandom:
            int audienceRandomPercent=40+rand()%(60-40+1); //losowanie procent poprawnej odpowiedzi od 40 do 60%
            int audienceRandomPercentSecondPosition=rand()%((100-audienceRandomPercent)+1);
            int audienceRandomPercentThreePosition=rand()%((100-(audienceRandomPercent+audienceRandomPercentSecondPosition))+1);
            int audienceRandomPercentFourthPosition=(100-(audienceRandomPercent+audienceRandomPercentSecondPosition+audienceRandomPercentThreePosition));
            cout<<"Odpowiedzi publiczności to: "<<endl<<answerAudience<<":"<<audienceRandomPercent<<"%"<<endl<<
            askAudience[0]<<":"<<audienceRandomPercentSecondPosition<<"%"<<endl<<askAudience[1]<<":"<<audienceRandomPercentThreePosition<<"%"<<endl<<
            askAudience[2]<<":"<<audienceRandomPercentFourthPosition<<"%"<<endl;
        goto exit_function;
    }//pytanie do publiczności
    else if (answer=="2"&askAudienceUsage==1){
        cout<<"Użyłeś juz koła ratunkowego pytanie do publiczności"<<endl;
        goto exit_function;
    }//pytanie do publiczność użyte po raz 2
    else if (answer == "3" & halfToHalfUsage==0) {//Poł na poł
        cout << "Użyłeś koła ratunkowego:" << endl << "Pół na Pół" << endl;
        if (qaTable[y + 6] == "A") {
            halfToHalf[0] = {"B"};
            halfToHalf[1] = {"C"};
            halfToHalf[2] = {"D"};
            int randNumbHalfToHalfA = (rand() % 3);
            cout << "Podpowiedz od przyjaciela to: " << friendPhone[randNumbHalfToHalfA] << " oraz " << qaTable[y + 6]
                 << endl;
        }
        if (qaTable[y + 6] == "B") {
            halfToHalf[0] = {"A"};
            halfToHalf[1] = {"C"};
            halfToHalf[2] = {"D"};
            int randNumbHalfToHalfA = (rand() % 3);
            cout << "Podpowiedz od przyjaciela to: " << friendPhone[randNumbHalfToHalfA] << " oraz " << qaTable[y + 6]
                 << endl;
        }
        if (qaTable[y + 6] == "C") {
            halfToHalf[0] = {"B"};
            halfToHalf[1] = {"A"};
            halfToHalf[2] = {"D"};
            int randNumbHalfToHalfA = (rand() % 3);
            cout << "Podpowiedz od przyjaciela to: " << friendPhone[randNumbHalfToHalfA] << " oraz " << qaTable[y + 6]
                 << endl;
        }
        if (qaTable[y + 6] == "D") {
            halfToHalf[0] = {"B"};
            halfToHalf[1] = {"C"};
            halfToHalf[2] = {"A"};
            int randNumbHalfToHalfA = (rand() % 3);
            cout << "Podpowiedz od przyjaciela to: " << friendPhone[randNumbHalfToHalfA] << " oraz " << qaTable[y + 6]
                 << endl;
        }
    }//Poł na poł
    else if (answer=="3"&halfToHalfUsage==1){
        cout<<"Niestety koło ratunkowe poł na poł zostało użyte wcześniej"<<endl;
        goto exit_function;
    }//Poł na poł użyte 2 raz
    else if (answer=="a" || answer=="b"||answer=="c"||answer=="d") {
        cout << "Używaj tylko dużych liter lub cyfr 1,2,3 " << endl;
        goto exit_function;}//użycie małej litery
    else{
        cout<<"Niestety nie udało cie sie zdobyć miliona"<<endl<<"Ale zdobywasz: "<<gwarantowana<<endl;
        cout<<"Aby zakończyć rozgrywkę wciśnij 5"<<endl;
        cin>>endKey;
        if(endKey=="5"){
            return 0;
        }
        else{
            return 0;
        }
    }
    end_Win:
    cout<<"Udało ci sie zdobyć Milion"<<endl;
    cout<<"Gratulacje"<<endl;
    cout<<"Aby zakończyć rozgrywkę wciśnij 5"<<endl;
    cin>>endKey;
    if(endKey=="4"){
        goto po1;
    }
    else if(endKey=="5"){
        return 0;
    }
    else{
        return 0;
    }
#pragma endregion
}







