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
 * Class SetOptionCest
 */
class SetOptionCest
{
    /**
     * Tests Phalcon\Validation\CombinedFieldsValidator :: setOption()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function validationCombinedfieldsvalidatorSetOption(IntegrationTester $I)
    {
        $I->wantToTest('Validation\CombinedFieldsValidator - setOption()');
        $I->skipTest('Need implementation');
    }
}
