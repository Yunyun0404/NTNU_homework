#include "key.h"

const char *rust_language[]={
    "as"      , "break" , "const"   , "continue",
    "crate"   , "else"  , "enum"    , "extern",
    "false"   , "fn"    , "for"     , "if",
    "impl"    , "in"    , "let"     , "loop",
    "match"   , "mod"   , "move"    , "mut",
    "pub"     , "ref"   , "return"  , "self",
    "Self"    , "static", "struct"  , "super",
    "trait"   , "true"  , "type"    , "unsafe"
    "use"     , "where" , "while"   , "async",
    "await"   , "dyn"   , "abstract", "become",
    "box"     , "do"    , "final"   , "macro",
    "override", "priv"  , "typeof"  , "unsized",
    "virtual" , "yeild" , "try"     , "union",
    "'static"
};
const char *java_language[]={
    "abstract", "assert"      , "boolean" , "break",
    "byte"    , "case"        , "catch"   , "char",
    "class"   , "const"       , "continue", "defalt",
    "do"      , "double"      , "else"    , "enum",
    "extends" , "final"       , "finally" , "float",
    "for"     , "if"          , "goto"    , "implements",
    "import"  , "instanceof"  , "int"     , "interface",
    "long"    , "native"      , "new"     , "package",
    "private" , "protected"   , "public"  , "return",
    "short"   , "static"      , "strictfp", "super",
    "switch"  , "synchronized", "this"    , "throw",
    "throws"  , "transient"   , "try"     , "void",
    "volatile", "while"       , "_"
};

const char *js_language[]={
    "await"  ,"break" ,"case"      , "catch"   ,
    "class"  ,"const" ,"continue"  , "debugger",
    "default","delete","do"        , "else"    ,
    "enum"   ,"export","extends"   , "false"   ,
    "finally","for"   ,"function"  , "if"      ,
    "import" ,"in"    ,"instanceof", "new"     ,
    "null"   ,"return","super"     , "switch"  ,
    "this"   ,"throw" ,"true"      , "try"     ,
    "typeof" ,"var"   ,"void"      , "while"   ,
    "with"   ,"yield"
};

const char *c_plus_language[]={
    "alignas"      , "alignof"     , "asm"             , "auto"     ,
    "bool"         , "break"       , "case"            , "catch"    ,
    "char"         , "char16_t"    , "char32_t"        , "class"    ,
    "const"        , "constexpr"   , "const_case"      , "continue" ,
    "decltype"     , "default"     , "delete"          , "do"       ,
    "double"       , "dynamic_case", "else"            , "enum"     ,
    "explicit"     , "export"      , "extern"          , "false"    ,
    "float"        , "for"         , "friend"          , "goto"     ,
    "if"           , "inline"      , "int"             , "long"     ,
    "mutable"      , "namespace"   , "new"             , "noexcept" ,
    "nullptr"      , "operator"    , "private"         , "protected",
    "public"       , "register"    , "reinterpret_cast", "return"   ,
    "short"        , "signed"      , "sizeof"          , "static"   ,
    "static_assert", "static_cast" , "struct"          , "switch"   ,
    "template"     , "this"        , "thread_local"    , "throw"    ,
    "true"         , "try"         , "typedef"         , "typeid"   ,
    "typename"     , "union"       , "unsigned"        , "using"    ,
    "virtual"      , "void"        , "volatile"        , "wchar_t"  ,
    "while"        , "and"         , "and_eq"          , "bitand"   ,
    "bitor"        , "compl"       , "not"             , "not_eq"   ,
    "or"           , "or_eq"       , "xor"             , "xor_eq"   ,
};

const char *C_language[]={
    "auto"       , "break"     , "case"           , "char"         ,
    "const"      , "continue"  , "default"        , "do"           ,
    "double"     , "else"      , "enum"           , "extern"       ,
    "float"      , "for"       , "goto"           , "if"           ,
    "inline"     , "int"       , "long"           , "register"     ,
    "restrict"   , "return"    , "short"          , "signed"       ,
    "sizeof"     , "static"    , "struct"         , "switch"       ,
    "typedef"    , "union"     , "unsigned"       , "void"         ,
    "volatile"   , "while"     , "_Alignas"       , "_Alignof"     ,
    "_Atomic"    , "_Bool"     , "_Complex"       , "_Generic"     ,
    "_lmaginary" , "_Noreturn" , "_Static_assert" , "Thread_local"
};

const char **lans[]={
    C_language,c_plus_language,js_language,java_language,rust_language
};

const int32_t len[5]={44,84,38,51,53};

enum elang{
    c=0,
    cpp,
    js,
    java,
    rust
};

enum elang c_lang=c;

void print(FILE *at){
    char buffer[512]={0};
    fseek( at, 0, SEEK_SET );

    while( !feof(at) ){
        fgets(buffer,511,at);
        printf("%s",buffer);
    }
}

