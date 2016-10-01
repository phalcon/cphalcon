<?php

namespace Phalcon\Test\Integration\Forms;

use Phalcon\Tag;
use IntegrationTester;
use Phalcon\Forms\Form;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Password;

/**
 * \Phalcon\Test\Integration\Forms\FormCest
 * Tests the \Phalcon\Forms\Form component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Integration\Forms
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class FormCest
{
    /**
     * Tests clearing the Form Elements
     *
     * @issue  12165
     * @issue  12099
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-10-01
     * @param  IntegrationTester $I
     */
    public function clearFormElements(IntegrationTester $I)
    {
        $pass = new Password('password');
        $eml = new Email('email');

        $text = new Text('name');
        $text->setDefault('Serghei Iakovlev');

        $form = new Form;
        $form
            ->add($eml)
            ->add($text)
            ->add($pass);

        $I->assertNull($form->get('password')->getValue());
        $I->assertEquals('Serghei Iakovlev', $form->get('name')->getValue());

        $_POST = [
            'password' => 'secret',
            'name' => 'Andres Gutierrez',
        ];

        $I->assertEquals('secret', $form->get('password')->getValue());
        $I->assertEquals('Andres Gutierrez', $form->get('name')->getValue());

        Tag::setDefault('email', 'andres@phalconphp.com');

        $I->assertEquals('andres@phalconphp.com', $form->get('email')->getValue());
        $I->assertEquals($pass->getValue(), $form->get('password')->getValue());

        $pass->clear();

        $I->assertNull($pass->getValue());
        $I->assertEquals($pass->getValue(), $form->get('password')->getValue());

        $form->clear();

        $I->assertEquals('Serghei Iakovlev', $form->get('name')->getValue());
        $I->assertNull($form->get('email')->getValue());

        $I->assertEquals(['password' => 'secret', 'name' => 'Andres Gutierrez'], $_POST);
    }
}
