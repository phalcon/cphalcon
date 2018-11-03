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
		$validator = new Validation();

		$validator->add('creeA', new PresenceOfValidator(array(
			'message' => "La date de création est nécessaire"
		)));

		$validator->add('courrierElectronique', new EmailValidator(array(
			'field' => '',
			'message' => 'Le courrier électronique est invalide'
		)));

		$validator->add('statut', new ExclusionInValidator(array(
			'domain' => array('X', 'Z'),
			'message' => 'L\'état ne doit être "X" ou "Z"'
		)));

		$validator->add('statut', new InclusionInValidator(array(
			'domain' => array('P', 'I', 'w'),
			'message' => 'L\'état doit être "P", "I" ou "w"'
		)));

		$validator->add('courrierElectronique', new UniquenessValidator(array(
			'message' => 'Le courrier électronique doit être unique',
			'model' => $this
		)));

		$validator->add('statut', new RegexValidator(array(
			'pattern' => '/[A-Z]/',
			'message' => "L'état ne correspond pas à l'expression régulière"
		)));

		$validator->add('courrierElectronique', new StringLengthValidator(array(
			'min' => '7',
			'max' => '50',
			'messageMinimum' => "Le courrier électronique est trop court",
			'messageMaximum' => "Le courrier électronique est trop long"
		)));

		return $this->validate($validator);
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
