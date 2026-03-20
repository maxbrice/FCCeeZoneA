#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogDigitalTwinTools, All, All);

class FDigitalTwinToolsModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void AddMenu(FMenuBarBuilder& MenuBarBuilder);
	void FillMenu(FMenuBuilder& MenuBuilder);
};
