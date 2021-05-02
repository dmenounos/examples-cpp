#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

class AlgorithmIterator;

class Algorithm {

public:

	Algorithm(int init, int steps);

	/**
	 * Returns whether we are is still in progress.
	 */
	bool hasNext();

	/**
	 * Returns the current value and advances to the next step.
	 */
	int next();

	// Standard interface for iterable
	AlgorithmIterator begin();
	AlgorithmIterator end();

private:

	int _curr;
	int _size;

	friend AlgorithmIterator;
};

#endif // ALGORITHM_HPP
