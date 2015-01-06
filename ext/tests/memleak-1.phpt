--TEST--
Memory leak in Phalcon\Translate\Adapter\NativeArray::query()
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$options = array(
	'content' => array(
		'Hello!'                         => 'Привет!',
		'Hello %fname% %mname% %lname%!' => 'Привет, %fname% %mname% %lname%!',
	),
);

$t = new \Phalcon\Translate\Adapter\NativeArray($options);
$t->_('Hello %fname% %mname% %lname%!', array('fname' => 'John', 'lname' => 'Doe', 'mname' => 'D.'));
?>
--EXPECT--
