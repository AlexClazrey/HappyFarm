objects = ConsoleBlockBackpack.o ConsoleBlockDesc.o ConsoleBlockField.o ConsoleBlockFolder.o ConsoleBlockLog.o ConsoleBlockMenu.o ConsoleBlock.o ConsoleBlockPause.o ConsoleBlockShop.o ConsoleListA.o ConsoleList.o ConsoleTextArea.o CursorControl.o DeleteCallback.o DescriptionMaker.o DialogManager.o DialogUnitBackpack.o DialogUnitDesc.o DialogUnitField.o DialogUnitLog.o DialogUnitMenu.o DialogUnit.o DialogUnitPause.o DialogUnitShop.o DialogUnitTime.o DisplayManager.o DrawCommand.o EventManager.o FarmBuilderLoad.o FarmBuilderNew.o FarmBuilder.o FarmClock.o FarmCommand.o FarmField.o FarmItem.o FarmItemSeed.o FarmManager.o Farm.o FarmPackBuilderNew.o FarmPackBuilder.o FarmPack.o FarmToolbox.o FarmToolHarvest.o FarmTool.o FarmToolPesticide.o FarmToolPlant.o FarmToolWater.o FarmYard.o GameDriver.o GameDriverSingleton.o InputCommand.o InputManager.o main.o MenuOption.o PlantFactory.o PlantLive.o PlantSpecies.o PlantSpeciesStrategyClasses.o PlantState.o 
cc = g++
cxxflags = -std=c++11 -O -Wall
head = -I ./include

all: $(objects)
	$(cc) -o test *.o -lpanel -lncurses

clean: 
	rm -f $(objects)
	rm -f test

ConsoleBlockBackpack.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockBackpack.cpp
ConsoleBlockDesc.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockDesc.cpp
ConsoleBlockField.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockField.cpp
ConsoleBlockFolder.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockFolder.cpp
ConsoleBlockLog.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockLog.cpp
ConsoleBlockMenu.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockMenu.cpp
ConsoleBlock.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlock.cpp
ConsoleBlockPause.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockPause.cpp
ConsoleBlockShop.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleBlockShop.cpp
ConsoleListA.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleListA.cpp
ConsoleList.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleList.cpp
ConsoleTextArea.o:
	$(cc) $(cxxflags) $(head) -c src/ConsoleTextArea.cpp
CursorControl.o:
	$(cc) $(cxxflags) $(head) -c src/CursorControl.cpp
DeleteCallback.o:
	$(cc) $(cxxflags) $(head) -c src/DeleteCallback.cpp
DescriptionMaker.o:
	$(cc) $(cxxflags) $(head) -c src/DescriptionMaker.cpp
DialogManager.o:
	$(cc) $(cxxflags) $(head) -c src/DialogManager.cpp
DialogUnitBackpack.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitBackpack.cpp
DialogUnitDesc.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitDesc.cpp
DialogUnitField.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitField.cpp
DialogUnitLog.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitLog.cpp
DialogUnitMenu.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitMenu.cpp
DialogUnit.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnit.cpp
DialogUnitPause.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitPause.cpp
DialogUnitShop.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitShop.cpp
DialogUnitTime.o:
	$(cc) $(cxxflags) $(head) -c src/DialogUnitTime.cpp
DisplayManager.o:
	$(cc) $(cxxflags) $(head) -c src/DisplayManager.cpp
DrawCommand.o:
	$(cc) $(cxxflags) $(head) -c src/DrawCommand.cpp
EventManager.o:
	$(cc) $(cxxflags) $(head) -c src/EventManager.cpp
FarmBuilderLoad.o:
	$(cc) $(cxxflags) $(head) -c src/FarmBuilderLoad.cpp
FarmBuilderNew.o:
	$(cc) $(cxxflags) $(head) -c src/FarmBuilderNew.cpp
FarmBuilder.o:
	$(cc) $(cxxflags) $(head) -c src/FarmBuilder.cpp
FarmClock.o:
	$(cc) $(cxxflags) $(head) -c src/FarmClock.cpp
FarmCommand.o:
	$(cc) $(cxxflags) $(head) -c src/FarmCommand.cpp
FarmField.o:
	$(cc) $(cxxflags) $(head) -c src/FarmField.cpp
FarmItem.o:
	$(cc) $(cxxflags) $(head) -c src/FarmItem.cpp
FarmItemSeed.o:
	$(cc) $(cxxflags) $(head) -c src/FarmItemSeed.cpp
FarmManager.o:
	$(cc) $(cxxflags) $(head) -c src/FarmManager.cpp
Farm.o:
	$(cc) $(cxxflags) $(head) -c src/Farm.cpp
FarmPackBuilderNew.o:
	$(cc) $(cxxflags) $(head) -c src/FarmPackBuilderNew.cpp
FarmPackBuilder.o:
	$(cc) $(cxxflags) $(head) -c src/FarmPackBuilder.cpp
FarmPack.o:
	$(cc) $(cxxflags) $(head) -c src/FarmPack.cpp
FarmToolbox.o:
	$(cc) $(cxxflags) $(head) -c src/FarmToolbox.cpp
FarmToolHarvest.o:
	$(cc) $(cxxflags) $(head) -c src/FarmToolHarvest.cpp
FarmTool.o:
	$(cc) $(cxxflags) $(head) -c src/FarmTool.cpp
FarmToolPesticide.o:
	$(cc) $(cxxflags) $(head) -c src/FarmToolPesticide.cpp
FarmToolPlant.o:
	$(cc) $(cxxflags) $(head) -c src/FarmToolPlant.cpp
FarmToolWater.o:
	$(cc) $(cxxflags) $(head) -c src/FarmToolWater.cpp
FarmYard.o:
	$(cc) $(cxxflags) $(head) -c src/FarmYard.cpp
GameDriver.o:
	$(cc) $(cxxflags) $(head) -c src/GameDriver.cpp
GameDriverSingleton.o:
	$(cc) $(cxxflags) $(head) -c src/GameDriverSingleton.cpp
InputCommand.o:
	$(cc) $(cxxflags) $(head) -c src/InputCommand.cpp
InputManager.o:
	$(cc) $(cxxflags) $(head) -c src/InputManager.cpp
main.o:
	$(cc) $(cxxflags) $(head) -c main.cpp
MenuOption.o:
	$(cc) $(cxxflags) $(head) -c src/MenuOption.cpp
PlantFactory.o:
	$(cc) $(cxxflags) $(head) -c src/PlantFactory.cpp
PlantLive.o:
	$(cc) $(cxxflags) $(head) -c src/PlantLive.cpp
PlantSpecies.o:
	$(cc) $(cxxflags) $(head) -c src/PlantSpecies.cpp
PlantSpeciesStrategyClasses.o:
	$(cc) $(cxxflags) $(head) -c src/PlantSpeciesStrategyClasses.cpp
PlantState.o:
	$(cc) $(cxxflags) $(head) -c src/PlantState.cpp
