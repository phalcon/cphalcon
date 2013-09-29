#! /bin/sh
cd /tmp
wget -q -O - http://www.xunsearch.com/scws/down/scws-1.2.2.tar.bz2 | tar xjf -
cd scws-1.2.2 ; ./configure ; sudo make install

