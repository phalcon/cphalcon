--TEST--
Phalcon\Debug and link to file with an error - https://github.com/phalcon/cphalcon/issues/1401
--SKIPIF--
<?php include('skipif.inc'); ?>
--INI--
xdebug.file_link_format=file://%f#%l
--FILE--
<?php
include('skipif.inc'); // This is to make sure the list of the included files is not empty

function do_it()
{
	throw new \Exception('Test');
}

$d = new \Phalcon\Debug();
$d->listen(true, true);
do_it();
?>
--EXPECTREGEX--
.*<\/h1><span class="error-file"><a href="file:\/\/.*?(?:\/|\\)issue-1401\.phpt?\#[0-9]+">.+?<a href="file:\/\/.*?(?:\/|\\)issue-1401\.phpt?\#[0-9]+">.*
