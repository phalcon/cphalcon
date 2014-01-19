<?php

class Test4Controller extends Phalcon\Mvc\Controller
{

	public function requestAction()
	{
		return $this->request->getPost('email', 'email');
	}

	public function viewAction()
	{
		return $this->view->setParamToView('born', 'this');
	}

}