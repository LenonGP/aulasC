import numpy as np


def metodonewton(f, dfdx, x0, precisao):
    taperto = 0
    pprecisao = 10 ** (-precisao)
    # roundval = precisao + 3

    n = 0
    x = x0
    while not taperto:
        xx = f(x)
        xxderivado = dfdx(x)

        print("iteração " + str(n))
        print("x" + str(n) + " = " + str(x))
        print("f(x" + str(n) + ") = " + str(xx))
        print("-" * 50)
        x = x - (xx / xxderivado)
        n += 1
        if pprecisao > abs(f(x)):
            taperto = True

    print("O RESULTADO:")
    print("iteração " + str(n))
    print("x" + str(n) + " = " + str(x))
    print("f(x" + str(n) + ") = " + str(f(x)))
    print("-" * 50)


def metodopontofalso(f, a, b, precisao):
    pprecisao = 10 ** (-precisao)
    aa = f(a)
    bb = f(b)
    n = 0

    # checa se o intervalo a:b satisfaz o teorema de bolzano(se a função cruza o eixo x)
    if 0 > (aa * bb):

        while True:

            # calcula o valor de x e o valor da função f para as variáveis a,b e x.
            # arredonda os resultados para 3 casas decimais além da precisão
            aa = f(a)
            bb = f(b)
            x = abs(a * bb - b * aa) / abs(bb - aa)
            xx = f(x)

            print("iteração " + str(n))
            print("a = " + str(a) + " b = " + str(b) + " x = " + str(x))
            print("f(x) = " + str(xx))
            print("f(a) = " + str(aa) + " f(b) = " + str(bb))
            print("-" * 50)
            n += 1
            if abs(xx) > pprecisao:
                if (aa * xx) > 0:
                    a = x
                elif (bb * xx) > 0:
                    b = x
            else:
                break

    else:
        print("os valores de a e b inicial não satisfazem as condições do teorema de bolzano")


def metodobissecao(f, a, b, precisao):
    true = 1
    pprecisao = 10 ** (-precisao)
    roundval = precisao + 3
    aa = f(a)
    bb = f(b)
    n = 0

    # checa se o intervalo a:b satisfaz o teorema de bolzano(se a função cruza o eixo x)
    if 0 > (aa * bb):

        while true:

            # calcula o valor de x e o valor da função f para as variáveis a,b e x.
            # arredonda os resultados para 3 casas decimais além da precisão
            x = round(((a + b) / 2), roundval)
            xx = round(f(x), roundval)
            aa = round(f(a), roundval)
            bb = round(f(b), roundval)

            print("iteração " + str(n))
            print("a = " + str(a) + " b = " + str(b) + " x = " + str(x))
            print("f(x) = " + str(xx))
            print("f(a) = " + str(aa) + " f(b) = " + str(bb))
            print("-" * 50)
            n += 1
            if abs(xx) > pprecisao:
                if (aa * xx) > 0:
                    a = x
                elif (bb * xx) > 0:
                    b = x
            else:
                break
    else:
        print("os valores de a e b inicial não satisfazem as condições do teorema de bolzano")


# Sistemas Lineares
def gauss(matriz_a, matriz_b=np.array([False]), log=True):
    if matriz_b.dtype != 'bool':
        matriz_a = ampliamatriz(matriz_a, matriz_b)

    print("MÉTODO DE GAUSS" * log)
    k = 0
    if matriz_a.shape[0] + 1 == matriz_a.shape[1]:
        while k <= matriz_a.shape[0] - 1:
            i = k + 1
            if log:
                print("A(%i)|B(%i)" % (k, k))
                print(matriz_a)
            while i < matriz_a.shape[0]:
                j = k
                mik = matriz_a[i, k] / matriz_a[k, k]
                while j < matriz_a.shape[1]:
                    matriz_a[i, j] -= mik * matriz_a[k, j]
                    j += 1
                i += 1

            k += 1
        return lusolver(matriz_a, isupper=True)
    else:
        print("provavelmente a matriz não ta aumentada.")


