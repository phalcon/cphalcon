--TEST--
Segmentation fault in zim_Phalcon_Mvc_Collection_save
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

class EvilCollection extends \Phalcon\Mvc\Collection
{
	public function save()
	{
		unset($this->_dependencyInjector);
		return parent::save();
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$di->setShared('collectionManager', function() { return new \Phalcon\Mvc\Collection\Manager(); });
$c  = new \EvilCollection();
try {
	$c->save();
	assert(false);
}
catch (Exception $e) {
	assert(true);
}
?>
--EXPECT--
