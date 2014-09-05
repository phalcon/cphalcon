--TEST--
Memory leak in Phalcon\Cache\Backend\Apc::flush() - https://github.com/phalcon/cphalcon/issues/1455
--INI--
report_memleaks=1
--SKIPIF--
<?php
include('skipif.inc');
if (!class_exists('APCIterator', false)) {
	die('skip APC or APCu is required');
}
?>
--FILE--
<?php
$front = new \Phalcon\Cache\Frontend\Data(array('lifetime' => 600));
$cache = new \Phalcon\Cache\Backend\Apc($front, array('prefix' => 'prefix_'));

$cache->save('foo', 1);
$cache->save('bar', 1);
$cache->flush();
?>
--EXPECT--
