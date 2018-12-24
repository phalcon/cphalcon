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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;

/**
 * Class DropIndexCest
 */
class DropIndexCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: dropIndex()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresqlDropIndex(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Postgresql - dropIndex()');
        $I->skipTest('Need implementation');
    }
}
