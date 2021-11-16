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
use UnitTester;

class FilterCest
{
    /**
     * Tests Phalcon\Messages\Messages :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessagesFilter(UnitTester $I): void
    {
        $I->wantToTest('Messages\Messages - filter()');

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

        $I->assertCount(3, $messages);

        $actual = $messages->filter('Password');

        $I->assertIsArray($actual);

        $I->assertCount(2, $actual);

        /** @var Message $message1 */
        /** @var Message $message2 */
        [$message1, $message2] = $actual;

        $I->assertEquals('Password: no number present', $message1->getMessage());
        $I->assertEquals('Password', $message1->getField());
        $I->assertEquals('Password', $message1->getField());
        $I->assertEquals(111, $message1->getCode());
        $I->assertEquals(['My1' => 'Metadata1'], $message1->getMetaData());

        $I->assertEquals('Password: no uppercase letter present', $message2->getMessage());
        $I->assertEquals('Password', $message2->getField());
        $I->assertEquals('Password', $message2->getField());
        $I->assertEquals(222, $message2->getCode());
        $I->assertEquals(['My2' => 'Metadata2'], $message2->getMetaData());
    }
}
