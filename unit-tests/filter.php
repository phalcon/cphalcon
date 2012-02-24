<?php

//Required for run in GDB
if(PHP_OS=='Linux'){
	if($_SERVER['USERNAME']=='gutierrezandresfelipe'){
		chdir('/home/gutierrezandresfelipe/phalcon');
	}
}

$filter = new Phalcon_Filter();

$value = $filter->sanitize("lol", "string");
if($value=="lol"){
	echo 'Phalcon_Filter::sanizite() [1] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [1] [FAILED]', PHP_EOL;
	return;
}

$value = $filter->sanitize("lol", array("string"));
if($value=="lol"){
	echo 'Phalcon_Filter::sanizite() [2] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [2] [FAILED]', PHP_EOL;
	return;
}

$value = $filter->sanitize("lol<<", "string");
if($value=="lol"){
	echo 'Phalcon_Filter::sanizite() [3] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [3] [FAILED]', PHP_EOL;
	return;
}

$value = $filter->sanitize("lol", "int");
if($value==""){
	echo 'Phalcon_Filter::sanizite() [4] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [4] [FAILED]', PHP_EOL;
	return;
}

$value = $filter->sanitize("!100a019", "int");
if($value=="100019"){
	echo 'Phalcon_Filter::sanizite() [5] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [5] [FAILED]', PHP_EOL;
	return;
}

$value = $filter->sanitize("!100a019.01a", "float");
if($value=="100019.01"){
	echo 'Phalcon_Filter::sanizite() [6] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [6] [FAILED]', PHP_EOL;
	return;
}

$value = $filter->sanitize("some(one)@exa\\mple.com", "email");
if($value=="someone@example.com"){
	echo 'Phalcon_Filter::sanizite() [7] [OK]', PHP_EOL;
} else {
	echo 'Phalcon_Filter::sanizite() [7] [FAILED] '.$value, PHP_EOL;
	return;
}

