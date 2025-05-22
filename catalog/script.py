"""
@file script.py
@author cuber-lotus
@brief
    A script to record all code-file names
"""

import os
import sys


def Record_eachFile(path, dir):
    """
    @brief
        just have file
    """
    file_list = os.listdir(path)
    for file_name in sorted(file_list):
        str = f"- [{file_name}](../code/{dir}/{file_name})"
        print(str)


def Search_rootDir(root_dir):
    """
    @brief
        just have dir
    """
    sub_dir_list = os.listdir(root_dir)
    for sub_dir in sorted(sub_dir_list):
        print(f"\n## {sub_dir}\n")
        Record_eachFile(os.path.join(root_dir, sub_dir), sub_dir)


if __name__ == "__main__":
    """
    @brief
        redirect to `./catalog.md`
    """
    CONST_FILE_PATH = os.path.split(os.path.realpath(__file__))[0]
    CONST_SOURCE_PATH = "../code"
    CONST_TARGET_FILE = "./catalog.md"

    with open(os.path.join(CONST_FILE_PATH, CONST_TARGET_FILE), "w+") as file:
        sys.stdout = file
        print("# Catalog\n")
        print("[toc]")
        Search_rootDir(os.path.join(CONST_FILE_PATH, CONST_SOURCE_PATH))
