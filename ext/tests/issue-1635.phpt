--TEST--
Safe serialization/unserialization of Phalcon\Beanstalk\Queue - https://github.com/phalcon/cphalcon/pull/1635
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class Test extends \Phalcon\Queue\Beanstalk
{
	public function getParams()
	{
		return $this->_parameters;
	}

	public function getConnection()
	{
		return $this->_connection;
	}

	public function setParams($v)
	{
		$this->_parameters = $v;
	}

	public function setConnection($v)
	{
		$this->_connection = $v;
	}
}

$x = new \Test(array('host' => 127, 'port' => '11300'));
var_dump($x->getParams());

$x->setConnection(123.0);
assert($x->getConnection() === 123.0);
var_export(serialize($x));
echo PHP_EOL;

$s = 'O:4:"Test":2:{s:14:"' . "\0" . '*' . "\0" . '_connection";d:123;s:14:"' . "\0" . '*' . "\0" . '_parameters";a:2:{s:4:"host";s:3:"127";s:4:"port";i:11300;}}';
$x = unserialize($s);
var_dump($x->getConnection());

$samples = array(
	'O:4:"Test":1:{s:14:"' . "\0" . '*' . "\0" . '_parameters";a:2:{s:4:"Host";s:3:"127";s:4:"port";i:11300;}}',
	'O:4:"Test":1:{s:14:"' . "\0" . '*' . "\0" . '_parameters";a:2:{s:4:"host";s:3:"127";s:4:"Port";i:11300;}}',
	'O:4:"Test":1:{s:14:"' . "\0" . '*' . "\0" . '_parameters";a:2:{s:4:"host";i:127;s:4:"port";i:11300;}}',
	'O:4:"Test":1:{s:14:"' . "\0" . '*' . "\0" . '_parameters";a:2:{s:4:"host";s:3:"127";s:4:"port";s:5:"11300";}}',
);

foreach ($samples as $sample) {
	try {
		unserialize($sample);
		assert(false);
	}
	catch (\Phalcon\Exception $e) {
		echo $e->getMessage(), PHP_EOL;
	}
}

?>
--EXPECT--
array(2) {
  ["host"]=>
  string(3) "127"
  ["port"]=>
  int(11300)
}
'O:4:"Test":1:{s:14:"' . "\0" . '*' . "\0" . '_parameters";a:2:{s:4:"host";s:3:"127";s:4:"port";i:11300;}}'
NULL
Invalid serialization data
Invalid serialization data
Invalid serialization data
Invalid serialization data
