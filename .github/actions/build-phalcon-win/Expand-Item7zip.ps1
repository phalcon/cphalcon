<#
    .SYNOPSIS
        Expand archive files wit 7zip
#>

[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)] [System.String] $Archive,
    [Parameter(Mandatory = $true)] [System.String] $Destination
)

process {
    if (-not (Test-Path -Path $Archive -PathType Leaf)) {
        throw "Specified archive File is invalid: [$Archive]"
    }

    if (-not (Test-Path -Path $Destination -PathType Container)) {
        New-Item $Destination -ItemType Directory | Out-Null
    }

    $Result = (& 7z x "$Archive" "-o$Destination" -aoa -bd -y -r)

    if ($LastExitCode -ne 0) {
        Write-Output "An error occurred while unzipping [$Archive] to [$Destination]. Error code was: ${LastExitCode}"
        Exit $LastExitCode
    }
}

