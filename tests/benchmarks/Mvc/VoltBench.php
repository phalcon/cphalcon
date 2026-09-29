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

namespace Phalcon\Tests\Benchmarks\Mvc;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class VoltBench
{
    private const EXPECTED_SHA1 = '73bcae84d8942ae94094863e982a4e0d5d9bedcb';

    private Compiler $compiler;

    private string $template = '';

    public function setUp(): void
    {
        $this->compiler = new Compiler();
        $this->template = (string) file_get_contents(
            dirname(__DIR__) . '/Apps/Mvc/views/products/show.volt'
        );
    }

    /**
     * Compiles the product view (loop, filters, function call, partial) to PHP code.
     */
    public function benchCompileString(): void
    {
        $code   = $this->compiler->compileString($this->template);
        $actual = sha1($code);

        if (self::EXPECTED_SHA1 !== $actual) {
            throw new RuntimeException(sprintf('Unexpected code (sha1 %s): %s', $actual, $code));
        }
    }
}
