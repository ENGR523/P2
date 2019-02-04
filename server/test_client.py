#!/usr/bin/env python3 
import librosa
import socket
import struct

server_address = ('iot.lukefahr.org', 10001)
#server_address = ('18.218.51.247', 10001)

ys, sr = librosa.core.load('elephant.wav', mono=True, sr=16000)
assert(sr == 16000)

raw = struct.pack("<"+"f"*sr, *ys)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

chunks = [raw[i:i+1024] for i in range(0, len(raw), 1024)]
sent = 0
for chunk in chunks:
    sent += s.sendto(chunk, server_address)
print ('sent: %d bytes' % sent)


