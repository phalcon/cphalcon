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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Messages\Message;
use Phalcon\Tests\AbstractUnitTestCase;

final class MessageFactoryTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function testFilterValidationValidatorStringLengthMessageFactory(): void
    {
        $validator  = new StringLength();
        $validation = new Validation();
        $field      = 'name';

        // Default template uses class name
        $message = $validator->messageFactory($validation, $field);

        $this->assertInstanceOf(Message::class, $message);
        $this->assertSame($field, $message->getField());
        $this->assertSame(StringLength::class, $message->getType());
        $this->assertSame(0, $message->getCode());

        $expected = 'The field name is not valid for ' . StringLength::class;
        $this->assertSame($expected, $message->getMessage());

        // Custom template
        $validator->setTemplate('Custom message for :field');
        $message  = $validator->messageFactory($validation, $field);
        $expected = 'Custom message for name';
        $this->assertSame($expected, $message->getMessage());

        // Array field is joined with ', '
        $message = $validator->messageFactory($validation, ['name', 'email']);
        $this->assertSame('name, email', $message->getField());
        $expected = 'Custom message for name, email';
        $this->assertSame($expected, $message->getMessage());

        // Replacements are merged with :field
        $validator->setTemplate(':field has :count errors');
        $message  = $validator->messageFactory($validation, $field, [':count' => 3]);
        $expected = 'name has 3 errors';
        $this->assertSame($expected, $message->getMessage());
    }
}
