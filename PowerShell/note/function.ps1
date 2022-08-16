function primeQ ([int]$n)
{
    [int]$crit = [Math]::Ceiling([Math]::Sqrt($n))
    [int]$r = $n % 2
    for([int]$i = 3; ($i -le $crit) -and ($r -ne 0); $i++) {
        $r = $n % $i
    }
    if ($r -eq 0) {
        return $false
    } else {
        return $true
    }
}

function pipTest([Parameter(ValueFromPipeline=$true)]$n)
{
    $n
    $n | get-member
}