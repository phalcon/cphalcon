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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\Email;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Email :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorEmailValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Email - validate() - empty");

        $validation = new Validation();
        $validator  = new Email(['allowEmpty' => true,]);
        $validation->add('email_one', $validator);
        $entity            = new stdClass();
        $entity->email_one = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'email_one');
        $I->assertTrue($result);
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Email :: validate() - single field
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <tram@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorEmailValidateSingleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Email - validate() - single field");

        $validation = new Validation();
        $validation->add('email_one', new Email());

        $messages = $validation->validate(
            [
                'email_one' => 'team@phalcon.io',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'email_one' => 'random-text',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);
    }

    /**
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <tram@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorEmailValidateMultipleField(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Email - validate() - multiple field");

        $validation = new Validation();

        $validationMessages = [
            'email_one' => 'Email One must be email.',
            'email_two' => 'Email Two must by email.',
        ];

        $validation->add(
            ['email_one', 'email_two'],
            new Email(
                [
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'email_one' => 'team@phalcon.io',
                'email_two' => 'team2@phalcon.io',
            ]
        );

        $expected = 0;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);


        $messages = $validation->validate(
            [
                'email_one' => 'random-text',
                'email_two' => 'team@phalcon.io',
            ]
        );

        $expected = 1;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['email_one'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $messages = $validation->validate(
            [
                'email_one' => 'random-text',
                'email_two' => 'random-text',
            ]
        );

        $expected = 2;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['email_one'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertSame($expected, $actual);

        $expected = $validationMessages['email_two'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests email validator with single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorEmailSingleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'email',
            new Email()
        );


        $messages = $validation->validate(
            [
                'email' => 'test@somemail.com',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'email' => 'rootlocalhost',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $expected = new Messages(
            [
                new Message(
                    'Field email must be an email address',
                    'email',
                    Email::class,
                    0
                ),
            ]
        );

        $I->assertEquals($expected, $messages);
    }

    /**
     * Tests email validator with multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorEmailMultipleField(IntegrationTester $I)
    {
        $validation = new Validation();

        $validationMessages = [
            'email'        => 'Email must be correct email.',
            'anotherEmail' => 'AnotherEmail must be correct email.',
        ];

        $validation->add(
            [
                'email',
                'anotherEmail',
            ],
            new Email(
                [
                    'message' => $validationMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'email'        => 'test@somemail.com',
                'anotherEmail' => 'test@somemail.com',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'email'        => 'rootlocalhost',
                'anotherEmail' => 'test@somemail.com',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['email'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'email'        => 'rootlocalhost',
                'anotherEmail' => 'rootlocalhost',
            ]
        );

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['email'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
            $validationMessages['anotherEmail'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    public function filterValidationValidatorEmailCustomMessage(IntegrationTester $I)
    {
        $validation = new Validation();

        $validation->add(
            'email',
            new Email(
                [
                    'message' => 'The email is not valid',
                ]
            )
        );

        $actual   = $validation->validate([]);
        $expected = new Messages(
            [
                new Message(
                    'The email is not valid',
                    'email',
                    Email::class,
                    0
                ),
            ]
        );
        $I->assertEquals($expected, $actual);

        $actual = $validation->validate(['email' => 'x=1']);
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['email' => 'x.x@hotmail.com']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertSame($expected, $actual);
    }
}
