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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class GetRealSQLStatementCest
 */
class GetRealSQLStatementCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: getRealSQLStatement()
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @dataProvider getExamples
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-16
     *
     */
    public function dbAdapterPdoMysqlGetRealSQLStatement(
        IntegrationTester $I,
        Example $example
    ) {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - getRealSQLStatement() - ' . $example[0]);

        $this->setNewFactoryDefault();
        $this->setDiMysql();

        /** @var Mysql $db */
        $db = $this->container->get('db');
        $migration = new InvoicesMigration($db);
        $migration->create();

        $db->execute($example[1], $example[2]);

        $expected = $example[3];
        $actual   = $db->getRealSQLStatement();
        $I->assertEquals($expected, $actual);

        $migration->drop();
    }

    /**
     * @return array
     */
    private function getExamples(): array
    {
        return [
            [
                'no parameters',
                'select inv_id, inv_title from co_invoices',
                [],
                'select inv_id, inv_title from co_invoices',
            ],
            [
                'named',
                'select inv_id, inv_title from co_invoices where inv_id = ?',
                [
                    1
                ],
                'select inv_id, inv_title from co_invoices where inv_id = 1',
            ],
            [
                'named',
                'select inv_id, inv_title from co_invoices where inv_id = :id',
                [
                    'id' => 1
                ],
                'select inv_id, inv_title from co_invoices where inv_id = 1',
            ],
            [
                'insert',
                'insert into co_invoices (inv_id, inv_cst_id, ' .
                'inv_status_flag, inv_title, inv_total, inv_created_at) ' .
                'values (?, ?, ?, ?, ?, ?)',
                [
                    4,
                    1,
                    1,
                    "title 4",
                    400,
                    "2020-01-01 01:02:03"
                ],
                "insert into co_invoices (inv_id, inv_cst_id, " .
                "inv_status_flag, inv_title, inv_total, inv_created_at) " .
                "values (4, 1, 1, 'title 4', 400, '2020-01-01 01:02:03')",
            ],
        ];
    }
}
