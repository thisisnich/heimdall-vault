from math import log
km = 3
f_values = [200,400,600,800,1000,1200,1400,1600,1800,2000]
print(f"line loss for {km} km and {f_values} MHz")
print('formula: 20*log(km) + 20*log(f) + 32.44')
print('20logd = 20log(3) = 9.54 dB')
for f in f_values:
    print(f'{f} MHz: {20*log(f, 10)} dB')
for f in f_values:
    print(f'{f} MHz: {9.54 + 20*log(f, 10)+32.44} dB')

    # print(f'total loss = 9.54 + {20*log(f, 10)} + 32.44 = {9.54 + 20*log(f, 10) + 32.44} dB')



print('--------------------------------')






