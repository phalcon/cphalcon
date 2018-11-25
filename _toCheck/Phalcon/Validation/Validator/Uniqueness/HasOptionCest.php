<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Validation\Validator\Uniqueness;

use UnitTester;

class HasOptionCest
{
    /**
     * Tests Phalcon\Validation\Validator\Uniqueness :: hasOption()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationValidatorUniquenessHasOption(UnitTester $I)
    {
        $I->wantToTest("Validation\Validator\Uniqueness - hasOption()");
        $I->skipTest("Need implementation");
    }
}
