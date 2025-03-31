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

ninjavis --title "CustomRegex Build" .ninja_log .\build\buildLog.html

if ($?) {
    # .\build\regexTool.exe  -f ".\src\tests\sampleText.txt" -p "[^a-z,A-Z]$" -t
    .\build\regexTool.exe  -f ".\src\tests\sampleText.txt" -p "[k]" -t
}
