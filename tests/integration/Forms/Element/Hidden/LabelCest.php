<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element\Hidden;

use IntegrationTester;

class LabelCest
{
    /**
     * Tests Phalcon\Forms\Element\Hidden :: label()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementHiddenLabel(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Element\Hidden - label()");
        $I->skipTest("Need implementation");
    }
}
