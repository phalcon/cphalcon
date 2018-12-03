<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element;

use IntegrationTester;

class AddValidatorsCest
{
    /**
     * Tests Phalcon\Forms\Element :: addValidators()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementAddValidators(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Element - addValidators()");
        $I->skipTest("Need implementation");
    }
}
