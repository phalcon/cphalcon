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

use Phalcon\Mvc\View;
use Phalcon\Tests\AbstractUnitTestCase;

class StartTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewStart(): void
    {
        $view   = new View();
        $result = $view->start();
        $this->assertInstanceOf(View::class, $result);
        $view->finish();
    }

    /**
     * Regression coverage for [#17041]: View::start() must leave $content
     * as an empty string so that View::getContent() (declared `-> string`)
     * does not throw a TypeError. Application::handle() calls getContent()
     * after start() on every request, so a null assignment in start() is
     * not survivable from userland.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-21
     */
    public function testMvcViewStartLeavesContentAsEmptyString(): void
    {
        $view = new View();
        $view->start();

        $this->assertSame('', $view->getContent());

        $view->finish();
    }
}
