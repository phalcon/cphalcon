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

namespace Phalcon\Tests\Benchmarks\Html;

use Phalcon\Html\Escaper;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class EscaperBench
{
    private const EXPECTED = 'Product &lt;b&gt;7&lt;/b&gt; &amp; &quot;friends&quot;';

    private const INPUT = 'Product <b>7</b> & "friends"';

    private Escaper $escaper;

    public function setUp(): void
    {
        $this->escaper = new Escaper();
    }

    public function benchHtml(): void
    {
        $actual = $this->escaper->html(self::INPUT);

        if (self::EXPECTED !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $actual));
        }
    }
}
