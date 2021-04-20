<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model\Query\Builder;

use DatabaseTester;
use Phalcon\Mvc\Model\Query\Builder;
use Phalcon\Storage\Exception;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\RecordsTrait;
use Phalcon\Test\Models\Invoices;

class OrderByCest
{
    use DiTrait;
    use RecordsTrait;

    /**
     * Executed before each test
     *
     * @param DatabaseTester $I
     *
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: getSql() - Issue 14657
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-04-20
     * @issue  15411
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelQueryBuilderOrderBy(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Query\Builder :: orderBy()');

        $builder = new Builder();
        $phql    = $builder
            ->columns('inv_id, inv_title')
            ->addFrom(Invoices::class)
            ->orderBy('inv_title')
            ->getPhql()
        ;

        $expected = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'ORDER BY inv_title';
        $actual   = $phql;
        $I->assertEquals($expected, $actual);

        $phql    = $builder
            ->orderBy('inv_title DESC')
            ->getPhql()
        ;

        $expected = 'SELECT inv_id, inv_title '
            . 'FROM [Phalcon\Test\Models\Invoices] '
            . 'ORDER BY inv_title DESC';
        $actual   = $phql;
        $I->assertEquals($expected, $actual);
    }
}
