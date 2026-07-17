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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Callback;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exceptions\InvalidCallbackReturn;
use Phalcon\Filter\Validation\Validator\Callback;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-06
     */
    public function testFilterValidationValidatorCallbackValidateBoundClosure(): void
    {
        $validation = new Validation();

        $validation->add(
            'title',
            new Callback(
                [
                    'callback' => function ($data) {
                        if (!is_string($data['title'])) {
                            $this->setTemplate('Title is not a string');

                            return false;
                        }

                        if (strlen($data['title']) > 10) {
                            $this->setTemplate('Title too long');

                            return false;
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'title' => 123,
            ]
        );

        $this->assertCount(1, $messages);
        $this->assertSame(
            'Title is not a string',
            $messages[0]->getMessage()
        );


        $messages = $validation->validate(
            [
                'title' => 'This title is way too long',
            ]
        );

        $this->assertCount(1, $messages);
        $this->assertSame(
            'Title too long',
            $messages[0]->getMessage()
        );


        $messages = $validation->validate(
            [
                'title' => 'Short',
            ]
        );

        $this->assertCount(0, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-06
     */
    public function testFilterValidationValidatorCallbackValidateBoundClosureTemplateIsolation(): void
    {
        $validation = new Validation();

        $validation->add(
            'amount',
            new Callback(
                [
                    'message'  => 'DEFAULT failure message',
                    'callback' => function ($data) {
                        if ($data['amount'] > 100) {
                            $this->setTemplate('Amount too big');

                            return false;
                        }

                        return $data['amount'] >= 0;
                    },
                ]
            )
        );


        /**
         * The branch that calls setTemplate() must use that template.
         */
        $messages = $validation->validate(
            [
                'amount' => 200,
            ]
        );

        $this->assertCount(1, $messages);
        $this->assertSame(
            'Amount too big',
            $messages[0]->getMessage()
        );


        /**
         * A later branch that does NOT call setTemplate() must fall back to
         * the configured 'message' option, not leak the template set on the
         * previous call.
         */
        $messages = $validation->validate(
            [
                'amount' => -5,
            ]
        );

        $this->assertCount(1, $messages);
        $this->assertSame(
            'DEFAULT failure message',
            $messages[0]->getMessage()
        );


        $messages = $validation->validate(
            [
                'amount' => 50,
            ]
        );

        $this->assertCount(0, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testFilterValidationValidatorCallbackValidateException(): void
    {
        $this->expectException(InvalidCallbackReturn::class);
        $this->expectExceptionMessage(
            'Callback must return bool or Phalcon\Filter\Validation\Validator object'
        );

        $validation = new Validation();

        $validation->add(
            'user',
            new Callback(
                [
                    'callback' => function ($data) {
                        return new Validation();
                    },
                ]
            )
        );

        $validation->validate(
            [
                'user' => 'user',
            ]
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testFilterValidationValidatorCallbackValidateMultipleFieldBoolean(): void
    {
        $validation = new Validation();

        $validation->add(
            ['user', 'admin'],
            new Callback(
                [
                    'message'  => 'There must be only an user or admin set',
                    'callback' => function ($data) {
                        if (!empty($data['user']) && !empty($data['admin'])) {
                            return false;
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'user'  => null,
                'admin' => 'admin',
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => null,
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => 'admin',
            ]
        );

        $this->assertCount(2, $messages);


        $expected = new Messages(
            [
                new Message(
                    'There must be only an user or admin set',
                    'user',
                    Callback::class,
                    0
                ),
                new Message(
                    'There must be only an user or admin set',
                    'admin',
                    Callback::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testFilterValidationValidatorCallbackValidateMultipleFieldValidator(): void
    {
        $validation = new Validation();

        $validation->add(
            ['user', 'admin'],
            new Callback(
                [
                    'message'  => 'There must be only an user or admin set',
                    'callback' => function ($data) {
                        if (empty($data['user']) && empty($data['admin'])) {
                            return new PresenceOf(
                                [
                                    'message' => 'You must provide admin or user',
                                ]
                            );
                        }

                        if (!empty($data['user']) && !empty($data['admin'])) {
                            return false;
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'admin' => null,
                'user'  => null,
            ]
        );

        $this->assertCount(2, $messages);


        $expected = new Messages(
            [
                new Message(
                    'You must provide admin or user',
                    'user',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'You must provide admin or user',
                    'admin',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'admin' => 'admin',
                'user'  => null,
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'admin' => null,
                'user'  => 'user',
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'admin' => 'admin',
                'user'  => 'user',
            ]
        );

        $this->assertCount(2, $messages);


        $expected = new Messages(
            [
                new Message(
                    'There must be only an user or admin set',
                    'user',
                    Callback::class,
                    0
                ),
                new Message(
                    'There must be only an user or admin set',
                    'admin',
                    Callback::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-08
     */
    public function testFilterValidationValidatorCallbackValidateNoCallback(): void
    {
        $validation = new Validation();

        $validation->add(
            'user',
            new Callback(
                [
                    'callback' => 'test',
                ]
            )
        );

        $messages = $validation->validate(
            [
                'user'  => 'u',
                'admin' => 'admin',
            ]
        );

        $this->assertCount(0, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testFilterValidationValidatorCallbackValidateSingleFieldBoolean(): void
    {
        $validation = new Validation();

        $validation->add(
            'user',
            new Callback(
                [
                    'callback'   => function ($data) {
                        return empty($data['admin']);
                    },
                    'message'    => 'You cant provide both admin and user.',
                    'allowEmpty' => true,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => null,
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => null,
                'admin' => 'admin',
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'user',
                'admin' => 'admin',
            ]
        );

        $this->assertCount(1, $messages);


        $expected = new Messages(
            [
                new Message(
                    'You cant provide both admin and user.',
                    'user',
                    Callback::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-29
     */
    public function testFilterValidationValidatorCallbackValidateSingleFieldValidator(): void
    {
        $validation = new Validation();

        $validation->add(
            'user',
            new Callback(
                [
                    'callback' => function ($data) {
                        if (empty($data['admin'])) {
                            return new StringLength(
                                [
                                    'min'            => 4,
                                    'messageMinimum' => 'User name should be minimum 4 characters.',
                                ]
                            );
                        }

                        return true;
                    },
                ]
            )
        );


        $messages = $validation->validate(
            [
                'user'  => 'u',
                'admin' => 'admin',
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'users',
                'admin' => null,
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'user'  => 'u',
                'admin' => null,
            ]
        );

        $this->assertCount(1, $messages);


        $expected = new Messages(
            [
                new Message(
                    'User name should be minimum 4 characters.',
                    'user',
                    Min::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }
}
