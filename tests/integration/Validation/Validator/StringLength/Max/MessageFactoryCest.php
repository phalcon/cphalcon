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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Max;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength\Max;

class MessageFactoryCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength\Max :: messageFactory()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthMaxMessageFactory(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Max - messageFactory()');

        $validator = new Max([
            'max' => [
                'last_name' => 10,
            ],
        ]);

        $validation = new Validation();
        $validation->add(
            [
                'last_name',
            ],
            $validator
        );

        $messages = $validation->validate(['last_name' => 'A name too long']);

        $I->assertInstanceOf(Messages::class, $messages, 'Failed validation instance of Messages\Messages');
        $I->assertEquals(1, $messages->count(), 'Has 1 Message');

        $actual = $validator->messageFactory(
            $validation,
            'last_name',
            [':max' => 10]
        );

        $expected = new Message(
            'Field last_name must not exceed 10 characters long',
            'last_name',
            Max::class
        );

        $I->assertInstanceOf(Message::class, $actual, 'Failed validation message instanceof Message');
        $I->assertEquals($expected, $actual, 'Failed validation message and factory message are the same');
    }
}
