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
use Phalcon\Db\Dialect\Mysql;

class SupportsReleaseSavepointsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: supportsReleaseSavepoints()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2017-02-26
     */
    public function dbDialectMysqlSupportsReleaseSavepoints(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Mysql - supportsReleaseSavepoints()');

        $dialect = new Mysql();

        $I->assertTrue(
            $dialect->supportsReleaseSavepoints()
        );
    }
}
