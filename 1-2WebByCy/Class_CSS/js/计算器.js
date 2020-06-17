
var butt = document.getElementsByClassName('bu')[0], // 按钮容器
	scan = document.getElementsByTagName('p')[0], // 显示器内容
	count = 0, //记录显示屏上字符及数字个数
	dian = false; //表示显示屏一个数字中是否已经有一个小数点的状态
	
butt.onclick = function(e) {
//	target 事件属性可返回事件的目标节点（触发该事件的节点），如生成事件的元素、文档或窗口。target事件就是会自动判断我们点的是哪个元素, target获取到的节点名称全部为大写
	var isB = e.target;
	if(isB.nodeName.toLowerCase() === 'button') {
		var num = isB.innerText;
		if(scan.innerText == 'Math Error' && num != 'AC') {
			return;
		}
		if(num == 'AC') {
			dian = false;
			scan.innerText = '0';
			count = 1;
		} else if(num == 'CE') {
			if(scan.innerText != '') {
				if(scan.innerText.length === 1) {
					scan.innerText = '0';
				} else {
//					slice() 方法可从已有的数组中返回选定的元素。 保头去尾 
					scan.innerText = scan.innerText.slice(0, -1);
//					slice(0, -1);倒叙之后删除第一个 也就是正序的最后一个
//					content.innerText = content.innerText.splice(count,1);
					
				}
				count--;
			}
		} else if(num == '=') {
			var text = scan.innerText;
			if(!text) {
				return;
			} else {
				text = text.replace(/x/g, '*');
				var result;
				try {
//		eval() 函数可计算某个字符串，并执行其中的的 JavaScript 代码。
//		document.write(eval("2+2"))------->4
//		var x=10 
//		document.write(eval(x+17))-------->27
					result = eval(text) + '';
					//这里被变成了一个字符串 result
//	search() 方法用于检索字符串中指定的子字符串，或检索与正则表达式相匹配的子字符串。
//var str="Hello world!"   
//document.write(str.search("world")) ---------->6 下标从0开始 空格也算
//document.write(str.search("World"))---------->-1
//document.write(str.search("woorld"))---------->-1
//document.write(str.search(/World/i))---------->6 忽略大小写
					if(result.search(/\./) > 0) {
//			search(/\./)----->search("\.")
//寻找字符串里面有没有/或是.  没有就会返回-1
//						正则表达式
//i	执行对大小写不敏感的匹配。
//g	执行全局匹配（查找所有匹配而非在找到第一个匹配后停止）。
//m	执行多行匹配。
						dian = true;//判断小数点
//			split() 方法用于把一个字符串分割成字符串数组。
//——————————————————————————————————————————————？？？？？？？
//这个是为了四舍五入 如果小数点后面的数字大于5位 就要四舍五入
						if(result.split('.')[1].length > 5) {
//——————————————————————————————————————————————？？？？？？？
							result = (+result).toFixed(5);
//			toFixed() 方法可把 Number 四舍五入为指定小数位数的数字。
						}
					}
					scan.innerText = result;
					count = result.length;
				} catch(e) {
					scan.innerText = 'Math Error';
				}
			}
		} else {
			if(isNaN(+num) && num != '.') {
				dian = false;
			}
			if(num == '.') {
				if(dian) {
					return;
				}
				dian = true;
			}
			if(scan.innerText == '0' && (!isNaN(+num) ||
					num == '(' || num == ')')) {
				scan.innerText = '';
			}
			scan.innerText += num;
			if(count++ >= 44) {
				alert('输入的字符过多');
			}
		}
	}
}