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

namespace Phalcon\Tests\Unit\Annotations\Reflection;

use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class GetReflectionDataTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAnnotationsReflectionGetReflectionData(): void
    {
        $reflection = new Reflection();

        $this->assertIsArray($reflection->getReflectionData());
        $this->assertEmpty($reflection->getReflectionData());
    }
}
