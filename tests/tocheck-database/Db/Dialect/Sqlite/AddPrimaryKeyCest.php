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

namespace Phalcon\Tests\Integration\Db\Dialect\Sqlite;

use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Db\Exception;
use Phalcon\Db\Index;

class AddPrimaryKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: addPrimaryKey()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function dbDialectSqliteAddPrimaryKey(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Sqlite - addPrimaryKey()");

        $dialect = new Sqlite();

        $index = new Index(
            'index1',
            [
                'column1',
            ]
        );

        $I->expectThrowable(
            new Exception(
                'Adding a primary key after table has been created is not supported by SQLite'
            ),
            function () use ($dialect, $index) {
                $dialect->addPrimaryKey(
                    'table',
                    'schema',
                    $index
                );
            }
        );
    }
}
