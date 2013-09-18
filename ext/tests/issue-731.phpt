--TEST--
Possibly Incorrect Behavior of Phalcon\Config::merge() - https://github.com/phalcon/cphalcon/issues/731
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$a = new \Phalcon\Config(array('aaa' => array('b' => 2, 'c' => 3)));
$b = new \Phalcon\Config(array('aaa' => array('a' => 10, 'c' => 30, 'd' => 40)));
$c = array('aaa' => array('b' => 2, 'c' => 30, 'a' => 10, 'd' => 40));
$a->merge($b);
print_r($a->toArray());
print_r($c);
echo PHP_EOL;

$a = new \Phalcon\Config(array('aab' => (object)array('n' => 'm')));
$b = new \Phalcon\Config(array('aab' => array('x' => 'y')));
$c = array('aab' => array('x' => 'y'));
$a->merge($b);
print_r($a->toArray());
print_r($c);
echo PHP_EOL;

$a = new \Phalcon\Config(array('ab' => array('b' => 1, 'c' => 2)));
$b = new \Phalcon\Config(array('ab' => array(0 => -10, 'c' => 20, 'd' => 30)));
$c = array('ab' => array(0 => -10, 'c' => 2, 'd' => 30, 'b' => 1));
$b->merge($a);
print_r($a->toArray());
print_r($c);
echo PHP_EOL;

$a = new \Phalcon\Config(array('ac' => array('b' => 1, 'c' => 2)));
$b = new \Phalcon\Config(array('ac' => array(0 => -10, 'c' => 20, 'd' => 30)));
$c = array('ac' => array(0 => -10, 'c' => 20, 'd' => 30, 'b' => 1));
$a->merge($b);
print_r($a->toArray());
print_r($c);
echo PHP_EOL;

$a = new \Phalcon\Config(array('ad' => array(0 => 1, 1 => 2, 2 => 3)));
$b = new \Phalcon\Config(array('ad' => array(1 => 20, 3 => 40)));
$c = array('ad' => array(0 => 1, 1 => 20, 2 => 3, 3 => 40));
$a->merge($b);
print_r($a->toArray());
print_r($c);
echo PHP_EOL;
?>
--EXPECT--
Array
(
    [aaa] => Array
        (
            [b] => 2
            [c] => 30
            [a] => 10
            [d] => 40
        )

)
Array
(
    [aaa] => Array
        (
            [b] => 2
            [c] => 30
            [a] => 10
            [d] => 40
        )

)

Array
(
    [aab] => Array
        (
            [x] => y
        )

)
Array
(
    [aab] => Array
        (
            [x] => y
        )

)

Array
(
    [ab] => Array
        (
            [b] => 1
            [c] => 2
        )

)
Array
(
    [ab] => Array
        (
            [0] => -10
            [c] => 2
            [d] => 30
            [b] => 1
        )

)

Array
(
    [ac] => Array
        (
            [b] => 1
            [c] => 20
            [0] => -10
            [d] => 30
        )

)
Array
(
    [ac] => Array
        (
            [0] => -10
            [c] => 20
            [d] => 30
            [b] => 1
        )

)

Array
(
    [ad] => Array
        (
            [0] => 1
            [1] => 20
            [2] => 3
            [3] => 40
        )

)
Array
(
    [ad] => Array
        (
            [0] => 1
            [1] => 20
            [2] => 3
            [3] => 40
        )

)

