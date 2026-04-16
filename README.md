\# Affine Cipher Program



This is a C++ implementation of the Affine Cipher encryption and decryption algorithm.



\## Features



\- Encrypt plaintext using Affine Cipher

\- Decrypt ciphertext using Affine Cipher

\- Validates that key A is coprime with 26

\- Handles spaces in text

\- Input validation for uppercase letters



\## How It Works



The Affine Cipher uses the formula:



Encryption:

C = (A \* P + B) mod 26



Decryption:

P = A⁻¹ \* (C - B) mod 26



Where:

\- A must be coprime with 26

\- B is any integer

\- A⁻¹ is the modular inverse of A



\## Usage



Compile:



g++ AffineCipherProgram.cpp -o affine\_cipher

Run:
./affine\_cipher

Notes

Only uppercase letters (A–Z) are supported

Spaces are preserved

Lowercase input is not allowed

