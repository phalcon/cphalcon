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

namespace Phalcon\Test\Unit\Messages\Messages;

use JsonSerializable;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use UnitTester;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Messages\Messages :: jsonSerialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessagesJsonSerialize(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - jsonSerialize()');

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

        $I->assertInstanceOf(
            JsonSerializable::class,
            $messages
        );

        $data = $messages->jsonSerialize();

        $I->assertTrue(is_array($data));

        $I->assertCount(2, $data);
    }
}
