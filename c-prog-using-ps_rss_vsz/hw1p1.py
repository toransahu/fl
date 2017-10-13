"""hw1p1.py."""


import subprocess
import shlex
import os


def get_rss():
    """Find resident set size under /proc/ ."""
    p1 = subprocess.Popen(["ls", "/proc"],
                          stdout=subprocess.PIPE)
    p2 = subprocess.Popen(shlex.split("grep '[0-9]'"),
                          stdin=p1.stdout,
                          stdout=subprocess.PIPE,
                          stderr=subprocess.PIPE)
    p1.stdout.close()
    out, err = p2.communicate()
    # print('out: {0}', format(out))
    # print('err: {0}', format(err))
    # print(out.decode("utf-8"))
    res = out.decode("utf-8").strip().split('\n')
    # decode converts bytes to str

    for pid in res:
        parmList = ["ps", "-p", pid, "-o", "rss", ""]
        # os.execvp("/bin/ps", parmList)


if __name__ == "__main__":
    get_rss()
