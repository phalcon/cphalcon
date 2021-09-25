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

namespace Phalcon\Tests\Unit\Http\Message\Request;

use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\Request;
use UnitTester;

class WithProtocolVersionCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: withProtocolVersion()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestWithProtocolVersion(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - withProtocolVersion()');

        $request = new Request();

        $newInstance = $request->withProtocolVersion('2.0');

        $I->assertNotEquals($request, $newInstance);

        $I->assertEquals(
            '1.1',
            $request->getProtocolVersion()
        );

        $I->assertEquals(
            '2.0',
            $newInstance->getProtocolVersion()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: withProtocolVersion() -
     * unsupported protocol
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestWithProtocolVersionEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - withProtocolVersion() - unsupported protocol');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Invalid protocol value'
            ),
            function () {
                $request = new Request();

                $newInstance = $request->withProtocolVersion('');
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: withProtocolVersion() - empty
     * protocol
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpMessageRequestWithProtocolVersionUnsupported(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - withProtocolVersion() - empty protocol');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Unsupported protocol 4.0'
            ),
            function () {
                $request = new Request();

                $newInstance = $request->withProtocolVersion('4.0');
            }
        );
    }
}
