main: Client.cpp Server.cpp main.cpp
	g++ -g -Wall $^ -o $@

clean:
	rm main