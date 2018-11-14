<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

class JsonSerializeCest
{
    /**
     * Tests Phalcon\Messages\Message :: jsonSerialize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testJsonSerialize(UnitTester $I, $scenario)
    {
        $message1 = new Message('This is a message #1', 'field1', 'Type1', 1);

        $expected = '\JsonSerializable';
        $actual   = $message1;
        $I->assertInstanceOf($expected, $actual);

        $expected = [
            'field'   => 'field1',
            'message' => 'This is a message #1',
            'type'    => 'Type1',
            'code'    => 1,
        ];
        $actual   = $message1->jsonSerialize();
        $I->assertEquals($expected, $actual);
    }
}
