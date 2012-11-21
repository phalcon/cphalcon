<?php

use Phalcon\Mvc\Model\Validator\PresenceOf as PresenceOfValidator;
use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
use Phalcon\Mvc\Model\Validator\InclusionIn as InclusionInValidator;
use Phalcon\Mvc\Model\Validator\Uniqueness as UniquenessValidator;
use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;

use Phalcon\Mvc\Model\Message as Message;

class Subscriptores extends Phalcon\Mvc\Model
{

	public function beforeValidation()
	{
		if ($this->email == 'marina@hotmail.com') {
			$this->appendMessage(new Message('Sorry Marina, but you are not allowed here'));
			return false;
		}
	}

	public function beforeDelete()
	{
		if ($this->email == 'fuego@hotmail.com') {
			$this->appendMessage(new Message('Sorry this cannot be deleted'));
			return false;
		}
	}

	public function validation()
	{

		$this->validate(new PresenceOfValidator(array(
			'field' => 'created_at'
		)));

		$this->validate(new StringLengthValidator(array(
			'field' => 'email',
			'min' => '7',
			'max' => '50'
		)));

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
