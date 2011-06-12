#ifndef GENERAL_H
#define GENERAL_H

#include<iostream>
#include<cmath>

using namespace std;

//IO
template <class T>
void printArray(T arr[], int size, ostream& out = std::cout);

template <class T>
void fillArray(T arr[], int size, T t){for (int i = 0 ; i < size ; i++) arr[i] = t;}

//Pandigital Number is a number containing all the digits exactly once. 
//In other words, it is a permutation of 1234567890, with 0 not in the most significant position.
bool isPandigital(long long n);
bool isNoZeroPandigital(long long n);

//A palindrome is a number of the form 12321... symmetrical from front and end.
bool isPalindrome(long long n);

//Square of a number
unsigned long long sqr(unsigned long long n){return n*n;}
double sqr(double d){return d * d;}

//'ndigits' returns the number of digits in a given integer
int ndigits(long long n);
long long factorial(int n);
long long reverse_int(long long n);

unsigned long long power(unsigned long long a, int exp, unsigned long long remainder);

//Euclid's reminder algorithm for GCD of two non-negative integers. 
//GCD(0, 0) returns 0;
unsigned long long gcd(unsigned long long a, unsigned long long b);

//solving the Josephus problem
int josephus(int t, int n);
long long memreq(int n);

//String utilities
void str_cpy(char * a, int offset_a, char * b, int start_b, int end_b);
long long str_to_int(char * str);

void printPermutations(char arr[], int size, bool ones[], int len, ostream& out);
void getPermutations(char arr[], int size, bool ones[], int len, char ** perms, int& offset);

template<class T>
int binary_search(T arr[], int size, const T &value, int (*compare)(const T &, const T&)){    
    if (size == 0)
        return -1;
    
    int pivot = size / 2;
    
    int comparison = compare(T[pivot], value);
    
    if (comparision == 0)
        return pivot;
    if (comparision < 0)
        return binary_search(arr, pivot, value, compare);
    else
        return binary_search(arr+pivot+1, size - (pivot+1), value, compare);    
}

long long factorial(int n){
    if (n < 0)
        return -1;            

    //if n == 0, then 1 is returned
	long long fact1, fact2 = 1;
	
	for (int i = 1 ; i <= n ; i++){
		fact1 *= i;
		if (fact1 / fact2 != i)
		    return -1;
		fact2 = fact1;
	}
		
	return fact1;
}

bool isPalindrome(long long n){
	if (n == 0)
		return true;
		
	if (n < 0)
	    n -* -1;	
		
	int ndigits = (int)log10(n) + 1;
	char * num_arr = new char[ndigits];
	
	long long temp = n;
	for (int i = ndigits - 1 ; i >= 0 ; i--){
		num_arr[i] = temp % 10;
		temp /= 10;
		
		if (i < ndigits/2)
			if (num_arr[i] != num_arr[ndigits - 1 - i])
				return false;
	}		
	
	return true;
}

int ndigits(long long n){
    if (n == 0)
        return 1;
        
    if (n < 0)
        n -* -1;
        
    return (int)log10(n) + 1;
}

