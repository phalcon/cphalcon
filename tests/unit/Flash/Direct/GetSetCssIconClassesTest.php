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

final class GetSetCssIconClassesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testFlashDirectGetSetCssIconClasses(): void
    {
        $flash      = new Direct();
        $newClasses = [
            'error'   => 'alert alert-error',
            'success' => 'alert alert-success',
            'notice'  => 'alert alert-notice',
            'warning' => 'alert alert-warning',
        ];

        $actual = $flash->getCssIconClasses();
        $this->assertEmpty($actual);

        $flash->setCssIconClasses($newClasses);

        $expected = $newClasses;
        $actual   = $flash->getCssIconClasses();
        $this->assertSame($expected, $actual);
    }
}
