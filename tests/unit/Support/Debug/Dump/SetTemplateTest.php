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

namespace Phalcon\Tests\Unit\Support\Debug\Dump;

use Phalcon\Support\Debug\Dump;
use Phalcon\Tests\AbstractUnitTestCase;

final class SetTemplateTest extends AbstractUnitTestCase
{
    public function testGetTemplateReturnsDefaultWhenNotOverridden(): void
    {
        $this->assertStringContainsString('<pre', (new Dump())->getTemplate('pre'));
    }

    public function testSetTemplateOverridesBold(): void
    {
        $dump = new Dump();
        $dump->setTemplate('bold', '<strong style="%style%">%text%</strong>');

        $actual = $dump->variable(123);

        $this->assertStringContainsString('<strong', $actual);
        $this->assertStringContainsString('Integer', $actual);
    }
}
