#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "sha256.cpp"

using namespace std;

class user {
	protected:
		string  gen_random(int len) {
			string s;
			static const char alphanum[] =
				"0123456789"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz"
				"!@#$%^&*()_+=/|<>?:{},.;'\[]";

			for (int i = 0; i < len; ++i) {
				s += alphanum[rand() % (sizeof(alphanum) - 1)];
			}

			return sha256(s);
		}

		string  gen_randomForName(int len) {
			string s;
			static const char alphanum[] =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";

			for (int i = 0; i < len; ++i) {
				s += alphanum[rand() % (sizeof(alphanum) - 1)];
			}

			return s;
		}

		string generatePublicKey() {
			string publicKey;

			publicKey = gen_random(16);

			return publicKey;
		}

		string generatePrivateKey() {
			string privateKey;

			privateKey = gen_random(32);

			return privateKey;
		}

		string generateName() {
			string name;

			name = gen_randomForName(8);

			return name;
		}

		void setPrivateKey(string input) { privateKey = input; }
		void setPublicKey(string input) { publicKey = input; }
		void setName(string input) { name = input; }
		void createBalance(double balance) { balance = fabs(rand() % 1000); }
	private:
		string publicKey = "";
		string name = "";
		string privateKey="";
		string getPrivateKey() { return privateKey; }
		double balance = 0;
	public:
		user() {
			setPrivateKey(generatePrivateKey());
			setPublicKey(generatePublicKey());
			setName(generateName());
			createBalance(balance);
		}
		double setBalance(double amountTraded) {
            this->balance = this->balance - amountTraded;
            return this->balance;
		}
		double getBalance(){
		    return balance;
        }
		string getPublicKey() {
			return publicKey;
		};
		string getName() {
			return name;
		}
};

class transaction{
 private:
     string timestamp;
     user user1;
     user user2;
     double amountTraded;
 public:
     user setUser1(user user){
        this->user1 = user;
        return this->user1;
     }
     user setUser2 (user user){
        this->user2 = user;
        return this->user2;
     }
     double setAmountTraded(double amount){
        this->amountTraded = amount;
        return this->amountTraded;
     }
     string getUser1PubKey() {return this->user1.getPublicKey(); }
     string getUser2PubKey() {return this->user2.getPublicKey(); }
     string getTimestamp() {return this->timestamp;}
     double getAmountTraded() {return this->amountTraded;}

    void performTransaction(double amountTraded){
        user1.setBalance(this->amountTraded);
        user2.setBalance(-(this->amountTraded));
        time_t now = time(0);
        this->timestamp = ctime(&now);
    }
};

vector<user> generateUsers() {
	vector<user> generatedUsers;
	generatedUsers.resize(1000);
	return generatedUsers;
}
