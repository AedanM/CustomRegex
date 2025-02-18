param (
    [bool] $clean = $false
)

if ($clean) {
    Remove-Item -Path .\build -Recurse -Force
    Remove-Item -Path .\obj -Recurse -Force
}


python NinjaGenerator.py

if ($?) {
    ninja
}

if ($?) {
    .\build\regexTool.exe  -f ".\sampleText.txt" -p "[^a-z,A-Z]$"
}
