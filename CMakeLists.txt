cmake_minimum_required(VERSION 3.1)

# top-level cmake file will have this line.
project(HappyFarm VERSION 1.0 DESCRIPTION "Happy Farm" LANGUAGES CXX)

add_executable(farm 
src/ConsoleBlock.cpp          src/DialogUnitLog.cpp    src/FarmPackBuilderNew.cpp
src/ConsoleBlockBackpack.cpp  src/DialogUnitMenu.cpp   src/FarmTool.cpp
src/ConsoleBlockDesc.cpp      src/DialogUnitPause.cpp  src/FarmToolbox.cpp
src/ConsoleBlockField.cpp     src/DialogUnitShop.cpp   src/FarmToolHarvest.cpp
src/ConsoleBlockFolder.cpp    src/DialogUnitTime.cpp   src/FarmToolPesticide.cpp
src/ConsoleBlockLog.cpp       src/DisplayManager.cpp   src/FarmToolPlant.cpp
src/ConsoleBlockMenu.cpp      src/DrawCommand.cpp      src/FarmToolWater.cpp
src/ConsoleBlockPause.cpp     src/EventManager.cpp     src/FarmYard.cpp
src/ConsoleBlockShop.cpp      src/Farm.cpp             src/GameDriver.cpp
src/ConsoleList.cpp           src/FarmBuilder.cpp      src/GameDriverSingleton.cpp
src/ConsoleListA.cpp          src/FarmBuilderLoad.cpp  src/InputCommand.cpp
src/ConsoleTextArea.cpp       src/FarmBuilderNew.cpp   src/InputManager.cpp
src/CursorControl.cpp         src/FarmClock.cpp        src/MenuOption.cpp
src/DeleteCallback.cpp        src/FarmCommand.cpp      src/PlantFactory.cpp
src/DescriptionMaker.cpp      src/FarmField.cpp        src/PlantLive.cpp
src/DialogManager.cpp         src/FarmItem.cpp         src/PlantSpecies.cpp
src/DialogUnit.cpp            src/FarmItemSeed.cpp     src/PlantSpeciesStrategyClasses.cpp
src/DialogUnitBackpack.cpp    src/FarmManager.cpp      src/PlantState.cpp
src/DialogUnitDesc.cpp        src/FarmPack.cpp
src/DialogUnitField.cpp       src/FarmPackBuilder.cpp
)

target_include_directories(farm PUBLIC include)

