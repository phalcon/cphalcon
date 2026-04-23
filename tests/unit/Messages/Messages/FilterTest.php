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

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;

final class FilterTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testMessagesMessagesFilter(): void
    {
        $messages = new Messages(
            [
                new Message(
                    'Password: no number present',
                    'Password',
                    'MyType1',
                    111,
                    [
                        'My1' => 'Metadata1',
                    ]
                ),
                new Message(
                    'Password: no uppercase letter present',
                    'Password',
                    'MyType2',
                    222,
                    [
                        'My2' => 'Metadata2',
                    ]
                ),
                new Message(
                    'Email: not valid',
                    'Email',
                    'MyType3',
                    333,
                    [
                        'My3' => 'Metadata3',
                    ]
                ),
            ]
        );

        $this->assertCount(3, $messages);

        $actual = $messages->filter('Password');

        $this->assertIsArray($actual);

        $this->assertCount(2, $actual);

        /** @var Message $message1 */
        /** @var Message $message2 */
        [$message1, $message2] = $actual;

        $this->assertSame('Password: no number present', $message1->getMessage());
        $this->assertSame('Password', $message1->getField());
        $this->assertSame('Password', $message1->getField());
        $this->assertSame(111, $message1->getCode());
        $this->assertSame(['My1' => 'Metadata1'], $message1->getMetaData());

        $this->assertSame('Password: no uppercase letter present', $message2->getMessage());
        $this->assertSame('Password', $message2->getField());
        $this->assertSame('Password', $message2->getField());
        $this->assertSame(222, $message2->getCode());
        $this->assertSame(['My2' => 'Metadata2'], $message2->getMetaData());
    }
}
