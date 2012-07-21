<?php

class Subscriptores extends Phalcon\Model\Base {

	public function validation(){
		$this->validate('Email', array(
			'field' => 'email'
		));
		$this->validate('ExclusionIn', array(
			'field' => 'status',
			'domain' => array('X', 'Z')
		));
		$this->validate('InclusionIn', array(
			'field' => 'status',
			'domain' => array('P', 'I', 'w')
		));
		$this->validate('Uniqueness', array(
			'field' => 'email'
		));
		$this->validate('Regex', array(
			'field' => 'status',
			'pattern' => '/[A-Z]/'
		));
		if($this->validationHasFailed()==true){
			return false;
		}
	}

}
