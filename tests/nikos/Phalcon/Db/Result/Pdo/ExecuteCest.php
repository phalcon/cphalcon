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
 * Class ExecuteCest
 */
class ExecuteCest
{
    /**
     * Tests Phalcon\Db\Result\Pdo :: execute()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbResultPdoExecute(UnitTester $I)
    {
        $I->wantToTest('Db\Result\Pdo - execute()');
        $I->skipTest('Need implementation');
    }
}
