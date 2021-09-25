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

class RollbackSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: rollbackSavepoint()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     */
    public function dbDialectSqliteRollbackSavepoint(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - rollbackSavepoint()');

        $dialect = new Sqlite();

        $I->assertEquals(
            'ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1',
            $dialect->rollbackSavepoint('PH_SAVEPOINT_1')
        );
    }
}
