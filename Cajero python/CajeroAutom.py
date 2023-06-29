#Programa que simule un cajero automatico con un saldo inicia de 1,000 y tendra el siguiente menu de opciones: Ingresar dinero, retirar dinero, mostrar dinero, salir

cuenta = 1000

while True:
    print("\nBienvenido al cajero automatico!\nLe mostramos las siguientes opciones")
    print("1. Ingresar dinero\n2. Retirar dinero\n3. Mostrar saldo actual disponible\n4. Salir")

    operacion = int(input("Por favor elija una de las opciones: "))

    if operacion == 1:
        ingresar = int(input("Favor de indicar el dinero a ingresar: "))
        cuenta += ingresar
        print(f"El saldo en su cuenta es de: {cuenta}")
    elif operacion== 2 :
        restar = int(input("Favor de indicar el dinero a retirar: "))
        if restar > cuenta:
            print("No puede retirar esa cantidad")
        else: 
            cuenta -= restar
            print(f"El saldo en su cuenta es de: {cuenta}")
    elif operacion == 3:
        print(f"El saldo en su cuenta es de: {cuenta}")
    elif operacion == 4:
        print("Hasta luego!")
        break
    else:
        print("Favor de ingresar una opción válida")
