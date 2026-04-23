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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Max;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class MessageFactoryTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMaxMessageFactory(): void
    {
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

        $this->assertInstanceOf(Messages::class, $messages);
        $this->assertSame(1, $messages->count(), 'Has 1 Message');

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

        $this->assertInstanceOf(Message::class, $actual);
        $this->assertEquals($expected, $actual);
    }
}
