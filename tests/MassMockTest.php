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

namespace Phalcon\Tests;

use PHPUnit\Framework\Attributes\Group;
use PHPUnit\Framework\MockObject\MockObject;
use PHPUnit\Framework\TestCase;
use ReflectionClass;

/**
 * Mocks every non final Phalcon class, to make sure that the reflection the
 * mock generator does on the extension causes no segmentation fault.
 *
 * The test suites do not contain this file. CI runs it by path in its own
 * step, because a crash stops the process and thus removes the report of the
 * other tests.
 *
 * The PHPUnit mocks are intentional. The mock generator is what this test
 * examines, thus do not replace them with fakes.
 */
#[Group('smoke')]
class MassMockTest extends TestCase
{
    public function testSegFaults(): void
    {
        $classes = array_filter(get_declared_classes(), function ($var) {
            return preg_match('/^Phalcon/', $var) === 1 && preg_match('/^Phalcon\\\\Test/', $var) === 0;
        });
        sort($classes);

        foreach ($classes as $class) {
            $reflector = new ReflectionClass($class);
            /**
             * Final class could not be mocked.
             */
            if ($reflector->isFinal()) {
                continue;
            }

            $mockBuilder = $this->createMock($class);
            $this->assertInstanceOf(MockObject::class, $mockBuilder);

            unset($reflector, $mockBuilder);
        }
    }
}
