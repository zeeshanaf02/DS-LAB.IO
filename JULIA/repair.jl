using Printf
function jobCh()
	print("Hours worked? ")
	hours=parse(Float64,readline())
	print("Cost of parts? ")
	parts=parse(Float64,readline())
	jobCh=hours*100+parts
	if jobCh<150
		jobCh=150
	end
	@printf("\nTotal charges:\$%0.2f\n",jobCh)
end
jobCh()
