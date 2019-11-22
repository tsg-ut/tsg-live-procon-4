# Tahoiya ga Tokuiya
-------ここからフレーバー(読まなくても大丈夫です)-------

TSGのたほいやにはランダム,たほいやAIくん1号 (仮) ,たほいやAIくん2号 (仮) の3人のbotが居ます。
botたちはみんな、自分の解答との編集距離が最小の解答に振り込むことになっています。
たほいやで得点をとりたいおじぎねこは、botたちから振り込んでもらうために、
できる限りbotと似た解答をすることにしました。おじぎねこの代わりに解答を考えてあげましょう。

-------ここまでフレーバー-------

文字列s,tの編集距離(レーベンシュタイン距離)は、
sに対して「1文字挿入」「1文字削除」「1文字置換」の操作を繰り替えしてtにするための最小の操作回数です。
たとえば、"ABCD" と "EASC" の編集距離は、"ABCD" -> "EABCD" -> "EABC" -> "EASC" の3です。

アルファベット大文字からなる文字列$s_1,s_2,s_3$が与えられます。
うまく文字列$t$を選んだ場合の $d(t,s_1)+d(t,s_2)+d(t,s_3) $ の最小値を求めてください。
ここで、$ d(s,t) $ は文字列$s,t$間の編集距離です。

## 入力フォーマット
入力は以下の形式で標準入力から与えられます。
```
$L_1$
$s_1$
$L_2$
$s_2$
$L_3$
$s_3$
```

## 出力フォーマット
編集距離の和の最小値を標準出力に出力してください。

## 制約

* $ 1 \leqq L_1,L_2,L_3 \leqq 100 $
* $ |s_1| = L_1, |s_2| = L_2, |s_3| = L_3 $
* $ s_1,s_2,s_3 $ はすべてアルファベット大文字([A-Z])からなる。

## 入出力例

### 入力例1
```
4
BFBC
4
ABFD
3
ACC
```

### 出力例1
```
5
```

たとえば、文字列"AFC"が、
$ d("AFC","BFBC") + d("AFC","ABFD") + d("AFC","ACC") = 2 + 2 + 1 = 5 $ で最小値 $5$ を与えます。

### 入力例2
```
3
TSG
4
LIVE
4
FOUR
```

### 出力例2
```
8
```

### 入力例3
```
100
NLIIERMEIMSYSELALGGMXFXNKJSEEPDWJSPFASOWWEVCVIRDQRLSLREIFKITHUWTNZLUVGGWTSKRMSBWCOVWMFIDIGQMZRXCYAJC
100
DKKMVOCVABUFPCRTSZYHBZLCZYDPSRQGHFKKJPOQITIFUIFOVPPHOUHFIVCJGMKENQNUUEHZJYQZSITPHKCYPNHGSFSPKHPCHLMB
100
JNGNCMADIQCOAHFKNZNTLCSWHAWKDEBFIMNAQOKOUGGLJPRISFSNJHFHPQGUEGPHOLVUECJTUFGNMFTDYIAJUFEFEUJFFAROUBSF
```

### 出力例3
```
169
```




