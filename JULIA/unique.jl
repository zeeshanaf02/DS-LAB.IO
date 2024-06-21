function getNextWord(inn::IOStream)
	ch=' '
	while !eof(inn)&&isletter(ch)
		ch=read(inn,Char)
	end
	if eof(inn)
		return nothing
	end
	wrd=string(ch)
	ch=read(inn,Char)
	while isletter(ch)
		wrd*=ch
		ch=read(inn,Char)
	end
	return wrd
end
function main()
	inn=open("input7.txt","r")
	wordList=Set{String}()
	while(word=getNextWord(inn))!=nothing
		union!(wordList,[lowercase(word)])
	end
	close(inn)
	print("Number of unique words:$(length(wordList))\n\n")
	print("Words in set:\n$wordList\n")
	print("\nWords in order\n")
	for w in sort(collect(wordList))
		print("$w")
	end
	println()
end
main()
