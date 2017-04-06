#pragma once
namespace sakib_complex {
	class complex {

	public:
		complex(double i=0,double j=0) {
			set_number(i, j);
		}

		double get_real() const;
		double get_imag()const;
		friend std::istream& operator>>(std::istream& outs, complex& b);
		complex& operator+=(const complex& added);
		complex& operator-=(const complex& added);

	private:
		double  real_part;
		double  imag_part;
		void set_number(double real, double imag);

	};


	bool operator==(const complex& a , const complex& b);
	std::ostream& operator<<(std::ostream& outs, const complex& b);
	complex operator-(const complex& a, const complex& b);
	complex operator+ (const complex& a, const complex& b);

	
};