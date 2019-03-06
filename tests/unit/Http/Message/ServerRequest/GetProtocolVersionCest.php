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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use UnitTester;

/**
 * Class GetProtocolVersionCest
 */
class GetProtocolVersionCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getProtocolVersion()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-05
     */
    public function httpMessageServerRequestGetProtocolVersion(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getProtocolVersion()');
        $request     = new ServerRequest(
            'GET',
            null,
            [],
            'php://input',
            [],
            [],
            [],
            [],
            null,
            '2.0'
        );

        $expected = '2.0';
        $actual   = $request->getProtocolVersion();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getProtocolVersion() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-05
     */
    public function httpMessageServerRequestGetProtocolVersionEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getProtocolVersion() - empty');
        $request     = new ServerRequest();

        $expected = '1.1';
        $actual   = $request->getProtocolVersion();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getProtocolVersion() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-05
     */
    public function httpMessageServerRequestGetProtocolVersionException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getProtocolVersion() - exception');
        $I->expectThrowable(
            new \InvalidArgumentException('Unsupported protocol 1.2'),
            function () {
                $request = new ServerRequest(
                    'GET',
                    null,
                    [],
                    'php://input',
                    [],
                    [],
                    [],
                    [],
                    null,
                    '1.2'
                );
            }
        );
    }
}
