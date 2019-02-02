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

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;

/**
 * Class GetSqlCest
 */
class GetSqlCest
{
    /**
     * Tests Phalcon\Mvc\Model\Query :: getSql()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelQueryGetSql(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Query - getSql()');
        $I->skipTest('Need implementation');
    }
}
