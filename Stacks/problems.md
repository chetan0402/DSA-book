# Problems on stacks

### Discuss how stacks can be used for checking balancing of symbols?

Stacks can be used to check whether the given expression has balanced symbols or not. This algorithm is very much useful in compliers. Each time parser reads on character at a time. If the character is an opening delimiter then it is written to the stack. When a closing delimiter is encountered the stack is popped. The opening and closing delimiters are then compared. If they match, the parsing of the string continues. If they do not match, the parser indicates that there is an error on the line.

### Discuss infix to postfix conversion algorithm using stacks?

`Infix`: An indix expression is a single letter, or an operator, proceeded by one infix string and following by another Infix string

- A
- A+B
- (A+B)+(C+D)

`Prefix`: A prefix expression is a single letter, or an operator, followed by two prefix strings. Every prefix string longer than a single variable contains an operator, first operand and second operand

- A
- +AB
- ++AB-CD

`Postfix`: A postfix expression is a single letter or an operator, proceded by two postfix strings. Every postfix string longer than a single variable contains first and second operands followed by an operator.

- A
- AB+
- AB+CD-+

Prefix and postfix notions are methods of writing mathematical expression without parenthesis. Time to evalutae a postfix and prefix expression is O(n), were n is the number of elemnts in the array.