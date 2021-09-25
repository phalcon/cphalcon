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
use PDO;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Snapshot\Robots;

class WhereCest
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
     * Tests Phalcon\Mvc\Model\Query\Builder :: where()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelQueryBuilderWhere(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder - where()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests merge bind types for Builder::where
     *
     * @issue https://github.com/phalcon/cphalcon/issues/11487
     */
    public function shouldMergeBindTypesForWhere(IntegrationTester $I)
    {
        $builder = new Builder();

        $builder->setDi($this->container);

        $builder
            ->from(Robots::class)
            ->where(
                'id = :id:',
                [
                    ':id:' => 3,
                ],
                [
                    ':id:' => PDO::PARAM_INT,
                ]
            )
        ;

        $builder->where(
            'name = :name:',
            [
                ':name:' => 'Terminator',
            ],
            [
                ':name:' => PDO::PARAM_STR,
            ]
        );

        $expected = [
            ':id:'   => 1,
            ':name:' => 2,
        ];

        $I->assertEquals(
            $expected,
            $builder->getQuery()->getBindTypes()
        );
    }
}
