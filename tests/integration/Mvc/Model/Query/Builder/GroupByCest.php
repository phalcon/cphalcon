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

namespace Phalcon\Test\Integration\Mvc\Model\Query\Builder;

use IntegrationTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Snapshot\Robots;

class GroupByCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiMysql();
    }

    /**
     * Tests Phalcon\Mvc\Model\Query\Builder :: groupBy()
     */
    public function mvcModelQueryBuilderGroupBy(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - groupBy()');

        $builder = new Builder();

        $phql = $builder->setDi($this->container)
                        ->columns(['name', 'SUM(price)'])
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
