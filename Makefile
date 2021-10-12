client_p02_cya: client_p02_cya.cc string_a.cc alphabet.cc
	g++ -o client_p02_cya client_p02_cya.cc string_a.cc alphabet.cc

clean:
	rm -r client_p02_cya *.txt