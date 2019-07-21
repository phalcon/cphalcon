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

namespace Phalcon\Test\Integration\Mvc\View;

use IntegrationTester;
use Phalcon\Mvc\View;

class GetSetMainViewCest
{
    /**
     * Tests Phalcon\Mvc\View :: getMainView() / setMainView()
     */
    public function mvcViewGetSetMainView(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getMainView() / setMainView()');

        $view = new View();

        $view->setMainView('html5');

        $I->assertEquals(
            'html5',
            $view->getMainView()
        );
    }
}
