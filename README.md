# RS255_Berlekamp_Decoder

RS 是一种基于代数的纠错码 (RS is a kind of Error Correcting Code(ECC) based on algebra)：

![useless_box](imgs/../docs/imgs/useless_box.gif)

```
source -> send -> noise -> receive -> decode
```

``` 
source code: [0, 0, 0, 0, 0, 0, 0]
+
noise: [0.1, 0.2, 0.05, 0.6, 0.1, 0.05, 0.3]
||
judgement: [0, 0, 0, 1, 0, 0, 0]
|
decode
|
v
after decode: [0, 0, 0, 0, 0, 0, 0]
```

[Berlekamp 算法](https://jimyma.github.io/2018/07/09/Berlekamp_algorithm/) 是一种纠错算法 (Berlekamp Algorithm is a method to correcting error.)

## 安装 (Install)
``` shell
git clone https://github.com/JimyMa/RS255_Berlekamp_Decoder --recursive
pip -r requirements.txt
python setup.py develop --user
```

## 使用方法 (Usage)
``` shell
cd examples
# end-to-end
python Berlekamp_decode_simulation.py
# step-by-step
jupyter-notebook Berlekamp_decode_simulation.ipynb
```
程序巡行成功将输出如下曲线 (Outputs when the program is done):
![性能曲线](imgs/../docs/imgs/RS255.svg)

