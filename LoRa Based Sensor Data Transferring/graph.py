import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('sensorvalue.csv')  
df['Time'] = pd.to_datetime(df['Time'])
df = df.sort_values(by='Time')

time = df['Time']
humidity = df['Value']

plt.plot(time, humidity, label='Humidity Value')
plt.xlabel('Time')
plt.ylabel('Value')
plt.title('Time-Humidity Graph')
plt.xticks(rotation=45)
plt.legend()
plt.tight_layout()
plt.show()