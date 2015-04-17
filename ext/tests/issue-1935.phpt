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


$registry->rewind();
while ($registry->valid()) {
	assert($registry->key() === 'a');
	assert($registry->current() === 1);
	$registry->next();
}

reset($registry);
while (list($key, $val) = each($registry)) {
	assert($key === 'a');
	assert($value === 1);
}

if (PHP_VERSION_ID >= 50304) {
	foreach ($registry as $key => &$value) {
		$value *= 10;
	}

	assert($registry->a === 10);
	unset($value);
}

$s = serialize($registry);
$copy = unserialize($s);

assert($registry == $copy);

$registry->registry = new \Phalcon\Registry();
gc_collect_cycles();
$registry->registry = null;
gc_collect_cycles();

$registry[0] = 1;
assert($registry->{'0'} === 1);
assert($registry->{0} === 1);
assert($registry->{0.0} === 1);

$registry->{1} = 2;
assert($registry->{'1'} === 2);
assert($registry->{1.0} === 2);
assert($registry[1] === 2);
assert($registry[1.0] === 2);
assert($registry['1'] === 2);

$registry->callback = function() { return 'string'; };
assert($registry->callback() === 'string');

$registry->callback = function($param) { return 'Hello, ' . $param; };
assert($registry->callback('world') === 'Hello, world');
assert($registry->__call('callback', array('world')) === 'Hello, world');
?>
--EXPECT--
