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
use Phalcon\Tests\Fixtures\Messages\MessageFixture;
use UnitTester;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Messages\Messages :: jsonSerialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesJsonSerialize(UnitTester $I): void
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

        $I->assertInstanceOf(JsonSerializable::class, $messages);

        $data = $messages->jsonSerialize();
        $I->assertIsArray($data);

        $I->assertCount(2, $data);
    }

    /**
     * Tests Phalcon\Messages\Messages :: jsonSerialize() - no jsonSerialize
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesJsonSerializeNoJsonSerialize(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - jsonSerialize() - no jsonSerialize');

        $fixture = new MessageFixture(
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
                $fixture
            ]
        );

        $I->assertInstanceOf(JsonSerializable::class, $messages);

        $actual   = $messages->jsonSerialize();
        $expected = [$fixture];
        $I->assertEquals($expected, $actual);
    }
}
