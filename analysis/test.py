import serial
import struct

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

while True:
    time = struct.unpack_from('<l', ser.read(4))[0]
    volt = int.from_bytes(ser.read(2), "little")
    
    v = volt * (5.0 / 1023.0)

    print(time)
    print(v)


    print('\n\n')
    
