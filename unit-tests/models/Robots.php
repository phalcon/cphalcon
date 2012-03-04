<?php

class Robots extends Phalcon_Model_Base {

	function initialize(){
		$this->hasMany('id', 'RobotsParts', 'robots_id');		
	}
	
}