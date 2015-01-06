--TEST--
Is storing objects in cache supported? - https://github.com/phalcon/cphalcon/issues/980
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$a = new \Phalcon\Config(array('aaa' => array('b' => 2, 'c' => 3)));
$s = serialize($a);
$b = unserialize($s);
print_r($a);
print_r($b);
?>
--EXPECT--
Phalcon\Config Object
(
    [aaa] => Phalcon\Config Object
        (
            [b] => 2
            [c] => 3
        )

)
Phalcon\Config Object
(
    [aaa] => Phalcon\Config Object
        (
            [b] => 2
            [c] => 3
        )

)
