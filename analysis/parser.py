import serial
import struct

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

time = []
volt_T = []
volt_R = []

while True:
    t = ser.read(4)
    
    if t == b'stop':
        ser.close()
        break
    
    else:
        time.append(struct.unpack_from('<l', t)[0])
        volt_T.append(int.from_bytes(ser.read(2), "little") * (5.0 / 1023.0))
        volt_R.append(int.from_bytes(ser.read(2), "little") * (5.0 / 1023.0))
        
for j in range(len(time)):
    print(time[j])
    print(volt_T[j])
    print(volt_R[j])
    print('\n')
    
