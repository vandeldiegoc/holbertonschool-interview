#!/usr/bin/python3
"""Write a script that reads stdin line by line and computes metrics"""
import sys

if __name__ == "__main__":

    nun = 0
    total_size = 0
    code = {"200": 0, "301": 0, "400": 0, "401": 0,
            "403": 0, "404": 0, "405": 0, "500": 0}
    try:
        for line in sys.stdin:
            status_code = line.split('"')[2].split(" ")[1]
            size = int(line.split('"')[2].split(" ")[2])
            total_size += size
            nun += 1
            for key in sorted(code.keys()):
                if status_code == key:
                    code[key] += 1
            if nun == 10:
                print("File size: {:d}".format(total_size))
                for key in sorted(code.keys()):
                    if code[key]:
                        print("{}: {:d}".format(key, code[key]))
                nun = 0
    except KeyboardInterrupt:
        pass
    finally:
        print("File size: {:d}".format(total_size))
        for key in sorted(code.keys()):
            if code[key]:
                print("{}: {:d}".format(key, code[key]))
