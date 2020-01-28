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
use Phalcon\Paginator\Adapter\QueryBuilder;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function paginatorAdapterQuerybuilderConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - __construct()');
        try {
            $paginator = new QueryBuilder(
                [
                    'builder' => new \stdClass(),
                    'limit'   => 10,
                    'page'    => 1,
                ]
            );
        } catch (\Phalcon\Paginator\Exception $ex) {
            $actual = $ex->getMessage();
        }
        $I->assertEquals(
            "Parameter 'builder' must be an instance of Phalcon\Mvc\Model\Query\Builder",
            $actual
        );
    }
}
