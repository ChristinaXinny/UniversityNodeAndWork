/* 所用到的函数的功能：
   indexOf() 方法可返回某个指定的字符串值在字符串中首次出现的位置。
   join()方法作用是把数组中的所有元素放入一个字符串
   eval()函数可计算某个字符串，并执行其中的的 JavaScript 代码
   push() 方法可向数组的末尾添加一个或多个元素，并返回新的长度
   substr() 方法可在字符串中抽取从 start 下标开始的指定数目的字符
   Tip：如果下标是负数，那么表示从字符串的尾部开始算起的位置，比如-1是指字符串中最后一个字符*/



var bn = document.getElementsByTagName("div"); //获取div集合
var text = document.getElementById("one"); //获取文本框
var res = []; //存储输入的值
var label = false; //一个开关，后续对重复输入功能键时进行处理
for (var i = 0; i < bn.length; i++) {
    bn[i].onclick = cal;

    function cal() {
        //输入为数字或者为 "."时
        if (!isNaN(this.innerHTML) || this.innerHTML == ".") {

            label = true;
            if (text.value !== "0") { //文本框初值不为0时

                if (text.value.indexOf(".") !== -1) {

                    if (this.innerHTML !== ".") {
                        text.value += this.innerHTML;
                    }
                } else { //文本框中含有“.”时
                    text.value += this.innerHTML;
                }
            }
            //文本框初值为0
            else {
                if (this.innerHTML == ".") {
                    text.value = "0" + this.innerHTML;
                } else {
                    text.value = this.innerHTML;
                }
            }
        }


        //功能键
        else {
            switch (this.innerHTML) {
                case "💡":
                    alert('\n我只是一个普通的计算器！\n恐怕没有什么办法能帮到您。');
                    break;
                case "+":
                    save(this);
                    break;
                case "-":
                    save(this);
                    break;
                case "/":
                    save(this);
                    break;
                case "*":
                    save(this);
                    break;
                case "%":
                    save(this);
                    break;
                case "=":
                    res.push(text.value);

                    var result = eval(res.join(""));

                    //如果结果是无穷时,结果为Error
                    text.value = result == Infinity ? "Error" : result;

                    res = [];
                    break;
                case "CE":
                    //从后往前一个一个的减数字 
                    text.value = text.value.length == 1 ? "0" : text.value.substr(0, text.value.length - 1);
                    break;
                case "AC":
                    text.value = "0";
                    res = []; //数组置空

                    break;
            }
        }
    }
}
//清屏之前存储用户按的值
function save(aa) {

    if (!label) { //连续两次按符号时，开关是关闭的，if表达式为真
        res[res.length - 1] = aa.innerHTML; //第二次的符号替代第一次的

    } else {

        res.push(text.value);
        res.push(aa.innerHTML); //功能键存入数组中
    }
    text.value = "0"; //清屏
    label = false; //关闭开关
}