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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Engine\Volt\Exceptions\InvalidCompilationPrefix;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

class GetUniquePrefixTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerGetUniquePrefix(): void
    {
        $compiler = new Compiler();
        $compiler->setUniquePrefix('myprefix');

        $this->assertSame('myprefix', $compiler->getUniquePrefix());
    }

    /**
     * Before a compile there is no path, so there is no prefix: it throws,
     * the same as cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/821
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcViewEngineVoltCompilerGetUniquePrefixBeforeCompile(): void
    {
        $compiler = new Compiler();

        $this->expectException(InvalidCompilationPrefix::class);
        $this->expectExceptionMessage('The unique compilation prefix is invalid');

        $compiler->getUniquePrefix();
    }
}
