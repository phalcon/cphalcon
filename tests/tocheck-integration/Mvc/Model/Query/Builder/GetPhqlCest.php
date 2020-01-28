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

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Snapshot\Robots;

class GetPhqlCest
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: getPhql()
     *
     * Test checks passing query params and dependency injector into
     * constructor
     */
    public function mvcModelQueryBuilderGetPhql(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - getPhql()');

        $params = [
            'models'     => Robots::class,
            'columns'    => ['id', 'name', 'status'],
            'conditions' => 'a > 5',
            'group'      => ['type', 'source'],
            'having'     => 'b < 5',
            'order'      => ['name', 'created'],
            'limit'      => 10,
            'offset'     => 15,
        ];

        $builder = new Builder($params, $this->container);

        $expectedPhql = 'SELECT id, name, status FROM [' . Robots::class . '] '
            . 'WHERE a > 5 GROUP BY [type], [source] '
            . 'HAVING b < 5 ORDER BY [name], [created] '
            . 'LIMIT :APL0: OFFSET :APL1:';

        $I->assertEquals(
            $expectedPhql,
            $builder->getPhql()
        );
    }
}
