#!/bin/zsh
hello="var1"
echo $hello

function fun1 {
  local hello="var2"
  echo $hello
}

fun1
echo $hello
