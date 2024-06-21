using Printf
function tolowercase(ch::Char)
	if isletter(ch)
		return lowercase(ch)
	end
	return '0'
end
function letfrequency(letterfreq::Dict,inn)
	while !eof(inn)
		ch=read(inn,Char)
		if(c=tolowercase(ch))!='0'
			letterfreq[c]=get(letterfreq,c,0)+1
		end
	end
end
function main()
	inn=open("input.txt","r")
	out=open("output.txt","w")
	letfreq=Dict{Char,Int64}()
	letfrequency(letfreq,inn)
	println(out,"Letter Frequency\n")
	for ch in sort(collect(keys(letfreq)))
		@printf(out,"%4c%8d\n",ch,letfreq[ch])
	end
	close(inn)
	close(out)
end
main()
