#!/bin/bash

# 创建存储目录
path=./tmp
mkdir -p ${path}
touch log

max_percent=$1
i=0

# 参数为空则退出
if [ -z "$max_percent" ]
then
    echo "请指定参数（指定磁盘的最大使用率），如 sh cp.sh 50"
    exit
fi

while [ true ]
do
    # 生出指定大小文件
    dd if=/dev/zero of=${path}/${i}hello.txt bs=10M count=2 >> log
    ((++i))
    sleep 0.5

    # 每生成 5 个文件后，检测是否超过临界值
    if [ $((i%5)) -eq 0 ]
    then
        percent=$(df | grep sda5 | awk '{ print $5 }' | cut -c 1-2)
        echo $percent
        echo "------------------0--0-----------------"
        # 磁盘使用率超过 max_percent 清空 tmp 目录
        if [ $percent -gt $max_percent ]
        then
            rm -rf ./tmp/*
            echo "磁盘使用率过高，清空缓存" >> log
            echo "------------------------" >> log
            echo "" >> log
            # 文件名重新开始计数
            i=0
        fi
    fi

done
