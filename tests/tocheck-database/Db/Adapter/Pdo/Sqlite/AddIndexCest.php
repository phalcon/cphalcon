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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

/**
 * Class AddIndexCest
 */
class AddIndexCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: addIndex()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteAddIndex(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - addIndex()');
        $I->skipTest('Need implementation');
    }
}
