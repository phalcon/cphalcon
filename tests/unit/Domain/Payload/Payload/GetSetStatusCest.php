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

namespace Phalcon\Test\Unit\Domain\Payload\Payload;

use Phalcon\Domain\Payload\Payload;
use Phalcon\Domain\Payload\Status;
use UnitTester;

class GetSetStatusCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getStatus()/setStatus()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetStatus(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Payload - getStatus()/setStatus()');

        $payload = new Payload();
        $payload->setStatus(Status::ACCEPTED);

        $actual = $payload->getStatus();
        $I->assertEquals(Status::ACCEPTED, $actual);
    }
}
