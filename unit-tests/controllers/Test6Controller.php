<?php

class Test6Controller extends Phalcon_Controller {

	public function beforeDispatch(){		
		return false;
	}

	public function indexAction(){
		return 'index';
	}

}