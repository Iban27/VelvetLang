struct token getNextTok();
struct token newToken();
int getStrLen(char *str);
int count(char *str, char symbol);
int spSmblCount(struct specialSymbolPair spSmbls[], char symbol);
int spWrdsCount(struct specialWordPair spWrds[], char *str);
int isDigit(char symbol);

int currentPos;
int textLen;
char *text;

enum tokTypes{
Void, Null, None, Int, Float, Compn, If, Else, For, While, Continue, Break, Pass, Return, Ret, Always, Let, Fn, Struct, Class, Output, Input, Section,
Plus, Minus, Mul, Div, PlusPlus, MinusMinus, Not, And, Or, DivRe, DivInt, LShift, RShift, BitAnd, BitOr, BitXor, Ls, Gr, Equal, NotEqual, LsEqual, GrEqual, Assign, Comma, Dot, Question, Colon, SmColon, 
OpParen, ClParen, OpBlock, ClBlock, OpBrac, ClBrac,
Invalid, EOF, Intn, Floatn, Char, Str,
EmptyTok, LastTok
};

struct token
{
    enum tokTypes type;
    char *tokText;
    //unsigned long long length;
};

