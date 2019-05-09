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

class NumRowsCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: numRows()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbResultPdoNumRows(UnitTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - numRows()');

        $I->skipTest('Need implementation');
    }
}
