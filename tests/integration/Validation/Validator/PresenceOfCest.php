<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Validation\Validator;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;

class PresenceOfCest
{
    /**
     * Tests presence of validator with single field
     *
     * @author       Wojciech Ślawski <jurigag@gmail.com>
     * @since        2016-06-05
     *
     * @dataProvider shouldValidateSingleFieldProvider
     */
    public function shouldValidateSingleField(IntegrationTester $I, Example $example)
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new PresenceOf()
        );

        $messages = $validation->validate(
            [
                'name' => $example['name'],
            ]
        );

        $I->assertEquals(
            $example['expected'],
            $messages->count()
        );
    }

    /**
     * Tests presence of validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function shouldValidateMultipleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'name' => 'Name cant be empty.',
            'type' => 'Type cant be empty.',
        ];

        $validation->add(
            ['name', 'type'],
            new PresenceOf(
                [
                    'message' => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue',
                'type' => 'SomeValue',
            ]
        );

        $I->assertEquals(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '',
                'type' => 'SomeValue',
            ]
        );

        $I->assertEquals(
            1,
            $messages->count()
        );


        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $expected = new Messages(
            [
                new Message(
                    'Name cant be empty.',
                    'name',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'name' => '',
                'type' => '',
            ]
        );

        $I->assertEquals(
            2,
            $messages->count()
        );

        $I->assertEquals(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertEquals(
            $validationMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );

        $expected = new Messages(
            [
                new Message(
                    'Name cant be empty.',
                    'name',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'Type cant be empty.',
                    'type',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests mixed fields
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-01
     */
    public function shouldValidateMixedFields(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation
            ->add('name', new PresenceOf(['message' => 'The name is required']))
            ->add('email', new PresenceOf(['message' => 'The email is required']))
            ->add('login', new PresenceOf(['message' => 'The login is required']))
        ;

        $expected = new Messages(
            [
                new Message(
                    'The name is required',
                    'name',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The email is required',
                    'email',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The login is required',
                    'login',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $actual = $validation->validate(
            []
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests cancel validation on first fail
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-01
     */
    public function shouldCancelOnFail(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation
            ->add('name', new PresenceOf(['message' => 'The name is required']))
            ->add('email', new PresenceOf([
                'message'      => 'The email is required',
                'cancelOnFail' => true,
            ]))
            ->add('login', new PresenceOf(['message' => 'The login is required']))
        ;

        $expected = new Messages(
            [
                new Message(
                    'The name is required',
                    'name',
                    PresenceOf::class
                ),
                new Message(
                    'The email is required',
                    'email',
                    PresenceOf::class
                ),
                new Message(
                    'The login is required',
                    'login',
                    PresenceOf::class
                ),
            ]
        );

        $actual = $validation->validate(
            []
        );

        $I->assertEquals($expected, $actual);
    }

    private function shouldValidateSingleFieldProvider(): array
    {
        return [
            [
                'name'     => 'SomeValue',
                'expected' => 0,
            ],

            [
                'name'     => '',
                'expected' => 1,
            ],
        ];
    }
}
