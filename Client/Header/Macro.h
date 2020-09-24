#pragma once

namespace Client
{
	constexpr int WINCX{ 800 };
	constexpr int WINCY{ 600 };

#define			BEGIN(NAMESPACE)		namespace NAMESPACE {
#define			END						}

#ifndef MSG_BOX
#define	MSG_BOX(_message)			MessageBox(NULL, TEXT(_message), L"System Message", MB_OK)
#endif
}