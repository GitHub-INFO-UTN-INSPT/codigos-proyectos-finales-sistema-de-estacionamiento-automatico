[![Review Assignment Due Date]

# SISTEMA AUROMTICO DE ESTACIONAMIENTO
# PROYECTO FINAL TECNICAS DIGITALES -  2023

# 1. Introducción:

En este proyecto a realizar, se presenta el diseño y la implementación de un sistema automático de estacionamiento que utiliza un Arduino, una pantalla LCD, sensores infrarrojos (IR) y un servo motor. El sistema tiene como objetivo optimizar el proceso de estacionamiento, indicando la disponibilidad de espacios y gestionando el acceso de vehículos.
Objetivos:
Diseñar un sistema de estacionamiento automatizado que gestione la entrada y salida de vehículos.
Proporcionar información en tiempo real sobre la disponibilidad de espacios de estacionamiento a través de una pantalla LCD.
Controlar una barrera utilizando un servo motor para el acceso.
Utilizar sensores IR para detectar la presencia de vehículos en los espacios de estacionamiento.

# Funcionalidades:
1.	Detección de Entrada y Salida de Vehículos: El sistema utiliza sensores infrarrojos (IR) colocados en las entradas y salidas del estacionamiento para detectar la llegada y la partida de vehículos. Cuando un vehículo se acerca a la entrada, el sensor de entrada detecta su presencia y activa el sistema.

2.	Control de Barrera: Para garantizar el acceso autorizado, el sistema controla una barrera utilizando un mini servo motor. Cuando se detecta un vehículo en la entrada, la barrera se levanta para permitir el acceso. Cuando un vehículo sale del estacionamiento, la barrera se cierra nuevamente.

3.	Visualización en Tiempo Real: El sistema muestra información en tiempo real sobre la disponibilidad de espacios de estacionamiento en una pantalla LCD de 20×4. Los usuarios pueden observar cuántos espacios están ocupados y cuántos están disponibles.

4.	Detección de Ocupación de Espacios: Se instalan sensores IR en cada espacio de estacionamiento individual para detectar si está ocupado por un vehículo. Cuando un vehículo ingresa a un espacio, el sensor lo registra como ocupado en la pantalla LCD. Al salir, el espacio se marca como disponible.

# Componentes Necesarios:
•	Arduino UNO
•	Pantalla LCD de 20×4
•	Módulo I2C para la pantalla LCD
•	Dos sensores IR (para entrada y salida)
•	Mini Servo Motor SG-90 (para control de barrera)
•	Seis sensores IR (para espacios de estacionamiento individuales)
•	Fuente de alimentación (220V)
•	Adaptador de corriente (5 V, 2 A)


