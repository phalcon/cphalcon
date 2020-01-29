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

class GetActionNameCest
{
    /**
     * Tests Phalcon\Mvc\View :: getActionName()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewGetActionName(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getActionName()');

        $view = new View();

        $view->setViewsDir(
            dataDir('fixtures/views')
        );

        $view->start();

        $view->render('simple', 'index');

        $view->finish();

        $I->assertEquals(
            'index',
            $view->getActionName()
        );
    }
}
