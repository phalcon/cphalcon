<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use IntegrationTester;

class ExistsBelongsToCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: existsBelongsTo()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelManagerExistsBelongsTo(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Manager - existsBelongsTo()");
        $I->skipTest("Need implementation");
    }
}
