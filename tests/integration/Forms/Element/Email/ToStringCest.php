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
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Forms\Element\Email :: __toString()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementEmailToString(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Element\Email - __toString()');
        $I->skipTest('Need implementation');
    }
}
