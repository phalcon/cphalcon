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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

class CompileAutoEscapeTest extends AbstractUnitTestCase
{
    use DiTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileAutoEscape(): void
    {
        $this->setNewFactoryDefault();

        $compiler = new Compiler();
        $compiler->setDI($this->container);

        $actual = $compiler->compileString(
            '{% autoescape true %}{{ "hello" }}{% endautoescape %}'
        );
        $this->assertSame("<?= \$this->escaper->html('hello') ?>", $actual);
    }
}
