#include "TodStringFile.h"
#include "SexyAppBase.h"
#include "PakInterface.h"

using namespace PVZMod;

bool PVZMod::TodStringListReadItems(const SexyChar* theFileText)
{
	int func = 0x51d2e0;
	bool result;
	__asm
	{
		push theFileText
		call func
		mov result, al
	}
	return result;
}

bool PVZMod::TodStringListReadFile(const char* theFileName)
{
	PFILE* pFile = p_fopen(theFileName, "rb");
	if (pFile == nullptr)
	{
		//TodTrace("Failed to open '%s'", theFileName);
		return false;
	}

	p_fseek(pFile, 0, SEEK_END);  // ָ��������ļ�ĩβ
	size_t aSize = p_ftell(pFile) / sizeof(SexyChar);  // ��ǰλ�ü�Ϊ�ļ�����
	p_fseek(pFile, 0, SEEK_SET);  // ָ������ļ���ͷ
	SexyChar* aFileText = new SexyChar[aSize + 1];
	bool aSuccess = true;
	if (p_fread(aFileText, sizeof(SexyChar), aSize, pFile) <= 0)  // ���ֽڶ�ȡ����
	{
		//TodTrace("Failed to read '%s'", theFileName);
		aSuccess = false;
	}
	aFileText[aSize] = '\0';
	if (aSuccess)
	{
		aSuccess = TodStringListReadItems(aFileText);
	}
	p_fclose(pFile);  // �ر��ļ���
	delete[] aFileText;

	return aSuccess;
}

void PVZMod::TodStringListLoad(const char* theFileName)
{
	if (!TodStringListReadFile(theFileName))
		MessageBoxA((gSexyAppBase && gSexyAppBase->mHWnd) ? gSexyAppBase->mHWnd : GetActiveWindow(), StrFormat("Failed to load string list file '%s'", theFileName).c_str(), "Error", MB_ICONEXCLAMATION);
}

SexyString PVZMod::TodStringListFind(const SexyString& theName)
{
	String aNameString = SexyStringToString(theName);
	StringWStringMap::iterator anItr = gSexyAppBase->mStringProperties.find(aNameString);
	if (anItr != gSexyAppBase->mStringProperties.end())
	{
		return WStringToSexyString(anItr->second);
	}
	else
	{
		return StrFormat(_S("<Missing %s>"), theName.c_str());
	}
}

SexyString PVZMod::TodStringTranslate(const SexyString& theString)
{
	if (theString.size() >= 3 && theString[0] == '[')
	{
		SexyString aName = theString.substr(1, theString.size() - 2);  // ȡ��[���롰]���м�Ĳ���
		return TodStringListFind(aName);
	}
	return theString;
}

SexyString PVZMod::TodStringTranslate(const SexyChar* theString)
{
	if (theString != nullptr)
	{
		int aLen = sexystrlen(theString);
		if (aLen >= 3 && theString[0] == _S('['))
		{
			SexyString aName(theString, 1, aLen - 2);  // ȡ��[���롰]���м�Ĳ���
			return TodStringListFind(aName);
		}
		else
			return theString;
	}
	else
		return _S("");
}

bool PVZMod::TodStringListExists(const SexyString& theString)
{
	if (theString.size() >= 3 && theString[0] == _S('['))
	{
		SexyString aName = theString.substr(1, theString.size() - 2);  // ȡ��[���롰]���м�Ĳ���
		return gSexyAppBase->mStringProperties.find(SexyStringToString(aName)) != gSexyAppBase->mStringProperties.end();
	}
	return false;
}
