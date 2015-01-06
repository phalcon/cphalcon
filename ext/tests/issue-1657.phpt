--TEST--
Use native iterators for Phalcon\Validation\Message\Group - https://github.com/phalcon/cphalcon/pull/1657
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class MyGroup extends \Phalcon\Validation\Message\Group
{
	public function rewind()
	{
		echo __METHOD__, PHP_EOL;
		return parent::rewind();
	}

	public function valid()
	{
		echo __METHOD__, PHP_EOL;
		return parent::valid();
	}

	public function current()
	{
		echo __METHOD__, PHP_EOL;
		return parent::current();
	}

	public function next()
	{
		echo __METHOD__, PHP_EOL;
		return parent::next();
	}
}

$messages = array(
	new \Phalcon\Validation\Message("Message 1"),
	new \Phalcon\Validation\Message("Message 2"),
	new \Phalcon\Validation\Message("Message 3"),
);

$group = new \Phalcon\Validation\Message\Group($messages);
// Native Iterator Interface is used here
foreach ($group as $msg) {
	var_dump($msg->getMessage());
}

// Class methods are used here
$group->rewind();
while ($group->valid()) {
	$msg = $group->current();
	var_dump($msg->getMessage());
	$group->next();
}

// Inherited class - userspace methods are invoked
$group = new \MyGroup($messages);
foreach ($group as $msg) {
	var_dump($msg->getMessage());
}

// Inherited class - userspace methods are invoked
$group->rewind();
while ($group->valid()) {
	$msg = $group->current();
	var_dump($msg->getMessage());
	$group->next();
}
?>
--EXPECT--
string(9) "Message 1"
string(9) "Message 2"
string(9) "Message 3"
string(9) "Message 1"
string(9) "Message 2"
string(9) "Message 3"
MyGroup::rewind
MyGroup::valid
MyGroup::current
string(9) "Message 1"
MyGroup::next
MyGroup::valid
MyGroup::current
string(9) "Message 2"
MyGroup::next
MyGroup::valid
MyGroup::current
string(9) "Message 3"
MyGroup::next
MyGroup::valid
MyGroup::rewind
MyGroup::valid
MyGroup::current
string(9) "Message 1"
MyGroup::next
MyGroup::valid
MyGroup::current
string(9) "Message 2"
MyGroup::next
MyGroup::valid
MyGroup::current
string(9) "Message 3"
MyGroup::next
MyGroup::valid
