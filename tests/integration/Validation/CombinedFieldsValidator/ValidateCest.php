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

namespace Phalcon\Test\Integration\Validation\CombinedFieldsValidator;

use IntegrationTester;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\CombinedFieldsValidator :: validate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationCombinedfieldsvalidatorValidate(IntegrationTester $I)
    {
        $I->wantToTest('Validation\CombinedFieldsValidator - validate()');
        $I->skipTest('Need implementation');
    }
}
