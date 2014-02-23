--TEST--
Trying to free someone else's memory frame in zim_Phalcon_Http_Response_Headers_send() - https://github.com/phalcon/cphalcon/issues/2081
--SKIPIF--
<?php include('skipif.inc'); ?>
--GET--
dummy=1
--FILE--
<?php

class IndexController extends \Phalcon\Mvc\Controller
{
	public function indexAction()
	{
		$this->response->redirect('http://www.google.com/');
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$di['view'] = function() { return new \Phalcon\Mvc\View(); };
$app = new \Phalcon\Mvc\Application($di);
$app->handle();
?>
--EXPECT--
