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

use
	Phalcon\Forms\Form,
	Phalcon\Forms\Element\Text,
	Phalcon\Forms\Element\Select,
	Phalcon\Forms\Element\Radio,
	Phalcon\Validation\Validator\PresenceOf,
	Phalcon\Validation\Validator\StringLength,
	Phalcon\Validation\Validator\Regex;

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

	public function testFormElementEmpty()
	{
		$element = new Text("name");

		$this->assertEquals($element->getLabel(), null);
		$this->assertEquals($element->getAttributes(), array());
	}

	public function testFormElement()
	{
		$element = new Text("name");

		$element->setLabel('name');
		$element->setAttributes(array('class' => 'big-input'));
		$element->setAttribute('placeholder', 'Type the name');

		$this->assertEquals($element->getLabel(), 'name');
		$this->assertEquals($element->getAttributes(), array(
			'class' => 'big-input',
			'placeholder' => 'Type the name'
		));

		$this->assertEquals($element->getAttribute('class'), 'big-input');
		$this->assertEquals($element->getAttribute('placeholder', 'the name'), 'Type the name');
		$this->assertEquals($element->getAttribute('lang', 'en'), 'en');
	}

	public function testFormPrepareAttributes()
	{
		$element1 = new Text("name");

		$element1->setLabel('name');

		$this->assertEquals(
			$element1->prepareAttributes(),
			array('name')
		);
	}

	public function testFormPrepareAttributesDefault()
	{
		$element1 = new Text("name");

		$element1->setLabel('name');
		$element1->setAttributes(array('class' => 'big-input'));

		$this->assertEquals(
			$element1->prepareAttributes(),
			array('name', 'class' => 'big-input')
		);
	}

	public function testFormOptions()
	{
		$element1 = new Text("name");

		$element1->setAttributes(array('class' => 'big-input'));
		$element1->setUserOptions(array('some' => 'value'));

		$this->assertEquals(
			$element1->getUserOptions(),
			array('some' => 'value')
		);

		$this->assertEquals(
			$element1->getUserOption('some'),
			'value'
		);

		$this->assertEquals(
			$element1->getUserOption('some-non'),
			null
		);

		$this->assertEquals(
			$element1->getUserOption('some-non', 'default'),
			'default'
		);
	}

	public function testFormPrepareAttributesNoDefault()
	{
		$element1 = new Text("name");

		$element1->setLabel('name');

		$this->assertEquals(
			$element1->prepareAttributes(array('class' => 'big-input')),
			array('name', 'class' => 'big-input')
		);
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

	public function testForm()
	{

		$form = new Form();

		$form->add(new Text("name"));

		$form->add(new Text("telephone"));

		$this->assertEquals(count($form), 2);
		$this->assertEquals($form->count(), 2);
	}

	public function testFormIndirectElementRender()
	{

		$form = new Form();

		$form->add(new Text("name"));

		$this->assertEquals($form->render('name'), '<input type="text" id="name" name="name" />');
		$this->assertEquals($form->render('name', array('class' => 'big-input')), '<input type="text" id="name" name="name" class="big-input" />');
	}

	public function testFormLabels()
	{

		$form = new Form();

		$form->add(new Text("name"));

		$telephone = new Text("telephone");

		$telephone->setLabel("The Telephone");

		$form->add($telephone);

		$this->assertEquals($form->getLabel('name'), 'name');
		$this->assertEquals($form->getLabel('telephone'), 'The Telephone');

		$this->assertEquals($form->label('name'), '<label for="name">name</label>');
		$this->assertEquals($form->label('telephone'), '<label for="telephone">The Telephone</label>');
	}

	public function testFormValidator()
	{
		//First element
		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$this->assertEquals(count($telephone->getValidators()), 1);

		$telephone->addValidators(array(
			new StringLength(array(
				'min' => 5,
				'messageMinimum' => 'The telephone is too short'
			)),
			new Regex(array(
				'pattern' => '/\+44 [0-9]+ [0-9]+/',
				'message' => 'The telephone has an invalid format'
			))
		));

		$this->assertEquals(count($telephone->getValidators()), 3);

		//Second element
		$address = new Text('address');

		$address->addValidator(new PresenceOf(array(
			'message' => 'The address is required'
		)));

		$this->assertEquals(count($address->getValidators()), 1);

		$form = new Form();

		$form->add($telephone);
		$form->add($address);

		$this->assertFalse($form->isValid(array()));

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' =>
				array(
					0 => Phalcon\Validation\Message::__set_state(array(
						'_type' => 'PresenceOf',
						'_message' => 'The telephone is required',
						'_field' => 'telephone',
						'_code' => 0,
					)),
					1 => Phalcon\Validation\Message::__set_state(array(
						'_type' => 'TooShort',
						'_message' => 'The telephone is too short',
						'_field' => 'telephone',
						'_code' => 0,
					)),
					2 => Phalcon\Validation\Message::__set_state(array(
						'_type' => 'Regex',
						'_message' => 'The telephone has an invalid format',
						'_field' => 'telephone',
						'_code' => 0,
					)),
					3 => Phalcon\Validation\Message::__set_state(array(
						'_type' => 'PresenceOf',
						'_message' => 'The address is required',
						'_field' => 'address',
						'_code' => 0,
					)),
				),
			)
		);

		$this->assertEquals($form->getMessages(), $expectedMessages);

		$this->assertFalse($form->isValid(array(
			'telephone' => '12345',
			'address' => 'hello'
		)));

		$expectedMessages = Phalcon\Validation\Message\Group::__set_state(array(
			'_messages' => array(
				0 =>  Phalcon\Validation\Message::__set_state(array(
					'_type' => 'Regex',
					'_message' => 'The telephone has an invalid format',
					'_field' => 'telephone',
					'_code' => 0,
				)),
			),
		));

		$this->assertEquals($form->getMessages(), $expectedMessages);

		$this->assertTrue($form->isValid(array(
			'telephone' => '+44 124 82122',
			'address' => 'hello'
		)));
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

		$this->assertEquals($form->render('address'), '<input type="text" id="address" name="address" value="Cr. 12 #12-82" />');
		$this->assertEquals($form->render('telephone'), '<input type="text" id="telephone" name="telephone" value="+44 124 82122" />');
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

		$this->assertEquals($form->render('address'), '<input type="text" id="address" name="address" value="Cr. 12 #12-82" />');
		$this->assertEquals($form->render('telephone'), '<input type="text" id="telephone" name="telephone" value="+44 124 82122" />');
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

	public function testIssues1029()
	{
		$form = new Form();
		$form->add(new Text("name"));

		$telephone = new Text("telephone");
		$telephone->setLabel("The Telephone");

		$form->add($telephone);

		$this->assertEquals($form->label('name', array('class' => 'form-control')), '<label for="name" class="form-control">name</label>');
		$this->assertEquals($form->label('telephone', array('class' => 'form-control')), '<label for="telephone" class="form-control">The Telephone</label>');
	}

	public function testIssue1190()
	{
		$object = new stdClass();
		$object->title = 'Hello "world!"';

		$form = new Phalcon\Forms\Form($object);
		$form->add(new Phalcon\Forms\Element\Text("title"));
		$actual   = $form->render('title');
		$expected = '<input type="text" id="title" name="title" value="Hello &quot;world!&quot;" />';
		$this->assertEquals($actual, $expected);
	}

	public function testIssue1210()
	{
		$e = new \Phalcon\Forms\Element\Text('test');
		$e->setLabel('Test');
		$actual   = $e->label();
		$expected = '<label for="test">Test</label>';
		$this->assertEquals($actual, $expected);
	}

	public function testIssue706()
	{
		$form = new \Phalcon\Forms\Form();
		$form->add(new \Phalcon\Forms\Element\Text('name'));

		$form->add(new \Phalcon\Forms\Element\Text('before'), 'name', true);
		$form->add(new \Phalcon\Forms\Element\Text('after'), 'name');

		$data = array('before', 'name', 'after');
		$result = array();

		foreach ($form as $element) {
			$result[] = $element->getName();
		}

		$this->assertEquals($result, $data);
	}

	public function testIssue2045()
	{
		$element = new \Phalcon\Forms\Element\Text("name");
		$element->setAttributes(array('class' => 'big-input'));
		$element->setAttribute("id", NULL);

		$this->assertEquals('<input type="text" name="name" class="big-input" />', $element->render());
	}
}
