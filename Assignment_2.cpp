// #include "stack.h"
// #include "stack.cpp"

// #include <iostream>
// #include <cmath>
// using namespace std;

// struct operandandvalue {
//     char operand;
//     float operandvalue;
// };

// class expression {
// public:

//     int precedence(char c) {
//         int p;
//         if (c == '+' || c == '-') p = 1;    
//         else if (c == '*' || c == '/') p = 2;
//         else p = 3;

//         return p;
//     }

//     string revstr(string str) {
//         string rev;
//         for (char ch : str) {
//             if (ch == '(') ch = ')';
//             else if (ch == ')') ch = '(';
//             rev = ch + rev;
//         }
//         return rev;
//     }

//     string infix_prefix(string str) {
//         string pre = revstr(str);
//         pre = infix_postfix(pre);
//         pre = revstr(pre);
//         return pre;
//     }

//     string infix_postfix(string str) {
//         string postfix;
//         stack<char> s;
//         for (char ch : str) {
//             if (ch == '(') s.push(ch);
//             else if (ch == ')') {
//                 while (s.peek() != '(') {
//                     postfix += s.peek();
//                     s.pop();
//                 }
//                 s.pop();
//             }
//             else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') {
//                 while (!s.isEmpty() && s.peek() != '(' && precedence(ch) <= precedence(s.peek())) {
//                     postfix += s.peek();
//                     s.pop();
//                 }
//                 s.push(ch);
//             }
//             else {
//                 postfix += ch;
//             }
//         }

//         while (!s.isEmpty()) {
//             postfix = postfix + s.peek();
//             s.pop();
//         }

//         return postfix;
//     }

//     int evalpostfix(string str) {
//         stack<float> s;
//         struct operandandvalue listopval[str.length()];
//         for (int i = 0; i < str.length(); i++) {
//             char ch = str[i];
//             listopval[i].operand = ch;
//             if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') {
//                 float a = s.peek();
//                 s.pop();
//                 float b = s.peek();
//                 s.pop();
//                 float c;
//                 switch (ch) {
//                     case '+': c = b + a;     break;
//                     case '-': c = b - a;     break;
//                     case '*': c = b * a;     break;
//                     case '/': c = b / a;     break;
//                     case '$': c = pow(b, a); break;
//                     default: c = 0;          break;
//                 }
//                 s.push(c);
//             } else {
//                 cout << "Enter Operand Value for " << ch << ": ";
//                 cin >> listopval[i].operandvalue;
//                 s.push(listopval[i].operandvalue);
//             }
//             cout << "Answer: " << s.peek() << endl;
//         }
//         return s.peek();
//     }

//     int evalprefix(string str) {
//         stack<float> s;
//         struct operandandvalue listopval[str.length()];
//         for (int i = str.length() - 1; i >= 0; i--) {
//             char ch = str[i];
//             listopval[i].operand = ch;
//             if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$') {
//                 float a = s.peek();
//                 s.pop();
//                 float b = s.peek();
//                 s.pop();
//                 float c;
//                 switch (ch) {
//                     case '+': c = a + b; break;
//                     case '-': c = a - b; break;
//                     case '*': c = a * b; break;
//                     case '/': c = a / b; break;
//                     case '$': c = pow(a, b); break;
//                     default: c = 0; break;
//                 }
//                 s.push(c);
//             } else {
//                 cout << "Enter Operand Value for " << ch << ": ";
//                 cin >> listopval[i].operandvalue;
//                 s.push(listopval[i].operandvalue);
//             }
//             cout << "Answer: " << s.peek() << endl;
//         }
//         return s.peek();
//     }
// };

// int main() {
//     cout << "Enter the infix expression: " << endl;
//     string str;
//     cin >> str;
//     expression exp;
//     string postfix = exp.infix_postfix(str);
//     string prefix = exp.infix_prefix(str);

//     cout << "The postfix expression is: " << postfix << endl;
//     cout << "The prefix expression is: " << prefix << endl;

//     cout << "Postfix evaluation of the Postfix expression is: " << endl;
//     float postfixev = exp.evalpostfix(postfix);
//     cout << exp.revstr(postfix) << endl;

//     cout << "Prefix evaluation of the Prefix expression is: " << endl;
//     float prefixev = exp.evalprefix(prefix);
//     cout << prefixev << endl;

//     return 0;
// }



