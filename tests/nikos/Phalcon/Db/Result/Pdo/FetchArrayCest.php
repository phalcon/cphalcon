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

namespace Phalcon\Test\Unit\Db\Result\Pdo;

use UnitTester;

/**
 * Class FetchArrayCest
 */
class FetchArrayCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: fetchArray()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbResultPdoFetchArray(UnitTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - fetchArray()');
        $I->skipTest('Need implementation');
    }
}
