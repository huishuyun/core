#pragma once

#include "BiffRecordContinued.h"
#include <Logic/Biff_structures/CellRangeRef.h>
#include <Logic/Biff_structures/SortCond12.h>

namespace XLS
{


// Logical representation of SortData record in BIFF8
class SortData: public BiffRecordContinued
{
	BIFF_RECORD_DEFINE_TYPE_INFO(SortData)
	BASE_OBJECT_DEFINE_CLASS_NAME(SortData)
public:
	SortData();
	~SortData();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);

	static const ElementType	type = typeSortData;

	bool			fCol;
	bool			fCaseSensitive;
	bool			fAltMethod;
	unsigned char	sfp;

	BIFF_DWORD		cconditions;
	BIFF_DWORD		idParent;

	BiffStructurePtrVector sortCond12Array;

//-----------------------------
	std::wstring	rfx;
};

} // namespace XLS

