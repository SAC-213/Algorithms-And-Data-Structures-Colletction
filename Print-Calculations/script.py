import subprocess
import csv
import os
import math
from tabulate import tabulate

argumentos = ["-1", "0", "1", "2", "3", "5", "15", 
              "20", "100", "409", "500", "593", 
              "1000", "1471", "1500", "2801", 
              "3000", "5000", "10000", "20000"]
datos_tabla = []
headers = ["Programa", "N", "Imp. Real", "Imp. Calc"]
nombre_csv = "respaldo_datos.csv"

def calc_formula(prog, n):
    n = int(n)
    try:
        if prog == "c.exe":
            if n <= 1: return "-inf"
            return f"{math.log2(n - 1):.2f}"
        
        elif prog == "c2.exe":
            if n <= 0: return "-nan"
            k = math.floor(math.log2(n) - 2)
            p = k * math.ceil(n / 2.0)
            return f"{p:.2f}"
        
        elif prog in ["c3.exe", "c4.exe"]:
            val = ((float(n) * n + n) / 2.0) * math.ceil((5.0 * n) / 2.0)
            return f"{val:.2f}"
        
        elif prog == "c5.exe":
            p = 0.0
            if (4.0 * n) - 1 <= 0: return "0.00"
            limit_i = math.floor(math.log2((4.0 * n) - 1))
            for k in range(int(limit_i) + 1):
                p += math.floor((5.0 * n - pow(2, k) - 1) / 3.0) + 1
            return f"{p:.2f}"
        
    except:
        return "Error_Mat"
    return "---"

def guardar_csv():
    with open(nombre_csv, "w", newline="") as f:
        writer = csv.writer(f)
        writer.writerow(headers)
        writer.writerows(datos_tabla)

def ejecutar_y_guardar(prog, val):
    print(f"Iniciando: {prog} con {val}")
    try:
        resultado = subprocess.run([prog, val], capture_output=True, text=True, check=True, timeout=180)
        salida = resultado.stdout.replace('\r', '').strip().split(",")
        if len(salida) >= 3:
            datos_tabla.append([prog] + salida[:3])
        else:
            datos_tabla.append([prog, val, "Error", "Formato"])
        print(f"Terminado exitosamente\n")
        guardar_csv()
        return True
    
    except subprocess.TimeoutExpired:
        calc_val = calc_formula(prog, val)
        datos_tabla.append([prog, val, "TIMEOUT", calc_val])
        print(f"TIMEOUT (180s)\n")
        guardar_csv()
        return False
    
    except Exception as e:
        datos_tabla.append([prog, val, "ERROR", str(e)[:20]])
        print(f"Error: {e}\n")
        guardar_csv()
        return True

programas = ["c.exe", "c2.exe", "c3.exe", "c4.exe", "c5.exe"]

for p in programas:
    for i, val in enumerate(argumentos):
        if not ejecutar_y_guardar(p, val):
            restantes = argumentos[i+1:]
            for faltante in restantes:
                calc_val = calc_formula(p, faltante)
                datos_tabla.append([p, faltante, "TIMEOUT", calc_val])
            guardar_csv()
            break

print("\n" + "="*40)
print(f"RESUMEN FINAL")
print("="*40)
print(tabulate(datos_tabla, headers=headers, tablefmt="grid"))