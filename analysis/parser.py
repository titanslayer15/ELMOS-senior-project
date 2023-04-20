import serial

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

time = []
volt = []

i = 0

while True:

    data = ser.read(4)
    
    if data == b'stop':
        ser.close()
        break

    else:
        print(int.from_bytes(data, "little"))
        print(int.from_bytes(ser.read(4), "little"))

# for j in range(len(time)):
    # time[j] = int.from_bytes(time[j], "little")
    # volt[j] = int.from_bytes(volt[j], "little") * (5.0 / 1023.0)
    # print(time[j], ",", volt[j])
    
