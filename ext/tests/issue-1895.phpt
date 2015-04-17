--TEST--
'Indirect modification of overloaded property' notice in Phalcon\Session\Bag - https://github.com/phalcon/cphalcon/issues/1895
--SKIPIF--
<?php include('skipif.inc'); ?>
<?php if (PHP_SAPI == 'cli') die ('skip CGI SAPI is required'); ?>
--GET--
dummy=1
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$di['session']->start();
$namespace = new \Phalcon\Session\Bag('test');
$namespace->{'prop1'}['prop2'] = 'my value';
var_dump($namespace->{'prop1'});
$namespace['prop3']['prop4'] = 'your value';
var_dump($namespace['prop3']);
var_dump(count($namespace));
foreach ($namespace as $key => $value) {
	echo $key, ' => ';
	var_dump($value);
}
?>
--EXPECT--
array(1) {
  ["prop2"]=>
  string(8) "my value"
}
array(1) {
  ["prop4"]=>
  string(10) "your value"
}
int(2)
prop1 => array(1) {
  ["prop2"]=>
  string(8) "my value"
}
prop3 => array(1) {
  ["prop4"]=>
  string(10) "your value"
}
