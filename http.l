%{
    ACCEPT, USER-AGENT, HOST,
    GET, POST, PUT, DELETE
%}

    digit   [0-9]
    letter  [A-Za-z]
    delim   [ \t\n]
    ws      {delim}+

%%

    Accept  {return(ACCEPT);}

%%
