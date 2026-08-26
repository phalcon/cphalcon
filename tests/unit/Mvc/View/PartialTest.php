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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use Throwable;

use function file_put_contents;
use function ob_end_clean;
use function ob_get_clean;
use function ob_get_level;
use function ob_start;
use function str_contains;

class PartialTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewPartial(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(Talon::settings()->supportPath('assets/views'))
        );
        $view->setPartialsDir('partials/');
        $view->setDI($container);

        ob_start();
        $view->partial('partial', ['cool_var' => 'abcde']);
        $actual = ob_get_clean();

        $this->assertSame('Hey, this is a partial, also abcde', $actual);
    }

    /**
     * Backslashes are path separators on Windows. They are normalized before
     * the `..` filter, so `..\\partial` resolves inside the partials
     * directory instead of one level above it.
     */
    public function testMvcViewPartialCannotTraverseWithBackslash(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(Talon::settings()->supportPath('assets/views'))
        );
        $view->setPartialsDir('partials/');
        $view->setDI($container);

        ob_start();
        $view->partial('..\\partial', ['cool_var' => 'abcde']);
        $actual = ob_get_clean();

        $this->assertSame('Hey, this is a partial, also abcde', $actual);
    }

    /**
     * An absolute partial path is used as is, ignoring basePath/viewsDir
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17426
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-01
     */
    public function testMvcViewPartialAbsolutePath(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(Talon::settings()->supportPath('assets/views'))
        );
        $view->setDI($container);

        ob_start();
        $view->partial(
            Talon::settings()->supportPath('assets/views/partials/partial'),
            ['cool_var' => 'abcde']
        );
        $actual = ob_get_clean();

        $this->assertSame('Hey, this is a partial, also abcde', $actual);
    }

    /**
     * A `..` in the partial path must not climb out of the partials directory
     * to include a file the developer never exposed (CWE-22 / CWE-98).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testMvcViewPartialCannotTraverse(): void
    {
        // A partial two levels ABOVE the partials dir that a traversal reaches.
        $secret = Talon::settings()->supportPath('assets/pwned-partial.phtml');
        file_put_contents($secret, 'LEAKED-VIA-TRAVERSAL');

        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(Talon::settings()->supportPath('assets/views'))
        );
        $view->setPartialsDir('partials/');
        $view->setDI($container);

        $leaked     = false;
        $startLevel = ob_get_level();

        ob_start();

        try {
            $view->partial('../../pwned-partial');

            $leaked = str_contains(
                (string) ob_get_clean(),
                'LEAKED-VIA-TRAVERSAL'
            );
        } catch (Throwable $ex) {
            // After the fix the path stays inside the partials dir and is not
            // found, so rendering throws instead of leaking the outside file.
            while (ob_get_level() > $startLevel) {
                ob_end_clean();
            }
        }

        $this->safeDeleteFile($secret);

        $this->assertFalse($leaked);
    }

    /**
     * Dropping the `.` and `..` segments must keep a legitimate sub-directory
     * partial working.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testMvcViewPartialSubDirectory(): void
    {
        $container = new Di();
        $view      = new View();

        $view->setViewsDir(
            $this->getDirSeparator(Talon::settings()->supportPath('assets/views'))
        );
        $view->setDI($container);

        ob_start();
        $view->partial('partials/partial', ['cool_var' => 'abcde']);
        $actual = ob_get_clean();

        $this->assertSame('Hey, this is a partial, also abcde', $actual);
    }
}
