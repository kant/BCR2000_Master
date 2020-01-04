/*
   Copyright (c) 2019 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#include "MainComponent.h"

#include "Logger.h"

class LogViewLogger : public SimpleLogger {
public:
	LogViewLogger(LogView &logview) : logview_(logview) {}


	virtual void postMessage(const String& message) override
	{
		logview_.addMessageToList(message);
	}

private:
	LogView &logview_;
};

//==============================================================================
MainComponent::MainComponent() : bcr_(std::make_shared<midikraft::BCR2000>()), editor_(bcr_)
{
	logger_ = std::make_unique<LogViewLogger>(logView_);
	addAndMakeVisible(editor_);	
	addAndMakeVisible(logView_);

    // Make sure you set the size of the component after
    // you add any child components.
    setSize (1280, 800);
}

MainComponent::~MainComponent()
{
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
	auto area = getLocalBounds();	
	logView_.setBounds(area.removeFromBottom(200).reduced(10));
	editor_.setBounds(area.reduced(10));
}
