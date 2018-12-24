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

namespace Phalcon\Test\Integration\Forms\Element\Email;

use IntegrationTester;

/**
 * Class AppendMessageCest
 */
class AppendMessageCest
{
    /**
     * Tests Phalcon\Forms\Element\Email :: appendMessage()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementEmailAppendMessage(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - appendMessage()');
        $I->skipTest('Need implementation');
    }
}
