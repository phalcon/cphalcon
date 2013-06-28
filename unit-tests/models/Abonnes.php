<?php

use Phalcon\Mvc\Model\Validator\PresenceOf as PresenceOfValidator;
use Phalcon\Mvc\Model\Validator\Email as EmailValidator;
use Phalcon\Mvc\Model\Validator\ExclusionIn as ExclusionInValidator;
use Phalcon\Mvc\Model\Validator\InclusionIn as InclusionInValidator;
use Phalcon\Mvc\Model\Validator\Uniqueness as UniquenessValidator;
use Phalcon\Mvc\Model\Validator\Regex as RegexValidator;
use Phalcon\Mvc\Model\Validator\StringLength as StringLengthValidator;

use Phalcon\Mvc\Model\Message as Message;

/**
 * Abonnes
 *
 * Abonnes is subscriptors in french
 */
class Abonnes extends Phalcon\Mvc\Model
{

	public function getSource()
	{
		return 'subscriptores';
	}

	public function beforeValidation()
	{
		if ($this->courrierElectronique == 'marina@hotmail.com') {
			$this->appendMessage(new Message('Désolé Marina, mais vous n\'êtes pas autorisé ici'));
			return false;
		}
	}

	public function beforeDelete()
	{
		if ($this->courrierElectronique == 'fuego@hotmail.com') {
			//Sorry this cannot be deleted
			$this->appendMessage(new Message('Désolé, ce ne peut pas être supprimé'));
			return false;
		}
	}

	public function validation()
	{

		$this->validate(new PresenceOfValidator(array(
			'field' => 'creeA',
			'message' => "La date de création est nécessaire"
		)));

		$this->validate(new EmailValidator(array(
			'field' => 'courrierElectronique',
			'message' => 'Le courrier électronique est invalide'
		)));

		$this->validate(new ExclusionInValidator(array(
			'field' => 'statut',
			'domain' => array('X', 'Z'),
			'message' => 'L\'état ne doit être "X" ou "Z"'
		)));

		$this->validate(new InclusionInValidator(array(
			'field' => 'statut',
			'domain' => array('P', 'I', 'w'),
			'message' => 'L\'état doit être "P", "I" ou "w"'
		)));

		$this->validate(new UniquenessValidator(array(
			'field' => 'courrierElectronique',
			'message' => 'Le courrier électronique doit être unique'
		)));

		$this->validate(new RegexValidator(array(
			'field' => 'statut',
			'pattern' => '/[A-Z]/',
			'message' => "L'état ne correspond pas à l'expression régulière"
		)));

		$this->validate(new StringLengthValidator(array(
			'field' => 'courrierElectronique',
			'min' => '7',
			'max' => '50',
			'messageMinimum' => "Le courrier électronique est trop court",
			'messageMaximum' => "Le courrier électronique est trop long"
		)));

		if ($this->validationHasFailed() == true) {
			return false;
		}
	}

	public function columnMap()
	{
		return array(
			'id' => 'code',
			'email' => 'courrierElectronique',
			'created_at' => 'creeA',
			'status' => 'statut',
		);
	}

}
