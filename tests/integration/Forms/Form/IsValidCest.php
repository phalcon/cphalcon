<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Forms\ValidationForm;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;

class IsValidCest
{
    /**
     * Tests Form::isValid()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/11500
     */
    public function testMergeValidators(IntegrationTester $I)
    {
        // First element
        $telephone = new Text('telephone');

        $telephone->addValidators(
            [
                new PresenceOf(
                    [
                        'message' => 'The telephone is required',
                    ]
                ),
            ]
        );

        $customValidation = new Validation();

        $customValidation->add(
            'telephone',
            new Regex(
                [
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format',
                ]
            )
        );

        $form = new Form();

        $address = new Text('address');

        $form->add($telephone);
        $form->add($address);

        $form->setValidation($customValidation);

        $I->assertFalse(
            $form->isValid(
                [
                    'address' => 'hello',
                ]
            )
        );

        $I->assertTrue(
            $form->get('telephone')->hasMessages()
        );

        $I->assertFalse(
            $form->get('address')->hasMessages()
        );


        $expected = new Messages(
            [
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    Regex::class,
                    0
                ),
                new Message(
                    'The telephone is required',
                    'telephone',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals(
            $expected,
            $form->get('telephone')->getMessages()
        );


        $expected = $form->getMessages();

        $I->assertEquals(
            $expected,
            $form->get('telephone')->getMessages()
        );


        $expected = new Messages();

        $I->assertEquals(
            $expected,
            $form->get('address')->getMessages()
        );
    }

    /**
     * Tests Form::isValid()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/13149
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsFormRemoveIsValidCancelOnFail(IntegrationTester $I)
    {
        $form = new ValidationForm();

        $data = [
            'fullname' => '',
            'email'    => '',
            'subject'  => '',
            'message'  => '',
        ];

        $actual = $form->isValid($data);
        $I->assertFalse($actual);

        /**
         * 6 validators in total
         */
        $messages = $form->getMessages();
        $I->assertCount(4, $messages);

        $data = [
            'fullname' => '',
            'email'    => 'team@phalcon.io',
            'subject'  => 'Some subject',
            'message'  => 'Some message',
        ];

        $actual = $form->isValid($data);
        $I->assertFalse($actual);

        $messages = $form->getMessages();
        $I->assertCount(1, $messages);

        $expected = new Messages(
            [
                new Message(
                    'your fullname is required',
                    'fullname',
                    PresenceOf::class
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }
}
