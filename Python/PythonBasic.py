c_prgoram = '''#include < stdio.h >
int main()
{
    int x ;
    x = 50 ;
    printf ( " The value of x is %d " , x ) ;
    return 0 ;
} '''

# variable for delimiters
delimiters = {'(', ')', '{', '}', '[', ']', '"', "'", ';', ','}
# variable for operators
operators = {"+","-","*","/","<",">","=","<=",">=","==","!=","++","--","%"}

_list = set()


for ch in c_prgoram.split():
    # this condition check delimiters
    if ch in delimiters:
        _list.add(ch)
    # this condition check operators
    if ch in operators:
            _list.add(ch)

print(_list)
