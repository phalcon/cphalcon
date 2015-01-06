--TEST--
Phalcon\Config::merge does not work with derived classes - https://github.com/phalcon/cphalcon/issues/1024
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$config1 = new \Phalcon\Config\Adapter\Ini(__DIR__ . '/config/1024-a.ini');
$config2 = new \Phalcon\Config\Adapter\Ini(__DIR__ . '/config/1024-b.ini');
$config1->merge($config2);
print_r($config1->toArray());
?>
--EXPECT--
Array
(
    [a] => Array
        (
            [a_1] => 1
            [a_2] => 1
        )

)
