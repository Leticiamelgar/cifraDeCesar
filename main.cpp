#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

std::string criptografarCesar (const std::string& texto, int chave){
    std::string resultado = "";
    chave = chave % 26;
    
    for (char caractere : texto) {
        if (isalpha(caractere)){
            char base = islower(caractere) ? 'a' : 'A' ;
            caractere = (caractere - base + chave) % 26 + base;
        }
        resultado += caractere;
    }
    return resultado;
}


void criptoanaliseFrequencia (const std::string& textoCifrado){
    cout << "iniciando criptoanálise por frequência" << endl;
    std::vector<int>frequencia(26,0);
    int totalLetras = 0;

    for (char c : textoCifrado){
        if(isalpha(c)){
            frequencia[tolower(c)- 'a']++;
            totalLetras++;
        }
    }
    if (totalLetras == 0) {
        std::cout << "Não há letras para analisar" << std::endl;
        return;
    }

    int maxFrequencia = 0;
    int indiceMaisFrequente = 0;
    for (int i = 0; i<26; i++) {
        if (frequencia[i]>maxFrequencia){
            maxFrequencia = frequencia[i];
            indiceMaisFrequente = i;
        }
    }
    
    const int indiceE = 4;
    int chaveProvavel = (indiceMaisFrequente - indiceE + 26) % 26;
    cout << "A letra mais frequente nesse texto é: " << char ('a' + indiceMaisFrequente) << endl;
    
}



int main (){
    std::string mensagem;
    int chave;
    cout << "Digite a mensagem" << endl;
    std::getline(std::cin,mensagem);
    cout << "Digite a chave: "<< endl;
    std::cin >> chave;
    std::string mensagemCriptografada = criptografarCesar(mensagem,chave);
    std::cout << "Mensagem Criptografada: " << mensagemCriptografada << endl;

    criptoanaliseFrequencia(mensagem);
}