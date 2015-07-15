#pragma once

#include "OfficeArtRecord.h"
#include <Binary/CFRecord.h>
#include "OfficeArtRecordHeader.h"
#include "OfficeArtBlip.h"


namespace XLS
{
	class CFRecord;
}

namespace ODRAW
{;

class OfficeArtBStoreContainerFileBlock : public XLS::BiffStructure
{
	BASE_STRUCTURE_DEFINE_CLASS_NAME(OfficeArtBStoreContainerFileBlock)
public:
	XLS::BiffStructurePtr clone();

	OfficeArtBStoreContainerFileBlock()
	{
		data_size = 0;
		pict_data = NULL;
		pict_type = L"jpeg";
		rgbUid1 = L"";
		rgbUid2 = L"";
		result = false;
	}

	~OfficeArtBStoreContainerFileBlock()
	{
		if (pict_data)
		{
			delete[] pict_data;
			pict_data = NULL;
		}
	}

	//virtual void setXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	//virtual void getXMLAttributes(MSXML2::IXMLDOMElementPtr xml_tag);
	virtual void load(XLS::CFRecord& record);
	virtual void store(XLS::CFRecord& record);

	void readCompressedData(XLS::CFRecord& record, OfficeArtMetafileHeader metafileHeader);

private:
	const std::wstring ReadMD4Digest(XLS::CFRecord& record)
	{
		std::wstring result;
		for(int i = 0; i < 16; i++)
		{
			unsigned char hex_data;
			record >> hex_data;
			result += STR::int2hex_wstr(hex_data, sizeof(hex_data));
		}
		return result;
	}

private:
	int bin_data_id;

	size_t data_size;
	char* pict_data;
	std::wstring  pict_type;

public:
	size_t recType;	
	std::wstring rgbUid1;
	std::wstring rgbUid2;
	bool result;
};

typedef boost::shared_ptr<OfficeArtBStoreContainerFileBlock> OfficeArtBStoreContainerFileBlockPtr;


} // namespace XLS
