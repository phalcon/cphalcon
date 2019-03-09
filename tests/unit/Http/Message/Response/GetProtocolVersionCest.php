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

namespace Phalcon\Test\Unit\Http\Message\Response;

use InvalidArgumentException;
use Phalcon\Http\Message\Response;
use UnitTester;

/**
 * Class GetProtocolVersionCest
 */
class GetProtocolVersionCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getProtocolVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-05
     */
    public function httpMessageResponseGetProtocolVersion(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getProtocolVersion()');
        $request = new Response();

        $expected = '1.1';
        $actual   = $request->getProtocolVersion();
        $I->assertEquals($expected, $actual);
    }
}
