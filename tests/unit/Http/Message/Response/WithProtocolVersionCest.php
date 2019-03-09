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
 * Class WithProtocolVersionCest
 */
class WithProtocolVersionCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withProtocolVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithProtocolVersion(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withProtocolVersion()');
        $request     = new Response();
        $newInstance = $request->withProtocolVersion('2.0');

        $I->assertNotEquals($request, $newInstance);

        $expected = '1.1';
        $actual   = $request->getProtocolVersion();
        $I->assertEquals($expected, $actual);

        $expected = '2.0';
        $actual   = $newInstance->getProtocolVersion();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withProtocolVersion() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithProtocolVersionException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withProtocolVersion() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Unsupported protocol 1.2'),
            function () {
                $request = new Response();
                $request->withProtocolVersion('1.2');
            }
        );
    }
}
