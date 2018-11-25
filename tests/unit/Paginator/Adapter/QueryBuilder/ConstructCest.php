<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Paginator\Adapter\QueryBuilder;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterQuerybuilderConstruct(UnitTester $I)
    {
        $I->wantToTest("Paginator\Adapter\QueryBuilder - __construct()");
        $I->skipTest("Need implementation");
    }
}
