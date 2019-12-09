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
use UnitTester;

class GetSetInputCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getInput()/setInput()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetSetInput(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Payload - getInput()/setInput()');

        $payload = new Payload();
        $payload->setInput('input');

        $actual = $payload->getInput();
        $I->assertEquals('input', $actual);
    }
}
