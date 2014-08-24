#ifndef GENERAL_H
#define GENERAL_H

#include<cstring>
#include<iostream>

template<typename T>
T minimum(T a, T b, T c) {
    if (a < b) 
        if (a < c) 
            return a;
        else 
            return c;
    else 
        if (b < c)
            return b;
        else
            return c;
}

/*
 * Returns the Levenshtein Distance of two strings.
 * http://en.wikipedia.org/wiki/Levenshtein_distance
 */
size_t wagnerFischer(char * A, char * B, size_t len_a, size_t len_b) {

    //std::cout << "lengths : " << len_a << " " << len_b << std::endl ;

    if (len_a == 0) {
        return len_b;
    }

    if (len_b == 0) {
        return len_a;
    }

    size_t n_rows = len_a + 1;
    size_t n_cols = len_b + 1;

    size_t ** distanceMatrix = new size_t* [n_rows]; 
    for (size_t i = 0 ; i < n_rows ; ++i) {
        distanceMatrix[i] = new size_t[n_cols];
    }

    //Fill first row and column.
    for (size_t i = 0 ; i < n_cols ; ++i) {
        distanceMatrix[0][i] = i; 
    }
    for (size_t i = 0 ; i < n_rows ; ++i) {
        distanceMatrix[i][0] = i;
    }

    size_t insertionResult, deletionResult, substitutionResult;
    for (size_t i = 1 ; i < n_rows ; ++i) {
        for (size_t j = 1 ; j < n_cols ; ++j) {
            insertionResult = distanceMatrix[i-1][j] + 1;
            deletionResult  = distanceMatrix[i][j-1] + 1;
            substitutionResult = distanceMatrix[i-1][j-1] + (size_t)(A[i] == B[j]);

            distanceMatrix[i][j] = minimum<size_t>(insertionResult, deletionResult, substitutionResult);
        }
    }

    return distanceMatrix[n_rows - 1][n_cols - 1];
}

#endif
