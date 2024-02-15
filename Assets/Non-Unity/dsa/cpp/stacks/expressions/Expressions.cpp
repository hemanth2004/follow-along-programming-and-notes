#include <iostream>
#include "evaluatepostfix.h"
#include "infixtopostfix.h"
#include "paranthesisvalidity.h"
#include <cctype>
#include <string.h>

using namespace std;

int main()
{
    
    while(1)
    {
    cout << "\n----------------------\n";
    cout << "EXPRESSIONS EVALUATOR (USING STACK)\n";
    string input = "hi";
    getline(cin, input);

    vector<string> args;
    string currentToken;
    for (int i = 0, j = 0; i < input.length(); i++) 
    {
        if (!isspace(input[i])) 
        {  
            if (isdigit(input[i])) 
            {
                currentToken += input[i];
            } 
            else 
            {
                if (!currentToken.empty()) 
                {
                    args.push_back(currentToken);
                    currentToken.clear(); 
                }
                
                args.push_back(string(1, input[i]));
            }
        }
    }

    if (!currentToken.empty()) {
        args.push_back(currentToken);
    }

    if(input[0] == 'e' || input[0] == 'E')
    {
        cout << "Quitting Expressions...";
        exit(0);
    }

    //ValidityChecks
    int valid, errorpos;

    //checking whether all arguements are non negative integers, braces and operators
    int expressionValidity = IsExpressionValid(args, args.size());
    decode(expressionValidity, valid, errorpos);
    if(!valid)
    {
        cout << "Expression invalid at " << errorpos;
        continue;
    }
    else
    {
        cout << "Expression uses valid arguements only ✅\n";
    }



    //checking validity of braces, whether they open and close correctly
    int paranthesisValidity = IsExpressionValid(args, args.size());
    decode(expressionValidity, valid, errorpos);
    if(!valid)
    {
        cout << "Expression's paranthesis invalid at " << errorpos;
        continue;
    }
    else
    {
        cout << "Expression uses valid paranthesis ✅\n";
    }


    //converting Infix To Postfix
    vector<string> expressionInPostFix = InfixToPostfix(args, args.size());
    cout << "Converted Postfix Version ✅(" << expressionInPostFix.size() <<"): ";
    for(int i = 0; i < expressionInPostFix.size(); i++)
    {
        cout << expressionInPostFix[i] + " ";
    }
    cout << endl;
    cout << endl << expressionInPostFix[2] << endl;
    //evaluating the postfix expression
    int finalResult = EvaluatePostFix(expressionInPostFix, expressionInPostFix.size());
    cout << "Evaluated Postfix Expression ✅ \nEnd result: " << finalResult << endl;
    cout << endl;
    }
    
}