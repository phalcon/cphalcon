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
use Psr\Http\Message\RequestInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageRequestConstruct(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - __construct()');

        $request = new Request();

        $I->assertInstanceOf(
            RequestInterface::class,
            $request
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: __construct() - body exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageRequestConstructExceptionBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - __construct() - exception body');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Invalid stream passed as a parameter'
            ),
            function () {
                $request = new Request('GET', null, false);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: __construct() - exception uri
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageRequestConstructExceptionUri(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - __construct() - exception uri');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Invalid uri passed as a parameter'
            ),
            function () {
                $request = new Request('GET', false);
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: __construct() - exception headers
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageRequestConstructExceptionHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - __construct() - exception headers');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Headers needs to be either an array or instance of Phalcon\Collection'
            ),
            function () {
                $request = new Request(
                    'GET',
                    '',
                    'php://memory',
                    false
                );
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: __construct() - headers with host
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageRequestConstructHeadersWithHost(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - __construct() - headers with host');

        $request = new Request(
            'GET',
            'https://dev.phalcon.ld:8080/action',
            'php://memory',
            [
                'Host'          => ['test.phalcon.ld'],
                'Accept'        => ['text/html'],
                'Cache-Control' => ['max-age=0'],
            ]
        );

        $expected = [
            'Host'          => ['dev.phalcon.ld:8080'],
            'Accept'        => ['text/html'],
            'Cache-Control' => ['max-age=0'],
        ];
        $actual   = $request->getHeaders();
        $I->assertEquals($expected, $actual);
    }
}
