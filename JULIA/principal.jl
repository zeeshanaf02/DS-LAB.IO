using Printf
function calcint()
	print("principal?")
	P=parse(Int64,readline())
	print("Interest rate?")
	r=parse(Float64,readline())
	print("Year amount")
	amt=P
	for y=1:10
		amt+=amt*r/100
		@printf("%3d %8.2f\n",y,amt)
		if amt>2P
			break 
		end
	end
end
calcint()
