<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
	+------------------------------------------------------------------------+
	| This source file is subject to the New BSD License that is bundled     |
	| with this package in the file docs/LICENSE.txt.                        |
	|                                                                        |
	| If you did not receive a copy of the license and are unable to         |
	| obtain it through the world-wide-web, please send an email             |
	| to license@phalconphp.com so we can send you a copy immediately.       |
	+------------------------------------------------------------------------+
	| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
	|          Eduar Carvajal <eduar@phalconphp.com>                         |
	+------------------------------------------------------------------------+
*/

use Phalcon\Validation\Validator\PresenceOf,
	Phalcon\Validation\Validator\Identical,
	Phalcon\Validation\Validator\Confirmation,
	Phalcon\Validation\Validator\Regex,
	Phalcon\Validation\Validator\InclusionIn,
	Phalcon\Validation\Validator\ExclusionIn,
	Phalcon\Validation\Validator\StringLength,
	Phalcon\Validation\Validator\Email,
	Phalcon\Validation\Validator\Between,
	Phalcon\Validation\Validator\Url,
	Phalcon\Validation\Validator\CreditCard,
	Phalcon\Validation\Validator\Date;

class ValidationTest extends PHPUnit_Framework_TestCase
{
	public function testValidationIdentical()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new Identical(array(
			'accepted' => 'Peter'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Identical',
					'_message' => 'Field name does not have the expected value',
					'_field' => 'name',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'Peter');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function providerCreditCardNumberValid()
	{
		return array(
			array('378282246310005'), //amex
			array('4012888888881881'), //visa
			array('38520000023237'), //dinners
			array('5105105105105100'), //mastercard
			array('6011000990139424') //discover
		);
	}

	/**
	 * @dataProvider providerCreditCardNumberValid
	 */
	public function testValidationCreditCardValid($number)
	{
		$_POST = array('number' => $number);

		$validation = new Phalcon\Validation();

		$validation->add('number', new CreditCard());

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function providerCreditCardNumberInvalid()
	{
		return array(
			array('1203191201121221'),
			array('102030102320'),
			array('120120s201023'),
			array('20323200003230'),
			array('12010012')
		);
	}

	/**
	 * @dataProvider providerCreditCardNumberInvalid
	 */
	public function testValidationCreditCardInvalid($number)
	{
		$_POST = array('number' => $number);

		$validation = new Phalcon\Validation();

		$validation->add('number', new CreditCard());

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'CreditCard',
					'_message' => 'Field number is not valid for a credit card number',
					'_field' => 'number',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);
	}

	public function providerValidDates()
	{
		return array(
			array('2015-01-01', 'Y-m-d'),
			array('01-01-2015', 'd-m-Y'),
		);
	}

	/**
	 * @dataProvider providerValidDates
	 */
	public function testValidationDateValid($date, $format)
	{
		$validation = new Phalcon\Validation();

		$validation->add('date', new Date(array('format' => $format)));

		$messages = $validation->validate(array('date' => $date));

		$this->assertEquals(count($messages), 0);
	}

	public function providerInvalidDates()
	{
		return array(
			array('', 'Y-m-d'),
			array(false, 'Y-m-d'),
			array(null, 'Y-m-d'),
			array(new stdClass, 'Y-m-d'),
			array('2015-13-01', 'Y-m-d'),
			array('2015-01-32', 'Y-m-d'),
			array('2015-01', 'Y-m-d'),
			array('2015-01-01', 'd-m-Y'),
		);
	}

	/**
	 * @dataProvider providerInvalidDates
	 */
	public function testValidationDateInvalid($date, $format)
	{
		$validation = new Phalcon\Validation();

		$validation->add('date', new Date(array('format' => $format)));

		$messages = $validation->validate(array('date' => $date));

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Date',
					'_message' => 'Field date is not a valid date',
					'_field' => 'date',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);
	}

