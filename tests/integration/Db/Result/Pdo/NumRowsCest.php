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
 * Class NumRowsCest
 */
class NumRowsCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: numRows()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbResultPdoNumRows(IntegrationTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - numRows()');
        $I->skipTest('Need implementation');
    }
}
