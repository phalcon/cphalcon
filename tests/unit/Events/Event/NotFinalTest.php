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

namespace Phalcon\Tests\Unit\Events\Event;

use Phalcon\Events\Event;
use Phalcon\Tests\AbstractUnitTestCase;
use ReflectionClass;

final class NotFinalTest extends AbstractUnitTestCase
{
    public function testEventIsNotFinal(): void
    {
        $class = new ReflectionClass(Event::class);

        $this->assertFalse($class->isFinal());
    }
}
