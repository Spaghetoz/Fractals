

class Complex {

    public:
        double a;
        double b;
        Complex(double a, double b);

        /// calculations got from simplified algebraic calculations between 2 complex (a+ib) and (a'+ib')

        Complex operator+(Complex const& c2) {
            return Complex(a+c2.a, b+c2.b);
        }
        Complex operator-(Complex const& c2) {
            return Complex(a-c2.a, b-c2.b);
        }
        Complex operator*(Complex const& c2) {
            return Complex(a*c2.a-b*c2.b, a*c2.b+b*c2.a);
        }
        Complex operator/(Complex const& c2) {
            return Complex( 
                (a*c2.a+b*c2.b) / (c2.a * c2.a + c2.b * c2.b), 
                (c2.a*b-a*c2.b) / (c2.a * c2.a + c2.b * c2.b)
            );
        }

        // calculation obtained using the remarkable identity (a+b)^2
        Complex pow2() {
            return Complex(a*a-b*b, 2*a*b);
        }
    
};