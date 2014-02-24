--TEST--
Array to string conversion in Phalcon\Http\Response::redirect() - https://github.com/phalcon/cphalcon/issues/2071
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI();
$di['url'] = function()
{
	$url = new \Phalcon\Mvc\Url();
	$url->setBaseUri('/');
	return $url;
};

$router = new \Phalcon\Mvc\Router(false);
$router->add('/test/{id:\d}')->setName('test');

$di['router'] = $router;

$response = new \Phalcon\Http\Response();
$response->setDI($di);
$response->redirect(array('for' => 'test', 'id' => 5));

var_dump($response->getHeaders()->toArray());
?>
--EXPECT--
array(3) {
  ["HTTP/1.1 302 Found"]=>
  NULL
  ["Status"]=>
  string(9) "302 Found"
  ["Location"]=>
  string(7) "/test/5"
}
