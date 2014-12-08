<?php

namespace Frontend\Controllers;

class IndexController extends \Phalcon\Mvc\Controller
{

	public function indexAction()
	{

	}

	public function forwardAction()
	{
		return $this->dispatcher->forward(array(
			'module' => 'backend',
			'namespace' => 'Backend\\Controllers\\',
			'controller' => 'login',
			'action' => 'index'
		));
	}

}