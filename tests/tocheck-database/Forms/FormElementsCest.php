<?php

namespace Phalcon\Tests\Integration\Forms;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;

/**
 * Phalcon\Tests\Integration\Forms\FormCest
 * Tests the \Phalcon\Forms\Form component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalcon.io
 * @author        Andres Gutierrez <andres@phalcon.io>
 * @author        Phalcon Team <team@phalcon.io>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class FormElementsCest
{
    /**
     * Executed before each test
     */
    public function _before(IntegrationTester $I)
    {
        Tag::resetInput();

        Tag::setDocType(
            Tag::HTML5
        );
    }

    /**
     * Tests cancelling validation on first fail
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13149
     *
     * @since  2017-11-19
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function shouldCancelValidationOnFirstFail(IntegrationTester $I)
    {
        $form = new Form();

        $lastName = new Text('lastName');

        $lastName->setLabel('user.lastName');

        $lastName->setFilters(
            [
                'string',
                'striptags',
                'trim',
            ]
        );

        $lastName->addValidators(
            [
                new PresenceOf(
                    [
                        'message'      => 'user.lastName.presenceOf',
                        'cancelOnFail' => true,
                    ]
                ),
                new StringLength(
                    [
                        'min'            => 3,
                        'max'            => 255,
                        'messageMaximum' => 'user.lastName.max',
                        'messageMinimum' => 'user.lastName.min',
                    ]
                ),
            ]
        );


        $firstName = new Text('firstName');

        $firstName->setLabel('user.firstName');

        $firstName->setFilters(
            [
                'string',
                'striptags',
                'trim',
            ]
        );

        $firstName->addValidators(
            [
                new PresenceOf(
                    [
                        'message'      => 'user.firstName.presenceOf',
                        'cancelOnFail' => true,
                    ]
                ),
                new StringLength(
                    [
                        'min'            => 3,
                        'max'            => 255,
                        'messageMaximum' => 'user.firstName.max',
                        'messageMinimum' => 'user.firstName.min',
                    ]
                ),
            ]
        );

        $form->add($lastName);
        $form->add($firstName);


        $_POST = [];

        $I->assertFalse(
            $form->isValid($_POST)
        );


        $expected = new Messages(
            [
                new Message(
                    'user.lastName.presenceOf',
                    'lastName',
                    PresenceOf::class
                ),
                new Message(
                    'user.firstName.presenceOf',
                    'firstName',
                    PresenceOf::class
                ),
            ]
        );

        $actual = $form->getMessages();

        $I->assertEquals($expected, $actual);
    }
}
