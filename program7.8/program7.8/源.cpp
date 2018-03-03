//Progran7.8 Calculate prime prime using dynamic memory allocation

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

int main() {
	int max = 0;		//Number of prime required
	int count = 3;		//Count of prime found
	long trial = 5;		//Candiate prime
	bool isprime = true;		//Indicates when a prime is found

	cout << endl
		<< "Enter the number of prime you would like: ";
	cin >> max;		//Number of primes required

	long* primes = new long[max];		//Allocate memory for them
	*primes = 2;						//Index to three seed primes...
	*(primes + 1) = 3;
	*(primes + 2) = 5;

	do {
		trial += 2;					//Next value for checking
		int i = 0;					//Index to primes array

		//Try dividing the candidate by all the primes we have
		do {
			isprime = trial % *(primes + i) > 0;		//False for exact division
		} while (++i < count && isprime);

		if (isprime)						//We got one...
			*(primes + count++) = trial;		//...so save it in primes array
	} while (count < max);

	//Output  primes 5 to a line
	for (int i = 0; i < max; i++) {
			if(i%5==0)					//Newline on 1st line and after ervery 5th prime	
		cout << endl;		
			cout << std::setw(10) << *(primes + i);

	}
	cout << endl;
	delete [] primes;			//Free up memory

	
	return 0;

}