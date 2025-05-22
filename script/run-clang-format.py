import os
import sys
from datetime import datetime
from subprocess import run, CalledProcessError
from concurrent.futures import ThreadPoolExecutor
from threading import Lock


class FormatterProgress:
    def display_progress(self, current, total, bar_length=60):
        progress = current / total
        filled = int(bar_length * progress)
        percent = progress * 100
        bar = f"[{'#' * filled}{'-' * (bar_length - filled)}]"
        sys.stdout.write(f"\r{bar} {current}/{total} ({percent:.2f}%)")
        sys.stdout.flush()

    def __init__(self, total):
        self.lock = Lock()
        self.completed = 0
        self.total = total
        sys.stdout.flush()

    def worker(self, task):
        task()
        with self.lock:
            self.completed += 1
            self.display_progress(self.completed, self.total)


def find_files(root_dir):
    EXCLUDE_DIRS = ["build"]
    SUFFIXES = (".h", ".hpp", ".cpp", ".cc", ".c")

    files = []
    for root, dirs, filenames in os.walk(root_dir):
        dirs[:] = [d for d in dirs if d not in EXCLUDE_DIRS]
        files.extend(os.path.join(root, f) for f in filenames if f.endswith(SUFFIXES))
    for suf in SUFFIXES:
        count = sum(1 for f in files if f.endswith(suf))
        print(f'"{suf}" \t=> {count:5d} files')
    return files


def format_file(file_path):
    try:
        run(["clang-format", "-i", file_path], check=True)
    except CalledProcessError as e:
        print(f"Error formatting {file_path}: {e}")


def main():
    script_dir = os.path.dirname(os.path.abspath(__file__))
    root_dir = os.path.dirname(script_dir)

    print("Scanning for files...")
    files = find_files(root_dir)

    print("Formatting files...")
    progress = FormatterProgress(len(files))

    max_workers = max(1, (os.cpu_count() or 1) - 4)
    with ThreadPoolExecutor(max_workers=max_workers) as executor:
        tasks = [lambda arg=path: format_file(arg) for path in files]
        executor.map(progress.worker, tasks)

    print("\nFormatting completed successfully!")


if __name__ == "__main__":
    print("Script Start:", datetime.now())
    main()
    print("Script End:", datetime.now())