def fatoracaolu(matriz_u, matriz_b=np.array([False]), log=True):
    print("FATORAÇÃO LU" * log)

    """
    caso não haja matriz_b. encarar a matriz como ampliada. 
    Separando a ultima coluna da matriz como termos idependentes
    """
    if matriz_b.dtype == 'bool':
        matriz_u, matriz_b = separamatriz(matriz_u)
    matriz_l = np.zeros(matriz_u.shape)

    k = 0
    while k < matriz_u.shape[0]:
        if log:
            print("A(%i)|B(%i)" % (k, k))
            print(matriz_u)
        matriz_l[k, k] = 1  # adiciona os valores unitarios que a matriz L possui em sua diagonal
        i = k + 1  # sempre começar da linha abaixo do pivô
        while i < matriz_u.shape[0]:
            j = k
            mik = matriz_u[i, k] / matriz_u[k, k]
            matriz_l[i, k] = mik

            while j < matriz_u.shape[1]:
                matriz_u[i, j] -= mik * matriz_u[k, j]
                j += 1
            i += 1
        k += 1
    matriz_y = lusolver(matriz_l, matriz_b, isupper=False)
    return lusolver(matriz_u, matriz_y, isupper=True)


def gaussjacobi(matriz_a, matriz_b=np.array([False]), matriz_x=np.array([False]), precs=10e-04, convcheck=True,
                iteracoes=100, log=True):
    """
    Extrai as icognitas da matriz através do metodo iterativo de gauss jacobi. A função demanda no mínimo uma
    matriz aumentada.
    :param matriz_a: matriz aumentada ou apenas dos coeficientes
    :param matriz_b: matriz dos termos idependentes
    :param matriz_x: matriz da primeira iteração(se houver)
    :param precs: precisão
    :param convcheck: valor booleano para desligar a checagem previa de garantia de convergencia
    :param iteracoes: numero maximo de iterações
    :param log: valor booleano para printar
    :return: as icógnitas aproximadas
    """
    if matriz_b.dtype == 'bool':
        matriz_a, matriz_b = separamatriz(matriz_a)

    if convcheck:
        if diagdominante(matriz_a):
            print("Há garantias de convergência, realizando o procedimento")
        else:
            print("não há garantias de convergência, realizando mesmo assim")
    if matriz_x.dtype == 'bool':
        matriz_x = np.empty(matriz_b.shape)

        # primeira iteração
        i = 0
        while i < matriz_x.shape[0]:
            matriz_x[i] = matriz_b[i] / matriz_a[i, i]
            i += 1

    # Aonde a brincadeira começa
    k = 1
    while k < iteracoes:
        matriz_xm1 = matriz_x.copy()

        i = 0
        while i < matriz_x.shape[0]:
            somatorio = 0
            j = 0
            while j < matriz_a.shape[1]:
                somatorio += matriz_a[i, j] * matriz_xm1[j]

                j += 1

            somatorio -= (matriz_a[i, i] * matriz_xm1[i])
            # print(somatorio)
            matriz_x[i] = (1 / matriz_a[i, i]) * (matriz_b[i] - somatorio)
            i += 1

        dr = absmax(matriz_x - matriz_xm1) / absmax(matriz_x)
        print("DR")
        print(dr)
        if log:
            logsislin(k, matriz_x, matriz_xm1, dr)

        if dr < precs:
            print("Matriz X encontrada\n"
                  "DR= %f" * log % dr)
            return matriz_x

        k += 1
    print("total de iterações: %i" % k)
    return matriz_x


