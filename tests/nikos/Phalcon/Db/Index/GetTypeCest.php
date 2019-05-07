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

namespace Phalcon\Test\Unit\Db\Index;

use UnitTester;

class GetTypeCest
{
    /**
     * Tests Phalcon\Db\Index :: getType()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbIndexGetType(UnitTester $I)
    {
        $I->wantToTest('Db\Index - getType()');

        $I->skipTest('Need implementation');
    }
}
