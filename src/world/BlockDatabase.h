#pragma once
#include <string>

class BlockDatabase {
public:
	BlockDatabase();
	static BlockDatabase& getInstance();
	~BlockDatabase();

	// Prevent copy and assignment
	BlockDatabase(const BlockDatabase&) = delete;
	BlockDatabase& operator=(const BlockDatabase&) = delete;
	// Add methods to manage blocks
	const 
	void addBlock(int id, const std::string& name);
	std::string getBlockName(int id) const;
	bool blockExists(int id) const;
private:

};
