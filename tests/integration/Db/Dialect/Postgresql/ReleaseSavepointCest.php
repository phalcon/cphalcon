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

namespace Phalcon\Test\Integration\Db\Dialect\Postgresql;

use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql;

class ReleaseSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: releaseSavepoint()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectPostgresqlReleaseSavepoint(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - releaseSavepoint()');

        $dialect = new Postgresql();

        $I->assertEquals(
            'RELEASE SAVEPOINT PH_SAVEPOINT_1',
            $dialect->releaseSavepoint('PH_SAVEPOINT_1')
        );
    }
}
