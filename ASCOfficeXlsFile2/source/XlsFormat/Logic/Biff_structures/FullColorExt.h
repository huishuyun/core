#pragma once

#include "BiffStructure.h"

namespace XLS
{;

class CFRecord;

class FullColorExt : public BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(FullColorExt)
public:
	BiffStructurePtr clone();

	//virtual void toXML(BiffStructurePtr & parent);
	//virtual const bool fromXML(BiffStructurePtr & parent);
	virtual void load(CFRecord& record);
	virtual void store(CFRecord& record);

private:
	unsigned __int16 xclrType;
	short nTintShade;
	unsigned int xclrValue;
};

} // namespace XLS
