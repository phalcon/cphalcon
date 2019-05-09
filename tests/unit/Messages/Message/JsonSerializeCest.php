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

namespace Phalcon\Test\Unit\Messages\Message;

use JsonSerializable;
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
    public function messagesMessageJsonSerialize(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - jsonSerialize()');

        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111,
            [
                'My1' => 'Metadata1',
            ]
        );


        $I->assertInstanceOf(
            JsonSerializable::class,
            $message
        );


        $expected = [
            'field'    => 'MyField',
            'message'  => 'This is a message #1',
            'type'     => 'MyType',
            'code'     => 111,
            'metaData' => [
                'My1' => 'Metadata1',
            ],
        ];

        $actual = $message->jsonSerialize();

        $I->assertEquals($expected, $actual);
    }
}
