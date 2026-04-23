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

namespace Phalcon\Tests\Unit\Application;

use Phalcon\Application\AbstractApplication;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Events\EventsAwareInterface;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Application\Fake\FakeApplication;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testApplicationConstruct(): void
    {
        $application = new FakeApplication();

        $class  = EventsAwareInterface::class;
        $actual = $application;
        $this->assertInstanceOf($class, $actual);

        $class = InjectionAwareInterface::class;
        $this->assertInstanceOf($class, $actual);

        $class = AbstractApplication::class;
        $this->assertInstanceOf($class, $actual);
    }
}
