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
headers = ["Programa", "N", "Asignaciones", "Aritmeticas", "Condicionales", "Total", "Calculado"]
nombre_csv = "respaldo_datos.csv"

def calc_formula(prog, n):
    n = int(n)
    try:
        if prog == "c.exe":
            if n <= 1:
                return "1"
            p = 1 + (3 * (n - 1)) + ((7 * (n - 1)) * math.floor(math.log2(n)))
            return f"{p}"
        
        elif prog == "c2.exe":
            p = (7 * (n + 1)) + 1
            return f"{p}"
        
        elif prog == "c3.exe":
            p = (4 * n) + (5 * n * n) + (6 * n * n * n) + 1
            return f"{p}"
        
        elif prog == "c4.exe":
            p = 7 * (n-2)
            return f"{p}"
            
        elif prog == "c5.exe":
            p = (7 * n) + 4
            return f"{p}"
        
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
        if len(salida) >= 6:
            datos_tabla.append([prog] + salida[:6])
        else:
            datos_tabla.append([prog, val, "ERROR", "ERROR", "ERROR", "ERROR", str(e)])
        print(f"Terminado exitosamente\n")
        guardar_csv()
        return True
    
    except subprocess.TimeoutExpired:
        datos_tabla.append([prog, val, "TIMEOUT", "TIMEOUT", "TIMEOUT", "TIMEOUT", calc_formula(prog, val)])    
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
                datos_tabla.append([p, val, "TIMEOUT", "TIMEOUT",  "TIMEOUT", "TIMEOUT", calc_formula(p, val)])
            guardar_csv()
            break

print("\n" + "="*40)
print(f"RESUMEN FINAL")
print("="*40)
print(tabulate(datos_tabla, headers=headers, tablefmt="grid"))