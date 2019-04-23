<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Password;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Test\Models\Select as MvcModel;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;

/**
 * Class ClearCest
 */
class ClearCest
{
    /**
     * Executed before each test
     *
     * @param IntegrationTester $I
     */
    public function _before(IntegrationTester $I)
    {
        Tag::resetInput();
        Tag::setDocType(Tag::HTML5);
    }

    /**
     * Tests Phalcon\Forms\Form :: clear()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsFormClear(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - clear()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests clearing the Form Elements
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12165
     * @issue  https://github.com/phalcon/cphalcon/issues/12099
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-10-01
     *
     * @param  IntegrationTester $I
     */
    public function clearFormElements(IntegrationTester $I)
    {
        $pass = new Password('passwd');
        $eml  = new Email('email');

        $text = new Text('name');
        $text->setDefault('Serghei Iakovlev');

        $form = new Form;
        $form
            ->add($eml)
            ->add($text)
            ->add($pass)
        ;

        $I->assertNull($form->get('passwd')->getValue());
        $I->assertEquals('Serghei Iakovlev', $form->get('name')->getValue());

        $I->assertEquals(
            '<input type="password" id="passwd" name="passwd">',
            $form->render('passwd')
        );

        $I->assertEquals(
            '<input type="email" id="email" name="email">',
            $form->render('email')
        );

        $I->assertEquals(
            '<input type="text" id="name" name="name" value="Serghei Iakovlev">',
            $form->render('name')
        );

        $_POST = [
            'passwd' => 'secret',
            'name'   => 'Andres Gutierrez',
        ];

        $I->assertEquals('secret', $form->get('passwd')->getValue());
        $I->assertEquals($pass->getValue(), $form->get('passwd')->getValue());
        $I->assertEquals('Andres Gutierrez', $form->get('name')->getValue());

        $I->assertEquals(
            '<input type="password" id="passwd" name="passwd" value="secret">',
            $form->render('passwd')
        );

        $I->assertEquals(
            '<input type="text" id="name" name="name" value="Andres Gutierrez">',
            $form->render('name')
        );

        Tag::setDefault('email', 'andres@phalconphp.com');


        $I->assertEquals(
            '<input type="email" id="email" name="email" value="andres@phalconphp.com">',
            $form->render('email')
        );
        $I->assertEquals('andres@phalconphp.com', $form->get('email')->getValue());

        $pass->clear();

        $I->assertEquals(
            '<input type="password" id="passwd" name="passwd">',
            $form->render('passwd')
        );

        $I->assertNull($pass->getValue());
        $I->assertEquals($pass->getValue(), $form->get('passwd')->getValue());

        $form->clear();

        $I->assertEquals('Serghei Iakovlev', $form->get('name')->getValue());
        $I->assertNull($form->get('email')->getValue());

        $I->assertEquals(
            '<input type="text" id="name" name="name" value="Serghei Iakovlev">',
            $form->render('name')
        );

        $I->assertEquals(
            '<input type="email" id="email" name="email">',
            $form->render('email')
        );

        $I->assertEquals(['passwd' => 'secret', 'name' => 'Andres Gutierrez'], $_POST);
    }

    /**
     * Tests clearing the Form Elements and using Form::isValid
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11978
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-10-01
     *
     * @param  IntegrationTester $I
     */
    public function clearFormElementsAndUsingValidation(IntegrationTester $I)
    {
        $password = new Password('password', ['placeholder' => 'Insert your Password']);

        $password->addValidators(
            [
                new PresenceOf(['message' => 'The field is required', 'cancelOnFail' => true]),
                new StringLength(['min' => 7, 'messageMinimum' => 'The text is too short']),
            ]
        );

        $form = new Form;
        $form->add($password);

        $I->assertNull($form->get('password')->getValue());

        $input = '<input type="password" id="password" name="password" placeholder="Insert your Password">';
        $I->assertEquals($input, $form->render('password'));

        $_POST = ['password' => 'secret'];

        $I->assertEquals('secret', $form->get('password')->getValue());

        $input = '<input type="password" id="password" name="password" value="secret" placeholder="Insert your Password">';
        $I->assertEquals($input, $form->render('password'));

        $I->assertFalse($form->isValid($_POST));

        $actual   = $form->getMessages();
        $expected = new Messages(
            [
                new Message(
                    'The text is too short',
                    'password',
                    'TooShort',
                    0
                ),
            ]
        );
        $I->assertEquals($actual, $expected);

        $form->clear(['password']);

        $I->assertNull($form->get('password')->getValue());

        $input = '<input type="password" id="password" name="password" placeholder="Insert your Password">';
        $I->assertEquals($input, $form->render('password'));

        $I->assertEquals(['password' => 'secret'], $_POST);
    }

    /**
     * Tests clearing the Form Elements by using Form::bind
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/11978
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-10-01
     *
     * @param  IntegrationTester $I
     */
    public function clearFormElementsByUsingFormBind(IntegrationTester $I)
    {
        $name = new Text('sel_name');
        $text = new Text('sel_text');

        $form = new Form;
        $form
            ->add($name)
            ->add($text)
        ;

        $entity = new MvcModel();

        $I->assertNull(Tag::getValue('sel_name'));
        $I->assertNull($form->getValue('sel_name'));
        $I->assertNull($form->get('sel_name')->getValue());
        $I->assertNull($name->getValue());

        Tag::setDefault('sel_name', 'Please specify name');
        $_POST = ['sel_name' => 'Some Name', 'sel_text' => 'Some Text'];

        $form->bind($_POST, $entity);

        $I->assertEquals('Some Name', $entity->getName());
        $I->assertEquals('Some Text', $entity->getText());

        $I->assertEquals('Some Name', $form->getValue('sel_name'));
        $I->assertEquals('Some Name', $form->get('sel_name')->getValue());
        $I->assertEquals('Some Name', $name->getValue());

        $I->assertEquals('Some Text', $form->getValue('sel_text'));
        $I->assertEquals('Some Text', $form->get('sel_text')->getValue());
        $I->assertEquals('Some Text', $text->getValue());

        $form->clear(['sel_name']);

        $I->assertNull(Tag::getValue('sel_name'));
        $I->assertNull($form->getValue('sel_name'));
        $I->assertNull($form->get('sel_name')->getValue());
        $I->assertNull($name->getValue());

        $I->assertEquals('Some Text', $form->getValue('sel_text'));
        $I->assertEquals('Some Text', $form->get('sel_text')->getValue());
        $I->assertEquals('Some Text', $text->getValue());

        $form->clear(['non_existent', 'another_filed']);

        $I->assertEquals('Some Text', $form->getValue('sel_text'));
        $I->assertEquals('Some Text', $form->get('sel_text')->getValue());
        $I->assertEquals('Some Text', $text->getValue());

        $form->clear();

        $I->assertNull(Tag::getValue('sel_text'));
        $I->assertNull($form->getValue('sel_text'));
        $I->assertNull($form->get('sel_text')->getValue());
        $I->assertNull($text->getValue());

        $I->assertEquals('Some Name', $entity->getName());
        $I->assertEquals('Some Text', $entity->getText());

        $I->assertEquals(['sel_name' => 'Some Name', 'sel_text' => 'Some Text'], $_POST);
    }
}
