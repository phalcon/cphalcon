--TEST--
\Phalcon\Debug and russian language - https://github.com/phalcon/cphalcon/issues/1099
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$d = new \Phalcon\Debug();
$d->listen(true, true);
throw new \Exception('Тест');
?>
--EXPECTREGEX--
.*?<meta http-equiv="Content-Type" content="text\/html; charset=utf-8"\/>.*
