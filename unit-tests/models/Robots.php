<?php

class Robots extends Phalcon\Model\Base {

	function initialize(){
		$this->hasMany('id', 'RobotsParts', 'robots_id', array(
			'foreignKey' => true
		));
	}

}