<?php

class Parts extends Phalcon_Model_Base {

	function initialize(){
		$this->hasMany('id', 'RobotsParts', 'parts_id');
	}
	
}