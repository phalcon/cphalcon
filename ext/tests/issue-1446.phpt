--TEST--
Phalcon\Cache\Backend\Apc::increment/decrement() are broken - https://github.com/phalcon/cphalcon/issues/1446
--SKIPIF--
<?php
include('skipif.inc');
if (!extension_loaded('apc')) {
	die('skip apc extension is not loaded');
}

if (ini_get('apc.enable_cli') != 1) {
	die('skip apc.enable_cli must be 1');
}
?>
--FILE--
<?php
$front = new \Phalcon\Cache\Frontend\Data(array('lifetime' => 600));
$cache = new \Phalcon\Cache\Backend\Apc($front, array('prefix' => 'prefix_'));

$cache->save('foo', 1);
$cache->increment('foo', 5);
echo $cache->get('foo'), PHP_EOL;
$cache->decrement('foo', 5);
echo $cache->get('foo'), PHP_EOL;
?>
--EXPECT--
6
1
