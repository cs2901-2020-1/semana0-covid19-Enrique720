#include <fstream>
#include <iostream>

using namespace std;

int main(){
    int iguales=0;
    int diferentes=0;

    fstream file1;
    fstream file2;
    file1.open("AY274119.txt",ios::in);
    file2.open("AY278488.2.txt",ios::in);

    if(!file1.is_open())
        cout << "File 1 is not working" <<endl;
    if(!file2.is_open())
        cout << "File 1 is not working" <<endl;

    string word1;
    getline(file1,word1);

    string word2;
    getline(file2,word2);

    int lenghtFirst;

    while(    file1 >> word1  &&  file2 >> word2    ){
        int range = max(word1.size(),word2.size());
        if( word1.size() != word2.size() ){
            lenghtFirst = iguales + diferentes + min(word1.size(),word2.size());
        }
        for(int i = 0; i < range; i++){
            if(word2[i] == word1[i])
            {iguales++;}
            else
            {diferentes++;}


        }
    }

    int total;
    if(file1.eof() && file2.eof()){
        total = iguales+diferentes;
     }
    else if(file2.eof()){
        diferentes += word1.size();
        while(file1 >> word1) {
            diferentes += word1.size();
        }
    }
    else if(file1.eof()){
        diferentes += word2.size();
        while(file2 >> word2){
            diferentes += word2.size();
        }
    }
    cout << "El porcentaje de igualdad entre los genomas es: " << float(iguales)*100/float(lenghtFirst) <<endl;
    cout << "Hay una diferencia de " << diferentes+iguales - (lenghtFirst) << " caracteres entre ambos genomas" << endl;
    return 0;

}
