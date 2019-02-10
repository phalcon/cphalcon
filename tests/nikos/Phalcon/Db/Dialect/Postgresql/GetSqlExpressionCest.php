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

namespace Phalcon\Test\Unit\Db\Dialect\Postgresql;

use UnitTester;

/**
 * Class GetSqlExpressionCest
 */
class GetSqlExpressionCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getSqlExpression()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbDialectPostgresqlGetSqlExpression(UnitTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - getSqlExpression()');
        $I->skipTest('Need implementation');
    }
}
