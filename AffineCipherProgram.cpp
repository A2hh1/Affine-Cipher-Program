#include <iostream>
#include <string>

using namespace std;

bool isCoprime(int a, int m) 
{
    while (m != 0) 
	{
        int temp = m;
        m = a % m;
        a = temp;
    }
    return a == 1;
}

int modInverse(int a, int m) 
{
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

string encrypt(string plaintext, int keyA, int keyB) 
{
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i++) 
	{
        if (plaintext[i] == ' ')
            ciphertext += ' ';
        else
            ciphertext += char(((keyA * (plaintext[i] - 'A') + keyB) % 26) + 'A');
    }
    return ciphertext;
}

string decrypt(string ciphertext, int keyA, int keyB) 
{
    string plaintext = "";
    int keyAInverse = modInverse(keyA, 26);
    for (int i = 0; i < ciphertext.length(); i++) 
	{
        if (ciphertext[i] == ' ')
            plaintext += ' ';
        else
            plaintext += char((keyAInverse * (ciphertext[i] - 'A' - keyB + 26) % 26) + 'A');
    }
    return plaintext;
}

int main() 
{
    
		int choice;

	do 
	{
		int keyA, keyB;
    	string plaintext, ciphertext;
    	cout << "   Affine cipher encryption/decryption program   " << endl;
    	cout << "-------------------------------------------------" << endl;
    	cout << "              Choose an option: \n"<< endl;
		cout << "              1. For Encryption" << endl;
		cout << "              2. For Decryption " << endl;
		cout << "              3. For Exiting \n" << endl;
		cout << "              Enter your choice: ";
		
		cin >> choice;
		cout << endl;
		switch(choice)
		{
			case 1:
				
    			do
    			{
    				cout << "Enter key A (must be coprime with 26): ";
    				cin >> keyA;
    				cout << "Enter key B: ";
    				cin >> keyB;
					cin.ignore();
    				if (!isCoprime(keyA, 26)) 
					{
        				cout << "\nError: Key A must be coprime with 26.\n" << endl;
    				}
    				else
    				{
						bool check;
    					do
						{
							check = false;
							
	    					cout << "Enter plaintext (only capital letters and spaces): ";
	    					getline(cin, plaintext);
	    					for(int i = 0; plaintext.length() > i; i++)
	    					{
								if(plaintext[i] < 'A' || plaintext[i] > 'Z')
								{
									
										cout << "\nInvalid PlainText. (only capital letters and spaces) \n\n";
										check = true;
										break;
								}
							}	
								
	    				}while(check);
	    				
	    				ciphertext = encrypt(plaintext, keyA, keyB);
	    				cout << "Encrypted text: " << ciphertext << "\n\n" << endl;
					}
				
				}while(!isCoprime(keyA, 26));

				break;
				
			case 2:
				do
				{
					
			    	cout << "Enter key A (must be coprime with 26): ";
	    			cin >> keyA;
	  				cout << "Enter key B: ";
	    			cin >> keyB;
					cin.ignore();
	    			if (!isCoprime(keyA, 26)) 
					{
	        			cout << "\nError: Key A must be coprime with 26.\n" << endl;
	    			}
	    			else
	    			{
	    				bool check;
	    					do
							{
								check = false;
	    						cout << "Enter ciphertext (only capital letters and spaces): ";
	    						getline(cin, ciphertext);
		    					for(int i = 0; ciphertext.length() > i; i++)
		    					{
									if(ciphertext[i] < 'A' || ciphertext[i] > 'Z')
									{
										
											cout << "\nInvalid ciphertext. (only capital letters and spaces) \n\n";
											check = true;
											break;
									}
								}
	
	    					}while(check);
	    				plaintext = decrypt(ciphertext, keyA, keyB);
	    				cout << "Decrypted text: " << plaintext << "\n\n" << endl;
	    			}
				}while(!isCoprime(keyA, 26));
				break;
				
			case 3: 
				cout << "Exiting the program... \n\n";
				cout << "Thank You For Using Our Program  " << endl;


				break;
			default: 
				cout << "Enter a valid choice:" <<endl;
		}
		
	}while(choice != 3);

		

    return 0;
}
 
