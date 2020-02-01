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

class GetCustomFunctionsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: getCustomFunctions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbDialectSqliteGetCustomFunctions(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - getCustomFunctions()');
        $I->skipTest('Need implementation');
    }
}
