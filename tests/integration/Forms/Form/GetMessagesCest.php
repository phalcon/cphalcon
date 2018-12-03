<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;

class GetMessagesCest
{
    /**
     * Tests Phalcon\Forms\Form :: getMessages()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsFormGetMessages(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Form - getMessages()");
        $I->skipTest("Need implementation");
    }
}
