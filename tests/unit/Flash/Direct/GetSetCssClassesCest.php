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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Flash\Direct;
use UnitTester;

use function ksort;

/**
 * Class GetSetCssClassesCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class GetSetCssClassesCest
{
    /**
     * Tests Phalcon\Flash\Direct :: getCssClasses()/setCssClasses()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectGetSetCssClasses(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - getCssClasses()/setCssClasses()');

        $flash = new Direct();

        $expected   = [
            'error'   => 'errorMessage',
            'notice'  => 'noticeMessage',
            'success' => 'successMessage',
            'warning' => 'warningMessage',
        ];
        $newClasses = [
            'error'   => 'alert alert-error',
            'notice'  => 'alert alert-notice',
            'success' => 'alert alert-success',
            'warning' => 'alert alert-warning',
        ];

        $actual = $flash->getCssClasses();
        ksort($actual);
        $I->assertSame($expected, $actual);

        $flash->setCssClasses($newClasses);

        $expected = $newClasses;
        $actual   = $flash->getCssClasses();
        ksort($actual);
        $I->assertSame($expected, $actual);
    }
}
