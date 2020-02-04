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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;

class ModifyColumnCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: modifyColumn()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-26
     */
    public function dbDialectSqliteModifyColumn(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - modifyColumn()');

        $dialect = new Sqlite();

        $I->expectThrowable(
            new Exception('Altering a DB column is not supported by SQLite'),
            function () use ($dialect) {
                $oldColumn = new Column(
                    'old',
                    [
                        'type' => Column::TYPE_VARCHAR,
                    ]
                );

                $newColumn = new Column(
                    'new',
                    [
                        'type' => Column::TYPE_VARCHAR,
                    ]
                );

                $dialect->modifyColumn(
                    'table',
                    'schema',
                    $newColumn,
                    $oldColumn
                );
            }
        );
    }
}
