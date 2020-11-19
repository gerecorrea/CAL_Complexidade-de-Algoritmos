from random import *
def millerrabin (n,s):
    aux = n-1
    k = 0
    while aux%2 == 0:
        aux = aux/2
        k+=1
    m = aux
    for i in range(1,s):
        a = randrange(2,(n-1),1)
        if witness(a,n,k,m) == False:
            return False
    return true

def witness(a,n,k,m):
    b = (a**m)
    b = b%n
    if b == 1 or b == n-1:
        return True
    for i in range(1,k):
        if b == -1 or b == n-1:
            return True
        else:
            b = b**2
            b = b%n
    return False

def main():
    primos = [1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063,
    1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123]
    naoprimos = [1007,1011,1015,1025,1027,1035,1043,1045,1053,1055,1057,1067,
    1071,1073,1075,1079,1083,1085,1099,1233]
    s = [3,7,13]

    print ('Primos: \n')
    for i in range(20):
        for j in range(3):
            print (primos[i], 'com s = ' ,s[j],'é primo? ',millerrabin(primos[i], s[j]))

    print ('Não Primos: \n')
    for i in range(20):
        for j in range(3):
            print (naoprimos[i],'com s= ' ,s[j],'é primo? ',millerrabin(naoprimos[i],s[j]))



if __name__ == "__main__":
    main()
