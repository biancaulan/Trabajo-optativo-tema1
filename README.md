# Trabajo optativo de la asignatura Sistemas de Cómputo Paralelo
  La red de comunicación de un multicomputador se utiliza para el envío de mensajes entre los nodos
del sistema; mensajes que van del nodo origen al nodo destino pasando por diferentes nodos
intermedios de la red. El mensaje incluye un campo, el registro de encaminamiento, que le indica
por dónde llegar a destino. Esa información de encaminamiento depende de la topología de la red.

  El objetivo de este código es implementar algoritmos de encaminamiento, que tome como entradas los siguientes
datos:
  1. Número de dimensiones de la red: n
  2. Número de nodos por dimensión: k
  3. Si la topología tiene anillos(1) o no(0) en cada dimensión
  4. Nodo origen del mensaje
  5. Nodo destino del mensaje
