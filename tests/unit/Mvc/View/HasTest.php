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

namespace Phalcon\Tests\Unit\Mvc\View;

use Phalcon\Di\Di;
use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;

use function dataDir;

class HasTest extends AbstractUnitTestCase
{
    /**
     * @author Kamil Skowron <git@hedonsoftware.com>
     * @since  2014-05-28
     */
    public function testMvcViewHas(): void
    {
        $container = new Di();

        $view = new View();

        $view->setViewsDir(
            $this->getDirSeparator(supportDir('assets/views'))
        );

        $view->setDI($container);

        $this->assertTrue(
            $view->has('currentrender/query')
        );

        $this->assertTrue(
            $view->has('currentrender/yup')
        );

        $this->assertFalse(
            $view->has('currentrender/nope')
        );

        $this->assertTrue(
            $view->exists('currentrender/query')
        );

        $this->assertTrue(
            $view->exists('currentrender/yup')
        );

        $this->assertFalse(
            $view->exists('currentrender/nope')
        );
    }
}
