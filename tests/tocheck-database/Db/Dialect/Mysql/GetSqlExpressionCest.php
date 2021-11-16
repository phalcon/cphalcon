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

namespace Phalcon\Tests\Integration\Db\Dialect\Mysql;

use IntegrationTester;

class GetSqlExpressionCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: getSqlExpression()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbDialectMysqlGetSqlExpression(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - getSqlExpression()');
        $I->skipTest('Need implementation');
    }
}
