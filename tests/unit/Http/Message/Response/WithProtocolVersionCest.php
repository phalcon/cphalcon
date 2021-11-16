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

namespace Phalcon\Tests\Unit\Http\Message\Response;

use InvalidArgumentException;
use Phalcon\Http\Message\Response;
use UnitTester;

class WithProtocolVersionCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withProtocolVersion()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithProtocolVersion(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withProtocolVersion()');
        $response    = new Response();
        $newInstance = $response->withProtocolVersion('2.0');

        $I->assertNotEquals($response, $newInstance);

        $expected = '1.1';
        $actual   = $response->getProtocolVersion();
        $I->assertEquals($expected, $actual);

        $expected = '2.0';
        $actual   = $newInstance->getProtocolVersion();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withProtocolVersion() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithProtocolVersionException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withProtocolVersion() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Unsupported protocol 1.2'),
            function () {
                $response = new Response();
                $response->withProtocolVersion('1.2');
            }
        );
    }
}
