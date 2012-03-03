<?php

class Test2Controller extends Phalcon_Controller {

	public function indexAction(){

	}

	public function otherAction(){

	}

	public function anotherAction(){
		return 100;
	}

	public function anotherTwoAction($a, $b){
		return $a+$b;
	}

	public function anotherThreeAction(){
		return $this->_forward('test2/anotherfour');
	}

	public function anotherFourAction(){
		return 120;
	}

}