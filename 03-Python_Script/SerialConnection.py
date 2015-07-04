import serial
'''
 ¡¡¡ Usando en Arduino el sketch: Conexion_Excel_LedsyPotenciometers  !!!
'''
class Conexion_Serial(object):
    def __init__(self):
        try:
            Puerto=int(raw_input("What port do you want to choose "))
            self.LongitudLectura= int(raw_input("Numbers of characteres read in each step "))
            self.ser=serial.Serial(Puerto)
            print self.ser.portstr
        except:
            print 'Sorry, but this port is not available'
    def TurnONRed (self):
        self.ser.write('3')

    def TurnONBlue (self):
        self.ser.write('5')

    def TurnONGreen (self):
        self.ser.write('6')

    def TurnOFFRed (self):
        self.ser.write('7')

    def TurnOFFBlue (self):
        self.ser.write('8')

    def TurnOFFGreen (self):
        self.ser.write('9')
    def TurnONLineal (self):
        self.ser.write('A')
    def TurnOFFLineal (self):
        self.ser.write('B')
    def TurnONRot (self):
        self.ser.write('C')
    def TurnOFFRot (self):
        self.ser.write('D')
    def NumeroEspera (self):
        if len(str(self.ser.inWaiting()))==1:
            return str(self.ser.inWaiting())[0]
        else:
            return str(self.ser.inWaiting())
    def Leer (self):
        if int(self.NumeroEspera())>0:
            return self.ser.read(self.LongitudLectura)
        else:
            print 'There is no Data on Buffer'
    def Vaciar (self):
        self.ser.flushInput()
    def Cerrar (self):
        self.ser.close()
