



enum class BlockID
{
	Air = 0,
	Grass = 1,
	Dirt = 2,
	Stone = 3,
	Sand = 4,
	Oak_Wood = 5,
	Oak_Leaf = 6,
	Water = 7,
	Rose = 8,
	Tall_Grass = 9,

	NUM_BlockTypeS
};
inline const char* toString(BlockID blockID) {
	switch (blockID) {
	case BlockID::Air: return "Air";
	case BlockID::Grass: return "Grass";
	case BlockID::Dirt: return "Dirt";
	case BlockID::Stone: return "Stone";
	case BlockID::Sand: return "Sand";
	case BlockID::Oak_Wood: return "Oak Wood";
	case BlockID::Oak_Leaf: return "Oak Leaf";
	case BlockID::Water: return "Water";
	case BlockID::Rose: return "Rose";
	case BlockID::Tall_Grass: return "Tall Grass";
	default: return "Unknown Block ID";
	}
}