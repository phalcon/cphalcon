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

namespace Phalcon\Tests\Unit\Mvc\Model;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionMethod;
use ReflectionNamedType;

final class FindReturnTypeTest extends AbstractUnitTestCase
{
    /**
     * Locks in the runtime return type of `Phalcon\Mvc\Model::find()`. The
     * type was inadvertently dropped in PR #16578 (Phalcon 5.7.0) while
     * adding `@template T` generic docblocks; this caused subclass overrides
     * that narrowed to `: ResultsetInterface` and strictly-typed call sites
     * to break for users upgrading from 5.6.x.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/16633
     */
    public function testFindReturnsResultsetInterface(): void
    {
        $reflection = new ReflectionMethod(Model::class, 'find');
        $returnType = $reflection->getReturnType();

        $this->assertInstanceOf(
            ReflectionNamedType::class,
            $returnType,
            'Model::find() must declare a runtime return type'
        );

        $this->assertSame(
            ResultsetInterface::class,
            $returnType->getName(),
            'Model::find() must declare ResultsetInterface as its return type'
        );
    }

    /**
     * `findFirst()` keeps its historical loose return type (`var|null`,
     * compiled to no explicit type with a nullable docblock) since it has
     * never been narrowed to a single class and downstream code relies on
     * that flexibility (it may return a `ModelInterface`, a `Row`, or `null`).
     *
     * @issue https://github.com/phalcon/cphalcon/issues/16633
     */
    public function testFindFirstReturnTypeIsLoose(): void
    {
        $reflection = new ReflectionMethod(Model::class, 'findFirst');
        $returnType = $reflection->getReturnType();

        // The Zephir `var | null` declaration compiles to no specific type
        // hint in the reflection layer (or a permissive one), so the test
        // here is intentionally tolerant: we only assert it's not the
        // narrow `ResultsetInterface` that find() declares.
        if ($returnType instanceof ReflectionNamedType) {
            $this->assertNotSame(
                ResultsetInterface::class,
                $returnType->getName()
            );
        } else {
            $this->assertNull($returnType);
        }
    }
}
