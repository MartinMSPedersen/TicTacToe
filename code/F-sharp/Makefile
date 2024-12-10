# Makefile to compile hello.fsx into a binary

# Variables
FSHARP_SCRIPT=TicTacToeBoard.fsx
DOTNET_PROJECT_DIR=TicTacToeBoard
PUBLISH_DIR=$(DOTNET_PROJECT_DIR)/bin/Release/net8.0/linux-x64/publish
OUTPUT_BINARY=$(PUBLISH_DIR)/TicTacToeBoard

.PHONY: all clean dotnet run

# Default target
all: $(OUTPUT_BINARY)

# Compile using dotnet SDK (self-contained native binary)
$(OUTPUT_BINARY): $(FSHARP_SCRIPT)
	@echo "Creating dotnet project if it doesn't exist..."
	@test -d $(DOTNET_PROJECT_DIR) || dotnet new console -lang F# -o $(DOTNET_PROJECT_DIR)
	@echo "Copying script content to the project..."
	cp $(FSHARP_SCRIPT) $(DOTNET_PROJECT_DIR)/Program.fs
	@echo "Publishing as self-contained application..."
	cd $(DOTNET_PROJECT_DIR) && dotnet publish -c Release -r linux-x64 --self-contained -p:NoWarn=NETSDK1188
	@echo "Output binary can be found in $(PUBLISH_DIR)"

# Clean generated files
clean:
	@echo "Cleaning up..."
	rm -rf $(DOTNET_PROJECT_DIR)

run: $(OUTPUT_BINARY)
	@echo "Running $(OUTPUT_BINARY)..."
	$(OUTPUT_BINARY)
