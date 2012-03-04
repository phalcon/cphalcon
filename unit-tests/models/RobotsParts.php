<?php

class RobotsParts extends Phalcon_Model_Base {

	function initialize(){
		$this->belongsTo('parts_id', 'Parts', 'id');
		$this->belongsTo('robots_id', 'Robots', 'id');
	}
	
}