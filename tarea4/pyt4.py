
from enum import Enum
from tarea4 import Transbordador, Vehiculo
# ENUM para el tipo de vehículo
tipo= Enum('tipo', ["auto", "camión", "bus", "ambulancia"])
# Creación de un transbordador
t1=Transbordador("Antares", "Quellón", 100000, 3, 50000)
# Cargar algunos vehículos
t1.pushVehiculo(1, Vehiculo("Mazda 3", 3000, 2500, tipo.auto))
t1.pushVehiculo(1, Vehiculo("Toyota Yaris", 2800, 2000, tipo.auto))
t1.pushVehiculo(2, Vehiculo("Tatra Phoenix", 9010, 8500, tipo.camión))
t1.pushVehiculo(2, Vehiculo("Skania k400", 9500, 7000, tipo.bus))
t1.pushVehiculo(3, Vehiculo("Honda CRV", 3100, 2200, tipo.auto))
t1.pushVehiculo(3, Vehiculo("Nissan Sentra", 3300, 2700, tipo.auto))
# Consultas
print(t1.getEspacioLibre(1))
print(t1.getLargoFila(1))
print(t1.getPesoLibre())
print(t1.getTipo(tipo.bus))
