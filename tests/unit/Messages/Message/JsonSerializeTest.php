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

namespace Phalcon\Tests\Unit\Messages\Message;

use JsonSerializable;
use Phalcon\Messages\Message;
use Phalcon\Tests\AbstractUnitTestCase;

final class JsonSerializeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessageJsonSerialize(): void
    {
        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111,
            [
                'My1' => 'Metadata1',
            ]
        );


        $this->assertInstanceOf(JsonSerializable::class, $message);

        $expected = [
            'field'    => 'MyField',
            'message'  => 'This is a message #1',
            'type'     => 'MyType',
            'code'     => 111,
            'metaData' => [
                'My1' => 'Metadata1',
            ],
        ];
        $actual   = $message->jsonSerialize();
        $this->assertSame($expected, $actual);
    }
}
