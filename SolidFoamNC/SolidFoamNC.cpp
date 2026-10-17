// SolidFoamNC.cpp: определяет процедуры инициализации для библиотеки DLL.
//

#include "pch.h"

#include <QApplication>

#include "SolidFoamNC.h"
#include "SolverDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CSolidFoamNCApp, CWinApp)
END_MESSAGE_MAP()


void ShowSolverUI() {
	int argc = 0;
	char* argv[] = { nullptr };
	QApplication* app = (QApplication*)qApp;
	bool isAppCreatedHere = false;

	if (!app) {
		app = new QApplication(argc, argv);
		isAppCreatedHere = true;
	}

	QWidget* mainWindow = nullptr;
	if (app) {
		for (QWidget* widget : app->topLevelWidgets()) {
			if (widget->inherits("QMainWindow")) {
				mainWindow = widget;
				break;
			}
		}
	}

	SolverDialog dlg(mainWindow);

	dlg.setWindowFlags(dlg.windowFlags() | Qt::Tool | Qt::WindowStaysOnTopHint);

	if (dlg.exec() == QDialog::Accepted) {
		acutPrintf(_T("\nЗапуск подготовки данных для OpenFOAM...\n"));
	}

	if (isAppCreatedHere) {
		delete app;
	}
}

void InitApp()
{
	acedRegCmds->addCommand(L"SOLIDFOAMNC_GROUP",
		L"_SOLIDFOAMNC",
		L"SOLIDFOAMNC",
		ACRX_CMD_TRANSPARENT,
		ShowSolverUI);
}

void UnInitApp()
{
	acedRegCmds->removeGroup(L"SOLIDFOAMNC_GROUP");
}

extern "C" _declspec(dllexport) AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* appId)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(appId);
		acrxDynamicLinker->registerAppMDIAware(appId);
		InitApp();
		break;

	case AcRx::kUnloadAppMsg:
		UnInitApp();
		break;
	}

	return AcRx::kRetOK;
}


// Создание CSolidFoamNCApp

CSolidFoamNCApp::CSolidFoamNCApp()
{
	// TODO: добавьте код создания,
	// Размещает весь важный код инициализации в InitInstance
}


// Единственный объект CSolidFoamNCApp

CSolidFoamNCApp theApp;


// Инициализация CSolidFoamNCApp

BOOL CSolidFoamNCApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}