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

namespace Phalcon\Test\Integration\Paginator\Adapter\QueryBuilder;

use IntegrationTester;

/**
 * Class GetLimitCest
 */
class GetLimitCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getLimit()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function paginatorAdapterQuerybuilderGetLimit(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getLimit()');
        $I->skipTest('Need implementation');
    }
}
