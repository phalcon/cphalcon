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

class GetSetExtrasCest
{
    /**
     * Unit Tests Phalcon\Http\Payload\Payload :: getExtras()/setExtras()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-24
     */
    public function httpPayloadPayloadGetSetExtras(UnitTester $I)
    {
        $I->wantToTest('Http\Payload\Payload - getExtras()/setExtras()');

        $payload = new Payload();
        $payload->setExtras('extras');

        $actual = $payload->getExtras();
        $I->assertEquals('extras', $actual);
    }
}
