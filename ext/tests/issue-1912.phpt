--TEST--
Security::checkHash returns true when using with a non-bcrypt hash
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$di->setShared('security', function () {
	$security = new \Phalcon\Security();
	$security->setWorkFactor(12);
	return $security;
});

var_dump($di->get('security')->checkHash('not jelly beans', 'cb7d86ece76c57eac5ed18420ca67ea0'));
?>
--EXPECT--
bool(false)
