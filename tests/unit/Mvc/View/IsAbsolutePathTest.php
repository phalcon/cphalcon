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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

use const PHP_OS;

final class IsAbsolutePathTest extends AbstractUnitTestCase
{
    /**
     * A path that starts with "/" is absolute. All other paths, also the
     * empty path, are relative.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-13
     */
    public function testMvcViewIsAbsolutePath(): void
    {
        if ('WINNT' === PHP_OS) {
            $this->markTestSkipped('Windows uses a different check');
        }

        $view = new View();

        $this->assertTrue($this->callProtectedMethod($view, 'isAbsolutePath', '/'));
        $this->assertTrue($this->callProtectedMethod($view, 'isAbsolutePath', '/srv/views'));
        $this->assertTrue($this->callProtectedMethod($view, 'isAbsolutePath', '//srv'));
        $this->assertFalse($this->callProtectedMethod($view, 'isAbsolutePath', ''));
        $this->assertFalse($this->callProtectedMethod($view, 'isAbsolutePath', 'views/index'));
        $this->assertFalse($this->callProtectedMethod($view, 'isAbsolutePath', './views'));
        $this->assertFalse($this->callProtectedMethod($view, 'isAbsolutePath', 'C:/views'));
        $this->assertFalse($this->callProtectedMethod($view, 'isAbsolutePath', '\\srv'));
    }
}
