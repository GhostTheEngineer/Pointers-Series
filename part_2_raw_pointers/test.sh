#!/bin/bash

# Define colors
RED="\033[91m"
GREEN="\033[92m"
YELLOW="\033[93m"
CYAN="\033[96m"
RESET="\033[0m"

echo -e "${CYAN}============================="
echo -e "   Choose a C++ Source File"
echo -e "=============================${RESET}"

# List all C++ files in src/
count=0
files=()
while IFS= read -r -d '' file; do
    ((count++))
    files+=("$file")
    echo -e "${GREEN}$count. ${file#src/}${RESET}"
done < <(find src -maxdepth 1 -name "*.cpp" -print0)

exit_val=$((count+1))
echo -e "${YELLOW}$exit_val. Exit${RESET}"

# If no files found, exit
if [[ $count -eq 0 ]]; then
    echo -e "${RED}No C++ source files found.${RESET}"
    exit 1
fi

# Get user input for file selection
echo
read -p "$(echo -e "${CYAN}Enter the number of the file to compile: ${RESET}")" choice

# Exit if the user selects the exit option
if [[ "$choice" -eq "$exit_val" ]]; then
    echo -e "${YELLOW}Exiting...${RESET}"
    exit 0
fi

# Validate input
if [[ -z "${files[$((choice-1))]}" ]]; then
    echo -e "${RED}Invalid choice. Exiting...${RESET}"
    exit 1
fi

filename="${files[$((choice-1))]}"
basename=$(basename "$filename" .cpp)

# Choose the build method
echo -e "${CYAN}============================="
echo -e "   Choose Build Method"
echo -e "=============================${RESET}"
echo -e "${GREEN}1. Build with g++${RESET}"
echo -e "${GREEN}2. Build with CMake${RESET}"
echo -e "${YELLOW}3. Exit${RESET}"
echo

read -p "$(echo -e "${CYAN}Enter choice: ${RESET}")" build_method

# Handle exit
if [[ "$build_method" -eq 3 ]]; then
    echo -e "${YELLOW}Exiting...${RESET}"
    exit 0
fi

# ============================================================
# Build with g++
# ============================================================
if [[ "$build_method" -eq 1 ]]; then
    echo -e "${CYAN}Compiling $filename with g++...${RESET}"
    g++ -std=c++17 -o "$basename" "src/$basename.cpp"

    if [[ $? -ne 0 ]]; then
        echo -e "${RED}Compilation failed.${RESET}"
        exit 1
    fi

    # Run the program
    echo -e "${GREEN}Running $basename...${RESET}"
    echo -e "${CYAN}------------------------------------------------${RESET}"
    ./"$basename"
    echo -e "${CYAN}------------------------------------------------${RESET}"

    exit 0
fi

# ============================================================
# Build with CMake
# ============================================================
if [[ "$build_method" -eq 2 ]]; then
    echo -e "${CYAN}Setting up CMake build for $filename...${RESET}"

    # Ensure build directory exists
    mkdir -p build
    cd build || exit 1

    # Run CMake with the selected file
    cmake .. -DSELECTED_FILE="$basename.cpp"

    if [[ $? -ne 0 ]]; then
        echo -e "${RED}CMake configuration failed.${RESET}"
        exit 1
    fi

    cmake --build .

    if [[ $? -ne 0 ]]; then
        echo -e "${RED}Build failed.${RESET}"
        exit 1
    fi

    # Run the program
    echo -e "${GREEN}Running $basename...${RESET}"
    echo -e "${CYAN}------------------------------------------------${RESET}"
    ./Debug/"$basename"
    echo -e "${CYAN}------------------------------------------------${RESET}"

    exit 0
fi

# Invalid choice
echo -e "${RED}Invalid choice. Exiting...${RESET}"
exit 1

clear