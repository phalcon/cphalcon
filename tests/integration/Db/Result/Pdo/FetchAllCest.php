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

namespace Phalcon\Test\Integration\Db\Result\Pdo;

use IntegrationTester;

/**
 * Class FetchAllCest
 */
class FetchAllCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: fetchAll()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbResultPdoFetchAll(IntegrationTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - fetchAll()');
        $I->skipTest('Need implementation');
    }
}
