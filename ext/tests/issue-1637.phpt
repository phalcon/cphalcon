--TEST--
Cannot Remove A Property From Phalcon Persistent Storage - https://github.com/phalcon/cphalcon/issues/1637
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--GET--
dummy=1
--FILE--
<?php

class Test extends \Phalcon\Di\Injectable
{
	public function test()
	{
		$this->persistent->destroy();
		$this->dump('anu');
		echo "Set\n";
		$this->persistent->anu = 'Aloha';
		$this->dump('anu');
		echo "Remove\n";
		$this->persistent->remove('anu');
		$this->dump('anu');
		echo "set\n";
		$this->persistent->anu = 'Aloha';
		$this->dump('anu');
		echo "assign null\n";
		$this->persistent->anu = null;
		$this->dump('anu');
		echo "set\n";
		$this->persistent->anu = 'Aloha';
		$this->dump('anu');
		echo "destroy\n";
		$this->persistent->destroy();
		$this->dump('anu');
	}

	public function dump($v)
	{
		echo $v, '=', var_dump($this->persistent->get($v));
		echo 'has(', $v, ')=', var_dump($this->persistent->has($v));
		echo 'isset(', $v, ')=', var_dump(isset($this->persistent->$v));
		echo PHP_EOL;
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$di['session'] = function() { $s = new \Phalcon\Session\Adapter\Files(array('uniqueId' => 'issue-1575')); $s->start(); return $s; };

$test = new Test();
$test->test();

?>
--EXPECT--
anu=NULL
has(anu)=bool(false)
isset(anu)=bool(false)

Set
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

Remove
anu=NULL
has(anu)=bool(false)
isset(anu)=bool(false)

set
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

assign null
anu=NULL
has(anu)=bool(true)
isset(anu)=bool(true)

set
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

destroy
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

Set
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

Remove
anu=NULL
has(anu)=bool(false)
isset(anu)=bool(false)

set
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

assign null
anu=NULL
has(anu)=bool(true)
isset(anu)=bool(true)

set
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

destroy
anu=string(5) "Aloha"
has(anu)=bool(true)
isset(anu)=bool(true)

