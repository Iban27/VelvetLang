//#include <vlvtcompiler.h>
#include "vlvtcompiler.h"
//#include <stdio.h>
#define MAXWORDLENGTH 50

struct specialSymbolPair{
    char symbol;
    enum tokTypes type;
} specialSymbols[] = {
    {'+', Plus},
    {'-', Minus},
    {'*', Mul},
    {'/', Div},
    {'++', PlusPlus},
    {'--', MinusMinus},
    {'<', Ls},
    {'>', Gr},
    {'==', Equal},
    {'!=', NotEqual},
    {'<=', LsEqual},
    {'>=', GrEqual},
    {'=', Assign},
    {',', Comma},
    {'.', Dot},
    {'?', Question},
    {':', Colon},
    {';', SmColon},
    {'(', OpParen},
    {')', ClParen},
    {'{', OpBlock},
    {'}', ClBlock},
    {'[', OpBrac},
    {']', ClBrac},
    {LastTok}
};
struct specialWordsPair{
    char *word;
    enum tokTypes type;
} specialWords[] = {
    {'void', Void},
    {'null', Null},
    {'NONE', None},
    {'int', Int},
    {'float', Float},
    {'compn', Compn},
    {'if', If},
    {'else', Else},
    {'for', For},
    {'while', While},
    {'continue', Continue},
    {'break', Break},
    {'pass', Pass},
    {'return', Return},
    {'ret', Ret},
    {'always', Always},
    {'let', Let},
    {'fn', Fn},
    {'struct', Struct},
    {'class', Class},
    {'output', Output},
    {'input', Input},
    {'section', Section},
    { LastTok}
};

struct token NewToken(enum tokTypes type, char tokText){
    struct token newToken;
    newToken.type = type;
    newToken.tokText = tokText;
    return newToken;
}

int getStrLen(char *str){
    int n;
    for (n = 0; *str != '\0'; str++){n++;}
    return n;
}

int count(char* str, char symbol){
    int n;
    for (n = 0; *str != '\0'; str++){
        if(str == symbol){n = 1; break;}
    }
    return n;
}

int spSmblCount(struct specialSymbolPair spSmbls[], char symbol){
    int n = 0;
    for (int i = 0; spSmbls[i].type != LastTok; i++){
        if(spSmbls[i].symbol == symbol){n = 1; break;}
    }
    return n;
}

int spWrdsCount(struct specialWordPair spWrds[], char *str){
    int n = 0;
    for (int i = 0; spWrds[i].type != LastTok; i++){
        if(spWrds[i].word == str){n = 1; break;}
    }
    return n;
}

int isDigit(char symbol){
    if(symbol>='0' && symbol<='9') {return 1;}else{return 0;}
}

struct token getNextTok(){
    //struct token tok;
    if(currentPos == textLen) /*=>*/ return newToken(EOF, "");
    char *str; char currentSymbol = text[currentPos++];
    while ((currentSymbol == ' ' || currentSymbol == '\n' || currentSymbol == '\t' || currentSymbol == '\r') && currentPos < textLen) /*=>*/ currentSymbol = text[currentPos++];
    if(currentPos == textLen) /*=>*/ return newToken(EOF, "");
    while(!(currentSymbol == ' ' || currentSymbol == '\n' || currentSymbol == '\t' || currentSymbol == '\r')){
        if(getStrLen(str) == 0){
            if(count(specialSymbols, currentSymbol)) return newToken(specialSymbols[currentSymbol]);
            else if (isDigit(currentSymbol)){
                do{
                    str += currentSymbol;
                    currentSymbol = text[currentPos++];
                }while(isDigit(currentSymbol));
                currentPos--;
                break;
            }else str+=currentSymbol;
        }else{
            if(count(specialSymbols, currentSymbol)){
                currentPos--;
                break;
            }
            str+=currentSymbol;
        }
        /*
        if(count(specialWords, currentSymbol){

        }
        */
    }
}