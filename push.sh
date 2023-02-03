#! /bin/bash

cd D:\cpp_code_review

echo "----------------------- 更新本地库 -----------------------"
echo ""

git pull

echo ""
echo "----------------------- 本地库状态 -----------------------"
echo ""

git status

echo ""

echo -n "正在提交备注...，请填写备注（可空）"
read remarks

if [ ! -n "$remarks" ];then
	remarks="$(date +%m-%d\ %H:%M)"
fi

git add .

git commit -m "$remarks"

echo ""
echo "----------------------- 提交结果 -----------------------"
echo ""

git push

echo ""

