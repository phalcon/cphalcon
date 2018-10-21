<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use Phalcon\Forms\Element\Radio;
use Phalcon\Forms\Element\Select;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Validation\Message;
use Phalcon\Validation\Validator\PresenceOf;
use PHPUnit\Framework\TestCase;

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

class FormsTest extends TestCase
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
