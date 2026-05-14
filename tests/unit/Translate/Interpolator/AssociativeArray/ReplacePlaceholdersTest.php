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

namespace Phalcon\Tests\Unit\Translate\Interpolator\AssociativeArray;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Translate\Interpolator\AssociativeArray;

final class ReplacePlaceholdersTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateInterpolatorAssociativearrayReplacePlaceholders(): void
    {

        $interpolator = new AssociativeArray();

        $stringFrom = 'Hello, %fname% %mname% %lname%!';

        $actual = $interpolator->replacePlaceholders($stringFrom, ['fname' => 'John',
                                                                   'lname' => 'Doe',
                                                                   'mname' => 'D.',]);

        $this->assertSame('Hello, John D. Doe!', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateInterpolatorAssociativearrayReplacePlaceholdersWithNoPlaceholders(): void
    {
        $interpolator = new AssociativeArray();

        $source   = 'Hello, %fname% %mname% %lname%!';
        $expected = $source;
        $actual   = $interpolator->replacePlaceholders($source, []);
        $this->assertSame($expected, $actual);
    }
}
