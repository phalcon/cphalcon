<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
	Phalcon\Validation\Validator\Between;

class ValidationTest extends PHPUnit_Framework_TestCase
{

	public function testValidationGroup()
	{

		$message1 = new Phalcon\Validation\Message('This a message #1', 'field1', 'Type1');
		$message2 = new Phalcon\Validation\Message('This a message #2', 'field2', 'Type2');
		$message3 = new Phalcon\Validation\Message('This a message #3', 'field3', 'Type3');

		$messages = new Phalcon\Validation\Message\Group(array($message1, $message2));

		$this->assertEquals(count($messages), 2);
		$this->assertEquals($messages[0], $message1);
		$this->assertEquals($messages[1], $message2);

		$this->assertTrue(isset($messages[0]));
		$this->assertTrue(isset($messages[1]));

		$messages->appendMessage($message3);

		$this->assertEquals($messages[2], $message3);

		$number = 0;
		foreach ($messages as $position => $message) {
			$this->assertEquals($position, $number);
			$this->assertEquals($messages[$position]->getMessage(), $message->getMessage());
			$this->assertEquals($messages[$position]->getField(), $message->getField());
			$this->assertEquals($messages[$position]->getType(), $message->getType());
			$number++;
		}
		$this->assertEquals($number, 3);
	}

	public function testValidationPresenceOf()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new PresenceOf());

		$validation->add('last_name', new PresenceOf());

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'name is required',
					'_field' => 'name',
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'last_name is required',
					'_field' => 'last_name',
				)),
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST['last_name'] = 'Walter';

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'name is required',
					'_field' => 'name',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);
	}

	public function testValidationPresenceOfCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new PresenceOf(array(
			'message' => 'The name is required'
		)));

		$validation->add('last_name', new PresenceOf(array(
			'message' => 'The last name is required'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The name is required',
					'_field' => 'name',
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The last name is required',
					'_field' => 'last_name',
				)),
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST['last_name'] = 'Walter';

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The name is required',
					'_field' => 'name',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);
	}

	public function testValidationIdentical()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new Identical(array(
			'value' => 'Peter'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Identical',
					'_message' => 'name does not have the expected value',
					'_field' => 'name',
				))
			)
		));

		$this->assertEquals($expectedMessages, $messages);

		$_POST = array('name' => 'Peter');

		$messages = $validation->validate($_POST);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationIdenticalCustomMessage()
	{
		$_POST = array();

		$validation = new Phalcon\Validation();

		$validation->add('name', new Identical(array(
			'value' => 'Peter',
			'message' => 'The name must be peter'
		)));

		$messages = $validation->validate($_POST);

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Identical',
					'_message' => 'The name must be peter',
					'_field' => 'name',
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
					'_message' => 'Value of field \'car_plate\' doesn\'t match regular expression',
					'_field' => 'car_plate',
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
					'_message' => 'Value of field \'email\' must have a valid e-mail format',
					'_field' => 'email',
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
					'_message' => 'Value of field \'status\' must be part of list: A, I',
					'_field' => 'status',
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
					'_message' => 'Value of field \'status\' must not be part of list: A, I',
					'_field' => 'status',
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
					'_message' => 'Value of field \'name\' is less than the minimum 3 characters',
					'_field' => 'name',
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
					'_message' => 'Value of field \'name\' exceeds the maximum 4 characters',
					'_field' => 'name',
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
					'_message' => 'price is not between a valid range',
					'_field' => 'price',
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
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The email is required',
					'_field' => 'email',
				)),
				2 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The login is required',
					'_field' => 'login',
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
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The email is required',
					'_field' => 'email',
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

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 =>  Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The name is required',
					'_field' => 'name',
				)),
				1 => Phalcon\Validation\Message::__set_state(array(
					'_type' => 'PresenceOf',
					'_message' => 'The email is required',
					'_field' => 'email',
				))
			),
		));

		$this->assertEquals($messages, $expectedMessages);

		$_POST = array();
	}


	public function testIssue441()
	{
		$group = new Phalcon\Validation\Message\Group;
		try {
			$group[0] = 'invalid';
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}

		try {
			$group->appendMessage('invalid');
			$this->assertTrue(false);
		}
		catch (Exception $e) {
			$this->assertTrue(true);
		}
	}

}
