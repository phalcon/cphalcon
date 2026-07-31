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

namespace Phalcon\Tests\Unit\ADR\Router;

use Phalcon\ADR\Exceptions\RouteNotFound;
use Phalcon\ADR\Router\AttributeFilter;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use RuntimeException;

final class FilterTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() anchors the regex to the whole segment
     */
    public function testAdrAttributeFilterFilterAnchorsRegexFully(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['id' => ['match' => '\d+']];
            }
        };

        $this->expectException(RouteNotFound::class);

        (new AttributeFilter())->filter($action::class, ['12abc']);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() casts to float
     */
    public function testAdrAttributeFilterFilterCastsFloat(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['ratio' => ['type' => 'float']];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['1.5']);

        $this->assertSame(['ratio' => 1.5], $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() validates and casts to int
     */
    public function testAdrAttributeFilterFilterCastsInt(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['id' => ['match' => '\d+', 'type' => 'int']];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['42']);

        $this->assertSame(['id' => 42], $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() lets a converter exception bubble
     */
    public function testAdrAttributeFilterFilterConverterExceptionBubbles(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['id' => ['convert' => fn ($v) => throw new RuntimeException('boom')]];
            }
        };

        $this->expectException(RuntimeException::class);

        (new AttributeFilter())->filter($action::class, ['1']);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() runs the converter on the cast value
     */
    public function testAdrAttributeFilterFilterConverterReceivesCastValue(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['id' => ['type' => 'int', 'convert' => fn ($v) => is_int($v)]];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['7']);

        $this->assertSame(['id' => true], $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() names attributes by declaration order
     */
    public function testAdrAttributeFilterFilterNamesByDeclarationOrder(): void
    {
        $action = new class {
            public static function params(): array
            {
                return [
                    'year' => ['type' => 'int'],
                    'slug' => [],
                ];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['2026', 'hello']);

        $this->assertSame(['year' => 2026, 'slug' => 'hello'], $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() passes surplus segments through positionally
     */
    public function testAdrAttributeFilterFilterPassesSurplusPositionally(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['id' => ['type' => 'int']];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['5', 'extra']);

        $this->assertSame(['id' => 5, 1 => 'extra'], $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() passes through when no params() method
     */
    public function testAdrAttributeFilterFilterPassesThroughWhenNoParams(): void
    {
        $action = new class {
        };

        $result = (new AttributeFilter())->filter($action::class, ['1', '2']);

        $this->assertSame(['1', '2'], $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() rejects a segment that fails its regex
     */
    public function testAdrAttributeFilterFilterRejectsOnRegexMiss(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['id' => ['match' => '\d+', 'type' => 'int']];
            }
        };

        $this->expectException(RouteNotFound::class);

        (new AttributeFilter())->filter($action::class, ['abc']);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() skips a declared parameter with no segment
     */
    public function testAdrAttributeFilterFilterSkipsMissingParameter(): void
    {
        $action = new class {
            public static function params(): array
            {
                return [
                    'id'   => ['type' => 'int'],
                    'slug' => [],
                ];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['5']);

        $this->assertSame(['id' => 5], $result);
        $this->assertArrayNotHasKey('slug', $result);
    }

    /**
     * Unit Tests Phalcon\ADR\Router\AttributeFilter :: filter() treats an unknown type as string
     */
    public function testAdrAttributeFilterFilterTreatsUnknownTypeAsString(): void
    {
        $action = new class {
            public static function params(): array
            {
                return ['x' => ['type' => 'weird']];
            }
        };

        $result = (new AttributeFilter())->filter($action::class, ['9']);

        $this->assertSame(['x' => '9'], $result);
    }
}
