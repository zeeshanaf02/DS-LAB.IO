function mat_add(A::Matrix,B::Matrix)::Matrix
	if size(A)!=size(B)
		error("Matrices must have the same dimensions for addition")
	end
	return A+B
end
function mat_subs(A::Matrix,B::Matrix)::Matrix
	if size(A)!=size(B)
		error("Matrix must have same dimensions for substraction")
	end
	return A-B
end
A=[1 2 3;4 5 6;7 8 9]
B=[9 8 7;6 5 4;3 2 1]
res_add=mat_add(A,B)
println("Element-wise addition:")
println(res_add)
res_sub=mat_subs(A,B)
println("Element-wise substraction:")
println(res_sub)
