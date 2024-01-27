import serial
import pandas as pd
from datetime import datetime

df = pd.read_csv('sensorvalue.csv')
Value_df = pd.DataFrame(columns=["Time", "Value"])

port_name = 'COM3'  
ser = serial.Serial(port_name, baudrate=9600)  

while True:
    value = ser.readline().decode('utf-8').strip()  
    time = datetime.now().strftime("%Y-%m-%d %H:%M:%S") 
    value_df = pd.concat([Value_df, pd.DataFrame({"Time": [time], "Value": [value]})], ignore_index=True)
    value_df.to_csv("sensorvalue.csv", index=False,quoting=0) 
    print(value, time)  


