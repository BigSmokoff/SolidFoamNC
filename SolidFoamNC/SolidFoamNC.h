// SolidFoamNC.h: основной файл заголовка для библиотеки DLL SolidFoamNC
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#ifndef ReportNotImplementedAPI
#define ReportNotImplementedAPI(...) 
#endif

#include "resource.h"		// основные символы
#include "arxHeaders.h"
#include "AcExtensionModule.h"

// CSolidFoamNCApp
// Реализацию этого класса см. в файле SolidFoamNC.cpp
//

class CSolidFoamNCApp : public CWinApp
{
public:
	CSolidFoamNCApp();

// Переопределение
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
