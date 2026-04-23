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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\PresenceOf;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    public static function getSingleFieldExamples(): array
    {
        return [
            [
                'SomeValue',
                0,
            ],

            [
                '',
                1,
            ],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-01
     */
    public function testFilterValidationValidatorPresenceOfCancelOnFail(): void
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

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-01
     */
    public function testFilterValidationValidatorPresenceOfMixedFields(): void
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

        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorPresenceOfMultipleFields(): void
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

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '',
                'type' => 'SomeValue',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );


        $this->assertSame(
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

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'name' => '',
                'type' => '',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
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

        $this->assertEquals($expected, $messages);
    }

    /**
     * @dataProvider getSingleFieldExamples
     *
     * @author       Wojciech Ślawski <jurigag@gmail.com>
     * @since        2016-06-05
     */
    public function testFilterValidationValidatorPresenceOfSingleField(
        string $name,
        int $expected
    ): void {
        $validation = new Validation();
        $validation->add('name', new PresenceOf());

        $messages = $validation->validate(
            [
                'name' => $name,
            ]
        );

        $this->assertSame($expected, $messages->count());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorPresenceOfValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new PresenceOf(['allowEmpty' => true,]);
        $validation->add('price', $validator);
        $entity        = new stdClass();
        $entity->price = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'price');
        $this->assertTrue($result);
    }
}
