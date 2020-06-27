
template<typename T>
class Rational{
public:
    Rational(const T& numerator = 0, 
        const T& denominator = 1);

    // friend Rational operator*(const Rational& lhs, const Rational& rhs);

public:
    T numerator;
    T denominator;
};

template<typename T>
Rational<T>::Rational(const T& numerator, const T& denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

template<typename T>
Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs)
{
    return Rational<T>(lhs.numerator*rhs.numerator, lhs.denominator * rhs.denominator);
}