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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-09-09
     */
    public function testDiConstruct(): void
    {
        $class = Di::class;
        new Di();

        $actual = Di::getDefault();
        $this->assertInstanceOf($class, $actual);

        $actual = Di::getDefault();
        $this->assertInstanceOf($class, $actual);
    }
}
