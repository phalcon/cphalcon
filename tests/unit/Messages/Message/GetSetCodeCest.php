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

namespace Phalcon\Test\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

class GetSetCodeCest
{
    /**
     * Tests Phalcon\Messages\Message :: getCode()/setCode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function messagesMessageGetSetCode(UnitTester $I)
    {
        $I->wantToTest('Messages\Message - getCode()/setCode()');

        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $I->assertEquals(
            111,
            $message->getCode()
        );
    }
}
