--TEST--
Memory corruption due to a bug in Phalcon\Cache\Backend\Memory::increment/decrement() - https://github.com/phalcon/cphalcon/issues/1451
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$front = new \Phalcon\Cache\Frontend\None();
$cache = new \Phalcon\Cache\Backend\Memory($front);
$cache->save('var', 1);
$cache->increment('var');
echo $cache->get('var'), PHP_EOL;
$cache->decrement('var');
echo $cache->get('var'), PHP_EOL;
?>
--EXPECT--
2
1
