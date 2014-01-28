--TEST--
Phalcon\Registry - https://github.com/phalcon/cphalcon/pull/1935
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$registry = new \Phalcon\Registry();
$registry['a'] = 1;
$registry->b   = 2;
assert($registry->a === $registry['a'] && $registry->a === 1);
assert($registry->b === $registry['b'] && $registry->b === 2);
assert(isset($registry->a));
assert(isset($registry['a']));
assert(!isset($registry->c));
assert(!isset($registry['c']));
$registry['c'] = 3;
assert(count($registry) == 3);
unset($registry->b);
unset($registry['c']);
assert(!isset($registry->b));
assert(!isset($registry['b']));

foreach ($registry as $key => $value) {
	assert($key === 'a');
	assert($value === 1);
}

$s = serialize($registry);
$copy = unserialize($s);

assert($registry == $copy);

?>
--EXPECT--
