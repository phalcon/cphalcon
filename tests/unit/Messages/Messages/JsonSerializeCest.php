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
 * Class JsonSerializeCest
 */
class JsonSerializeCest
{
    /**
     * Tests Phalcon\Messages\Messages :: jsonSerialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function messagesMessagesJsonSerialize(UnitTester $I)
    {
        $I->wantToTest('Messages\Messages - jsonSerialize()');
        $messages = new Messages(
            [
                new Message('This is a message #1', 'MyField1', 'MyType1', 111, ['My1' => 'Metadata1']),
                new Message('This is a message #2', 'MyField2', 'MyType2', 222, ['My2' => 'Metadata2']),
            ]
        );
        $expected = '\JsonSerializable';
        $actual   = $messages;
        $I->assertInstanceOf($expected, $actual);

        $data      = $messages->jsonSerialize();
        $condition = is_array($data);
        $I->assertTrue($condition);

        $expected = 2;
        $actual   = count($data);
        $I->assertEquals($expected, $actual);
    }
}
