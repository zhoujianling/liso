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

    #define URI_ 100
//    #define ASTERISK 101
//    #define ABS_URI 102
//    #define ABS_PATH 103
//    #define AUTHORITY_VAL 104
    #define HTTP_VER 105
    int yylval;//temparary val to pass compile
%}


/*    abs_uri {(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?} */
/*    abs_path {(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\?([^#]*))?(#(.*))?} */
    /*(\*)     {return (ASTERISK);}*/

%%
HTTP/\d+\.\d+ {printf("HTTP VER!\n");return (HTTP_VER);}
Accept  {yylval = ACCEPT; return(REQUEST_HEADER_KEY);}
Accept-Charset  {yylval = ACCEPT_CHARSET; return(REQUEST_HEADER_KEY);}
Accept-Encoding {yylval = ACCEPT_ENCODING; return(REQUEST_HEADER_KEY);}
Accept-Language {yylval = ACCEPT_LANGUAGE; return(REQUEST_HEADER_KEY);}
Authorization {yylval = AUTHORIZATION; return(REQUEST_HEADER_KEY);}
Expect {yylval = EXPECT; return(REQUEST_HEADER_KEY);}
From {yylval = FROM; return(REQUEST_HEADER_KEY);}
Host {yylval = HOST; return(REQUEST_HEADER_KEY);}
If-Match {yylval = IF_MATCH; return(REQUEST_HEADER_KEY);}
If-Modified-Since {yylval = IF_MODIFIED_SINCE; return(REQUEST_HEADER_KEY);}
If-None-Match {yylval = IF_NONE_MATCH; return(REQUEST_HEADER_KEY);}
If-Range {yylval = IF_RANGE; return(REQUEST_HEADER_KEY);}
If-Unmodified-Since {yylval = IF_UNMODIFIED_SINCE; return(REQUEST_HEADER_KEY);}
Max-Forwards {yylval = MAX_FORWARDS; return(REQUEST_HEADER_KEY);} 
Proxy-Authrization {yylval = PROXY_AUTHRIZATION; return(REQUEST_HEADER_KEY);} 
Range {yylval = RANGE; return(REQUEST_HEADER_KEY);} 
Referer {yylval = REFERER; return(REQUEST_HEADER_KEY);} 
Te {yylval = TE; return(REQUEST_HEADER_KEY);} 
User-Agent {yylval = USER_AGENT; return(REQUEST_HEADER_KEY);} 
Cache-Control {yylval = CACHE_CONTROL; return(GENERAL_HEADER_KEY);} //$$
Connection {yylval = CONNECTION; return(GENERAL_HEADER_KEY);} 
Date {yylval = DATE; return(GENERAL_HEADER_KEY);} 
Pragma {yylval = PRAGMA; return(GENERAL_HEADER_KEY);} 
Transfer-Encoding {yylval = TRANSFER_ENCODING; return(GENERAL_HEADER_KEY);} 
Upgrade {yylval = UPGRADE; return(GENERAL_HEADER_KEY);} 
Via {yylval = VIA; return(GENERAL_HEADER_KEY);} 
Warning {yylval = WARNING; return(GENERAL_HEADER_KEY);} 
Upgrade-Insecure-Requests {yylval = UPGRADE_INSECURE_REQUESTS; return(GENERAL_HEADER_KEY);} 
Allow {yylval = ALLOW; return(ENTITY_HEADER_KEY);}//%%% 
Content-Encoding {yylval = CONTENT_ENCODING; return(ENTITY_HEADER_KEY);} 
Content-Language {yylval = CONTENT_LANGUAGE; return(ENTITY_HEADER_KEY);} 
Content-Length {yylval = CONTENT_LENGTH; return(ENTITY_HEADER_KEY);} 
Content-Location {yylval = CONTENT_LOCATION; return(ENTITY_HEADER_KEY);} 
Content-Md5 {yylval = CONTENT_MD5; return(ENTITY_HEADER_KEY);} 
Content-Range {yylval = CONTENT_RANGE; return(ENTITY_HEADER_KEY);} 
Content-Type {yylval = CONTENT_TYPE; return(ENTITY_HEADER_KEY);} 
Expires {yylval = EXPIRES; return(ENTITY_HEADER_KEY);} 
Last-Modified {yylval = LAST_MODIFIED; return(ENTITY_HEADER_KEY);} 
Extension-Header {yylval = EXTENSION_HEADER; return(ENTITY_HEADER_KEY);}
GET     {yylval = GET;printf("http method\n"); return (METHOD);}//^^^ 
POST    {yylval = POST; return (METHOD);} 
PUT     {yylval = PUT; return (METHOD);} 
DELETE  {yylval = DELETE; return (METHOD);} 
OPTIONS {yylval = OPTIONS; return(METHOD);}
TRACE {yylval = TRACE; return(METHOD);}
HEADER {yylval = HEADER; return(METHOD);}
CONNECT {yylval = CONNECT; return(METHOD);}
    
[^\s]* {printf("uri:%s\n", yytext);return (URI_);}

%%

    void start_parse() {
        yylex();
    } 

    /** MUST add it **/
    int yywrap() {
        return 1;
    }
