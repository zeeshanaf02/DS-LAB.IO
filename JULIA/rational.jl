function eval_expre(expression::String)
	try
		res=eval(Meta.parse(expression))
		println("Result:",res)
	catch e
		println("Error:",e)
	end
end
expressions=[
	     "2+3",
	     "2.5*4.7",
	     "sin(pi/2)",
	     "sqrt(2)+exp(1)*log(10)",
	     "sqrt(2)"
	     ]
for exp in expressions
	println("Expression:",exp)
	eval_expre(exp)
	println()
end
