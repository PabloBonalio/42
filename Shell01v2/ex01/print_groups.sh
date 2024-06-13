#!/bin/sh
id -Gn $FT_USER | tr ' ' ',' | tr --delete '\n'