def gaussseidel(matriz_a, matriz_b=np.array([False]), matriz_x=np.array([False]), precs=1e-04, convcheck=True,
                iteracoes=100, log=True):
    """
    Aproxima para a matriz utilizando o método de gauss seidel
    :param matriz_a: matriz aumentada ou dos coeficientes
    :param matriz_b: matriz dos termos idependentes
    :param matriz_x: vetor da primeira iteração
    :param precs: precisão do resultado
    :param convcheck: checagem previa da garantia de convolução
    :param iteracoes: numero maximo de iterações
    :param log: printar os passos da operação
    :return: vetor x aproximado
    """
    if matriz_b.dtype == 'bool':
        if matriz_b.dtype == 'bool':
            matriz_a, matriz_b = separamatriz(matriz_a)
    if convcheck:
        if sassenfeld(matriz_a)[0]:
            print("Há garantias de convergência, realizando o procedimento")
        else:
            print("não há garantias de convergência, realizando mesmo assim")
    if matriz_x.dtype == 'bool':
        matriz_x = np.empty(matriz_b.shape)
        # primeira iteração
        i = 0
        while i < matriz_x.shape[0]:
            matriz_x[i] = matriz_b[i] / matriz_a[i, i]
            i += 1

    # Aonde a brincadeira começa
    k = 1
    while k < iteracoes:
        matriz_xm1 = matriz_x.copy()
        i = 0
        while i < matriz_x.shape[0]:
            somatorio = 0
            j = 0
            while j < matriz_a.shape[1]:
                somatorio += matriz_a[i, j] * matriz_x[j]
                j += 1

            somatorio -= (matriz_a[i, i] * matriz_x[i])
            # print(somatorio)
            matriz_x[i] = (1 / matriz_a[i, i]) * (matriz_b[i] - somatorio)
            i += 1
        dr = absmax(matriz_x - matriz_xm1) / absmax(matriz_x)
        if log:
            logsislin(k, matriz_x, matriz_xm1, dr)

        if dr < precs:
            print("Matriz X encontrada\n"
                  "DR= %f" * log % dr)
            break
        k += 1
    print("total de iterações: %i" % k)
    return matriz_x


#Putaria

def sassenfeld(matriz_a):
    """
    Verifica se a matriz possui sua convergência garantida pelo critério de sassenfeld.
    :param matriz_a: a matriz a ser analisada.
    :return: Valor Booleano sobre a garantia de convergência, Vetor resultante das operações.
    """
    matriz_b = np.ones(matriz_a.shape[0])
    i = 0
    while i < matriz_b.shape[0]:
        j = 0
        somatorio = 0
        while j < matriz_a.shape[1]:
            somatorio += abs(matriz_a[i, j]) * matriz_b[j]
            j += 1
        somatorio -= abs(matriz_a[i, i]) * matriz_b[i]
        matriz_b[i] = somatorio / matriz_a[i, i]
        i += 1
    if np.max(matriz_b) < 1:
        return True, matriz_b
    else:
        return False, matriz_b


def diagdominante(vetor):
    """
    Verifica se a matriz possui sua convergência garantida pelo critério de sassenfield
    :param vetor: matriz a ser analisada
    :return: valor booleano representando a garantia de convergência
    """
    convbool = False
    diagonalarray = np.diag(vetor)
    counter = 0

    while counter < 2:
        convbool = True
        i = 0
        while i < vetor.shape[1]:
            somatorio = 0
            j = 0
            while j < vetor.shape[0]:
                somatorio += vetor[
                    (i * int(0 == counter) + j * int(1 == counter), j * int(0 == counter) + i * int(1 == counter))]
                j += 1
            somatorio -= diagonalarray[i]
            if somatorio > diagonalarray[i]:
                convbool = False
            i += 1
        if convbool:
            break
        counter += 1
    return convbool


def logsislin(niter, matriz, matrizm1, maxabs):
    print("\nITERAÇÃO %i" % niter)
    print("matriz X%i" % niter)
    print(matriz)

    print("\nmatriz de X%i" % (niter - 1))
    print(matrizm1)

    print("\nmaximo absoluto de X(k)-X(k-1)")
    print(maxabs)
    print("-" * 50)


