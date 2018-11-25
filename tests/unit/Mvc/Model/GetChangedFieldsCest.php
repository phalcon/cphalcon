<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model;

use UnitTester;

class GetChangedFieldsCest
{
    /**
     * Tests Phalcon\Mvc\Model :: getChangedFields()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelGetChangedFields(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model - getChangedFields()");
        $I->skipTest("Need implementation");
    }
}
