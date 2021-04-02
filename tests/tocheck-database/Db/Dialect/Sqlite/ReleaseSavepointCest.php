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
use Phalcon\Db\Dialect\Sqlite;

class ReleaseSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: releaseSavepoint()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     */
    public function dbDialectSqliteReleaseSavepoint(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - releaseSavepoint()');

        $dialect = new Sqlite();

        $I->assertEquals(
            'RELEASE SAVEPOINT PH_SAVEPOINT_1',
            $dialect->releaseSavepoint('PH_SAVEPOINT_1')
        );
    }
}
