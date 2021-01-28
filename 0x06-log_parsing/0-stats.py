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
            status_code = line.split(" ")
            if len(status_code) > 2:
                total_size += int(status_code[-1])
            if status_code[-2] in code:
                code[status_code[-2]] += 1
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
    except Exception:
        pass
    finally:
        print("File size: {:d}".format(total_size))
        for key in sorted(code.keys()):
            if code[key]:
                print("{}: {}".format(key, code[key]))
