struct Compnum
	real::Float64
	imag::Float64
end
function add_com(a::Compnum,b::Compnum)
	return Compnum(a.real+b.real,a.imag+b.imag)
end
function sub_com(a::Compnum,b::Compnum)
	return Compnum(a.real-b.real,a.imag-b.imag)
end
function mult_com(a::Compnum,b::Compnum)
	real_part=a.real*b.real-a.imag*b.imag
	imag_part=a.real*b.imag+a.imag*b.real
	return Compnum(real_part,imag_part)
end
function div_comp(a::Compnum,b::Compnum)
	dem=b.real^2+b.imag^2
	if dem!=0
		real_part=(a.real*b.real+a.imag*b.imag)/dem
		imag_part=(a.imag*b.real-a.real*b.imag)/dem
		return Compnum(real_part,imag_part)
	else
		println("Error:Devision by zero!")
		return Compnum(NaN,NaN)
	end
end
function main()
	println("Enter the real and imaginary parts of the first complex number:")
	real1=parse(Float64,readline())
	imag1=parse(Float64,readline())
	println("Enter the real and imaginary parts of the second complex number:")
	real2=parse(Float64,readline())
	imag2=parse(Float64,readline())
	comp1=Compnum(real1,imag1)
	comp2=Compnum(real2,imag2)
	println("Addition:",add_com(comp1,comp2))
	println("Substraction:",sub_com(comp1,comp2))
	println("Multiplication:",mult_com(comp1,comp2))
	println("Division:",div_comp(comp1,comp2))
end
main()
