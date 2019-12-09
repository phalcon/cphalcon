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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\StringLength\Min;

class MessageFactoryCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Min :: messageFactory()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMinMessageFactory(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - messageFactory()');

        $validator = new Min([
            'min' => [
                'last_name' => 20,
            ],
        ]);

        $validation = new Validation();
        $validation->add(
            [
                'last_name',
            ],
            $validator
        );

        $messages = $validation->validate(['last_name' => 'A name too short']);

        $I->assertInstanceOf(Messages::class, $messages, 'Failed validation instance of Messages\Messages');
        $I->assertEquals(1, $messages->count(), 'Has 1 Message');

        $actual = $validator->messageFactory(
            $validation,
            'last_name',
            [':min' => 10]
        );

        $expected = new Message(
            'Field last_name must be at least 10 characters long',
            'last_name',
            Min::class
        );

        $I->assertInstanceOf(Message::class, $actual, 'Failed validation message instanceof Message');
        $I->assertEquals($expected, $actual, 'Failed validation message and factory message are the same');
    }
}
