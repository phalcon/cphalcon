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

/**
 * Class SetVarsCest
 */
class SetVarsCest
{
    /**
     * Tests Phalcon\Mvc\View\Simple :: setVars()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewSimpleSetVars(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Simple - setVars()');

        $view = new Simple();

        $expected = [
            'foo2' => 'bar2',
            'foo3' => 'bar3',
        ];

        $I->assertEquals(
            $view,
            $view->setVars($expected)
        );

        $I->assertEquals(
            'bar2',
            $view->foo2
        );

        $I->assertEquals(
            'bar3',
            $view->foo3
        );

        $I->assertEquals(
            $view,
            $view->setVars($expected, false)
        );
    }
}
