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

namespace Phalcon\Test\Unit\Validation\CombinedFieldsValidator;

use UnitTester;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\CombinedFieldsValidator :: validate()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function validationCombinedFieldsValidatorValidate(UnitTester $I)
    {
        $I->wantToTest('Validation\CombinedFieldsValidator - validate()');
        $I->skipTest('Need implementation');
    }
}
