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

namespace Phalcon\Tests\Benchmarks\Filter;

use Phalcon\Filter\FilterFactory;
use Phalcon\Filter\FilterInterface;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class FilterBench
{
    private const EXPECTED = 'Some text';

    private const INPUT = '  <b>Some</b> text  ';

    private FilterInterface $filter;

    public function setUp(): void
    {
        $this->filter = (new FilterFactory())->newInstance();
    }

    public function benchSanitize(): void
    {
        $actual = $this->filter->sanitize(self::INPUT, ['striptags', 'trim']);

        if (self::EXPECTED !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: "%s"', $actual));
        }
    }
}
