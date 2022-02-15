all:
	g++ pageRank.cpp -o pageRank -Wall -g -O2

clean:
	rm -rf bin
