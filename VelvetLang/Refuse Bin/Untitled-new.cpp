/*

struct Name{
  const char *Id;
  int Kind;
  long long Length;
  
};

class NamesMap { 
  bool IsInit; 
  llvm::StringMap<Name> HashTable; 
  Name *addName(llvm::StringRef Id, tok::TokenKind TokenCode);
  
  public: 
  NamesMap(): IsInit(false) { }
  void addKeywords(); 
  Name *getName(llvm::StringRef Id); 
};


namespace tok
{
  enum TokenKind : unsigned short{
    #define TOK(ID, TEXT) ID,
    
  };
}
*/