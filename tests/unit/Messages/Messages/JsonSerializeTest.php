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

namespace Phalcon\Tests\Unit\Messages\Messages;

use JsonSerializable;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Messages\Fake\FakeMessage;

final class JsonSerializeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessagesJsonSerialize(): void
    {
        $messages = new Messages(
            [
                new Message(
                    'This is a message #1',
                    'MyField1',
                    'MyType1',
                    111,
                    [
                        'My1' => 'Metadata1',
                    ]
                ),
                new Message(
                    'This is a message #2',
                    'MyField2',
                    'MyType2',
                    222,
                    [
                        'My2' => 'Metadata2',
                    ]
                ),
            ]
        );

        $this->assertInstanceOf(JsonSerializable::class, $messages);

        $data = $messages->jsonSerialize();
        $this->assertIsArray($data);

        $this->assertCount(2, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessagesJsonSerializeNoJsonSerialize(): void
    {
        $fixture = new FakeMessage(
            'This is a message #1',
            'MyField1',
            'MyType1',
            111,
            [
                'My1' => 'Metadata1',
            ]
        );

        $messages = new Messages(
            [
                $fixture,
            ]
        );

        $this->assertInstanceOf(JsonSerializable::class, $messages);

        $actual   = $messages->jsonSerialize();
        $expected = [$fixture];
        $this->assertSame($expected, $actual);
    }
}
