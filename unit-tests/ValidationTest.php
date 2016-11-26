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
		$validation = new Phalcon\Validation();

		$validation->add('number', new CreditCard());

		$messages = $validation->validate(['number' => $number]);

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
		$validation = new Phalcon\Validation();

		$validation->add('number', new CreditCard());

		$messages = $validation->validate(['number' => $number]);

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

	public function testValidationStringLengthMinimum()
	{
		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'min' => 3
		)));

		$messages = $validation->validate([]);

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

		$messages = $validation->validate(['name' => 'p']);

		$this->assertEquals($expectedMessages, $messages);

		$messages = $validation->validate(['name' => 'peter']);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMinimumCustomMessage()
	{
		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'min' => 3,
			'messageMinimum' => 'The message is too short'
		)));

		$messages = $validation->validate([]);

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

		$messages = $validation->validate(['name' => 'p']);

		$this->assertEquals($expectedMessages, $messages);

		$messages = $validation->validate(['name' => 'peter']);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMaximum()
	{
		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'max' => 4
		)));

		$messages = $validation->validate(['name' => 'Johannes']);

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

		$messages = $validation->validate(['name' => 'a']);

		$this->assertEquals(count($messages), 0);
	}

	public function testValidationStringLengthMaximumCustomMessage()
	{
		$validation = new Phalcon\Validation();

		$validation->add('name', new StringLength(array(
			'max' => 4,
			'messageMaximum' => 'The message is too long'
		)));

		$messages = $validation->validate(['name' => 'Johannes']);

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

		$messages = $validation->validate(['name' => 'pet']);

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

		$messages = $validation->validate([]);

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

		$messages = $validation->validate([]);

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
