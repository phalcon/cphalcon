<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Php;

use Error;
use Phalcon\Mvc\View\Engine\Php as PhpEngine;
use Phalcon\Mvc\View\Simple;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function ob_end_clean;
use function ob_start;

class RenderTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEnginePhpRender(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view   = $this->container->get('viewSimple');
        $engine = new PhpEngine($view);
        $path   = $view->getViewsDir() . 'simple/index.phtml';

        ob_start();
        $engine->render($path, [], true);
        ob_end_clean();

        $this->assertSame('We are here', $view->getContent());
    }

    /**
     * A view parameter named after an engine local (`path`) must not replace
     * the file that is included.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testMvcViewEnginePhpRenderIgnoresPathParameter(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view   = $this->container->get('viewSimple');
        $engine = new PhpEngine($view);
        $path   = $view->getViewsDir() . 'simple/index.phtml';

        ob_start();
        $engine->render($path, ['path' => '/etc/hostname', 'mustClean' => false], true);
        ob_end_clean();

        $this->assertSame('We are here', $view->getContent());
    }

    /**
     * A parameter named "this" throws, as in cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/921
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    public function testMvcViewEnginePhpRenderThisParameter(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        /** @var Simple $view */
        $view   = $this->container->get('viewSimple');
        $engine = new PhpEngine($view);
        $path   = $view->getViewsDir() . 'simple/index.phtml';

        $this->expectException(Error::class);
        $this->expectExceptionMessage('Cannot re-assign $this');

        ob_start();
        try {
            $engine->render($path, ['this' => 'x'], true);
        } finally {
            ob_end_clean();
        }
    }
}