// Function to return precedence of operators
// int prec(char c) {
//     if (c == '^')
//         return 3; // Highest precedence
//     else if (c == '*' || c == '/')
//         return 2;
//     else if (c == '+' || c == '-')
//         return 1;
//     else
//         return -1;
// }

// // The main function to convert infix expression to postfix expression
// void infixToPostfix(string s) {
//     stack<char> st;
//     string result;

//     for (int i = 0; i < s.length(); i++) {
//         char c = s[i];

//         // If the scanned character is an operand, add it to the output string
//         if (isalnum(c))  // Checks if c is a letter or digit
//             result += c;

//         // If the scanned character is an ‘(‘, push it to the stack
//         else if (c == '(')
//             st.push(c);

//         // If the scanned character is an ‘)’, pop and add to output until ‘(’ is encountered
//         else if (c == ')') {
//             while (!st.empty() && st.top() != '(') {
//                 result += st.top();
//                 st.pop();
//             }
//             st.pop(); // Remove '(' from the stack
//         }

//         // If an operator is scanned
//         else {
//             // Handle precedence and associativity
//             while (!st.empty() && 
//                    (prec(c) < prec(st.top()) || 
//                     (prec(c) == prec(st.top()) && c != '^'))) { // Right-associative check for '^'
//                 result += st.top();
//                 st.pop();
//             }
//             st.push(c);
//         }
//     }

//     // Pop all the remaining elements from the stack
//     while (!st.empty()) {
//         result += st.top();
//         st.pop();
//     }

//     cout << result << endl;
// }

// int main() {
//     string exp = "a+b^c^g*e/f";
//     infixToPostfix(exp); // Convert infix to postfix
//     return 0;
// }

#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

bool isOperator(char c) {
  return (!isalpha(c) && !isdigit(c));
}

int getPriority(char C) {
  if (C == '-' || C == '+')
    return 1;
  else if (C == '*' || C == '/')
    return 2;
  else if (C == '^')
    return 3;
  return 0;
}

string infixToPostfix(string infix) {
  infix = '(' + infix + ')';
  int l = infix.size();
  stack < char > char_stack;
  string output;

  for (int i = 0; i < l; i++) {

    // If the scanned character is an operand, add it to output
    if (isalpha(infix[i]) || isdigit(infix[i]))
      output += infix[i];

    // If the scanned character is ‘(’, push it to the stack
    else if (infix[i] == '(')
      char_stack.push('(');

    // If the scanned character is ‘)’, pop and output from the stack until ‘(’ is encountered
    else if (infix[i] == ')') {
      while (char_stack.top() != '(') {
        output += char_stack.top();
        char_stack.pop();
      }
      // Remove '(' from the stack
      char_stack.pop();
    }

    // If an operator is scanned
    else {
      if (isOperator(char_stack.top())) {
        // Handle the right-associative operator '^'
        while (!char_stack.isEmpty() && 
                   (getPriority(infix[i]) < getPriority(char_stack.top()) || 
                    (getPriority(infix[i]) == getPriority(char_stack.top()) && infix[i] != '^'))) { // Right-associative check for '^'
                output += char_stack.top();
                char_stack.pop();
            }

        // Push the current operator to the stack
        char_stack.push(infix[i]);
      }
    }
  }
  while (!char_stack.isEmpty()) {
    output += char_stack.top();
    char_stack.pop();
  }
  return output;
}

void reverse(string &expression){
    string answer;
    for(char c:expression){
        answer=c+answer;
    }
    expression=answer;
}

string infixToPrefix(string infix) {
  /* Reverse String
   * Replace ( with ) and vice versa
   * Get Postfix
   * Reverse Postfix */
  int l = infix.size();

  // Reverse the infix expression
  reverse(infix);

  // Replace '(' with ')' and vice versa
  for (int i = 0; i < l; i++) {
    if (infix[i] == '(') {
      infix[i] = ')';
    } else if (infix[i] == ')') {
      infix[i] = '(';
    }
  }

  // Convert the reversed infix expression to postfix
  string prefix = infixToPostfix(infix);

  // Reverse the postfix expression to get the prefix expression
  reverse(prefix);

  return prefix;
}

int main() {
  string s = "(G+H)/F/E+D-C*B^A";
  cout << "Infix expression: " << s << endl;
  cout << "Postfix Expression: " << infixToPostfix(s) << endl;
  cout << "Prefix Expression: " << infixToPrefix(s) << endl;
  return 0;
}
