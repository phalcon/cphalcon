<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Messages\Messages;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use UnitTester;

/**
 * Class FilterCest
 */
class FilterCest
{
    /**
     * Tests Phalcon\Messages\Messages :: filter()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesFilter(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - filter()');
        $messages = new Messages(
            [
                new Message('Password: no number present', 'Password', 'MyType1', 111, ['My1' => 'Metadata1']),
                new Message('Password: no uppercase letter present', 'Password', 'MyType2', 222, ['My2' => 'Metadata2']),
                new Message('Email: not valid', 'Email', 'MyType3', 333, ['My3' => 'Metadata3']),
            ]
        );

        $actual = $messages;
        $I->assertCount(3, $actual);

        $actual = $messages->filter('Password');
        $I->assertTrue(is_array($actual));
        $I->assertCount(2, $actual);

        $expected = [
            0 => Message::__set_state(
                [
                    '_message'  => 'Password: no number present',
                    '_field'    => 'Password',
                    '_type'     => 'MyType1',
                    '_code'     => 111,
                    '_metaData' => ['My1' => 'Metadata1']
                ]
            ),
            1 => Message::__set_state(
                [
                    '_message'  => 'Password: no uppercase letter present',
                    '_field'    => 'Password',
                    '_type'     => 'MyType2',
                    '_code'     => 222,
                    '_metaData' => ['My2' => 'Metadata2']
                ]
            ),
        ];
        $I->assertEquals($expected, $actual);
    }
}
