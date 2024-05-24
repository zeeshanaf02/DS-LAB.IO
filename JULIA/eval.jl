function eval_expre(expre)
	try
		res=Meta.parse(expre)
		println("Result:",eval(res))
	catch e
		println("Error:",e)
	end
end
function main()
	println("Enter the expression to evaluate:")
	expre=readline()
	eval_expre(expre)
end
main()
