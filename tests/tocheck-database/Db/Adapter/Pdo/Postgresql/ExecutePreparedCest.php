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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;

/**
 * Class ExecutePreparedCest
 */
class ExecutePreparedCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: executePrepared()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresqlExecutePrepared(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Postgresql - executePrepared()');
        $I->skipTest('Need implementation');
    }
}
