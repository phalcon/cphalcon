<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element\Password;

use IntegrationTester;

class SetAttributesCest
{
    /**
     * Tests Phalcon\Forms\Element\Password :: setAttributes()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementPasswordSetAttributes(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Element\Password - setAttributes()");
        $I->skipTest("Need implementation");
    }
}
