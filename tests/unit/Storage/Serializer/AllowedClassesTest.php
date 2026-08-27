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

namespace Phalcon\Tests\Unit\Storage\Serializer;

use Phalcon\Storage\Serializer\Php;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Storage\Fake\WakeupCanary;
use stdClass;

use function serialize;

final class AllowedClassesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageSerializerPhpAllowedClassesDefaultAcceptsObjects(): void
    {
        $serializer = new Php();

        $this->assertTrue($serializer->getAllowedClasses());

        $serializer->unserialize(serialize(new stdClass()));

        $this->assertTrue($serializer->isSuccess());
        $this->assertInstanceOf(stdClass::class, $serializer->getData());
    }

    /**
     * With the allow-list off, stored bytes cannot build any object: the
     * canary's __wakeup() never runs and the read is reported as failed.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageSerializerPhpAllowedClassesFalseRejectsObjects(): void
    {
        $serializer = (new Php())->setAllowedClasses(false);

        WakeupCanary::$fired = false;
        $serializer->unserialize(serialize(new WakeupCanary()));

        $this->assertFalse(WakeupCanary::$fired);
        $this->assertFalse($serializer->isSuccess());
        $this->assertSame('', $serializer->getData());

        // Scalars and arrays are unaffected.
        $serializer->unserialize(serialize(['a' => 1]));
        $this->assertTrue($serializer->isSuccess());
        $this->assertSame(['a' => 1], $serializer->getData());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-26
     */
    public function testStorageSerializerPhpAllowedClassesListAcceptsListedOnly(): void
    {
        $serializer = (new Php())->setAllowedClasses([stdClass::class]);

        $this->assertSame([stdClass::class], $serializer->getAllowedClasses());

        $serializer->unserialize(serialize(new stdClass()));
        $this->assertTrue($serializer->isSuccess());
        $this->assertInstanceOf(stdClass::class, $serializer->getData());

        WakeupCanary::$fired = false;
        $serializer->unserialize(serialize(new WakeupCanary()));
        $this->assertFalse(WakeupCanary::$fired);
        $this->assertFalse($serializer->isSuccess());
    }
}
