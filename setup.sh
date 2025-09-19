#!/bin/bash

# --- Function to check for and install packages (apt-based systems) ---
install_packages() {
    local packages=("$@")
    local packages_to_install=()

    for pkg in "${packages[@]}"; do
        if ! command -v "$pkg" &> /dev/null; then
            echo "Package '$pkg' not found. Adding to installation list."
            packages_to_install+=("$pkg")
        else
            echo "Package '$pkg' is already installed."
        fi
    done

    if [ ${#packages_to_install[@]} -gt 0 ]; then
        echo "Installing missing packages: ${packages_to_install[*]}..."
        sudo apt update
        sudo apt install -y "${packages_to_install[@]}"
        echo "Packages installed successfully."
    else
        echo "All required packages are already installed."
    fi
}

# --- Main script starts here ---

echo "Starting C++ workspace setup for VS Code on Linux..."

# 1. Install necessary command-line tools
echo ""
echo "--- Step 1: Installing system prerequisites (clang, cmake, etc.) ---"
REQUIRED_DEBS=(clang-16 clangd-16 clang-tidy-16 clang-format-16 cmake ninja-build lldb)
install_packages "${REQUIRED_DEBS[@]}"

# Update alternatives for the clang binaries to ensure VS Code finds them
echo ""
echo "--- Configuring system alternatives for Clang tools ---"
sudo update-alternatives --install /usr/bin/clangd clangd /usr/bin/clangd-16 100
sudo update-alternatives --install /usr/bin/clang-tidy clang-tidy /usr/bin/clang-tidy-16 100
sudo update-alternatives --install /usr/bin/clang-format clang-format /usr/bin/clang-format-16 100
echo "Clang tools configured."

# 2. Install VS Code extensions
echo ""
echo "--- Step 3: Installing VS Code extensions ---"
if ! command -v code &> /dev/null; then
    echo "VS Code 'code' command not found. Please ensure VS Code is installed and in your PATH."
else
    code --install-extension llvm-vs-code-extensions.vscode-clangd
    code --install-extension ms-vscode.cmake-tools
    code --install-extension vadimcn.vscode-lldb
    code --install-extension usernamehw.errorlens # Provides inline errors
    code --install-extension christian-kohler.path-intellisense # Optional, for convenience
fi

# 3. Create .vscode directory and settings.json
echo ""
echo "--- Step 4: Configuring VS Code workspace settings ---"
mkdir .vscode
cat > .vscode/settings.json <<EOL
{
    "clangd.arguments": [
        "--background-index",
        "--clang-tidy",
        "--header-insertion=iwyu",
        "--compile-commands-dir=${workspaceFolder}/build/"
    ],
    "C_Cpp.intelliSenseEngine": "Disabled",
    "editor.defaultFormatter": "llvm-vs-code-extensions.vscode-clangd",
    "editor.formatOnSave": true,
    "editor.rulers": [79],
}
EOL
echo ".vscode/settings.json configured."

# 4. Create clang-tidy and clang-format config files
echo ""
echo "--- Step 5: Creating clang-tidy and clang-format config files ---"
cat > .clang-tidy <<EOL
Checks: '-*,readability-*,bugprone-*,cppcoreguidelines-*,performance-*'
WarningsAsErrors: ''
HeaderFilterRegex: ''
FormatStyle: file
EOL
echo ".clang-tidy config file created."

cat > .clang-format <<EOL
BasedOnStyle: LLVM
IndentWidth: 4
ColumnLimit: 100
UseTab: Never
BreakBeforeBraces: Custom
BraceWrapping:
  AfterClass: true
  AfterControlStatement: false
  AfterEnum: true
  AfterFunction: false
  AfterNamespace: false
  AfterStruct: true
  AfterUnion: true
  AfterExternBlock: false
  BeforeCatch: true
  BeforeElse: true
  IndentBraces: false
EOL
echo ".clang-format config file created."
cat > .clang-format <<EOL
CompileFlags:
  Add: [-std=c++98, -Wall, -Wextra, -Werror]

Diagnostics:
  UnusedIncludes: Strict
  MissingIncludes: Strict
  ClangTidy: {}

InlayHints:
  Enabled: true
  ParameterNames: true
  DeducedTypes: true
  Designators: true
  BlockEnd: true

Hover:
  ShowAKA: true

Completion:
  AllScopes: true
  IncludeIneligibleResults: true

Index:
  Background: Build
  StandardLibrary: true

Semantic:
  HighlightingKind: detailed

EOL

echo ""
echo "Setup complete! Your C++ project is configured according to the rules."
echo "Don't forget to reload the VS Code window (Ctrl+Shift+P > Reload Window) for changes to take effect."
