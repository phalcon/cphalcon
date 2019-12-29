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
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personnes;

class GetSetQueryBuilderCest
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
     * Tests Phalcon\Paginator\Adapter\QueryBuilder :: getQueryBuilder() /
     * setQueryBuilder()
     */
    public function paginatorAdapterQuerybuilderGetSetQueryBuilder(IntegrationTester $I)
    {
        $I->wantToTest('Paginator\Adapter\QueryBuilder - getQueryBuilder() / setQueryBuilder()');

        $manager = $this->getService('modelsManager');

        $builder1 = $manager->createBuilder()
                            ->columns('cedula, nombres')
                            ->from(Personnes::class)
                            ->orderBy('cedula')
        ;

        $paginator = new QueryBuilder(
            [
                'builder' => $builder1,
                'limit'   => 10,
                'page'    => 1,
            ]
        );


        $I->assertEquals(
            $builder1,
            $paginator->getQueryBuilder()
        );


        $builder2 = $manager->createBuilder()
                            ->columns('cedula, nombres')
                            ->from(Personnes::class)
        ;

        $setterResult = $paginator->setQueryBuilder($builder2);

        $I->assertEquals(
            $builder2,
            $paginator->getQueryBuilder()
        );

        $I->assertEquals($paginator, $setterResult);
    }
}
