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

namespace Phalcon\Tests\Integration\Db\Dialect\Postgresql;

use IntegrationTester;

class GetCustomFunctionsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getCustomFunctions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbDialectPostgresqlGetCustomFunctions(IntegrationTester $I)
    {
        $I->wantToTest('Db\Dialect\Postgresql - getCustomFunctions()');
        $I->skipTest('Need implementation');
    }
}
