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

namespace Phalcon\Tests\Unit\Di\FactoryDefault\Cli;

use Phalcon\Di\FactoryDefault\Cli as Di;
use Phalcon\Tests\AbstractUnitTestCase;

use function spl_object_hash;

final class GetSetDefaultResetTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDiFactorydefaultCliGetDefault(): void
    {
        // Reset and create a Cli so it becomes the default
        Di::reset();
        $container = new Di();

        // there is a DI container
        $this->assertInstanceOf(Di::class, Di::getDefault());

        $container = Di::getDefault();

        // delete it
        Di::reset();

        // Get a new container
        $new = Di::getDefault();

        $this->assertNull($new);

        // set it again
        Di::setDefault($container);

        $class  = Di::class;
        $actual = Di::getDefault();
        $this->assertInstanceOf($class, $actual);

        $containerHash = spl_object_hash($container);
        $currentHash   = spl_object_hash($actual);
        $this->assertSame($containerHash, $currentHash);
    }
}
