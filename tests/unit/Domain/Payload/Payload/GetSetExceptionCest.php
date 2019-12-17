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

namespace Phalcon\Test\Unit\Domain\Payload\Payload;

use Phalcon\Domain\Payload\Payload;
use RuntimeException;
use UnitTester;

class GetSetExceptionCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getException()/setException()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-07
     */
    public function httpPayloadPayloadGetSetException(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Payload - getException()/setException()');

        $payload   = new Payload();
        $exception = new RuntimeException('Runtime error');
        $payload->setException($exception);

        $actual = $payload->getException();
        $I->assertEquals($exception, $actual);
    }
}
