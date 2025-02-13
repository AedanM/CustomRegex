# cSpell: disable
from pathlib import Path


def Main(path: Path):
    output = "cxx = g++\n"

    output += f"cflags = {(' '.join(["-Wall", "-Wextra", "-Iinclude"]))}\n\n"

    output += "rule compile\n  "
    output += "command = $cxx -MMD -MT $out -MF $out.d $cflags -c $in -o $out -std=c++23\n"
    output += "depfile = $out.d\n\n"
    output += "rule link\n  command = $cxx $ldflags -o $out $in\n\n"

    objSrc = [(rf".\obj\{src.stem}.o", src) for src in path.parent.glob("src/**/*.cpp")]
    for obj, src in objSrc:
        output += f"build {obj}: compile {str(src)}\n"
        output += "  description = Compiling {str(src)}\n\n"

    objListStr = " ".join([(obj) for obj, _src in objSrc])
    output += f"\nbuild build/regexTool: link {objListStr}\n  description = Linking\n"
    path.write_text(output)


if __name__ == "__main__":
    p = Path(r".\build.ninja")
    Main(p)
