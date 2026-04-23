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

namespace Phalcon\Tests\Unit\Assets\Manager;

use Phalcon\Assets\Manager;
use Phalcon\Di\InjectionAwareInterface;
use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-19
     */
    public function testAssetsManagerConstruct(): void
    {
        $manager = new Manager(new TagFactory(new Escaper()));

        $class  = Manager::class;
        $actual = $manager;
        $this->assertInstanceOf($class, $actual);

        $class = InjectionAwareInterface::class;
        $this->assertInstanceOf($class, $actual);
    }
}
