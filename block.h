#pragma once
#include "User.h"
#include "sha256.cpp"
#include <iostream>
#include <cmath>

using namespace std;

class transactionList {
private:
	int amountTraded;
	user user;
protected:

public:
	transactionList() {

	}

	void getTransactions() {

	}
};

class block {
	private:
	transactionList list;
	string blockHash;
	string prevBlockHash;
	string timeStamp;
	int nonce;
	int version;
	int difficultyTarget;

	protected:
	string prevBlockHash(block block) {
		this->prevBlockHash = block.getBlockHash();
	}

	public:
	block() {
		nonce = fabs(rand());
		blockHash = sha256(to_string(nonce));
		time_t now = time(0);
		timeStamp = ctime(&now);
		version = 0.1;
		difficultyTarget = 0;
	}
	string getPrevBlockHash() {
		return prevBlockHash;
	}
	string getBlockHash() {
		return blockHash;
	}
	string getTimeStamp() {
		return timeStamp;
	}
	int getVersion() {
		return version;
	}

};

block genesis;