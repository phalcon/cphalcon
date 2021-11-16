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
use Phalcon\Http\Message\Uri;
use Psr\Http\Message\ServerRequestInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-08
     */
    public function httpMessageServerRequestConstructCest(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - __construct()');

        $request = new ServerRequest();

        $I->assertInstanceOf(
            ServerRequestInterface::class,
            $request
        );
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: __construct()
     *
     * @author cq-z <64899484@qq.com>
     * @since  2019-06-02
     */
    public function httpMessageServerRequestConstructIssues14151(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - __construct()');

        $request = new ServerRequest(
            'GET',
            new Uri(),
            [],
            'php://input',
            [
                'host' => ['127.0.0.1'],
            ]
        );

        $expected = ['127.0.0.1'];

        $I->assertEquals(
            $expected,
            $request->getHeader('host')
        );
    }
}
