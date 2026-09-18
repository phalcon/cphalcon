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

namespace Phalcon\Tests\Unit\Mvc\Model\Hydration;

use Phalcon\Mvc\Model\Hydration\GetPrivateProperties;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\Objects\PrivatePropertiesChild;
use ReflectionProperty;

final class GetPrivatePropertiesTest extends AbstractUnitTestCase
{
    /**
     * The per-class cache must hand back the same ReflectionProperty objects.
     */
    public function testCachesResultPerClass(): void
    {
        $first  = GetPrivateProperties::getPrivateProperties(
            PrivatePropertiesChild::class
        );
        $second = GetPrivateProperties::getPrivateProperties(
            PrivatePropertiesChild::class
        );

        $this->assertSame($first['childOnly'], $second['childOnly']);
        $this->assertSame($first['parentOnly'], $second['parentOnly']);
    }

    /**
     * Static private properties are skipped; public and protected ones are
     * never collected.
     */
    public function testExcludesStaticAndNonPrivateProperties(): void
    {
        $actual = GetPrivateProperties::getPrivateProperties(
            PrivatePropertiesChild::class
        );

        $this->assertArrayNotHasKey('staticParent', $actual);
        $this->assertArrayNotHasKey('protectedParent', $actual);
        $this->assertArrayNotHasKey('publicParent', $actual);
    }

    /**
     * Inherited private properties are included, and a name declared in both
     * the child and the parent resolves to the child's declaration.
     */
    public function testIncludesInheritedPrivatePropertiesWithChildWinning(): void
    {
        $actual = GetPrivateProperties::getPrivateProperties(
            PrivatePropertiesChild::class
        );

        $keys = array_keys($actual);
        sort($keys);

        $this->assertSame(['childOnly', 'parentOnly', 'shadowed'], $keys);
        $this->assertInstanceOf(ReflectionProperty::class, $actual['parentOnly']);
        $this->assertSame(
            PrivatePropertiesChild::class,
            $actual['shadowed']->getDeclaringClass()->getName()
        );
    }
}
