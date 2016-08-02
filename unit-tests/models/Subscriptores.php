<?php

use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf as PresenceOfValidator;
use Phalcon\Validation\Validator\Email as EmailValidator;
use Phalcon\Validation\Validator\ExclusionIn as ExclusionInValidator;
use Phalcon\Validation\Validator\InclusionIn as InclusionInValidator;
use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;
use Phalcon\Validation\Validator\Regex as RegexValidator;
use Phalcon\Validation\Validator\StringLength as StringLengthValidator;

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
		$validator = new Validation();

		$validator->add('created_at', new PresenceOfValidator());

		$validator->add('email', new StringLengthValidator(array(
			'min' => '7',
			'max' => '50'
		)));

		$validator->add('email', new EmailValidator());

		$validator->add('status', new ExclusionInValidator(array(
			'domain' => array('X', 'Z')
		)));

		$validator->add('status', new InclusionInValidator(array(
			'domain' => array('P', 'I', 'w')
		)));

		$validator->add('email', new UniquenessValidator(array(
			'model' => $this
		)));

		$validator->add('status', new RegexValidator(array(
			'pattern' => '/[A-Z]/'
		)));

		return $this->validate($validator);
	}

}
