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

final class GetSetAutomaticHtmlTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFlashDirectGetSetAutomaticHtml(): void
    {
        $flash = new Direct();

        $actual = $flash->getAutomaticHtml();
        $this->assertTrue($actual);

        $actual = $flash->setAutomaticHtml(false);
        $this->assertInstanceOf(Direct::class, $actual);

        $actual = $flash->getAutomaticHtml();
        $this->assertFalse($actual);
    }
}
