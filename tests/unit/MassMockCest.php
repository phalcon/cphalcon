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

namespace Phalcon\Test\Unit;

use PHPUnit\Framework\MockObject\MockObject;
use PHPUnit\Framework\TestCase;
use ReflectionClass;

class MassMockCest extends TestCase
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

            /**
             * Enable this for debug in case of segmentation faults.
             */
            //printf($class . PHP_EOL);
            //ob_flush();

            $mockBuilder = $this->getMockBuilder($class)->disableOriginalConstructor();
            $this->assertInstanceOf(MockObject::class, $mockBuilder->getMock());

            unset($reflector, $mockBuilder);
        }
    }
}
