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

namespace Phalcon\Tests\Integration\Mvc\View\Simple;

use IntegrationTester;
use Phalcon\Mvc\View\Simple;

use function dataDir;

use const DIRECTORY_SEPARATOR;

/**
 * Class GetSetViewsDirCest
 */
class GetSetViewsDirCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: getViewsDir()/setViewsDir()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleGetSetViewsDir(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - getViewsDir()/setViewsDir()');

        $view = new Simple();

        $view->setViewsDir(
            dataDir('views' . DIRECTORY_SEPARATOR)
        );

        $I->assertEquals(
            dataDir('views' . DIRECTORY_SEPARATOR),
            $view->getViewsDir()
        );
    }
}
