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

use
	Phalcon\Forms\Form,
	Phalcon\Forms\Element\Text,
	Phalcon\Forms\Element\Select,
	Phalcon\Validation\Validator\PresenceOf,
	Phalcon\Validation\Validator\StringLength,
	Phalcon\Validation\Validator\Regex;

class FormsTest extends PHPUnit_Framework_TestCase
{

	public function testFormElementEmpty()
	{
		$element = new Text("name");

		$this->assertEquals($element->getLabel(), null);
		$this->assertEquals($element->getAttributes(), null);
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
	}

	public function testFormPrepareAttributes()
	{
		$element1 = new Text("name");

		$element1->setLabel('name');

		$this->assertEquals(
			$element1->prepareAttributes(),
			array('name', 'value' => null)
		);
	}

	public function testFormPrepareAttributesDefault()
	{
		$element1 = new Text("name");

		$element1->setLabel('name');
		$element1->setAttributes(array('class' => 'big-input'));

		$this->assertEquals(
			$element1->prepareAttributes(),
			array('name', 'class' => 'big-input', 'value' => null)
		);
	}

	public function testFormPrepareAttributesNoDefault()
	{
		$element1 = new Text("name");

		$element1->setLabel('name');

		$this->assertEquals(
			$element1->prepareAttributes(array('class' => 'big-input')),
			array('name', 'class' => 'big-input', 'value' => null)
		);
	}

	public function testFormElementRender()
	{
		$element1 = new Text("name");
		$element1->setAttributes(array('class' => 'big-input'));

		$this->assertEquals($element1->render(), '<input type="text" class="big-input" value="" name="name" id="name" />');
		$this->assertEquals((string) $element1, '<input type="text" class="big-input" value="" name="name" id="name" />');
	}

	public function testForm()
	{

		$form = new Form();

		$form->add(new Text("name"));

		$form->add(new Text("telephone"));

		$this->assertEquals(count($form), 2);
		$this->assertEquals($form->count(), 2);
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
		$telephone = new Text("telephone");

		$telephone->addValidator(new PresenceOf(array(
			'message' => 'The telephone is required'
		)));

		$this->assertEquals(count($telephone->getValidators()), 1);

		$telephone->addValidators(array(
			new StringLength(array(
				'min' => 5,
				'minimumMessage' => 'The telephone is too short'
			)),
			new Regex(array(
				'pattern' => '/\+44 [0-9]+ [0-9]+/',
				'message' => 'The telephone has an invalid format'
			))
		));

		$this->assertEquals(count($telephone->getValidators()), 3);
	}

}

