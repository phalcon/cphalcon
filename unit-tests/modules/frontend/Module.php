<?php

namespace Frontend;

class Module implements \Phalcon\Mvc\ModuleDefinitionInterface
{

	public function registerAutoloaders(\Phalcon\DiInterface $di=null)
	{

	}

	public function registerServices(\Phalcon\DiInterface $di)
	{
		$di->set('view', function() {
			$view = new \Phalcon\Mvc\View();
			$view->setViewsDir('unit-tests/modules/frontend/views/');
			return $view;
		});
	}

}
