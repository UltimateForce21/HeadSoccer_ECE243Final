import sys
import os

def merge_c_files(input_files, output_file):
    # Form the quom command to merge files
    quom_command = [sys.executable, "-m", "quom", input_files] + output_file

    # Execute the quom command
    os.system(" ".join(quom_command))

if __name__ == "__main__":
    # List of input files to merge
    input_files = "main.c"
    #["drawFunctions.h", "drawFunctions.c", "images.h", "images.c", "main.c"]

    # Output file where merged content will be written
    output_file = ["main_gen.cpp"]

    # Merge the files
    merge_c_files(input_files, output_file)
