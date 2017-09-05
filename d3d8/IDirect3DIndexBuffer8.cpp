/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "d3d8.h"

HRESULT m_IDirect3DIndexBuffer8::QueryInterface(THIS_ REFIID riid, void** ppvObj)
{
	return m_pD3DIBuffer8->QueryInterface(riid, ppvObj);
}

ULONG m_IDirect3DIndexBuffer8::AddRef(THIS)
{
	return m_pD3DIBuffer8->AddRef();
}

ULONG m_IDirect3DIndexBuffer8::Release(THIS)
{
	ULONG count = m_pD3DIBuffer8->Release();

	if (count == 0)
	{
		RemoveWrapper(m_pD3DIBuffer8);
		delete this;
	}

	return count;
}

HRESULT m_IDirect3DIndexBuffer8::GetDevice(THIS_ IDirect3DDevice8** ppDevice)
{
	HRESULT hr = m_pD3DIBuffer8->GetDevice(ppDevice);

	if (SUCCEEDED(hr))
	{
		*ppDevice = GetOrCreateWrapperT(IDirect3DDevice8, *ppDevice);
	}

	return hr;
}

HRESULT m_IDirect3DIndexBuffer8::SetPrivateData(THIS_ REFGUID refguid, CONST void* pData, DWORD SizeOfData, DWORD Flags)
{
	return m_pD3DIBuffer8->SetPrivateData(refguid, pData, SizeOfData, Flags);
}

HRESULT m_IDirect3DIndexBuffer8::GetPrivateData(THIS_ REFGUID refguid, void* pData, DWORD* pSizeOfData)
{
	return m_pD3DIBuffer8->GetPrivateData(refguid, pData, pSizeOfData);
}

HRESULT m_IDirect3DIndexBuffer8::FreePrivateData(THIS_ REFGUID refguid)
{
	return m_pD3DIBuffer8->FreePrivateData(refguid);
}

DWORD m_IDirect3DIndexBuffer8::SetPriority(THIS_ DWORD PriorityNew)
{
	return m_pD3DIBuffer8->SetPriority(PriorityNew);
}

DWORD m_IDirect3DIndexBuffer8::GetPriority(THIS)
{
	return m_pD3DIBuffer8->GetPriority();
}

void m_IDirect3DIndexBuffer8::PreLoad(THIS)
{
	return m_pD3DIBuffer8->PreLoad();
}

D3DRESOURCETYPE m_IDirect3DIndexBuffer8::GetType(THIS)
{
	return m_pD3DIBuffer8->GetType();
}

HRESULT m_IDirect3DIndexBuffer8::Lock(THIS_ UINT OffsetToLock, UINT SizeToLock, BYTE** ppbData, DWORD Flags)
{
	return m_pD3DIBuffer8->Lock(OffsetToLock, SizeToLock, ppbData, Flags);
}

HRESULT m_IDirect3DIndexBuffer8::Unlock(THIS)
{
	return m_pD3DIBuffer8->Unlock();
}

HRESULT m_IDirect3DIndexBuffer8::GetDesc(THIS_ D3DINDEXBUFFER_DESC *pDesc)
{
	return m_pD3DIBuffer8->GetDesc(pDesc);
}
