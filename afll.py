def start(c):
    if (c == 'a'):
        dfa = 1
    elif (c == 'b'):
        dfa = 3
    else:
        dfa = -1
    return dfa
def state1(c):
    if (c == 'a'):
        dfa = 2
    elif (c == 'b'):
        dfa = 4
    else:
        dfa = -1
    return dfa
def state2(c):
    if (c == 'b'):
        dfa = 3
    elif (c == 'a'):
        dfa = 2
    else:
        dfa = -1
    return dfa
def state3(c):
    if (c == 'b'):
        dfa = 3
    elif (c == 'a'):
        dfa = 4
    else:
        dfa = -1
    return dfa
def state4(c):
    dfa = -1
    return dfa
def auto(str):
    l = len(str)
    dfa = 0
    for i in range(l):
        if (dfa == 0):
            dfa = start(str[i])

        elif (dfa == 1):
            dfa = state1(str[i])

        elif (dfa == 2) :
            dfa = state2(str[i])

        elif (dfa == 3) :
            dfa = state3(str[i])

        elif (dfa == 4) :
            dfa = state4(str[i])
        else:
            return 0
    if(dfa == 3) :
        return 1
    else:
        return 0
str=input("Enter the automata to be checked:")
if (auto(str)) :
    print("ACCEPTED")
else:
    print("NOT ACCEPTED")
