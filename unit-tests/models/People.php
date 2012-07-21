<?php

class People extends Phalcon\Model\Base {

	public function initialize(){
		$this->setSource('personas');
	}

}