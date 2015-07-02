#include "FramePreprocessor.h"
#include "ApplicationState.h"

FramePreprocessor::FramePreprocessor()
{
	
}


FramePreprocessor::~FramePreprocessor()
{

}

void FramePreprocessor::moduleInit(ApplicationState &appState)
{
	//
}

void FramePreprocessor::moduleDeinit()
{
	//
}

bool FramePreprocessor::moduleProcess(ApplicationState &appState)
{
	if (appState.frameSrc.empty())
		return false;

	cvtColor(appState.frameSrc, appState.frameGray, COLOR_BGR2GRAY);
	


	
	GaussianBlur(appState.frameGray, appState.frameGray, Size(5, 5), 3, 3);
	GaussianBlur(appState.frameGray, appState.frameGray, Size(5, 5), 3, 3);
	GaussianBlur(appState.frameGray, appState.frameGray, Size(5, 5), 3, 3);
	//equalizeHist(appState.frameGray, appState.frameGray);

	return true;
}
