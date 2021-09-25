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

use Phalcon\Translate\Interpolator\AssociativeArray;
use UnitTester;

class ReplacePlaceholdersCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\AssociativeArray ::
     * replacePlaceholders()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateInterpolatorAssociativearrayReplacePlaceholders(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\AssociativeArray - replacePlaceholders()');

        $interpolator = new AssociativeArray();

        $stringFrom = 'Hello, %fname% %mname% %lname%!';

        $actual = $interpolator->replacePlaceholders(
            $stringFrom,
            [
                'fname' => 'John',
                'lname' => 'Doe',
                'mname' => 'D.',
            ]
        );

        $I->assertEquals(
            'Hello, John D. Doe!',
            $actual
        );
    }
}
