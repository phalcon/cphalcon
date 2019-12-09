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

class GetSetPartialsDirCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: getPartialsDir() / setPartialsDir()
     */
    public function mvcViewGetSetPartialsDir(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getPartialsDir() / setPartialsDir()');

        $view = new View();

        $view->setBasePath(
            dataDir()
        );

        $view->setPartialsDir('views/partials/');

        $I->assertEquals(
            'views/partials/',
            $view->getPartialsDir()
        );
    }
}
