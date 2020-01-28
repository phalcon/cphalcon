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

class ConstructCest
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - __construct()');

        $I->skipTest('Need implementation');
    }

    /**
     * Test checks passing dependency injector into constructor
     */
    public function testConstructor(IntegrationTester $I)
    {
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

        $I->assertEquals(
            $this->container,
            $builder->getDI()
        );
    }

    /**
     * Test checks passing 'limit'/'offset' query param into constructor.
     * limit key can take:
     * - single numeric value
     * - array of 2 values (limit, offset)
     */
    public function testConstructorLimit(IntegrationTester $I)
    {
        // separate limit and offset
        $params = [
            'models' => Robots::class,
            'limit'  => 10,
            'offset' => 15,
        ];

        $builderLimitAndOffset = new Builder($params);

        // separate limit with offset

        $params = [
            'models' => Robots::class,
            'limit'  => [10, 15],
        ];

        $builderLimitWithOffset = new Builder($params);

        $expectedPhql = 'SELECT [' . Robots::class . '].* FROM [' . Robots::class . '] LIMIT :APL0: OFFSET :APL1:';

        $I->assertEquals(
            $expectedPhql,
            $builderLimitAndOffset->getPhql()
        );

        $I->assertEquals(
            $expectedPhql,
            $builderLimitWithOffset->getPhql()
        );
    }
}
