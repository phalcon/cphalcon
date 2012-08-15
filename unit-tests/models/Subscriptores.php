<?php

use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
use Phalcon\Mvc\Model\Validator\InclusionIn as InclusionInValidator;
use Phalcon\Mvc\Model\Validator\Uniqueness as UniquenessValidator;
use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;

class Subscriptores extends Phalcon\Mvc\Model
{

	public function validation()
	{
		$this->validate(new EmailValidator(array(
			'field' => 'email'
		)));
		$this->validate(new ExclusionInValidator(array(
			'field' => 'status',
			'domain' => array('X', 'Z')
		)));
		$this->validate(new InclusionInValidator(array(
			'field' => 'status',
			'domain' => array('P', 'I', 'w')
		)));
		$this->validate(new UniquenessValidator(array(
			'field' => 'email'
		)));
		$this->validate(new RegexValidator(array(
			'field' => 'status',
			'pattern' => '/[A-Z]/'
		)));
		if ($this->validationHasFailed() == true) {
			return false;
		}
	}

}
