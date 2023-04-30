# Description

Welcome this short document describes how formats were handled in this project.

It might get complicated but we will try to keep it as simple as possible.

Currently the program follows this principle `0`(Normal Mode) & `1`(Escape Character/Specifier).
Kind of like binary(how computers talk to each other).
The reason this was chosen was because it was easier to use the switch statement instead of
`if/else` statements which can get very messy I tell you.

##### 0 Mode(Normal Mode)
Normal mode means that the `%` was not found anywhere, so it will just take everything as a string.
For example:
command: `_printf("Hello World")`
output: `Hello World`

##### 1 Mode(Escape Character/Specifier Mode)
This means the code(our printf) found the `%` sign in the code & will print out the value in the specified format.
For example:
command: `_printf("%S", "Hello World")`
output: `Hello World`


##### Helper Functions

There are smaller functions that help calculate `length`, there's even one to calculate strings `_parse_string`.
The reason why that was done was to follow the `SOC`(separation of concerns) principle.
Meaning make one thing well & let it do its job well, it becomes a headache to try and dig through
code you remember worked. Although you aren't sure how exactly each piece works & what does what.

#### Reference

- [Separation Of Concerns](https://en.wikipedia.org/wiki/Separation_of_concerns)
