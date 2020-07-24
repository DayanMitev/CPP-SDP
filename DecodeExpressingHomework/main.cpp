#include <iostream>
#include <stack>
#include <cstring>
#include <sstream>
#include <string>
#include <fstream>


void Reverse(std::string& expr)
{
    std::stack<char> reverseStack;
    for(int j = 0; j < expr.length(); j++)
    {
        reverseStack.push(expr[j]);
    }
    for(int i = 0; i < expr.length(); i++)
    {
        expr[i] = reverseStack.top();
        reverseStack.pop();
    }
}


int quoteMeeting(std::string& expr)
{
    int count = 0, i = 0;
    char q = '"';
    while(expr[i] != '\0')
    {
        if(expr[i] == q)
            count++;
            i++;
    }
    return count;
}
int slashMeeting(std::string& expr)
{
    int count = 0, i = 0;
    char s ='\\';
    while(expr[i] != '\0')
    {
        if(expr[i] == s)
            count++;
            i++;
    }
    return count;
}
bool isNumber(char n)
{
    if(n >= '0' && n <= '9')
        return true;
    else
        return false;
}
int bracketCount(std::string& expr)
{
    int count = 0, i = 0;
    char ob = '(', cb = ')';
    while(expr[i] != '\0')
    {
        if(expr[i] == ob || expr[i] == cb)
            count++;
            i++;
    }
    return count;
}

bool isValid(std::string& expr)
{
    bool flag = true;
    for(int i = 0; i < expr.length(); ++i)
    {
        if(expr[i] == '"')
        {
            if(quoteMeeting(expr) % 2 !=0)
            {

                    std::cout << "Invalid quote expression! \n";
                    flag = false;
            }
        }
        else if(expr[i] == '(')
        {
            if(bracketCount(expr) % 2 != 0)
            {
                std::cout <<"Invalid bracket expression! \n";
                flag =false;
            }

        }
        else if(expr[i] == '\\')
        {
            if(slashMeeting(expr) % 2 != 0 && expr[i + 1] == '\0')
            {
                std::cout << "Invalid slash expression! \n";
                flag = false;
            }
        }

    }
    if(flag)
        return true;
    else
       return false;
}

std::string encodeToDecoded(std::string& expr)
{
    std::stack<int> integerStack;
    std::stack<char> symStack;
    std::string subString = "", result = "";

    for(int i = 0; i < expr.length(); i++)
    {
        int mulNum = 0;

        if (expr[i] == '"')
        {
            if(quoteMeeting(expr) % 2 == 0)
            {
                int quotes = quoteMeeting(expr);
                for(int j = i + 1; expr[j] != '"'; j++, i++)
                {
                    symStack.push(expr[j]);
                }
                quotes -= 2;
                i++;
            }
        }
        else if(expr[i] == '\\')
        {
            int slash = slashMeeting(expr);
                if(slash > 0){
                    symStack.push(expr[i+1]);
                }
            slash--;
            i++;
        }
        /// converts it from string to number and pushes that number into the number Stack

        else if (expr[i] >= '0' && expr[i] <='9')
        {
            while (expr[i] >= '0' && expr[i] <= '9')
            {
                mulNum = mulNum * 10 + expr[i] - '0';
                i++;
            }

            i--;
            integerStack.push(mulNum);
        }

    /// If '(' opening bracket, push it into character stack.
        else if (expr[i] == '(')
        {
            if (expr[i-1] >= '0' && expr[i-1] <= '9')
            {
                symStack.push(expr[i]);
            }
            else
            {
                symStack.push(expr[i]);
                integerStack.push(1);
            }
        }

        /// If closing bracket ')', pop elemment until
        /// '(' opening bracket is not found in the
        /// character stack.
        else if (expr[i] == ')')
        {
            subString = "";
            mulNum = 0;

            if (! integerStack.empty())
            {
                mulNum = integerStack.top();
                integerStack.pop();
            }

            while (! symStack.empty() && symStack.top()!='(' )
            {

                subString =  symStack.top() + subString;
                symStack.pop();

            }

            if (! symStack.empty() && symStack.top() == '(')
                symStack.pop();

            /// Repeating the popped string 'subString' mulNum
            /// number of times.
            for (int j = 0; j < mulNum; j++)
                result = result + subString;

            /// Push it in the character stack.
            for (int j = 0; j < result.length(); j++)
                symStack.push(result[j]);

            result = "";
        }

        else
            ///everything else goes to the stack
            symStack.push(expr[i]);
    }

    /// Pop all the elmenet, make a string and return.
    while (! symStack.empty())
    {
        result = symStack.top() + result;
        symStack.pop();
    }

    return result;

}

int main()
{
    std::string expr;
    /*if(isValid(expr))
    {
        std::cout << encodeToDecoded(expr) << std:: endl;
    }*/

    std::ofstream outFile;
    outFile.open("expression.txt");
    if(outFile.fail())
    {
        std::cout << "failed to open the file! " << std::endl;
    }else
    {
        std::cin >> expr;
        outFile << encodeToDecoded(expr);


        outFile.close();
    }
    std::ifstream inFile;
    inFile.open("expression.txt");

    if(inFile.fail())
    {
        std::cout << "failed opening the file! " << std::endl;
    }
    else{

        while(std::getline(inFile, expr))
        {
            if(isValid(expr)){
                std::cout << encodeToDecoded(expr);
            }
        }
    inFile.close();
    }


    return 0;
}

