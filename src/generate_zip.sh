#!/usr/bin/env bash

project_name='prog3_pc1_v2024_1'
source_code='
        board.h
        counter.h
  '
rm -f ${project_name}.zip
zip -r -S ${project_name} ${source_code}