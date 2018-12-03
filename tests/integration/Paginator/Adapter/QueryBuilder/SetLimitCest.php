<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Paginator\Adapter\QueryBuilder;

use IntegrationTester;

class SetLimitCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: setLimit()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterQuerybuilderSetLimit(IntegrationTester $I)
    {
        $I->wantToTest("Paginator\Adapter\QueryBuilder - setLimit()");
        $I->skipTest("Need implementation");
    }
}
