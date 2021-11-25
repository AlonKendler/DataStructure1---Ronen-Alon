#!/bin/python
import subprocess
from os import listdir 

TEST_INPUT_DIR="testFiles/input"
TEST_OUTPUT_DIR="testFiles/input"
TEST_RES_DIR="testFiles/res"
exec_name ="main" # add .exe for windows

input_files=listdir(TEST_INPUT_DIR)

for file in input_files:
    subprocess.getoutput("./" + exec_name + " <" + TEST_INPUT_DIR + "/" +file + " > " + TEST_RES_DIR + "/" + file + ".res")

output_files=listdir(TEST_OUTPUT_DIR)
res_files=listdir(TEST_RES_DIR)

diffs = []

for i in range(len(output_files)):
    diff = 0
    with open(TEST_OUTPUT_DIR + "/" + output_files[i], "r") as foutput: 
        with open(TEST_RES_DIR + "/" + res_files[i], "r") as fres:
            output_lines = foutput.readlines()
            res_lines = fres.readlines()
            for i in range(min(len(res_lines), len(output_lines))):
                if output_lines[i] != res_lines[i]:
                    diff=diff+1
            diff = diff + max(len(output_files), len(res_lines)) - min(len(output_files), len(res_lines)) 
    diffs.append(diff)



print(diffs)
