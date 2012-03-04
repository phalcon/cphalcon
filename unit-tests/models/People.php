<?php

class People extends Phalcon_Model_Base {

	public function initialize(){
		$this->setSource('personas');
	}

}