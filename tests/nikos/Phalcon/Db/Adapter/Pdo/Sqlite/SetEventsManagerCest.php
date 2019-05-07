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

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Sqlite;

use UnitTester;

class SetEventsManagerCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: setEventsManager()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbAdapterPdoSqliteSetEventsManager(UnitTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - setEventsManager()');

        $I->skipTest('Need implementation');
    }
}
