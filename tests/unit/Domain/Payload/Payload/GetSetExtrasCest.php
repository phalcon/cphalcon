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

class GetSetExtrasCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getExtras()/setExtras()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetSetExtras(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Payload - getExtras()/setExtras()');

        $payload = new Payload();
        $payload->setExtras('extras');

        $actual = $payload->getExtras();
        $I->assertEquals('extras', $actual);
    }
}
