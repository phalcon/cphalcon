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

namespace Phalcon\Tests\Unit\Messages\Message;

use Phalcon\Messages\Message;
use UnitTester;

class GetSetFieldCest
{
    /**
     * Tests Phalcon\Messages\Message :: getField()/setField()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function messagesMessageGetSetField(UnitTester $I): void
    {
        $I->wantToTest('Messages\Message - getField()/setField()');

        $message = new Message(
            'This is a message #1',
            'MyField',
            'MyType',
            111
        );

        $I->assertEquals(
            'MyField',
            $message->getField()
        );
    }
}