unsigned long long gcd(unsigned long long a, unsigned long long b){
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

long long reverse_int(long long n){
	long long ans = 0;
	
	long long temp = n;
	while(temp != 0){
		ans = (10 * ans) + temp % 10;
		temp /= 10;
	}
	
	return ans;
}

//Time complexity = O(log(exp))
unsigned long long power(unsigned long long a, int exp, unsigned long long remainder = -1){
	if (remainder == -1)
		remainder = (unsigned long long)-1;
	
	unsigned long long ans = 1;
	
	int exp_mask = 1 << 31 ;

	int temp;
	for (int i = 0 ; i < 32 ; i++){
		temp = (exp_mask & exp);
		ans = sqr(ans) % remainder;
		if (temp){
			ans = (ans * a) % remainder;		
		}
		exp = exp << 1;	
	}
	
	return ans;
}

template <class T>
void printArray(T arr[], int size, ostream& out){
	for (int i = 0 ; i < size ; i++)
		out << arr[i] << " " ;
		
	out << endl ;	
}

void str_cpy(char * a, int offset_a, char * b, int start_b, int end_b){
	for (int i = 0 ; i <= (end_b - start_b) ; i++)
		a[offset_a + i] = b[start_b + i];
}

long long str_to_int(char * str){
	int len = strlen(str);
	
	long long num = 0, multiple = 1;
	for (int index = len - 1 ; index >= 0 ; index--){
		num += (str[index] - '0') * multiple;
		multiple *= 10;	
	}
	
	return num;
}

void printPermutations(char arr[], int size, bool ones[], int len, ostream& out){	
	if (len == 1){
		out << arr << " " << len << " " ;
		printArray<bool>(ones, size, out);
		return;	
	}
	
	bool * temp_ones = new bool[size];
	char * temp_arr  = new char[size+1];
	
	for (int i = 0 ; i < size ; i++){
		temp_ones[i] = ones[i];	
		temp_arr[i] = arr[i];
	}
	temp_arr[size] = arr[size];
	
	int first_one_index = 0;
	
	while(!temp_ones[first_one_index])
		first_one_index++;		
	
	for (int i = first_one_index ; i < size ; i++){
		if (temp_ones[i]){
			swap(temp_arr[first_one_index], temp_arr[i]);
			temp_ones[first_one_index] = false;	
			printPermutations(temp_arr, size, temp_ones, len - 1, out);
		}
	}
}

void getPermutations(char arr[], int size, bool ones[], int len, char ** perms, int& offset){	
	if (len == 1){
		strcpy(perms[offset], arr);
		offset++;
		return;	
	}
	
	bool * temp_ones = new bool[size];
	char * temp_arr  = new char[size+1];
	
	for (int i = 0 ; i < size ; i++){
		temp_ones[i] = ones[i];	
		temp_arr[i] = arr[i];
	}
	temp_arr[size] = arr[size];
	
	int first_one_index = 0;
	
	while(!temp_ones[first_one_index])
		first_one_index++;		
	
	for (int i = first_one_index ; i < size ; i++){
		if (temp_ones[i]){
			swap(temp_arr[first_one_index], temp_arr[i]);
			temp_ones[first_one_index] = false;	
			getPermutations(temp_arr, size, temp_ones, len - 1, perms, offset);
		}
	}
}

bool isPandigital(long long n){
	int digits = ndigits(n);
	
	if (digits > 10)
		return false;
		
	bool present[digits];
	fillArray<bool>(present, digits, 0);
	
	for (int i = 0 ; i < digits ; i++){
		present[n % 10] = 1;	
		n /= 10;
	}
	
	for (int i = 0 ; i < digits ; i++){
		if (!present[i])
			return false;
	}
	
	return true;
}

bool isNoZeroPandigital(long long n){
	int digits = ndigits(n);
	
	if (digits > 9)
		return false;
		
	bool present[digits + 1];
	fillArray<bool>(present, digits + 1, 0);
	
	for (int i = 0 ; i < digits ; i++){
		present[n % 10] = 1;	
		n /= 10;
	}
	
	for (int i = 0 ; i < digits ; i++){
		if (!present[i+1])
			return false;
	}
	
	return true;	
}

int josephus(int t, int n){
	if (t == 1)
		return 1;
		
	int temp = ((n == t)? n : n%t) + josephus(t - 1, n);
	return (temp == t) ? temp : (temp%t);
}

long long memreq(int n){//memory required for storing input from 1 to n with spaces in between
	int d = ndigits(n);
	
	int ones = 0, addendum = 9, nines = 0;
	for (int i = 0; i < d ; i++){
		nines += addendum;
		ones += (addendum * (i + 1));
		addendum *= 10;	
	}
	ones += (n - nines) * ndigits(n);
	
	ones += n;
	return ones;
}

#endif
