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

namespace Phalcon\Test\Unit\Validation\Validator\Between;

use UnitTester;

class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Between :: validate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function validationValidatorBetweenValidate(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\Between - validate()');

        $I->skipTest('Need implementation');
    }
}
