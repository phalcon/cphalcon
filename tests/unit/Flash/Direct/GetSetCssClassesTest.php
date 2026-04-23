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
use Phalcon\Tests\AbstractUnitTestCase;

use function ksort;

final class GetSetCssClassesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectGetSetCssClasses(): void
    {
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
        $this->assertSame($expected, $actual);

        $flash->setCssClasses($newClasses);

        $expected = $newClasses;
        $actual   = $flash->getCssClasses();
        ksort($actual);
        $this->assertSame($expected, $actual);
    }
}
