#预处理
from cyaron import *

#函数
#

#cyaron函数
def _cyaron( i):
    io=IO( file_prefix = "main", data_id = i)
    
    #for j in range():
    #n = randint( 1, 30)

    io.input_writeln( 6)
    io.input_writeln( "0 0 0 0 0 0")
    io.input_writeln( "0 0 1 1 1 1")
    io.input_writeln( "0 1 1 0 0 1")
    io.input_writeln( "1 1 0 0 0 1")
    io.input_writeln( "1 0 0 0 0 1")
    io.input_writeln( "1 1 1 1 1 1")
    
    io.output_gen( "C:\\Users\\user\\Desktop\\code\\oj\\luogu\\pj-\\1162\\main.exe")

#

#主函数
if __name__ == "__main__":
    #for i in range( 1, 4):
    _cyaron( 1)
    