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

class GetSetLayoutCest
{
    /**
     * Tests Phalcon\Mvc\View :: getLayout()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewGetLayout(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View - getLayout()');

        $view = new View();

        $view->setLayout('test2');

        $I->assertEquals(
            'test2',
            $view->getLayout()
        );
    }
}
