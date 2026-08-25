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

namespace Phalcon\Tests\Unit\Translate\Interpolator\IndexedArray;

use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Translate\Interpolator\IndexedArray;

final class ReplacePlaceholdersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateInterpolatorIndexedarrayReplacePlaceholders(): void
    {

        $interpolator = new IndexedArray();

        $actual = $interpolator->replacePlaceholders('Hello, %s %s %s!', ['John',
                                                                          'D.',
                                                                          'Doe',]);

        $this->assertSame('Hello, John D. Doe!', $actual);
    }

    /**
     * A translation whose format specifiers do not match the given arguments
     * must not raise a ValueError (CWE-134); it is returned unchanged.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testTranslateInterpolatorIndexedarrayReplacePlaceholdersWithMismatchedFormat(): void
    {
        $interpolator = new IndexedArray();

        $expected = '%9$s';
        $actual   = $interpolator->replacePlaceholders('%9$s', ['only-one']);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateInterpolatorIndexedarrayReplacePlaceholdersWithNoPlaceholders(): void
    {

        $interpolator = new IndexedArray();

        $source   = 'Hello, %s %s %s!';
        $expected = $source;
        $actual   = $interpolator->replacePlaceholders('Hello, %s %s %s!', []);
        $this->assertSame($expected, $actual);
    }
}
