##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Inheritance
ConfigurationName      :=Debug
WorkspacePath          :=E:/Codelite/CPPWorkspace
ProjectPath            :=E:/Codelite/CPPWorkspace/Inheritance
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ishan
Date                   :=17/12/2021
CodeLitePath           :=D:/CodeLite
LinkerName             :="C:/Program Files/mingw-w64/mingw64/bin/g++.exe"
SharedObjectLinkerName :="C:/Program Files/mingw-w64/mingw64/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Inheritance.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="C:/Program Files/mingw-w64/mingw64/bin/windres.exe"
LinkOptions            :=  -static
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := "C:/Program Files/mingw-w64/mingw64/bin/ar.exe" rcu
CXX      := "C:/Program Files/mingw-w64/mingw64/bin/g++.exe"
CC       := "C:/Program Files/mingw-w64/mingw64/bin/gcc.exe"
CXXFLAGS :=  -g -O0 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := "C:/Program Files/mingw-w64/mingw64/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=D:\CodeLite
Objects0=$(IntermediateDirectory)/Account.cpp$(ObjectSuffix) $(IntermediateDirectory)/Savings_account.cpp$(ObjectSuffix) $(IntermediateDirectory)/Checking_account.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Trust_account.cpp$(ObjectSuffix) $(IntermediateDirectory)/Default_functions.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Account.cpp$(ObjectSuffix): Account.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Account.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Account.cpp$(DependSuffix) -MM Account.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/CPPWorkspace/Inheritance/Account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Account.cpp$(PreprocessSuffix): Account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Account.cpp$(PreprocessSuffix) Account.cpp

$(IntermediateDirectory)/Savings_account.cpp$(ObjectSuffix): Savings_account.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Savings_account.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Savings_account.cpp$(DependSuffix) -MM Savings_account.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/CPPWorkspace/Inheritance/Savings_account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Savings_account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Savings_account.cpp$(PreprocessSuffix): Savings_account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Savings_account.cpp$(PreprocessSuffix) Savings_account.cpp

$(IntermediateDirectory)/Checking_account.cpp$(ObjectSuffix): Checking_account.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Checking_account.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Checking_account.cpp$(DependSuffix) -MM Checking_account.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/CPPWorkspace/Inheritance/Checking_account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Checking_account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Checking_account.cpp$(PreprocessSuffix): Checking_account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Checking_account.cpp$(PreprocessSuffix) Checking_account.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/CPPWorkspace/Inheritance/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Trust_account.cpp$(ObjectSuffix): Trust_account.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Trust_account.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Trust_account.cpp$(DependSuffix) -MM Trust_account.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/CPPWorkspace/Inheritance/Trust_account.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Trust_account.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Trust_account.cpp$(PreprocessSuffix): Trust_account.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Trust_account.cpp$(PreprocessSuffix) Trust_account.cpp

$(IntermediateDirectory)/Default_functions.cpp$(ObjectSuffix): Default_functions.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Default_functions.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Default_functions.cpp$(DependSuffix) -MM Default_functions.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "E:/Codelite/CPPWorkspace/Inheritance/Default_functions.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Default_functions.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Default_functions.cpp$(PreprocessSuffix): Default_functions.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Default_functions.cpp$(PreprocessSuffix) Default_functions.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


