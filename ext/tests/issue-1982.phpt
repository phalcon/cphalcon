--TEST--
Crashes in multimodule applications - https://github.com/phalcon/cphalcon/pull/1982
--SKIPIF--
<?php include('skipif.inc'); ?>
--FILE--
<?php

if (!defined('NEED_MODULE')) :

class IndexController
{
	public function indexAction()
	{
	}
}

$di = new \Phalcon\DI\FactoryDefault();
$di['view'] = function() { return new Phalcon\Mvc\View(); };
$di['router']->setDefaultModule('frontend')->notFound(array("controller" => "index", "action" => "index"));

define('NEED_MODULE', 1);
$application = new \Phalcon\Mvc\Application($di);
$application->registerModules(
	array(
		'frontend' => array('className' => 'Module', 'path' => __FILE__),
	)
);
echo $application->handle()->getContent();

else :

class Module
{
	public function registerAutoloaders()
	{
	}

	public function registerServices()
	{
	}
}

endif;
?>
--EXPECT--
