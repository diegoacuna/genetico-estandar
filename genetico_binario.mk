##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=genetico_binario
ConfigurationName      :=Debug
WorkspacePath          := "/home/dacuna/.codelite/evolutivos"
ProjectPath            := "/home/dacuna/.codelite/evolutivos/genetico_binario"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Diego Acuña
Date                   :=10/30/2012
CodeLitePath           :="/home/dacuna/.codelite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
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
ObjectsFileList        :="/home/dacuna/.codelite/evolutivos/genetico_binario/genetico_binario.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lm -lmatheval
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/ag$(ObjectSuffix) $(IntermediateDirectory)/operadores$(ObjectSuffix) $(IntermediateDirectory)/seleccion$(ObjectSuffix) $(IntermediateDirectory)/utilidades$(ObjectSuffix) $(IntermediateDirectory)/cmdline$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.c $(IntermediateDirectory)/main$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/genetico_binario/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/genetico_binario/main.c"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/genetico_binario/main.c"

$(IntermediateDirectory)/ag$(ObjectSuffix): ag.c $(IntermediateDirectory)/ag$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/genetico_binario/ag.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ag$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ag$(DependSuffix): ag.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ag$(ObjectSuffix) -MF$(IntermediateDirectory)/ag$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/genetico_binario/ag.c"

$(IntermediateDirectory)/ag$(PreprocessSuffix): ag.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ag$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/genetico_binario/ag.c"

$(IntermediateDirectory)/operadores$(ObjectSuffix): operadores.c $(IntermediateDirectory)/operadores$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/genetico_binario/operadores.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/operadores$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/operadores$(DependSuffix): operadores.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/operadores$(ObjectSuffix) -MF$(IntermediateDirectory)/operadores$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/genetico_binario/operadores.c"

$(IntermediateDirectory)/operadores$(PreprocessSuffix): operadores.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/operadores$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/genetico_binario/operadores.c"

$(IntermediateDirectory)/seleccion$(ObjectSuffix): seleccion.c $(IntermediateDirectory)/seleccion$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/genetico_binario/seleccion.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/seleccion$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/seleccion$(DependSuffix): seleccion.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/seleccion$(ObjectSuffix) -MF$(IntermediateDirectory)/seleccion$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/genetico_binario/seleccion.c"

$(IntermediateDirectory)/seleccion$(PreprocessSuffix): seleccion.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/seleccion$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/genetico_binario/seleccion.c"

$(IntermediateDirectory)/utilidades$(ObjectSuffix): utilidades.c $(IntermediateDirectory)/utilidades$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/genetico_binario/utilidades.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utilidades$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utilidades$(DependSuffix): utilidades.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utilidades$(ObjectSuffix) -MF$(IntermediateDirectory)/utilidades$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/genetico_binario/utilidades.c"

$(IntermediateDirectory)/utilidades$(PreprocessSuffix): utilidades.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utilidades$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/genetico_binario/utilidades.c"

$(IntermediateDirectory)/cmdline$(ObjectSuffix): cmdline.c $(IntermediateDirectory)/cmdline$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/dacuna/.codelite/evolutivos/genetico_binario/cmdline.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/cmdline$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cmdline$(DependSuffix): cmdline.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/cmdline$(ObjectSuffix) -MF$(IntermediateDirectory)/cmdline$(DependSuffix) -MM "/home/dacuna/.codelite/evolutivos/genetico_binario/cmdline.c"

$(IntermediateDirectory)/cmdline$(PreprocessSuffix): cmdline.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/cmdline$(PreprocessSuffix) "/home/dacuna/.codelite/evolutivos/genetico_binario/cmdline.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/ag$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/ag$(DependSuffix)
	$(RM) $(IntermediateDirectory)/ag$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/operadores$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/operadores$(DependSuffix)
	$(RM) $(IntermediateDirectory)/operadores$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/seleccion$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/seleccion$(DependSuffix)
	$(RM) $(IntermediateDirectory)/seleccion$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utilidades$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utilidades$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utilidades$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/cmdline$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/cmdline$(DependSuffix)
	$(RM) $(IntermediateDirectory)/cmdline$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "/home/dacuna/.codelite/evolutivos/.build-debug/genetico_binario"


