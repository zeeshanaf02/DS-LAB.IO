using Printf
function position(ch::Char)
	if isuppercase(ch)
		return ch-'A'+1
	end
	if islowercase(ch)
		return ch-'a'+1
	end
	return 0
end
function charFreq(inn::IOStream)
	LIA=26
	freq=fill(0,LIA)
	while !eof(inn)
		n=position(read(inn,Char))
		if n!=0
			freq[n]+=1
		end
	end
	print("Letters Frequency:\n")
	for ch='a':'z'
		@printf("%4c %8d\n",ch,freq[ch-'a'+1])
	end
	close(inn)
end
inn=open("passage.txt","r")
charFreq(inn)