int color_line(FILE *at,char *type){
    if( strcasecmp(type,"c")==0 ){
        c_lang=c;
    }else if( strcasecmp(type,"c++")==0 ){
        c_lang=cpp;
    }else if( strcasecmp(type,"js")==0 ){
        c_lang=js;
    }else if( strcasecmp(type,"java")==0 ){
        c_lang=java;
    }else if( strcasecmp(type,"rust")==0 ){
        c_lang=rust;
    }else{
        printf(yellow"I don't provide the survice of this language\n"none);
        return 0;
    }

    char buffer[1025]={0};
    int32_t is_comment=0;
    int32_t is_mulcomment=0;
    int32_t is_string=0;

    int32_t line=2;
    printf(yellow"   1"none);

    while( !feof(at) ){
        fgets(buffer,1024,at);
        for(size_t i=0 ; i<strlen(buffer) ; ++i){
            if(buffer[i]=='\n'){
                is_comment=0;
                printf(yellow"\n%4d"none,line);
                line++;
            }else if( is_comment==1 || is_mulcomment==1 || is_string==1 ){

                if( buffer[i]=='*' && buffer[i+1]=='/' ){
                    printf("%c%c",buffer[i],buffer[i+1]);
                    i++;
                    is_mulcomment=0;
                }else if(buffer[i]=='\"'){
                    printf("%c",buffer[i]);
                    is_string=0;
                }else printf("%c",buffer[i]);
                
            }else if( buffer[i]=='/' && buffer[i+1]=='/' ){
                printf("%c%c",buffer[i],buffer[i+1]);
                i++;
                is_comment=1;
            }else if( buffer[i]=='/' && buffer[i+1]=='*'){
                printf("%c%c",buffer[i],buffer[i+1]);
                i++;
                is_mulcomment=1;
            }else if(buffer[i]=='\"'){
                printf("%c",buffer[i]);
                is_string=1;
            }else{
                int tmp=0;
                const char *now=&buffer[i];
                for( int32_t u=0 ; u<len[c_lang] ; ++u ){

                    //找key word
                    const char *kw=lans[c_lang][u];
                    int32_t c_len=strlen(kw);
                    if( strncmp(now,kw,c_len)==0 ){
                        if( i>0 && ( isalpha(buffer[i-1]) || isalpha(buffer[i+c_len]) || buffer[i-1]=='_' || buffer[i+c_len]=='_' ) ){
                            break;
                        }
                        printf(light"%s"none,kw);
                        i=i+c_len-1;
                        tmp=1;
                        break;
                    }
                }
                if(tmp==0)printf("%c",buffer[i]);
            }
        }
    }

    return 1;
}

int color(FILE *at,char *type){
    if( strcasecmp(type,"c")==0 ){
        c_lang=c;
    }else if( strcasecmp(type,"c++")==0 ){
        c_lang=cpp;
    }else if( strcasecmp(type,"js")==0 ){
        c_lang=js;
    }else if( strcasecmp(type,"java")==0 ){
        c_lang=java;
    }else if( strcasecmp(type,"rust")==0 ){
        c_lang=rust;
    }else{
        printf(yellow"I don't provide the survice of this language\n"none);
        return 0;
    }

    char buffer[1025]={0};
    int32_t is_comment=0;
    int32_t is_mulcomment=0;
    int32_t is_string=0;


    while( !feof(at) ){
        fgets(buffer,1024,at);
        for(size_t i=0 ; i<strlen(buffer) ; ++i){
            if(buffer[i]=='\n'){
                is_comment=0;
                printf(yellow"\n"none);
            }else if( is_comment==1 || is_mulcomment==1 || is_string==1 ){

                if( buffer[i]=='*' && buffer[i+1]=='/' ){
                    printf("%c%c",buffer[i],buffer[i+1]);
                    i++;
                    is_mulcomment=0;
                }else if(buffer[i]=='\"'){
                    printf("%c",buffer[i]);
                    is_string=0;
                }else printf("%c",buffer[i]);
                
            }else if( buffer[i]=='/' && buffer[i+1]=='/' ){
                printf("%c%c",buffer[i],buffer[i+1]);
                i++;
                is_comment=1;
            }else if( buffer[i]=='/' && buffer[i+1]=='*'){
                printf("%c%c",buffer[i],buffer[i+1]);
                i++;
                is_mulcomment=1;
            }else if(buffer[i]=='\"'){
                printf("%c",buffer[i]);
                is_string=1;
            }else{
                int tmp=0;
                const char *now=&buffer[i];
                for( int32_t u=0 ; u<len[c_lang] ; ++u ){

                    //找key word
                    const char *kw=lans[c_lang][u];
                    int32_t c_len=strlen(kw);
                    if( strncmp(now,kw,c_len)==0 ){
                        if( i>0 && ( isalpha(buffer[i-1]) || isalpha(buffer[i+c_len]) || buffer[i-1]=='_' || buffer[i+c_len]=='_' ) ){
                            break;
                        }
                        printf(light"%s"none,kw);
                        i=i+c_len-1;
                        tmp=1;
                        break;
                    }
                }
                if(tmp==0)printf("%c",buffer[i]);
            }
        }
    }

    return 1;
}

void line(FILE *at){
    char buffer[1025]={0};
    int line=2;
    fseek( at, 0, SEEK_SET );
    //考慮註解
    printf("1");
    while( !feof(at) ){
        fgets(buffer,1024,at);
        for(size_t i=0 ; i<strlen(buffer) ; ++i){
            if(buffer[i]=='\n'){
                printf("\n"yellow"%4d"none,line);
                line++;
            }else{
                printf("%c",buffer[i]);
            }
        }
    }
}