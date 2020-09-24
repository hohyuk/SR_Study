#pragma once

namespace Engine
{
#define USING(NAMESPACE)		using namespace NAMESPACE;

#define			BEGIN(NAMESPACE)		namespace NAMESPACE {
#define			END						}


#ifdef ENGINE_EXPORTS
#define ENGINE_DLL _declspec(dllexport)
#else
#define ENGINE_DLL _declspec(dllimport)
#endif // ENGINE_EXPORTS

}