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

namespace Phalcon\Tests\Unit\Mvc\View\Simple;

use Phalcon\Mvc\View\Simple;
use Phalcon\Tests\AbstractUnitTestCase;

class GetSetParamsToViewTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleGetSetParamsToView(): void
    {
        $view = new Simple();

        $expected = [
            'foo2' => 'bar2',
            'foo3' => 'bar3',
        ];

        $this->assertEquals(
            $view,
            $view->setVars($expected)
        );
        $this->assertEquals(
            $view,
            $view->setParamToView('foo4', 'bar4')
        );

        $expectedParamsToView = [
            'foo2' => 'bar2',
            'foo3' => 'bar3',
            'foo4' => 'bar4',
        ];

        $this->assertEquals(
            $expectedParamsToView,
            $view->getParamsToView()
        );
    }
}
