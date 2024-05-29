function SCA()
	n=0
	sum=0
	print("Enter a number:")
	while(snum=readline())!=""
		n+=1
		sum+=parse(Int64,snum)
		print("Enter a number:")
	end
	if n==0
		println("\nNo numbers entered")
	else
		println("\n $n Number(s) entered")
		println("Sum if $sum")
		println("Average is $(round(sum/n,digits=1))")
	end
end
SCA()
