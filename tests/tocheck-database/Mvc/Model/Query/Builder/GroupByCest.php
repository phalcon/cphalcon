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

namespace Phalcon\Tests\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Snapshot\Robots;

class GroupByCest
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: groupBy()
     */
    public function mvcModelQueryBuilderGroupBy(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - groupBy()');

        $builder = new Builder();
        $builder->setDi($this->container);

        $phql = $builder->columns(['name', 'SUM(price)'])
                        ->from(Robots::class)
                        ->groupBy('id, name')
                        ->getPhql()
        ;

        $I->assertEquals(
            'SELECT name, SUM(price) FROM [' . Robots::class . '] GROUP BY [id], [name]',
            $phql
        );
    }
}
