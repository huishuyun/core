#pragma once

#include "BiffRecord.h"

namespace XLS
{;


// Logical representation of Fbi2 record in BIFF8
class Fbi2: public BiffRecord
{
	BIFF_RECORD_DEFINE_TYPE_INFO(Fbi2)
	BASE_OBJECT_DEFINE_CLASS_NAME(Fbi2)
public:
	Fbi2();
	~Fbi2();

	BaseObjectPtr clone();

	void writeFields(CFRecord& record);
	void readFields(CFRecord& record);
//-----------------------------
//	BIFF_WORD userName;
public:
	//BO_ATTRIB_MARKUP_BEGIN
//		//BO_ATTRIB_MARKUP_ATTRIB(userName)
	//BO_ATTRIB_MARKUP_END

};

} // namespace XLS

