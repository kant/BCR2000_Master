/*
   Copyright (c) 2019 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "JuceHeader.h"

#include "BCLEditor.h"
#include "BCR2000.h"
#include "LogView.h"

class LogViewLogger;

class MainComponent   : public Component
{
public:
    MainComponent();
    ~MainComponent();

    void resized() override;

private:
	std::shared_ptr<midikraft::BCR2000> bcr_;
	BCLEditor editor_;
	LogView logView_;
	std::unique_ptr<LogViewLogger> logger_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
