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

namespace Phalcon\Test\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Simple;

/**
 * Class UnderscoreGetSetCest
 */
class UnderscoreGetSetCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: __get()/__set()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleUnderscoreGetSet(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - __get()/__set()');

        $view = new Simple();

        $view->foo = 'bar';

        $I->assertEquals(
            'bar',
            $view->foo
        );
    }
}
