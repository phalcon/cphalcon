<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Integration\Mvc\Application;

use IntegrationTester;

class GetSetDICest
{
    /**
     * Tests Phalcon\Mvc\Application :: getDI() / setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcApplicationGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Application - getDI() / setDI()');

        $I->skipTest('Need implementation');
    }
}
