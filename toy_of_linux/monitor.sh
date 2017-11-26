#!/bin/bash

# 监控程序是否正常运行，如果没有运行，那么启动程序

i=1
while [ true ]
do
    pro=$(ps -ef | grep ${1}.sh | grep -v grep)

    if [ $i -eq 1 ]
    then
        echo $pro
    fi
    ((++i))

    if [ -z $pro ]
    then
        sh ${1}.sh
    fi

    sleep 1
done
