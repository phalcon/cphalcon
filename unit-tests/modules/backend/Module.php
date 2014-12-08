<?php

namespace Backend;

class Module implements \Phalcon\Mvc\ModuleDefinitionInterface
{
	public $initialized = false;
	public $servicesRegistered = false;

	public function registerAutoloaders(\Phalcon\DiInterface $di=null)
	{
		// Creates the autoloader
		$loader = new \Phalcon\Loader();

		$loader->registerNamespaces(array(
			'Backend\Controllers' => 'unit-tests/modules/backend/controllers/'
		));

		$loader->register();

		$di->set('backendLoader', $loader);
	}

	public function registerServices(\Phalcon\DiInterface $di)
	{
		$di->set('view', function() {
			$view = new \Phalcon\Mvc\View();
			$view->setViewsDir('unit-tests/modules/backend/views/');
			return $view;
		});

		$this->servicesRegistered = true;
	}

	public function initialize($di)
	{
		$this->initialized = true;
	}
}
