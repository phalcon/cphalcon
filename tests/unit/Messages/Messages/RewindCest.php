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
 * Class RewindCest
 */
class RewindCest
{
    /**
     * Tests Phalcon\Messages\Messages :: rewind()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesRewind(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - rewind()');
        $messages = new Messages(
            [
                new Message('This is a message #1', 'MyField1', 'MyType1', 111, ['My1' => 'Metadata1']),
                new Message('This is a message #2', 'MyField2', 'MyType2', 222, ['My2' => 'Metadata2']),
            ]
        );

        $messages->next();

        $class  = Message::class;
        $actual = $messages->current();
        $I->assertInstanceOf($class, $actual);

        $expected = 'This is a message #2';
        $actual   = $actual->__toString();
        $I->assertEquals($expected, $actual);

        $messages->rewind();

        $class  = Message::class;
        $actual = $messages->current();
        $I->assertInstanceOf($class, $actual);

        $expected = Message::__set_state(
            [
                '_message'  => 'This is a message #1',
                '_field'    => 'MyField1',
                '_type'     => 'MyType1',
                '_code'     => 111,
                '_metaData' => ['My1' => 'Metadata1']
            ]
        );
        $I->assertEquals($expected, $actual);
    }
}
