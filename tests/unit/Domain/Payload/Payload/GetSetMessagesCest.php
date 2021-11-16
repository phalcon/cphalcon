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

namespace Phalcon\Tests\Unit\Domain\Payload\Payload;

use Phalcon\Domain\Payload\Payload;
use UnitTester;

class GetSetMessagesCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getMessages()/setMessages()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetSetMessages(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Payload - getMessages()/setMessages()');

        $payload = new Payload();
        $payload->setMessages('messages');

        $actual = $payload->getMessages();
        $I->assertEquals('messages', $actual);
    }
}
