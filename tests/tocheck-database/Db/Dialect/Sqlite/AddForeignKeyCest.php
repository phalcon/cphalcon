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
use Phalcon\Db\Reference;

class AddForeignKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: addForeignKey()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function testAddForeignKey(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Sqlite - addForeignKey()");

        $dialect = new Sqlite();

        $I->expectThrowable(
            new Exception(
                'Adding a foreign key constraint to an existing table is not supported by SQLite'
            ),
            function () use ($dialect) {
                $reference = new Reference(
                    'fk1',
                    [
                        'referencedTable'   => 'ref_table',
                        'columns'           => ['column1'],
                        'referencedColumns' => ['column2'],
                    ]
                );

                $dialect->addForeignKey(
                    'table',
                    'schema',
                    $reference
                );
            }
        );
    }
}
