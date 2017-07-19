<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
	+------------------------------------------------------------------------+
	| This source file is subject to the New BSD License that is bundled     |
	| with this package in the file LICENSE.txt.                             |
	|                                                                        |
	| If you did not receive a copy of the license and are unable to         |
	| obtain it through the world-wide-web, please send an email             |
	| to license@phalconphp.com so we can send you a copy immediately.       |
	+------------------------------------------------------------------------+
	| Authors: Andres Gutierrez <andres@phalconphp.com>                      |
	|          Eduar Carvajal <eduar@phalconphp.com>                         |
	+------------------------------------------------------------------------+
*/

use
	Phalcon\Forms\Form,
	Phalcon\Forms\Element\Text,
	Phalcon\Forms\Element\Select,
	Phalcon\Forms\Element\Radio,
	Phalcon\Validation\Validator\PresenceOf,
	Phalcon\Validation\Validator\StringLength,
	Phalcon\Validation\Validator\Regex,
	Phalcon\Validation\Message;

class ContactFormPublicProperties
{
	public $telephone = '+44 124 82122';
	public $address = 'Cr. 12 #12-82';
}

class ContactFormSettersGetters
{
	private $telephone = '+44 124 82122';

	private $address = 'Cr. 12 #12-82';

	public function getTelephone()
	{
		return $this->telephone;
	}

	public function getAddress()
	{
		return $this->address;
	}

	public function setTelephone($telephone)
	{
		$this->telephone = $telephone;
	}

	public function setAddress($address)
	{
		$this->address = $address;
	}
}

class FormsTest extends PHPUnit_Framework_TestCase
{

	public function setUp()
	{
		Phalcon\DI::reset();
		return new Phalcon\DI\FactoryDefault();
	}

	public function testFormElementRender()
	{

		$element1 = new Text("name");
		$element1->setAttributes(array('class' => 'big-input'));

		$element2 = new Radio('radio');
		$element2->setAttributes(array('value' => 0));

		$this->assertEquals('<input type="text" id="name" name="name" class="big-input" />', $element1->render());
		$this->assertEquals('<input type="text" id="name" name="name" class="big-input" />', (string) $element1);
		$this->assertEquals('<input type="radio" id="radio" name="radio" value="0" />', (string)$element2);
	}

	public function testFormRenderEntity()
	{
		//Second element
		$address = new Text('address');

		$address->addValidator(new PresenceOf(array(
			'message' => 'The address is required'
		)));

		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$form = new Form(new ContactFormPublicProperties());

		$form->add($address);
		$form->add($telephone);

		$this->assertEquals(
			$form->render('address'),
			'<input type="text" id="address" name="address" value="Cr. 12 #12-82" />'
		);

		$this->assertEquals(
			$form->render('telephone'),
			'<input type="text" id="telephone" name="telephone" value="+44 124 82122" />'
		);
	}

	public function testFormRenderEntityGetters()
	{
		//Second element
		$address = new Text('address');

		$address->addValidator(new PresenceOf(array(
			'message' => 'The address is required'
		)));

		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$form = new Form(new ContactFormSettersGetters());

		$form->add($address);
		$form->add($telephone);

		$this->assertEquals(
			$form->render('address'),
			'<input type="text" id="address" name="address" value="Cr. 12 #12-82" />'
		);

		$this->assertEquals(
			$form->render('telephone'),
			'<input type="text" id="telephone" name="telephone" value="+44 124 82122" />'
		);
	}

	public function testFormValidatorEntity()
	{
		//Second element
		$address = new Text('address');

		$address->addValidator(new PresenceOf(array(
			'message' => 'The address is required'
		)));

		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$form = new Form(new ContactFormPublicProperties());

		$form->add($address);
		$form->add($telephone);

		$this->assertTrue($form->isValid(array(
			'telephone' => '+44 124 82122',
			'address' => 'hello'
		)));
	}

	public function testFormValidatorEntityBind()
	{
		//Second element
		$address = new Text('address');

		$address->addValidator(new PresenceOf(array(
			'message' => 'The address is required'
		)));

		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$entity = new ContactFormPublicProperties();

		$form = new Form();

		$form->add($address);
		$form->add($telephone);

		$form->bind(array(
			'telephone' => '+44 123 45678',
			'address' => 'hello'
		), $entity);

		$this->assertTrue($form->isValid());

		$this->assertEquals($entity->telephone, '+44 123 45678');
		$this->assertEquals($entity->address, 'hello');
	}

	public function testFormValidatorEntityBindSetters()
	{
		//Second element
		$address = new Text('address');

		$address->addValidator(new PresenceOf(array(
			'message' => 'The address is required'
		)));

		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$entity = new ContactFormSettersGetters();

		$form = new Form();

		$form->add($address);
		$form->add($telephone);

		$form->bind(array(
			'telephone' => '+44 123 45678',
			'address' => 'hello'
		), $entity);

		$this->assertTrue($form->isValid());

		$this->assertEquals($entity->getTelephone(), '+44 123 45678');
		$this->assertEquals($entity->getAddress(), 'hello');
	}

	public function testCorrectlyAddOptionToSelectElementIfParameterIsAnArray()
	{
		$element = new Select('test-select');
		$element->addOption(array('key' => 'value'));

		$this->assertEquals(
			'<select id="test-select" name="test-select"><option value="key">value</option></select>',
			preg_replace('/[[:cntrl:]]/', '', $element->render())
		);
	}

	public function testCorrectlyAddOptionToSelectElementIfParameterIsAString()
	{
		$element = new Select('test-select');
		$element->addOption('value');

		$this->assertEquals(
			'<select id="test-select" name="test-select"><option value="0">value</option></select>',
			preg_replace('/[[:cntrl:]]/', '', $element->render())
		);
	}

	public function testElementAppendMessage()
	{
		$element = new Select('test-select');
		$element->appendMessage(new Message(''));
	}
}
