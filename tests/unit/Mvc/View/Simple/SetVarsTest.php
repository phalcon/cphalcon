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

class SetVarsTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewSimpleSetVars(): void
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
            'bar2',
            $view->foo2
        );

        $this->assertEquals(
            'bar3',
            $view->foo3
        );

        $this->assertEquals(
            $view,
            $view->setVars($expected, false)
        );
    }
}
