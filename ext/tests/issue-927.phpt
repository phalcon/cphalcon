--TEST--
Invalid memory reads when GC is on - https://github.com/phalcon/cphalcon/pull/927
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$config = new \Phalcon\Config(array('test1' => 1, 'test2' => 2));
$config->merge(new \Phalcon\Config(array('test2')));
gc_collect_cycles();
?>
--EXPECT--
