using Printf
function calcpay()
	print("Hours worked? ")
	hours=parse(Float64,readline())
	print("Rate of pay? ")
	rate=parse(Float64,readline())
	if hours<40
		regpay=hours*rate
		ovtpay=0
	else
		regpay=40*rate
		ovtpay=(40-hours)*rate*1.5
	end
	grosspay=regpay+ovtpay
	@printf("\nRegular pay:\$%0.2f\n",regpay)
	@printf("\novertime pay:\$%0.2f\n",ovtpay)
	@printf("\nGross pay:\$%0.2f\n",grosspay)
end
calcpay()
