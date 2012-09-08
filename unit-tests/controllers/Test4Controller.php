<?php

class Test4Controller extends Phalcon_Controller {

	public function requestAction(){
		return $this->request->getPost('email', 'email');
	}

	public function viewAction(){
		return $this->view->setParamToView('born', 'this');
	}

	public function modelAction(){
		return $this->Personas->find("nombres LIKE '%FELIPE%'");
	}

}