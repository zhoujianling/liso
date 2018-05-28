%{
    #define REQUEST_HEADER_KEY 1
    #define GENERAL_HEADER_KEY 2
    #define ENTITY_HEADER_KEY 3
    // request header
    #define METHOD 4
    #define OPTIONS 5
    #define GET 6
    #define HEADER 7
    #define POST 8
    #define PUT 9
    #define DELETE 10
    #define TRACE 11
    #define CONNECT 12
    #define ACCEPT 13
    #define ACCEPT_CHARSET 14
    #define ACCEPT_LANGUAGE 15
    #define ACCEPT_ENCODING 16
    #define AUTHORIZATION 17
    #define EXPECT 18
    #define FROM 19
    #define HOST 20
    #define IF_MATCH 21
    #define IF_MODIFIED_SINCE 22
    #define IF_NONE_MATCH 23
    #define IF_RANGE 24
    #define IF_UNMODIFIED_SINCE 25
    #define MAX_FORWARDS 26
    #define PROXY_AUTHRIZATION 27
    #define RANGE 28
    #define REFERER 29
    #define TE 30
    #define USER_AGENT 31
    // general header, rfc2616 4.5
    #define CACHE_CONTROL 32
    #define CONNECTION 33
    #define DATE 34
    #define PRAGMA 35
    #define TRANSFER_ENCODING 36
    #define UPGRADE 37
    #define VIA 38
    #define WARNING 39
    #define UPGRADE_INSECURE_REQUESTS 40
    // entity header, rfc2616 7.1
    #define ALLOW 41
    #define CONTENT_ENCODING 42
    #define CONTENT_LANGUAGE 43
    #define CONTENT_LENGTH 44
    #define CONTENT_LOCATION 45
    #define CONTENT_MD5 46
    #define CONTENT_RANGE 47
    #define CONTENT_TYPE 48
    #define EXPIRES 49
    #define LAST_MODIFIED 50
    #define EXTENSION_HEADER 51
%}

    digit   [0-9]
    letter  [A-Za-z]
    delim   [ \t\n] 
    ws      {delim}+

%%

    {ws}    {/*do nothing*/}
    Accept  {yylval = ACCEPT; return(REQUEST_HEADER_KEY);}
    User-Agent  {return(USER_AGENT);} 
    GET     {yylval = GET; return (METHOD);} 
    POST    {yylval = POST; return (METHOD);} 
    PUT     {yylval = PUT; return (METHOD);} 
    DELETE  {yylval = DELETE; return (METHOD);} 
    

%%

    int foo() {

    }
