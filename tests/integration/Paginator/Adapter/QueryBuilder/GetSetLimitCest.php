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
use Phalcon\Paginator\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;

class GetSetLimitCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getLimit() / setLimit()
     */
    public function paginatorAdapterQuerybuilderGetSetLimit(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getLimit() / setLimit()');

        $manager = $this->getService('modelsManager');

        $builder = $manager->createBuilder()
                           ->columns('cedula, nombres')
                           ->from(Personnes::class)
                           ->orderBy('cedula')
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder,
                'limit'   => 10,
                'page'    => 1,
            ]
        );

        $I->assertEquals(
            10,
            $paginator->getLimit()
        );

        $setterResult = $paginator->setLimit(25);

        $I->assertEquals(
            25,
            $paginator->getLimit()
        );

        $I->assertEquals($paginator, $setterResult);

        $I->expectThrowable(new Exception('Limit must be greater then zero'), function () use ($builder) {
            $paginator = new QueryBuilder(
                [
                    'builder' => $builder,
                    'limit'   => 0,
                    'page'    => 1,
                ]
            );

            $paginator->paginate();
        });
    }
}
