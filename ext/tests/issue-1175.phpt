--TEST--
Use recommended reason phrases for redirect - https://github.com/phalcon/cphalcon/issues/1175
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php
$di = new \Phalcon\DI\FactoryDefault();
$response = new \Phalcon\Http\Response();
$response->setDI($di);

$response->resetHeaders();
$response->redirect("some/local/uri");
$h = $response->getHeaders();
echo $h->get('Status'), PHP_EOL;

$response->resetHeaders();
$response->redirect("http://google.com", true);
$h = $response->getHeaders();
echo $h->get('Status'), PHP_EOL;

$response->resetHeaders();
$response->redirect("http://google.com", true, 301);
$h = $response->getHeaders();
echo $h->get('Status'), PHP_EOL;

for ($i=300; $i<310; ++$i) {
	$response->resetHeaders();
	$response->redirect("http://google.com", true, $i);
	$h = $response->getHeaders();
	echo $h->get('Status'), PHP_EOL;
}
?>
--EXPECT--
302 Found
302 Found
301 Moved Permanently
300 Multiple Choices
301 Moved Permanently
302 Found
303 See Other
304 Not Modified
305 Use Proxy
306 Switch Proxy
307 Temporary Redirect
308 Permanent Redirect
309 Redirect
