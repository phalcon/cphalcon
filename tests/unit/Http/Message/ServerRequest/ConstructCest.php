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
use Psr\Http\Message\ServerRequestInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-08
     */
    public function httpMessageServerRequestConstructCest(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - __construct()');
        $request = new ServerRequest();
        $class   = ServerRequestInterface::class;
        $I->assertInstanceOf($class, $request);
    }
}
