<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Paginator\Adapter\NativeArray;

use BadMethodCallException;
use Phalcon\Paginator\Adapter\NativeArray;
use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\NativeArray :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterNativearrayConstruct(UnitTester $I)
    {
        $I->wantToTest("Paginator\Adapter\NativeArray - __construct() - wrong parameters");
        $I->expectThrowable(
            new BadMethodCallException('Wrong number of parameters'),
            function () {
                $paginator = new NativeArray();
            }
        );
    }
}
