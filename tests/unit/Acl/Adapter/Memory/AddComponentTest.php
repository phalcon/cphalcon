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

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\ComponentInterface;
use Phalcon\Acl\Exceptions\ForbiddenDelimiter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class AddComponentTest extends AbstractUnitTestCase
{
    /**
     * A custom ComponentInterface cannot give a name with the "!" delimiter.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17800
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-26
     */
    public function testAclAdapterMemoryAddComponentCustomNameWithDelimiter(): void
    {
        $component = new class () implements ComponentInterface {
            public function __toString(): string
            {
                return 'Invoices!Reports';
            }

            public function getDescription(): string | null
            {
                return null;
            }

            public function getName(): string
            {
                return 'Invoices!Reports';
            }
        };

        $this->expectException(ForbiddenDelimiter::class);
        $this->expectExceptionMessage("The component name cannot contain '!'");

        (new Memory())->addComponent($component, ['list']);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddComponentNumericKey(): void
    {
        $acl       = new Memory();
        $component = new Component('11', 'Customer component');

        $actual = $acl->addComponent($component, ['index']);
        $this->assertTrue($actual);

        $actual = $acl->isComponent('11');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddComponentObject(): void
    {
        $acl       = new Memory();
        $component = new Component('Customer', 'Customer component');

        $actual = $acl->addComponent($component, ['index']);
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryAddComponentString(): void
    {
        $acl = new Memory();

        $actual = $acl->addComponent('Customer', ['index']);
        $this->assertTrue($actual);
    }
}
