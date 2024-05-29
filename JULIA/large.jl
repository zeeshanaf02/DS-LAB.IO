function findlar()
	bignum=typemin(Int64)
	for sum in eachline("input.txt")
		num=parse(Int64,sum)
		if num>bignum
			bignum=num
		end 
	end
	println("Largest is $bignum")
end 
findlar()
