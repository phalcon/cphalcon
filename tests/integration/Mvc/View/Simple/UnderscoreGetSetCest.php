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
     * @author Phalcon Team <team@phalconphp.com>
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
