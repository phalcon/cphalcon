--TEST--
Memory corruption due to a bug in Phalcon\Cache\Backend\File::increment/decrement() - https://github.com/phalcon/cphalcon/issues/1457
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$front = new \Phalcon\Cache\Frontend\Data(array('lifetime' => 600));
$cache = new \Phalcon\Cache\Backend\File($front, array('cacheDir' => __DIR__ . '/cache/'));
$cache->save('var', 1);
$cache->increment('var');
echo $cache->get('var'), PHP_EOL;
$cache->decrement('var');
echo $cache->get('var'), PHP_EOL;
?>
--EXPECT--
2
1
--CLEAN--
<?php unlink(__DIR__ . '/cache/var'); ?>