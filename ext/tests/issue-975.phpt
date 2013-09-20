--TEST--
Make Phalcon\Http\Cookie less depend on session - https://github.com/phalcon/cphalcon/pull/875
--SKIPIF--
<?php include('skipif.inc');
--FILE--
<?php
$di = new \Phalcon\DI();
$di->set('cookies', function () {
	$cookies = new \Phalcon\Http\Response\Cookies();
	$cookies->useEncryption(false);
	return $cookies;
});

$di->set('response', function() { return new \Phalcon\Http\Response(); });
$di->getShared('cookies')->set('gift_order', '2221dddd', time()+86400, '/');
$di->getShared('response')->send();
?>
--EXPECT--
