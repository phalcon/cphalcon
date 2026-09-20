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

namespace Phalcon\Tests\Unit\Annotations\Adapter\Memory;

use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Annotations\Reflection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Talon\Talon;
use TestClass;
use User\TestClassNs;

final class GetSetAnnotationsLimitTest extends AbstractUnitTestCase
{
    /**
     * The limit is 0 (unlimited) until it is set. When the cache holds as
     * many classes as the limit, the next class clears it.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-19
     */
    public function testAnnotationsAdapterMemoryGetSetAnnotationsLimit(): void
    {
        require_once Talon::settings()->supportPath('assets/Annotations/TestClass.php');
        require_once Talon::settings()->supportPath('assets/Annotations/TestClassNs.php');

        $adapter = new Memory();

        $this->assertSame(0, $adapter->getAnnotationsLimit());

        $adapter->setAnnotationsLimit(1);
        $this->assertSame(1, $adapter->getAnnotationsLimit());

        $first = $adapter->get(TestClass::class);
        $this->assertInstanceOf(Reflection::class, $first);

        /**
         * The cache is full, so this class clears it. The adapter still
         * answers with the annotations of the class asked for.
         */
        $second = $adapter->get(TestClassNs::class);
        $this->assertInstanceOf(Reflection::class, $second);
    }
}
