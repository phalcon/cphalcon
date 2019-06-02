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
use UnitTester;

class GetSetOutputCest
{
    /**
     * Unit Tests Phalcon\Domain\Payload\Payload :: getOutput()/setOutput()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetSetOutput(UnitTester $I)
    {
        $I->wantToTest('Domain\Payload\Payload - getOutput()/setOutput()');

        $payload = new Payload();
        $payload->setOutput('output');

        $actual = $payload->getOutput();
        $I->assertEquals('output', $actual);
    }
}
