#pragma once
#include "SharedEnums.h"
#include "GeneralHeaders.h"
#include "Objects.h"

class Tile;
class ArmorObject : public ObjectClass
{
public:
	ArmorObject();
	ArmorObject(const ArmorObject &Other);
	ArmorObject(ObjectClass &Other);

	void SetBodySlot(BodyLocation location) { BodySlot = location; }
	BodyLocation GetBodySlot() { return this->BodySlot; }

	const int GetArmorBonus();
	void SetArmorBonus(int bonus);

	int GetDamageReduction();
	void SetDamageReduction(int reduction);

	int GetMaxDexBonus();
	void SetMaxDex(int max);

	int GetArmorCheckPenalty();
	void SetArmorCheckPen(int penalty);

	int GetSpeedReduction();
	void SetSpeedReduction(int SpeedReduction);

	int GetEquipActions();
	void SetEquipActions(int actions);

	bool GetIsShield();
	void SetIsShield(bool isShield);

	std::vector<ArmorType> GetArmorTypes();
	void AddArmorType(ArmorType added);

	void DisplayArmorInfo();
	
	std::string GetName() { return ObjectName; }
	void SetName(std::string name) { ObjectName = name; }

	std::pair<int, int> GetLocation(){return mLocation;}

private:
	int ArmorBonus=0;
	int DamageReduction=0;
	int MaxDexBonus=0;
	int ArmorCheckPenalty=0;
	int SpeedReduction=0;
	int EquipActions=0;
	bool IsShield = false;

	//not loaded into master list
	
	std::vector<ArmorType> ArmorTypes = {};
	std::vector<WeaponType> WeaponTypes = { IMPROVISED };
	std::vector<DamageType> DamageTypes = {BLUNT};

	std::pair<int, DiceType> DamageDice = { 1, D4 };
	//inherited values
	SDL_Rect mBox = { 0,0,70,70 };
	std::string mPathTexture = "Armor1.png";
	LTexture* mTexture;
	std::pair<int, int> mLocation = { 0,0 };

	//The dimensions of the Entity
	int OBJECT_WIDTH = 70;
	int OBJECT_HEIGHT = 70;

	//Model information
	std::string ObjectName = "";
	std::string ObjectDescription = "";

	float Weight = 0.0; //how much does the item weigh? Unimportant save for carrying capacity and determining 2h for improvised weapons

	bool TwoHanded; //does it have to take up both hand slots?
	bool Versatile; //can it be weilded in 2 hands? (example, longsword)

	int RangeIncrement = 0;
	BodyLocation BodySlot = BODY; //indicates where this item can be used (manhand and offhand are interchangable)

	int CritMultiplier = 2;
	int CritThreat = 20;

public:
	//rendering functions
	LTexture * GetTexture() { return mTexture; }
	void SetPathTexture(std::string path) { mPathTexture = path; }
	std::string GetPathTexture() { return mPathTexture; }
	void SetTexture(std::map<std::string, LTexture*> TextureMap, std::string Path);

	void SetLocation(int x, int y, std::vector < std::vector < Tile> > &TileMap);
	//sets where the entity will render
	void SetRendLocation(std::vector<std::vector<Tile>> &TileVector);
	//calculates the middle of the tile the entity will render at
	std::pair<int, int> CalcRendLocation(std::vector<std::vector<Tile>> &Map);

	void render(SDL_Rect& camera, SDL_Renderer *& Renderer);



};