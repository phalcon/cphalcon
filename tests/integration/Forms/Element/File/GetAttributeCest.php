<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Forms\Element\File;

use IntegrationTester;

class GetAttributeCest
{
    /**
     * Tests Phalcon\Forms\Element\File :: getAttribute()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function formsElementFileGetAttribute(IntegrationTester $I)
    {
        $I->wantToTest("Forms\Element\File - getAttribute()");
        $I->skipTest("Need implementation");
    }
}
