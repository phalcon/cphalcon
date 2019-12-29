<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Forms\Element\Check;

use IntegrationTester;

/**
 * Class GetValidatorsCest
 */
class GetValidatorsCest
{
    /**
     * Tests Phalcon\Forms\Element\Check :: getValidators()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function formsElementCheckGetValidators(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Check - getValidators()');
        $I->skipTest('Need implementation');
    }
}
