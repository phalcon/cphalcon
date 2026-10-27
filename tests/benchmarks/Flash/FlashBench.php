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

namespace Phalcon\Tests\Benchmarks\Flash;

use Phalcon\Di\Di;
use Phalcon\Flash\Direct;
use Phalcon\Html\Escaper;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class FlashBench
{
    private const EXPECTED_OUTPUT = '<div class="successMessage">Robot &lt;b&gt;saved&lt;/b&gt;</div>' . PHP_EOL
        . '<div class="errorMessage">Robot &lt;b&gt;not saved&lt;/b&gt;</div>' . PHP_EOL
        . '<div class="noticeMessage">Robot &lt;b&gt;changed&lt;/b&gt;</div>' . PHP_EOL
        . '<div class="warningMessage">Robot &lt;b&gt;old&lt;/b&gt;</div>' . PHP_EOL;

    private Direct $flash;

    public function setUp(): void
    {
        Di::reset();

        $this->flash = new Direct(new Escaper());
        $this->flash->setImplicitFlush(false);
    }

    /**
     * 4 messages, one of each type. Each text has HTML, so the escaper runs.
     */
    public function benchMessages(): void
    {
        $actual = $this->flash->success('Robot <b>saved</b>')
            . $this->flash->error('Robot <b>not saved</b>')
            . $this->flash->notice('Robot <b>changed</b>')
            . $this->flash->warning('Robot <b>old</b>');

        if (self::EXPECTED_OUTPUT !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $actual));
        }
    }
}
