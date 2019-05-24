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

namespace Phalcon\Test\Unit\Http\Payload\Payload;

use Phalcon\Http\Payload\Payload;
use UnitTester;

class GetSetInputCest
{
    /**
     * Unit Tests Phalcon\Http\Payload\Payload :: getInput()/setInput()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetSetInput(UnitTester $I)
    {
        $I->wantToTest('Http\Payload\Payload - getInput()/setInput()');

        $payload = new Payload();
        $payload->setInput('input');

        $actual = $payload->getInput();
        $I->assertEquals('input', $actual);
    }
}
