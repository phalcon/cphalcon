<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;

class AppendMessageCest
{
    /**
     * Tests Phalcon\Mvc\Model :: appendMessage()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelAppendMessage(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model - appendMessage()");
        $I->skipTest("Need implementation");
    }
}
