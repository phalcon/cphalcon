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

/**
 * Class SupportsReleaseSavepointsCest
 */
class SupportsReleaseSavepointsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: supportsReleaseSavepoints()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectPostgresqlSupportsReleaseSavepoints(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - supportsReleaseSavepoints()');
        $I->skipTest('Need implementation');
    }
}
