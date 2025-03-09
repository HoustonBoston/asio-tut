main: Peer.cpp main.cpp
	g++ -g -Wall $^ -o $@

clean:
	rm main