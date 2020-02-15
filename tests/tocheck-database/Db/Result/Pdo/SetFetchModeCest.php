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

namespace Phalcon\Test\Integration\Db\Result\Pdo;

use IntegrationTester;

class SetFetchModeCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: setFetchMode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbResultPdoSetFetchMode(IntegrationTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - setFetchMode()');
        $I->skipTest('Need implementation');
    }
}
