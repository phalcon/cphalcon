<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Interpolator\AssociativeArray;

use Phalcon\Translate\Interpolator\AssociativeArray;
use UnitTester;

/**
 * Class ReplacePlaceholdersCest
 */
class ReplacePlaceholdersCest
{
    /**
     * Tests Phalcon\Translate\Interpolator\AssociativeArray ::
     * replacePlaceholders()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateInterpolatorAssociativearrayReplacePlaceholders(UnitTester $I)
    {
        $I->wantToTest('Translate\Interpolator\AssociativeArray - replacePlaceholders()');
        $interpolator = new AssociativeArray();

        $expected = 'Hello, John D. Doe!';

        $stringFrom = 'Hello, %fname% %mname% %lname%!';
        $actual     = $interpolator->replacePlaceholders(
            $stringFrom,
            [
                'fname' => 'John',
                'lname' => 'Doe',
                'mname' => 'D.',
            ]
        );

        $I->assertEquals($expected, $actual);
    }
}
