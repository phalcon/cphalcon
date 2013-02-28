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
	Phalcon\Validation\Validator\Regex,
	Phalcon\Validation\Validator\Email;

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

		$this->assertEquals(array(), $messages);
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

		$this->assertEquals(array(), $messages);
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

		$this->assertEquals(array(), $messages);
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

		$this->assertEquals(array(), $messages);
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

		$this->assertEquals(array(), $messages);
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

		$this->assertEquals(array(), $messages);
	}

	public function testValidationMixed()
	{

		$validation = new Phalcon\Validation();

		$validation->add('name', new PresenceOf(array(
			'message' => ''
		)));

		$messages = $validation->validate($_POST);


	}

}
