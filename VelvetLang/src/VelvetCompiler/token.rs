mod token{



enum tokTypes
{
    Void, Null, None, Int, Float, Compn, If, Else, For, While, Continue, Break, Pass, Return, Ret, Always, Let, Fn, Struct, Class, Output, Input, Section,
    Plus, Minus, Mul, Div, PlusPlus, MinusMinus, Not, And, Or, DivRe, DivInt, LShift, RShift, BitAnd, BitOr, BitXor, Ls, Gr, Equal, NotEqual, LsEqual, GrEqual, Assign, Comma, Dot, Question, Colon, SmColon, 
    OpParen = "(", ClParen = ")", OpBlock = "[", ClBlock = "]", OpBrac = "{", ClBrac = "}",
    Invalid, Eof, Intn, Floatn, Char, Str,
    EmptyTok, LastTok,
    SectionCode, SectionUsing, SectionAsm
}

struct Token
{
    tokType : tokTypes,
    lexeme : &str,
    xpos : usize,
    ypos : usize
}

pub fn newToken(NewTokType : tokTypes, newTokText : &char) -> Token
{
    let newTok : Token = Token{};
    return newTok;
}

}