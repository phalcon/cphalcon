<?php

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Container\Definition;

use Phalcon\Container\Definition\DefinitionType;
use Phalcon\Tests\AbstractUnitTestCase;

final class DefinitionTypeTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-18
     */
    public function testContainerDefinitionDefinitionTypeConstants(): void
    {
        $this->assertSame('closure', DefinitionType::CLOSURE);
        $this->assertSame('object', DefinitionType::OBJECT);
        $this->assertSame('parameter', DefinitionType::PARAMETER);
        $this->assertSame('string', DefinitionType::STRING);
    }
}
