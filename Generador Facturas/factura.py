#Facturación con retenciones

monto = int(input("0 es Subtotal y 1 es Neto: "))
cantidad = float(input("Anotar la cantidad: "))
regimen = int(input("0 es PF y 1 es Resico: "))

if monto==0 and regimen==0:
    iva = cantidad * .16
    ret_iva = cantidad * .106667
    ret_isr = cantidad * .10
    resultadobruto = cantidad + iva - ret_iva - ret_isr
    print(f"El Neto es {resultadobruto}")

if monto==1 and regimen==0:
    tasa = 1.16 - .10 - .106667
    resultadoneto = cantidad / tasa
    print(f"El Subtotal es {resultadoneto}")

if monto==0 and regimen==1:
    iva = cantidad * .16
    ret_iva = cantidad * .106667
    ret_isr = cantidad * .0125
    resultadobrutores = cantidad + iva - ret_iva - ret_isr
    print(f"El Neto es {resultadobrutores}")

if monto==1 and regimen==1:
    tasa = 1.16 - .0125 - .106667
    resultadonetores = cantidad / tasa
    print(f"El Subtotal es {resultadonetores}")
