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

namespace Phalcon\Tests\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetProtocolVersionCest
{
//    /**
//     * Tests Phalcon\Http\Message\ServerRequest :: getProtocolVersion()
//     *
//     * @author Phalcon Team <team@phalcon.io>
//     * @since  2019-03-05
//     */
//    public function httpMessageServerRequestGetProtocolVersion(UnitTester $I)
//    {
//        $I->wantToTest('Http\Message\ServerRequest - getProtocolVersion()');
//        $request = new ServerRequest(
//            'GET',
//            null,
//            [],
//            'php://input',
//            [],
//            [],
//            [],
//            [],
//            null,
//            '2.0'
//        );
//
//        $expected = '2.0';
//        $actual   = $request->getProtocolVersion();
//        $I->assertEquals($expected, $actual);
//    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getProtocolVersion() - empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-05
     */
    public function httpMessageServerRequestGetProtocolVersionEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getProtocolVersion() - empty');
        $request = new ServerRequest();

        $expected = '1.1';
        $actual   = $request->getProtocolVersion();
        $I->assertEquals($expected, $actual);
    }
//
//    /**
//     * Tests Phalcon\Http\Message\ServerRequest :: getProtocolVersion() -
//     * exception
//     *
//     * @author Phalcon Team <team@phalcon.io>
//     * @since  2019-03-05
//     */
//    public function httpMessageServerRequestGetProtocolVersionException(UnitTester $I)
//    {
//        $I->wantToTest('Http\Message\ServerRequest - getProtocolVersion() - exception');
//        $I->expectThrowable(
//            new InvalidArgumentException('Unsupported protocol 1.2'),
//            function () {
//                $request = new ServerRequest(
//                    'GET',
//                    null,
//                    [],
//                    'php://input',
//                    [],
//                    [],
//                    [],
//                    [],
//                    null,
//                    '1.2'
//                );
//            }
//        );
//    }
}
