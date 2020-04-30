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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Http\RequestInterface;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Http\Cookie :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestConstruct(UnitTester $I)
    {
        $I->wantToTest("Http\Request - __construct()");

        $actual = new Request();
        $class  = RequestInterface::class;
        $I->assertInstanceOf($class, $actual);
    }
}
