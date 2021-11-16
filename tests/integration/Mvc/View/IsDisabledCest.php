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

namespace Phalcon\Tests\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;

class IsDisabledCest
{
    /**
     * Tests Phalcon\Mvc\View :: isDisabled()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-22
     */
    public function mvcViewIsDisabled(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - isDisabled()');

        $view = new View();

        $I->assertFalse(
            $view->isDisabled()
        );

        $view->disable();

        $I->assertTrue(
            $view->isDisabled()
        );

        $view->enable();

        $I->assertFalse(
            $view->isDisabled()
        );
    }
}
