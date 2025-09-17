# nim_hash.nim
proc h(x:int): int = (x*x + 3*x + 7) mod 97
when isMainModule:
  let v = if paramCount() > 0: parseInt(paramStr(1)) else: 10
  if h(v) == 42:
    echo "NIM-UNLOCK"
  else:
    echo "nope"

