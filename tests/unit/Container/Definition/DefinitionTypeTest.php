<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Definition;

use Phalcon\Container\Definition\DefinitionType;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class DefinitionTypeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionDefinitionTypeConstants(): void
    {
        $this->assertSame('closure', DefinitionType::CLOSURE_TYPE);
        $this->assertSame('object', DefinitionType::OBJECT_TYPE);
        $this->assertSame('parameter', DefinitionType::PARAMETER_TYPE);
        $this->assertSame('string', DefinitionType::STRING_TYPE);
    }
}
