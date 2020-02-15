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

namespace Phalcon\Test\Integration\Db\Dialect\Postgresql;

use IntegrationTester;

class GetSqlExpressionCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getSqlExpression()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbDialectPostgresqlGetSqlExpression(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - getSqlExpression()');
        $I->skipTest('Need implementation');
    }
}
