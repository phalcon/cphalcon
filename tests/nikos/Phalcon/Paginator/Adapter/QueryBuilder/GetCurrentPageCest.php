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

namespace Phalcon\Test\Unit\Paginator\Adapter\QueryBuilder;

use UnitTester;

class GetCurrentPageCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getCurrentPage()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function paginatorAdapterQueryBuilderGetCurrentPage(UnitTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getCurrentPage()');

        $I->skipTest('Need implementation');
    }
}
