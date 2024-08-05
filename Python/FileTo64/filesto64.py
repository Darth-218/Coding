import sys
from base64 import b64encode
from os import listdir


def main(target_folder: str, files_count: int):
    files = listdir(target_folder)[:files_count]
    for file in files:
        if "_encoded" in file:
            continue
        encoded_file_name = str(file).split(".")[0] + "_encoded"

        with open(file, "r") as input_file:
            file_content = input_file.read()
            encoded_file_content = bytes(b64encode(file_content.encode("ascii")))

            with open(encoded_file_name, "wb") as output_file:
                output_file.write(encoded_file_content)


if __name__ == "__main__":
    target_folder, count = sys.argv[1], int(sys.argv[2])
    main(target_folder, count)
