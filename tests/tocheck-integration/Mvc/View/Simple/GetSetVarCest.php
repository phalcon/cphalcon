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
 * Class GetSetVarCest
 */
class GetSetVarCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: getVar()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleGeSettVar(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - getVar()/setVar()');

        $view = new Simple();

        $I->assertEquals(
            $view,
            $view->setVar('foo1', 'bar1')
        );

        $I->assertEquals(
            'bar1',
            $view->getVar('foo1')
        );
    }
}
