# RS255_Berlekamp_Decoder

RS 是一种纠错码 (RS is a kind of Error Correcting Code(ECC))：

![useless_box](imgs/../docs/imgs/useless_box.gif)

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

