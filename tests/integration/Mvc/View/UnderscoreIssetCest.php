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
use Phalcon\Test\Fixtures\Traits\ViewTrait;

class UnderscoreIssetCest
{
    use ViewTrait;

    /**
     * Tests Phalcon\Mvc\View :: __isset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewUnderscoreIsset(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\View - __isset()");

        $view = new View();

        $view->setViewsDir(
            dataDir('fixtures/views')
        );

        $view->param = 'something';

        $content = $view->getRender('simple', 'isset');

        $I->assertEquals(
            '1',
            $content
        );
    }
}
