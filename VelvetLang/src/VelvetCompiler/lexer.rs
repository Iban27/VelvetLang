use token;

enum lexerState {
    Start,
    Number,
    Id
}

/*
trait TLexerState{
    fn NextState(&self);
}

impl TLexerState for lexerState::Start{

    fn NextState(&self){
        
    }
}
 */

struct Lexer
{
    input: Vec<char>,
    pos: usize,
    state: lexerState,
    lexeme: String = String::new()
    
}

impl Lexer {

    fn New(input: &str) -> Self{
        Lexer {
            input: input.chars().collect(),
            pos: 0,
        }
    }

    fn GetNextToken(&mut self) -> token::Token {

        loop{

            let symbol = match self.PeekChar() {
                Some(c) => c,
                None => {

                }
            };

            match state {

                lexerState::Start => {

                    if symbol.is_whitespace() {
                        self.Advance();
                        continue;
                    }

                    if symbol.is_ascii_digit(){
                        state = lexerState::Number;
                        lexem.push(symbol);
                        self.Advance();
                    } else if symbol.is_alphabetic() || symbol == '_' {
                        state = lexerState::Id;
                        lexem.push(symbol);
                        self.Advance();
                    } else {
                        self.Advance();
                        return 
                    }

                }


            }
        }
    }

    fn PeekChar(&self) -> Option<char> {
        self.input.get(self.pos).copied()
    }

    fn Advance(&mut self) {
        self.pos += 1;
    }

    fn GetOperator(s: char) -> token::Token {

    }

}

fn Main(){
    //Lexer::New();
}
