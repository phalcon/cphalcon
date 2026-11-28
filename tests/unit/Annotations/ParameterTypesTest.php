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

namespace Phalcon\Tests\Unit\Annotations;

use Phalcon\Annotations\Annotation;
use Phalcon\Annotations\Router\Connect;
use Phalcon\Annotations\Router\Delete;
use Phalcon\Annotations\Router\Get;
use Phalcon\Annotations\Router\Head;
use Phalcon\Annotations\Router\Options;
use Phalcon\Annotations\Router\Patch;
use Phalcon\Annotations\Router\Post;
use Phalcon\Annotations\Router\Purge;
use Phalcon\Annotations\Router\Put;
use Phalcon\Annotations\Router\Route;
use Phalcon\Annotations\Router\Trace;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\IgnoreDeprecations;
use stdClass;
use TypeError;

/**
 * cphalcon accepts a value of any type for these parameters. The method body
 * examines the value.
 *
 * @issue https://github.com/phalcon/phalcon/issues/845
 */
final class ParameterTypesTest extends AbstractUnitTestCase
{
    /**
     * @return array<string, array{0: bool, 1: string}>
     */
    public static function getArgumentPositions(): array
    {
        return [
            'true'  => [true, 'one'],
            'false' => [false, 'zero'],
        ];
    }

    /**
     * @return array<string, array{0: class-string<Route>}>
     */
    public static function getRouteClasses(): array
    {
        return [
            'Connect' => [Connect::class],
            'Delete'  => [Delete::class],
            'Get'     => [Get::class],
            'Head'    => [Head::class],
            'Options' => [Options::class],
            'Patch'   => [Patch::class],
            'Post'    => [Post::class],
            'Purge'   => [Purge::class],
            'Put'     => [Put::class],
            'Trace'   => [Trace::class],
        ];
    }

    /**
     * @return array<string, array{0: mixed}>
     */
    public static function getRouteValues(): array
    {
        return [
            'null'   => [null],
            'true'   => [true],
            'object' => [new stdClass()],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/845
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getArgumentPositions')]
    public function testAnnotationsAnnotationArgument(bool $position, string $expected): void
    {
        $annotation = $this->getAnnotation();

        $this->assertSame($expected, $annotation->getArgument($position));
        $this->assertTrue($annotation->hasArgument($position));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/845
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    public function testAnnotationsAnnotationArgumentArray(): void
    {
        $this->expectException(TypeError::class);
        $this->expectExceptionMessage('in isset or empty');

        $this->getAnnotation()->getArgument(['a']);
    }

    /**
     * On PHP 8.5 and later, a null position gives the deprecation "Using
     * null as an array offset". cphalcon gives the same deprecation.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/845
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[IgnoreDeprecations]
    public function testAnnotationsAnnotationArgumentNull(): void
    {
        $annotation = $this->getAnnotation();

        $this->assertNull($annotation->getArgument(null));
        $this->assertFalse($annotation->hasArgument(null));
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/845
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     *
     * @param class-string<Route> $class
     */
    #[DataProvider('getRouteClasses')]
    public function testAnnotationsRouterBeforeMatch(string $class): void
    {
        $beforeMatch = new stdClass();
        $route       = new $class('/a', null, [], [], $beforeMatch);

        $this->assertSame($beforeMatch, $route->beforeMatch);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/845
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-25
     */
    #[DataProvider('getRouteValues')]
    public function testAnnotationsRouterRoute(mixed $value): void
    {
        $route = new Route('/a', $value, null, [], [], $value);

        $this->assertSame($value, $route->methods);
        $this->assertSame($value, $route->beforeMatch);
    }

    private function getAnnotation(): Annotation
    {
        return new Annotation(
            [
                'name'      => 'Test',
                'arguments' => [
                    ['expr' => ['type' => 303, 'value' => 'zero']],
                    ['expr' => ['type' => 303, 'value' => 'one']],
                    ['name' => 'a', 'expr' => ['type' => 303, 'value' => 'A']],
                ],
            ]
        );
    }
}
