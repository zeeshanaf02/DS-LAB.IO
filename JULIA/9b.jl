using LinearAlgebra
function scalar_multi(A::Matrix,scalar::Real)::Matrix
	return A*scalar
end
function elemwise_multi(A::Matrix,B::Matrix)::Matrix
	if size(A)!=size(B)
		error("Matrices must have the same dimensions for element-wise multiplication")
	end
	return A*B
end
function dot_prod(A::Matrix,B::Matrix)
	if size(A)!=size(B)
		error("Matrices must have same dimensions for dot product ")
	end
	return dot(A,B)
end
function cross_prod(A::Matrix,B::Matrix)
	if size(A)!=(3,3)||size(B)!=(3,3)
		error("Matrices must have 3x3 for cross product")
	end 
	col1_A,col2_A,col3_A=eachcol(A)
	col1_B,col2_B,col3_B=eachcol(B)
	res_col1=cross(col1_A,col1_B)
	res_col2=cross(col2_A,col2_B)
	res_col3=cross(col3_A,col3_B)
	return hcat(res_col1,res_col2,res_col3)
end
A=[1 2 3;4 5 6;7 8 9]
B=[9 8 7;6 5 4;3 2 1]
scalar=2
res_scal=scalar_multi(A,scalar)
println("Scalar multiplication (A*$scalar)):")
println(res_scal)
res_elemwise=elemwise_multi(A,B)
println("Element-wise multiplication:")
println(res_elemwise)
res_dotprod=dot_prod(A,B)
println("Dot product:")
println(res_dotprod)
res_cross_prod=cross_prod(A,B)
println("Cross product")
println(res_cross_prod)
