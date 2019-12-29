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

namespace Phalcon\Test\Integration\Paginator\Adapter\QueryBuilder;

use IntegrationTester;

/**
 * Class GetCurrentPageCest
 */
class GetCurrentPageCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getCurrentPage()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterQuerybuilderGetCurrentPage(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getCurrentPage()');
        $I->skipTest('Need implementation');
    }
}
