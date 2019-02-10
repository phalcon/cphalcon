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

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

use UnitTester;

/**
 * Class PrepareCest
 */
class PrepareCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo :: prepare()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbAdapterPdoPrepare(UnitTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo - prepare()');
        $I->skipTest('Need implementation');
    }
}
