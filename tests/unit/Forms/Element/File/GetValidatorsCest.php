<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Forms\Element\File;

use UnitTester;

class GetValidatorsCest
{
    /**
     * Tests Phalcon\Forms\Element\File :: getValidators()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementFileGetValidators(UnitTester $I)
    {
        $I->wantToTest("Forms\Element\File - getValidators()");
        $I->skipTest("Need implementation");
    }
}
