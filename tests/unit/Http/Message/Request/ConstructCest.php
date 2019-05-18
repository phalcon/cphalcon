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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use Psr\Http\Message\RequestInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
}
