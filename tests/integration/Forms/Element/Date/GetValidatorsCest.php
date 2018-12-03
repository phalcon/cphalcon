<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element\Date;

use IntegrationTester;

class GetValidatorsCest
{
    /**
     * Tests Phalcon\Forms\Element\Date :: getValidators()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementDateGetValidators(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Element\Date - getValidators()");
        $I->skipTest("Need implementation");
    }
}
