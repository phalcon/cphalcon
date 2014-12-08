<?php

namespace Objects;

class Module implements \Phalcon\Mvc\ModuleDefinitionInterface
{

	public function registerAutoloaders(\Phalcon\DiInterface $di=null)
	{
		$loader = new \Phalcon\Loader();
		$loader->registerNamespaces(array(
			'Objects\Controllers' => __DIR__ . '/controllers/'
		));
		$loader->register();

		$di->set('objectsLoader', $loader);
	}

	public function registerServices(\Phalcon\DiInterface $di)
	{
		$di->set('view', function() {
			$view = new \Phalcon\Mvc\View();
			$view->setViewsDir(__DIR__ . '/views/');
			return $view;
		});
	}

	public function initialize(\Phalcon\DiInterface $di)
	{
		$router = $di->get('router');

		$router->add('/objects', array(
			'controller' => 'index',
			'module' => 'objects',
			'namespace' => 'Objects\Controllers\\'
		));
	}

}
