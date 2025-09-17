{ fpc_nested.pas }
program FPCNested;
uses sysutils;

procedure Outer(n: Integer);
  procedure Prize;
  begin
    writeln('FPC-PRIZE');
  end;
begin
  if ((n * 11) and $7) = 3 then Prize else writeln('nope');
end;

begin
  var v := 5;
  if ParamCount >= 1 then v := StrToInt(ParamStr(1));
  Outer(v);
end.

