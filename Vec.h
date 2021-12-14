#ifndef _VEC_H
#define _VEC_H
#include <ostream>
#include <math.h>

/**
 *A class for creating a generic three-dimensional vector of type T.
 *Includes operator overloading (for +, -, [], and <<) so that vector
 *operations can be performed.
 */
template<typename T>
class _vec3{
public:
    
    /**
     *Constructor
     */
    _vec3<T>(): d{0,0,0} {}
    
    /**
     *Destructor
     */
    _vec3<T>(T a, T b, T c) : d{a,b,c} {}
    
    /**
     *Operator for assigning a value to a component of the vector.
     *@param[in] i The index of the component to be accessed.
     *@return Reference to the i-th component of the vector.
     */
    T& operator[] (int i) {return d[i];}
    
    /**
     *Operator for reading a component of the vector.
     *@param[in] i The index of the component to be accessed.
     *@return The i-th component of the vector.
     */
    T operator[] (int i) const {return d[i];}
    
    /**
     *Operator for adding two vectors together.
     *@param[in] a Vector to be added.
     *@param[in] b Vector to be added.
     *@return \f$ a + b \f$
     */
    friend _vec3<T> operator+(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0]+b[0],a[1]+b[1],a[2]+b[2]);
    }
    
    /**
     *Operator for subtracting one vector from another.
     *@param[in] a Vector to be subtracted from.
     *@param[in] b Vector to be subtracted.
     *@return \f$ a - b \f$
     */
    friend _vec3<T> operator-(const _vec3<T>&a, const _vec3<T>&b) {
        return _vec3<T>(a[0]-b[0],a[1]-b[1],a[2]-b[2]);
    }
    
    /**
     *Performs dot product of two vectors.
     *@param[in] a Vector to be dotted.
     *@param[in] b Vector to be dotted.
     *@return \f$ a \cdot b \f$
     */
    friend T dot(const _vec3<T>&a, const _vec3<T>&b)  {
        return a[0]*b[0]+a[1]*b[1]+a[2]*b[2];
    }
    
    /**
     *Computes magnitude of a vector.
     *@param[in] a Vector with unknown magnitude.
     *@return \f$ \sqrt{a \cdot b} \f$
     */
    friend double mag(const _vec3<T>&a) {return sqrt(dot(a,a));}
    
    /**
     *Operator for outputting vector components to a stream.
     *@param[in] out Output stream object.
     *@param[in] a Vector to be outputted to stream.
     *@return Output stream object, so that operator can be used several times in a row.
     */
    friend std::ostream& operator<<(std::ostream &out, const _vec3<T>&a) {
       out<<a[0]<<" "<<a[1]<<" "<<a[2]; return out;
    }
    
protected:
    T d[3]; };

using double3 = _vec3<double>;

#endif
