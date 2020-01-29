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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;
use Phalcon\Test\Fixtures\Traits\ViewTrait;

class GetSetVarCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: getVar() / setVar()
     */
    public function mvcViewGetSetVar(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getVar() / setVar()');

        $view = new View();

        $view->setVar('foo1', 'bar1');

        $I->assertEquals(
            'bar1',
            $view->getVar('foo1')
        );
    }
}
