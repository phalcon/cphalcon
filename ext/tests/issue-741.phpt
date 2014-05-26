--TEST--
Segmentation fault when calling Phalcon\Validation\Message\Group::offsetSet() with a non-object - https://github.com/phalcon/cphalcon/issues/741
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$group = new \Phalcon\Validation\Message\Group;
try {
	$group[0] = 'invalid';
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}

try {
	$group->appendMessage('invalid');
}
catch (Exception $e) {
	echo $e->getMessage(), PHP_EOL;
}
?>
--EXPECT--
Unexpected value type: expected object of type Phalcon\Validation\Message, string given
Unexpected value type: expected object implementing Phalcon\Validation\MessageInterface, string given
