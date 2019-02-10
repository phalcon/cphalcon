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

namespace Phalcon\Test\Unit\Db\Reference;

use UnitTester;

/**
 * Class GetReferencedColumnsCest
 */
class GetReferencedColumnsCest
{
    /**
     * Tests Phalcon\Db\Reference :: getReferencedColumns()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbReferenceGetReferencedColumns(UnitTester $I)
    {
        $I->wantToTest('Db\Reference - getReferencedColumns()');
        $I->skipTest('Need implementation');
    }
}
