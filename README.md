simple dsl to wrap around wolf rpg editor for text-based commonevent editing

uses c-style syntax:

```
int func (int a, str b, int c) {
  // single-line comments can be written with a double slash

  // defining variables
  int variable = 1 + 2;
  str string = "asdf";

  // int variable; // ERROR: redeclaration of a variable

  {
    int variable = 1; // OK -- shadowing in a nested scope
  }

  CDB["タイプ"][123]["項目"] = 3; // DB access
  // UDB[1]["asdf"][1234] = ...
  // SDB[...]

  // ループ（繰り返し）
  loop {
    break; // ループ中断
  }

  // 回数付きループ
  loop (5) {
    continue; // ループ開始へ
  }

  // if/else
  if (1 >= 2) variable = 2;
  else if (false) {
    variable = 3;
  } else variable = 4;

  int var2 = 0x1234; // hexadecimal

  var2 += 1 / 5 % 4 * (3 + 2); // expression handling
  
  return variable;
}

void func2() {
  int a = func(1, "asdf", 2); // function call

  // 日本語もある程度使えます
  整数 変数1 = 1234;
  文字列 も2 = "あ";
  ループ (3) {
    変数1 += 1;
    ループ開始へ;
    ループ中断;
  }
  
}
```
