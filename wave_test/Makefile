
all: test.bin
	./test.bin 

wave_test.wav:  
	python3 ../wav_generator.py -d 0.001 --wav ./wave_test.wav 

wave_test.h: wave_test.wav
	python3 ../wav_to_header.py --wav ./wave_test.wav --cpp wave_test.h

test.bin: main.cpp wave_test.h 
	g++ main.cpp -o test.bin


.PHONY: clean
clean:
	rm -rf wave_test.wav wave_test.h
	rm -rf test.bin