	public function testValidationIdenticalCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new Identical(array(
			'accepted' => 'Peter',
			'message' => 'The name must be peter'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Identical',
					'_message' => 'The name must be peter',
					'_field' => 'name',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'Peter');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationRegex()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('car_plate', new Regex(array(
			'pattern' => '/[A-Z]{3}\-[0-9]{3}/'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Regex',
					'_message' => 'Field car_plate does not match the required format',
					'_field' => 'car_plate',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('car_plate' => 'XYZ-123');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationRegexCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('car_plate', new Regex(array(
			'pattern' => '/[A-Z]{3}\-[0-9]{3}/',
			'message' => 'The car plate is not valid'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Regex',
					'_message' => 'The car plate is not valid',
					'_field' => 'car_plate',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('car_plate' => 'XYZ-123');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationEmail()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('email', new Email());

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Email',
					'_message' => 'Field email must be an email address',
					'_field' => 'email',
					'_code' => 0,
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('email' => 'x=1');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('email' => 'x.x@hotmail.com');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationEmailCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('email', new Email(array(
			'message' => 'The email is not valid'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Email',
					'_message' => 'The email is not valid',
					'_field' => 'email',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('email' => 'x=1');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('email' => 'x.x@hotmail.com');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationInclusionIn()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('status', new InclusionIn(array(
			'domain' => array('A', 'I')
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'InclusionIn',
					'_message' => 'Field status must be a part of list: A, I',
					'_field' => 'status',
					'_code' => 0,
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'X');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'A');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationInclusionInCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('status', new InclusionIn(array(
			'message' => 'The status must be A=Active or I=Inactive',
			'domain' => array('A', 'I')
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'InclusionIn',
					'_message' => 'The status must be A=Active or I=Inactive',
					'_field' => 'status',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'x=1');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'A');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationExclusionIn()
	{
		$_POST = array('status' => 'A');

		$validation = new Phalcon\Validation();

		$validation->add('status', new ExclusionIn(array(
			'domain' => array('A', 'I')
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'ExclusionIn',
					'_message' => 'Field status must not be a part of list: A, I',
					'_field' => 'status',
					'_code' => 0,
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'A');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'X');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationExclusionInCustomMessage()
	{
		$_POST = array('status' => 'A');

		$validation = new Phalcon\Validation();

		$validation->add('status', new ExclusionIn(array(
			'message' => 'The status must not be A=Active or I=Inactive',
			'domain' => array('A', 'I')
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'ExclusionIn',
					'_message' => 'The status must not be A=Active or I=Inactive',
					'_field' => 'status',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'A');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('status' => 'X');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMinimum()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'min' => 3
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'TooShort',
					'_message' => 'Field name must be at least 3 characters long',
					'_field' => 'name',
					'_code' => 0,
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'p');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'peter');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMinimumCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'min' => 3,
			'messageMinimum' => 'The message is too short'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'TooShort',
					'_message' => 'The message is too short',
					'_field' => 'name',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'p');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'peter');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMaximum()
	{
		$_POST = array('name' => 'Johannes');

		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'max' => 4
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'TooLong',
					'_message' => 'Field name must not exceed 4 characters long',
					'_field' => 'name',
					'_code' => 0,
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'a');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMaximumCustomMessage()
	{
		$_POST = array('name' => 'Johannes');

		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'max' => 4,
			'messageMaximum' => 'The message is too long'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'TooLong',
					'_message' => 'The message is too long',
					'_field' => 'name',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'pet');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationBetween()
	{
		$_POST = array('price' => 5);

		$validation = new Phalcon\Validation();

		$validation->add('price', new Between(array(
			'minimum' => 1,
			'maximum' => 3
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Between',
					'_message' => 'Field price must be within the range of 1 to 3',
					'_field' => 'price',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array();

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('price' => 2);

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationBetweenCustomMessage()
	{
		$_POST = array('price' => 5);

		$validation = new Phalcon\Validation();

		$validation->add('price', new Between(array(
			'minimum' => 1,
			'maximum' => 3,
			'message' => 'The price must be between 1 and 3'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Between',
					'_message' => 'The price must be between 1 and 3',
					'_field' => 'price',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array();

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('price' => 2);

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationMixed()
	{

		$validation = new Phalcon\Validation();

		$validation
			->add('name', new PresenceOf(array(
				'message' => 'The name is required'
			)))
			->add('email', new PresenceOf(array(
				'message' => 'The email is required'
			)))
			->add('login', new PresenceOf(array(
				'message' => 'The login is required'
			)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 =>  Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The name is required',
					'_field' => 'name',
					'_code' => '0',
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The email is required',
					'_field' => 'email',
					'_code' => '0',
				)),
				2 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The login is required',
					'_field' => 'login',
					'_code' => '0',
				)),
			),
		));

		$this->assertEquals($messages, $expectedMessages);
	}

	public function testValidationCancelOnFail()
	{

		$validation = new Phalcon\Validation();

		$validation
			->add('name', new PresenceOf(array(
				'message' => 'The name is required'
			)))
			->add('email', new PresenceOf(array(
				'message' => 'The email is required',
				'cancelOnFail' => true
			)))
			->add('login', new PresenceOf(array(
				'message' => 'The login is required'
			)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 =>  Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The name is required',
					'_field' => 'name',
					'_code' => '0',
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The email is required',
					'_field' => 'email',
					'_code' => '0',
				))
			),
		));

		$this->assertEquals($messages, $expectedMessages);
	}

	public function testValidationFiltering()
	{

		$validation = new Phalcon\Validation();

		$validation->setDI(new Phalcon\DI\FactoryDefault());

		$validation
			->add('name', new PresenceOf(array(
				'message' => 'The name is required'
			)))
			->add('email', new PresenceOf(array(
				'message' => 'The email is required'
			)));

		$validation->setFilters('name', 'trim');
		$validation->setFilters('email', 'trim');

		$_POST = array('name' => '  ', 'email' => '    ');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 2);

		$filtered = $messages->filter('email');

		$expectedMessages = array(
			0 => Phalcon\Validation\Message::__set_state(array(
				'_type' => 'PresenceOf',
				'_message' => 'The email is required',
				'_field' => 'email',
				'_code' => '0',
			))
		);

		$this->assertEquals($filtered, $expectedMessages);

		$_POST = array();
	}

	public function testValidationUrl()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('url', new Url());

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
						'_type' => 'Url',
						'_message' => 'Field url must be a url',
						'_field' => 'url',
						'_code' => 0,
					))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('url' => 'x=1');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('url' => 'http://phalconphp.com');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationUrlCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('url', new Url(array(
			'message' => 'The url is not valid'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
						'_type' => 'Url',
						'_message' => 'The url is not valid',
						'_field' => 'url',
						'_code' => '0',
					))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('url' => 'x=1');

		$messages = $validation->validate($_POST);

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('url' => 'http://phalconphp.com');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationSetLabels()
	{
		$_POST = array('email' => '', 'firstname' => '');

		$validation = new Phalcon\Validation();

		$validation->add('email', new PresenceOf(array(
                            'message' => 'The :field is required'
		)));
		$validation->add('email', new Email(array(
                            'message' => 'The :field must be email',
                            'label' => 'E-mail'
		)));
		$validation->add('firstname', new PresenceOf(array(
                            'message' => 'The :field is required'
		)));
		$validation->add('firstname', new StringLength(array(
                            'min' => 4,
                            'messageMinimum' => 'The :field is too short'
		)));

		$validation->setLabels(array('firstname' => 'First name'));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The email is required',
					'_field' => 'email',
					'_code' => '0',
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Email',
					'_message' => 'The E-mail must be email',
					'_field' => 'email',
					'_code' => '0',
				)),
				2 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The First name is required',
					'_field' => 'firstname',
					'_code' => '0',
				)),
				3 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'TooShort',
					'_message' => 'The First name is too short',
					'_field' => 'firstname',
					'_code' => '0',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);
	}

	public function testGetDefaultValidationMessageShouldReturnEmptyStringIfNoneIsSet()
	{
		$validation = new \Phalcon\Validation();
		$this->assertEmpty($validation->getDefaultMessage('_notexistentvalidationmessage_'));
	}

	public function testOptionAllowEmpty()
	{
		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Confirmation',
					'_message' => 'Field password must be the same as password2',
					'_field' => 'password',
					'_code' => '0',
				)),
			)
		));

		// allowEmpty: true
		$validation = new Phalcon\Validation();
		$validation->add('password', new Confirmation(array(
			'allowEmpty' => true,
			'with'		 => 'password2'
		)));

		$this->assertEquals(count($validation->validate(array(
			'password'  => 'test123',
			'password2' => 'test123'
		))), 0);

		$this->assertEquals(count($validation->validate(array(
			'password'  => null,
			'password2' => 'test123'
		))), 0);
		// END

		// allowEmpty: false
		$validation = new Phalcon\Validation();
		$validation->add('password', new Confirmation(array(
			'allowEmpty' => false,
			'with'		 => 'password2'
		)));

		$this->assertEquals(count($validation->validate(array(
			'password'  => 'test123',
			'password2' => 'test123'
		))), 0);

		$messages = $validation->validate(array(
			'password'  => null,
			'password2' => 'test123'
		));

		$this->assertEquals(count($messages), 1);
		$this->assertEquals($messages, $expectedMessages);
		// END

		// allowEmpty: DEFAULT
		$validation = new Phalcon\Validation();
		$validation->add('password', new Confirmation(array(
			'with'		 => 'password2'
		)));

		$this->assertEquals(count($validation->validate(array(
			'password'  => 'test123',
			'password2' => 'test123'
		))), 0);

		$messages = $validation->validate(array(
			'password'  => null,
			'password2' => 'test123'
		));

		$this->assertEquals(count($messages), 1);
		$this->assertEquals($messages, $expectedMessages);
		// END
	}
}