def xacharb(matriz_a, matriz_x):
    matriz_b = np.empty(matriz_x.shape)
    i = 0
    while i < matriz_a.shape[0]:
        j = 0
        somatorio = 0
        while j < matriz_a.shape[1]:
            somatorio += matriz_a[i, j] * matriz_x[j]
            j += 1
        matriz_b[i] = somatorio
        i += 1
    return matriz_b


def ampliamatriz(matriz_a, matriz_b):
    matriz_a2 = np.empty((matriz_a.shape[0], matriz_a.shape[1] + 1))
    i = 0
    while i < matriz_a.shape[1]:
        matriz_a2[:, i] = matriz_a[:, i]
        i += 1
    matriz_a2[:, matriz_a2.shape[1] - 1] = matriz_b
    return matriz_a2


def separamatriz(aumentada):
    idependentes = aumentada[:, (aumentada.shape[1] - 1)]
    aumentada = np.delete(aumentada, aumentada.shape[1] - 1, 1)
    return aumentada, idependentes


def absmax(vetor):
    maximo = abs(np.max(vetor))
    minimo = abs(np.min(vetor))

    if maximo > minimo:
        return maximo
    elif minimo > maximo:
        return minimo
    elif maximo == minimo:
        return maximo


def lusolver(matriz_a, matriz_b=np.array([False]), isupper=True):
    """"
    recebe os coeficientes e termos idependentes de uma matriz triangular superior e retorna suas icógnitas.
    Caso matriz_a seja uma matriz aumentada. A determinação do array matriz_b será automática.
    isupper = 0: matriz triangular inferior
    urol = 1:matriz triangular superior
    matriz A: matriz dos coeficientes
    matriz B: matriz dos termos idependentes
    matriz X: serão as icógnitas. porém inicializado vazio
    """
    if matriz_b.dtype == 'bool':
        matriz_a, matriz_b = separamatriz(matriz_a)

    matriz_x = np.zeros(matriz_b.size)

    if isupper:  # triangular superior
        n = matriz_x.size - 1
        i = n - 1
        matriz_x[n] = matriz_b[n] / matriz_a[n, n]
        teto = 0
        while i >= teto:
            summ = 0
            j = n
            while j >= i:
                summ += matriz_a[i, j] * matriz_x[j]
                j -= 1

            matriz_x[i] = (matriz_b[i] - summ) / matriz_a[i, i]
            i -= 1

    else:  # triangular inferior
        n = 0
        i = n + 1
        matriz_x[n] = matriz_b[n] / matriz_a[n, n]
        teto = matriz_x.size - 1
        while i <= teto:
            summ = 0
            j = 0
            while j <= i:
                summ += matriz_a[i, j] * matriz_x[j]
                j += 1

            matriz_x[i] = (matriz_b[i] - summ) / matriz_a[i, i]
            i += 1

    return matriz_x


def pivoteamento(prepivot, prepivotb=np.array([False])):
    """
    pivoteamento parcial em matrizes ampliadas(A|B).
    """
    separadnv = 0
    if prepivotb.dtype != bool:
        separadnv = 1
        prepivot = ampliamatriz(prepivot, prepivotb)

    np.zeros(prepivot.shape)
    postpivot = prepivot.copy()

    k = 0
    while k <= postpivot.shape[1] - 2:
        i = k
        while i <= postpivot.shape[0] - 1:
            ii = i + 1
            while ii <= postpivot.shape[0] - 1:
                # print("comparei [%i,%i]=%i com [%i,%i]=%i" % (i, k, postpivot[i, k],ii,k, prepivot[ii, k]))
                if postpivot[i, k] < postpivot[ii, k]:
                    # print("//troquei %i por %i" % (postpivot[i,k], prepivot[ii,k]))
                    postpivot[i] = prepivot[ii]
                    postpivot[ii] = prepivot[i]
                    prepivot = postpivot.copy()
                ii += 1
            i += 1
        k += 1
    if separadnv:
        return separamatriz(postpivot)
    else:
        return postpivot
