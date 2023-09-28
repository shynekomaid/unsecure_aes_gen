program KeyGenerator;

uses
  SysUtils,
  DateUtils,
  CRT;

procedure PressAnyKeyToContinue;
var
  Key: Char;
begin
  WriteLn('Press any key to continue, or press Enter to exit...');

  Key := ReadKey;

  if Ord(Key) = 13 then // 13 is the ASCII code for Enter
  begin
    WriteLn('Exiting the program.');
    Halt(0);
  end;
end;

procedure GenerateHexKey(var Key: string; KeyLength: Integer);
const
  Charset: string = '0123456789ABCDEF';
var
  CharsetLength, i: Integer;
begin
  CharsetLength := Length(Charset);

  Key := '';

  for i := 1 to KeyLength do
  begin
    Key := Key + Charset[Random(CharsetLength) + 1];
  end;
end;

procedure GenerateRasKey(var Key: string; KeyLength: Integer);
const
  Charset: string = '$ABCDEFGHIJKLMNOPQRSTUVWXYZ-_0123456789';
var
  CharsetLength, i: Integer;
begin
  CharsetLength := Length(Charset);

  Key := '';

  for i := 1 to KeyLength do
  begin
    Key := Key + Charset[Random(CharsetLength) + 1];
  end;
end;

var
  Arc4Key, Aes256Key, PlsTskKey, RasKey: string;
begin
  Randomize; // Initialize the random number generator

  while True do
  begin
    GenerateHexKey(Arc4Key, 10);
    GenerateHexKey(Aes256Key, 64);
    GenerateHexKey(PlsTskKey, 24);
    GenerateRasKey(RasKey, 24);

    WriteLn('ARC4 Key: ', Arc4Key);
    WriteLn('AES-256 Key: ', Aes256Key);
    WriteLn('TSK-PLS Key: ', PlsTskKey);
    WriteLn('RAS Key: ', RasKey);

    PressAnyKeyToContinue;
  end;
end.
