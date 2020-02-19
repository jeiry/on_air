# coding: utf-8
import serial
import time
#import serial module
ser = serial.Serial('/dev/ttyUSB0', 9600,timeout=1);

#open named port at 9600,1s timeot

#try and exceptstructure are exception handler
# class colorLight:
#     def sentData(self,value):
#         i = 0
#         while i < 3:
#             try:
#                 # ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
#                 print('value',value)
#                 ser.write(value.encode())
#                 response = ser.readall()
#                 print('response',response)
#             except:
#                 ser.close();
#             i += 1
class colorLight:
    def sentData(self,value):
        try:
            # ser = serial.Serial('/dev/ttyUSB0', 9600, timeout=1)
            # print('value', value)
            ser.write(value.encode())
            response = ser.readall()
            # print('response', response)
        except:
            ser.close();
# i = 0
# while i < 3:
#     print(i)
#     ser.write("255,0,0".encode())
#     response = ser.readall()
#     print('response',response)
#     i += 1

# try:
#     while 1:
#         print('h?')
#         # ser.write('r'.encode())
#         ser.write("255,255,255".encode())
#         response = ser.readall()
#         print('response',response)
# except Exception as e:
#     ser.close()
#     print(e)

# try:
#     while 1:
#         ser.write('r');#writ a string to port
#         response = ser.readall();#read a string from port
#         print response;
# except:
#     ser.close();