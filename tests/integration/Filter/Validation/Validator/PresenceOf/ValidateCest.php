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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\PresenceOf;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\PresenceOf :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorPresenceOfValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\PresenceOf - validate() - empty");

        $validation = new Validation();
        $validator  = new PresenceOf(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $I->assertTrue($result);
    }

    /**
     * Tests presence of validator with single field
     *
     * @author       Wojciech Ślawski <jurigag@gmail.com>
     * @since        2016-06-05
     *
     * @dataProvider getSingleFieldExamples
     */
    public function filterValidationValidatorPresenceOfSingleField(IntegrationTester $I, Example $example)
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

        $I->assertSame(
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
    public function filterValidationValidatorPresenceOfMultipleFields(IntegrationTester $I)
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

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '',
                'type' => 'SomeValue',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );


        $I->assertSame(
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

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
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
    public function filterValidationValidatorPresenceOfMixedFields(IntegrationTester $I)
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
    public function filterValidationValidatorPresenceOfCancelOnFail(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation
            ->add('name', new PresenceOf(['message' => 'The name is required']))
            ->add(
                'email',
                new PresenceOf([
                    'message'      => 'The email is required',
                    'cancelOnFail' => true,
                ])
            )
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

    private function getSingleFieldExamples(): array
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
