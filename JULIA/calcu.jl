function display_menu()
	println("Welcome to the calculator program \n1.Additon\n2.Substraction\n3.Multiplication\n4.Division\n5.Exit\nEnter your choice:")
end
function addition(a,b)
	return a+b
end
function substraction(a,b)
	return a-b
end
function multi(a,b)
	return a*b
end
function division(a,b)
	if b!=0
		return a/b
	else
		println("Error:Zero division error!")
		return NaN
	end
end
function main()
	while true
		display_menu()
		choice=parse(Int64,readline())
		if choice==5
			println("Exit Calculator Program.")
			break
		end
		println("Enter first number:")
		num1=parse(Float64,readline())
		println("Enter second number:")
		num2=parse(Float64,readline())
		if choice==1
			result=addition(num1,num2)
			println("Result:",result)
		elseif choice==2
			result=substraction(num1,num2)
			println("Result:",result)
		elseif choice==3
			result=multi(num1,num2)
			println("Result:",result)
		elseif choice==4
			result=division(num1,num2)
			println("Result:",result)
		else
			println("Invalid choice! Please enter a number between 1 and 5.")
		end 
	end
end
main()
