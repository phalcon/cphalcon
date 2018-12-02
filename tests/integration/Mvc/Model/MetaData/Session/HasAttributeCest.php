<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\MetaData\Session;

use IntegrationTester;

class HasAttributeCest
{
    /**
     * Tests Phalcon\Mvc\Model\MetaData\Session :: hasAttribute()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelMetadataSessionHasAttribute(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\MetaData\Session - hasAttribute()");
        $I->skipTest("Need implementation");
    }
}
