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

use Phalcon\Tests\AbstractUnitTestCase;
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
