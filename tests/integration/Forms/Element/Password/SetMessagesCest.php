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

namespace Phalcon\Test\Integration\Forms\Element\Password;

use IntegrationTester;

/**
 * Class SetMessagesCest
 */
class SetMessagesCest
{
    /**
     * Tests Phalcon\Forms\Element\Password :: setMessages()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementPasswordSetMessages(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Password - setMessages()');
        $I->skipTest('Need implementation');
    }
}
