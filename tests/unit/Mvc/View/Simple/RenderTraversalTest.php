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

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Mvc\Fake\ViewTrait;
use Throwable;

use function file_put_contents;
use function ob_end_clean;
use function ob_get_level;
use function ob_start;
use function str_contains;

final class RenderTraversalTest extends AbstractUnitTestCase
{
    use DiTrait;
    use ViewTrait;

    public function setUp(): void
    {
        $this->newDi();
        $this->setDiService('viewSimple');

        ob_start();
    }

    public function tearDown(): void
    {
        if (ob_get_level()) {
            ob_end_clean();
        }
    }

    /**
     * A `..` in the render path must not climb out of the views directory to
     * include a file the developer never exposed (CWE-22 / CWE-98).
     */
    public function testMvcViewSimpleRenderCannotTraverse(): void
    {
        // A template one level ABOVE the views dir that a traversal reaches.
        $secret = Talon::settings()->supportPath('assets/pwned-view.phtml');
        file_put_contents($secret, 'LEAKED-VIA-TRAVERSAL');

        $view = $this->container->get('viewSimple');

        $leaked     = false;
        $startLevel = ob_get_level();

        try {
            $output = $view->render('../pwned-view');
            $leaked = str_contains((string) $output, 'LEAKED-VIA-TRAVERSAL');
        } catch (Throwable $ex) {
            // After the fix the path resolves inside the views dir and is not
            // found, so rendering throws instead of leaking the outside file.
            while (ob_get_level() > $startLevel) {
                ob_end_clean();
            }
        }

        $this->safeDeleteFile($secret);

        $this->assertFalse($leaked);
    }

    /**
     * Backslashes are path separators on Windows. They are normalized before
     * the `..` filter, so `..\\view` resolves inside the views directory
     * instead of one level above it.
     */
    public function testMvcViewSimpleRenderCannotTraverseWithBackslash(): void
    {
        $view = $this->container->get('viewSimple');

        $expected = 'here';
        $actual   = $view->render('..\\currentrender\\other');

        $this->assertSame($expected, $actual);
    }
}
