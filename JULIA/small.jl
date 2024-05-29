function findsmall()
	smallnum=typemax(Int64)
	for snum in eachline("input.txt")
		num=parse(Int64,snum)
		if num<smallnum
			smallnum=num
		end 
	end
	println("Smallest if $smallnum")
end
findsmall()

