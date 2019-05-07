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

class ConstructCest
{
    /**
     * Tests Phalcon\Validation\CombinedFieldsValidator :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function validationCombinedFieldsValidatorConstruct(UnitTester $I)
    {
        $I->wantToTest('Validation\CombinedFieldsValidator - __construct()');

        $I->skipTest('Need implementation');
    }
}
