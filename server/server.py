import librosa
import numpy
import socket
import struct

sr = 16000
port = 10001

s = socket.socket( socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
s.bind( ('0.0.0.0', port))

complete = b''
while len(complete) < sr*4:
    raw, addr = s.recvfrom(1024)
    complete += raw
print ('received: %d bytes' % len(complete))

parsed = struct.unpack('<'+'f'*sr, complete)
parsed = numpy.array(parsed, dtype= numpy.float32)

print ('saving: %d samples' % len(parsed))
librosa.output.write_wav('server.wav', parsed, sr)

s.close()
