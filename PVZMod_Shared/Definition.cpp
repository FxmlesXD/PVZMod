#include "Definition.h"
#include <cassert>
#include <cstdint>
#include <cstring>
#include <cstdlib>

using namespace PVZMod;

void TodAllocator::Initialize(int theGrowCount, int theItemSize)
{
	assert(theItemSize >= sizeof(void*));

	mFreeList = nullptr;
	mBlockList = nullptr;
	mGrowCount = theGrowCount;
	mTotalItems = 0;
	mItemSize = theItemSize;
}

void TodAllocator::Dispose()
{
	FreeAll();
}

void TodAllocator::Grow()
{
	assert(mGrowCount > 0);
	assert(mItemSize >= sizeof(void*));

	void* aBlock = malloc(mGrowCount * mItemSize + 4);
	*(void**)aBlock = mBlockList;
	mBlockList = aBlock;

	void* aFreeList = mFreeList;
	void* aItem = (void*)((uint32_t)aBlock + 4);
	for (int i = 0; i < mGrowCount; i++)
	{
		*(void**)aItem = aFreeList;
		aFreeList = aItem;
		aItem = (void*)((uint32_t)aItem + mItemSize);
	}
	mFreeList = aFreeList;
}

bool TodAllocator::IsPointerFromAllocator(void* theItem)
{
	size_t aBlockSize = mGrowCount * mItemSize;  // ÿ�Ρ�Grow�����ڴ��С����ÿ��������ڴ��С
	for (void* aPtr = mBlockList; aPtr != nullptr; aPtr = *(void**)aPtr)
	{
		uint32_t aItemPtr = (uint32_t)theItem;
		// ������׸����ֽ�Ϊ��������ġ����ڴ洢ָ����һ�����ָ�������
		uint32_t aBlockPtr = (uint32_t)aPtr + sizeof(void*);
		// �ж� theItem �Ƿ�λ�ڵ�ǰ��������ָ��ĳһ����������ʼ��ַ
		if (aItemPtr >= aBlockPtr && aItemPtr < aBlockPtr + aBlockSize && (aItemPtr - aBlockPtr) % mItemSize == 0)
			return true;
	}
	return false;
}

bool TodAllocator::IsPointerOnFreeList(void* theItem)
{
	for (void* aPtr = mFreeList; aPtr != nullptr; aPtr = *(void**)aPtr)
		if (theItem == aPtr)
			return true;
	return false;
}

void* TodAllocator::Alloc(int theItemSize)
{
	mTotalItems++;
	if (mFreeList == nullptr)
		Grow();

	void* anItem = (void*)mFreeList;
	mFreeList = *(void**)anItem;
	return anItem;
}

void* TodAllocator::Calloc(int theItemSize)
{
	void* anItem = Alloc(theItemSize);
	memset(anItem, 0, theItemSize);
	return anItem;
}

void TodAllocator::Free(void* theItem, int theItemSize)
{
	mTotalItems--;
	assert(IsPointerFromAllocator(theItem));
	assert(!IsPointerOnFreeList(theItem));
	*(void**)theItem = mFreeList;  // ��ԭ��������ͷ���� [*theItem] ��
	mFreeList = theItem;  // �� theItem ��Ϊ�µĿ�������ͷ
}

void TodAllocator::FreeAll()
{
	for (void* aBlock = mBlockList; aBlock != nullptr; )
	{
		void* aNext = *(void**)aBlock;
		free(aBlock);
		aBlock = aNext;
	}

	mBlockList = nullptr;
	mFreeList = nullptr;
	mTotalItems = 0;
}
