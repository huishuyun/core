#pragma once

#include "OperandPtg.h"

namespace XLS
{;

class CFRecord;

class PtgInt: public OperandPtg
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(PtgInt)
public:
	PtgInt();
	PtgInt(const std::wstring& word);
	BiffStructurePtr clone();

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void loadFields(CFRecord& record);
	virtual void storeFields(CFRecord& record);

	virtual void assemble(AssemblerStack& ptg_stack, PtgQueue& extra_data, BiffStructurePtr & parent);

	static const unsigned __int16 fixed_id = 0x1E;

private:
	unsigned __int16 integer;
};

} // namespace XLS

